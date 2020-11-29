//
// Created by Vladyslav Synytsyn on 22-Oct-20.
//

#include <logics/exceptions/CustomerRegistrationException.h>
#include <logics/exceptions/NotEnoughMoneyException.h>
#include <logics/bank_fees/CreditConditions.h>
#include <logics/exceptions/DepositMaxSumReachedException.h>
#include <data_access/CardDAO.h>
#include "OperationManager.h"

#include "QDebug"

// todo withdraw, transfer, register, takeCredit, repayCredit, replenishDeposit, startDeposit, setPayment can throw std::exception
bool OperationManager::authorizeCustomer(const QString& cardNumber, const QString& pinCode) {
    Customer* const customer = _customerDataManager.getCustomerByCardNumber(cardNumber);
    if (customer == nullptr)
        return false;
    QList<Card*> cards = customer->cards();
    for (int i = 0; i < cards.count(); ++i) {
        if (cards[i]->number() == cardNumber) {
            if (cards[i]->pin() == pinCode && !cards[i]->isBlocked()) {
                _authorizer.authorizeCustomer(customer, cards[i]);
                return true;
            }
        }
    }
    delete customer;
    return false;
}

void OperationManager::blockCustomer(const QString& cardNumber) {
    CardDAO& cardDao = CardDAO::getInstance();
    Card* pCard = cardDao.getById(cardNumber);
    if (pCard != nullptr) {
        pCard->block();
        qInfo() << "Card '" << cardNumber << "' was blocked";
        cardDao.updateCard(*pCard);
    }
    delete pCard;
}

QString OperationManager::registerCustomer(const CustomerVerificationData& verificationData) {
    return _registrator.registerCustomer(verificationData);
}


void OperationManager::replenish(uint howMuch) {
    _customerDataManager.replenish(Money(howMuch));
}

void OperationManager::withdraw(unsigned int howMuch) {
    _customerDataManager.withdraw(Money(howMuch));
}

void OperationManager::transfer(const QString& cardNumberFrom, const QString& cardNumberTo, const Money& amount) {
    if (cardNumberFrom == cardNumberTo)
        throw std::invalid_argument("Couldn't transfer yourself");

    Customer* const customer = CustomerDAO::getInstance().getCustomerByCardId(cardNumberTo);
    if (customer == nullptr)
        throw std::invalid_argument("No such card registered: '" + cardNumberTo.toStdString() + "'");

    Card* cardFrom = CardDAO::getInstance().getById(cardNumberFrom);
    const std::pair<Money, Money>& pair = cardFrom->transfer(cardNumberTo, amount);
    cardFrom->withdrawFree(pair.second); // Money before subtracting fee
    CardDAO::getInstance().updateCard(*cardFrom);
    delete cardFrom;
    delete customer;
}


void OperationManager::transfer(const QString& cardNumberTo, uint amount) {
    transfer(_customerDataManager.card().number(), cardNumberTo, amount);
}

QList<Credit*> OperationManager::getAllCredits() {
    return _customerDataManager.customer().credits();
}


void OperationManager::takeCredit(const QString& name,
                                  uint amount,
                                  uint period,
                                  uint payment,
                                  const QDateTime& start,
                                  const QDateTime& end) {
    double interest = CreditConditions::creditingOptions.value(period);
    const Money& debt = Money(amount);
    if (_customerDataManager.canAffordCredit(debt, period, interest)) {
        _customerDataManager.takeCredit(debt, name, interest, period);
    } else
        throw NotEnoughMoneyException(
                _customerDataManager.customer().creditLimit(),
                CustomerDataManager::getCreditValueWithPercents(amount, period, interest));
}

void OperationManager::repayCredit(uint id) {
    _customerDataManager.repayCredit(-1, id);
}

QList<Deposit*> OperationManager::getAllDeposits() {
    return _customerDataManager.customer().deposits();
}

