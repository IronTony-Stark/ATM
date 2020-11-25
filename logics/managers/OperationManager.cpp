//
// Created by Vladyslav Synytsyn on 22-Oct-20.
//

#include <logics/exceptions/CustomerRegistrationException.h>
#include <logics/exceptions/NotEnoughMoneyException.h>
#include <logics/bank_fees/CreditConditions.h>
#include <logics/exceptions/DepositMaxSumReachedException.h>
#include "OperationManager.h"

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
    return false;
}

void OperationManager::blockCustomer(const QString& cardNumber) {
    throw std::exception();
}

ushort OperationManager::registerCustomer(const CustomerVerificationData& verificationData) {
    return _registrator.registerCustomer(verificationData);
}


void OperationManager::replenish(uint howMuch) {
    _customerDataManager.replenish(Money(howMuch));
}

void OperationManager::withdraw(unsigned int howMuch) {
    _customerDataManager.withdraw(Money(howMuch));
}

void OperationManager::transfer(const QString& cardNumberTo, uint amount) {
    const Money money = Money(amount);
    if (_customerDataManager.balance() < money + _customerDataManager.card()._bankFee.transferFee())
        throw NotEnoughMoneyException(_customerDataManager.balance(), money);

    Customer* const customer = _customerDataManager.getCustomerByCardNumber(cardNumberTo);
    if (customer == nullptr)
        throw std::exception();
//        throw NoSuchCardException(_customerDataManager.customer().);

    _customerDataManager.card().transfer(cardNumberTo, amount);

//    const QList<Card*>& cards = customer->cards();
//    for (uint i = 0; i < cards.count(); ++i) {
//        if (cards[i]->number() == cardNumberTo){
//            _customerDataManager.withdraw(money);
//            cards[i]->transfer(money);
//        }
//    }
}

// TODO get all credits for the authorized user, not for all users
QList<Credit*> OperationManager::getAllCredits() {
	return _creditDao.getAll();
}

void OperationManager::takeCredit(const QString& name,
                                  uint amount,
                                  uint period,
                                  uint payment,
                                  const QDateTime& start,
                                  const QDateTime& end) {
    int interest = CreditConditions::creditingOptions.value(period);
    const Money& debt = Money(amount);
    if (_customerDataManager.canAffordCredit(debt, period)) {
        _customerDataManager.takeCredit(debt, name, interest);
    } else
        throw NotEnoughMoneyException(_customerDataManager.balance(), debt);
}

void OperationManager::repayCredit(uint id) {
    Credit* pCredit = _creditDao.getById(id);
    // TODO is this right?
    if (_customerDataManager.balance() >= pCredit->payment()) {
        pCredit->replenish(pCredit->payment());
        _customerDataManager.withdraw(pCredit->payment());
    } else
        throw NotEnoughMoneyException(_customerDataManager.balance(), pCredit->payment());
}


QList<Deposit*> OperationManager::getAllDeposits() {
	return _depositDao.getAll();
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
}

void OperationManager::replenishDeposit(uint id, uint amount) {
    Deposit* pDeposit = _depositDao.getById(id);
    if (_customerDataManager.balance() >= amount) {
        pDeposit->replenish(amount);
        _customerDataManager.withdraw(amount);
    }
    throw NotEnoughMoneyException(_customerDataManager.balance(), amount);
}


QList<RegularPayment* const> OperationManager::getAllPayments() {
//    return _paymentDao.getAll();
// TODO after DAO implemented
    return QList<RegularPayment* const>();
}

void OperationManager::setPayment(const QString& name, uint amount, const QString& receiver, const QDateTime& when) {
    if (_customerDataManager.balance() < amount)
        throw NotEnoughMoneyException(_customerDataManager.balance(), amount);

    RegularPayment* const pPayment = new RegularPayment(name, amount, _customerDataManager.card().number(), receiver,
                                                        when.date().day());
    _paymentDao.save(*pPayment);
}

void OperationManager::cancelPayment(uint id) {

}

OperationManager::OperationManager(
        CustomerDataManager manager,
        TimeDrivenEventsHandler handler,
        const CustomerDAO customerDao,
        const CreditDAO creditDao, const DepositDAO depositDao, const PaymentDAO paymentDao) :
        _customerDataManager(manager), _timeDrivenEventsHandler(handler),
        _creditDao(creditDao), _depositDao(depositDao), _paymentDao(paymentDao),
        _authorizer(Authorizer{_customerDataManager}),
        _registrator(Registrator{_customerDataManager, customerDao}) {
}

void OperationManager::setClock(Clock* clock) {
    _clock = clock;
};




