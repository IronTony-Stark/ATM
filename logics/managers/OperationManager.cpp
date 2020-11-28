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
            if (cards[i]->pin() == pinCode) {
                _authorizer.authorizeCustomer(customer, cards[i]);
                return true;
            }
        }
    }
    delete customer;
    return false;
}

void OperationManager::blockCustomer(const QString& cardNumber) {
    throw std::exception();
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
        _customerDataManager.takeCredit(debt, name, interest);
    } else
        throw NotEnoughMoneyException(
                _customerDataManager.customer().creditLimit(),
                CustomerDataManager::getCreditValueWithPercents(amount, period, interest));
}

void OperationManager::repayCredit(uint id) {
    Credit* pCredit = _creditDao.getById(id);
    const Money& requested = pCredit->payment();
    if (_customerDataManager.balance() >= requested) {
        pCredit->replenish(requested);
        _customerDataManager.withdraw(requested);
        delete pCredit;
    } else {
        delete pCredit;
        throw NotEnoughMoneyException(_customerDataManager.balance(), requested);
    }
}

QList<Deposit*> OperationManager::getAllDeposits() {
    return _customerDataManager.customer().deposits();
}

void OperationManager::startDeposit(
        const QString& name, uint amount, uint period, const QDateTime& start, const QDateTime& end,
        double percentage) {
    if (_customerDataManager.canOpenDeposit(amount)) {
        _customerDataManager.openDeposit(amount, name, percentage, period);
    } else
        throw DepositMaxSumReachedException("You have reached max sum on deposits.");
}


void OperationManager::cancelDeposit(uint id) {
    Deposit* pDeposit = _depositDao.getById(id);
//    todo: pDeposit->cancel();
    delete pDeposit;
}

void OperationManager::replenishDeposit(uint id, uint amount) {
    Deposit* pDeposit = _depositDao.getById(id);
    if (_customerDataManager.balance() >= amount) {
        pDeposit->replenish(amount);
        _customerDataManager.withdraw(amount);
        delete pDeposit;
    } else {
        delete pDeposit;
        throw NotEnoughMoneyException(_customerDataManager.balance(), amount);
    }
}

QList<RegularPayment*> OperationManager::getAllPayments() {
    return _paymentDao.getAll();
}

void OperationManager::setPayment(const QString& name, uint amount, const QString& receiver, const uint& day) {
    if (_customerDataManager.balance() < amount)
        throw NotEnoughMoneyException(_customerDataManager.balance(), amount);

    RegularPayment* const pPayment = new RegularPayment(name, amount, _customerDataManager.card().number(), receiver,
                                                        day);
    _paymentDao.save(*pPayment);
    delete pPayment;
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
    Deposit* pDeposit = _depositDao.getById(depositId);
    Customer* pCustomer = _customerDataManager.getCustomerByDepositId(depositId);

    // TODO replenish to card

    delete pDeposit;
    delete pCustomer;

    return depositId;
}

Money OperationManager::getCurrentCustomerCreditLimit() {
    return _customerDataManager.customer().creditLimit();
}

Money OperationManager::getInsertedCardBalance() {
    return _customerDataManager.balance();
}