void OperationManager::startDeposit(
        const QString& name, uint amount, uint period, const QDateTime& start, const QDateTime& end,
        double percentage) {
    if (_customerDataManager.canOpenDeposit(amount)) {
        _customerDataManager.openDeposit(amount, name, percentage, period, start.date(), end.date());
    } else
        throw DepositMaxSumReachedException("You have reached max sum on deposits.");
}


void OperationManager::cancelDeposit(uint id) {
    _customerDataManager.cancelDeposit(id);
}

void OperationManager::replenishDeposit(uint id, uint amount) {
    if (_customerDataManager.balance() >= amount) {
        _customerDataManager.replenishDeposit(amount, id);
    } else {
        throw NotEnoughMoneyException(_customerDataManager.balance(), amount);
    }
}

QList<RegularPayment*> OperationManager::getAllPayments() {
    return _paymentDao.getAll();
    // TODO
//    return _customerDataManager.customer().regularPayments();
}

void OperationManager::setPayment(const QString& name, uint amount, const QString& receiver, const uint& day) {
    if (_customerDataManager.balance() < amount)
        throw NotEnoughMoneyException(_customerDataManager.balance(), amount);
    if (_customerDataManager.card().number() == receiver)
        throw std::invalid_argument("The receiver couldn't be the same person as the sender.");

    Customer* pReceiver = _customerDataManager.getCustomerByCardNumber(receiver);
    if (pReceiver == nullptr)
        throw std::invalid_argument("No such card registered: '" + receiver.toStdString() + "'");

    auto* const pPayment = new RegularPayment(name, amount, _customerDataManager.card().number(), receiver,
                                                        day);
    _paymentDao.save(*pPayment);
    delete pPayment;
    delete pReceiver;
}

void OperationManager::cancelPayment(uint id) {
    _paymentDao.removePayment(id);
}

OperationManager::OperationManager(CustomerDataManager manager) :
        _customerDataManager(manager),

        _creditDao(CreditDAO::getInstance()), _depositDao(DepositDAO::getInstance()),
        _paymentDao(PaymentDAO::getInstance()), _customerDao(CustomerDAO::getInstance()),

        _authorizer(Authorizer{_customerDataManager}),
        _registrator(Registrator{_customerDataManager, _customerDao}),

        _timeDrivenEventsHandler(nullptr),
        _clock(nullptr) {
    _timeDrivenEventsHandler = new TimeDrivenEventsHandler(this);
}

void OperationManager::setClock(Clock* clock) {
    _clock = clock;
    _clock->subscribe(_timeDrivenEventsHandler);
}

int OperationManager::endDeposit(const uint depositId) {
    Deposit* pDeposit = DepositDAO::getInstance().getById(depositId);
    Customer* pCustomer = CustomerDataManager::getCustomerByDepositId(depositId);

    if (pDeposit == nullptr)
        throw std::invalid_argument("Given deposit id wasn't found in DB.");
    if (pCustomer == nullptr)
        throw std::invalid_argument("Given deposit isn't belong to any customer.");

    Card* pCard = CardDAO::getInstance().getById(pDeposit->ownerCard());
    if (pCard == nullptr)
        throw std::invalid_argument("Card, to which money must be transferred cannot be found in DB. "
                                    + pDeposit->ownerCard().toStdString());

    pCard->replenishFree(pDeposit->sum());
    pCustomer->removeDeposit(depositId);
    DepositDAO::getInstance().deleteById(depositId);
    CustomerDAO::getInstance().removeDeposit(depositId);
    CardDAO::getInstance().updateCard(*pCard);

    delete pDeposit;
    delete pCustomer;
    delete pCard;

    return depositId;
}

Money OperationManager::getCurrentCustomerCreditLimit() {
    return _customerDataManager.customer().creditLimit();
}

Money OperationManager::getInsertedCardBalance() {
    return _customerDataManager.balance();
}




