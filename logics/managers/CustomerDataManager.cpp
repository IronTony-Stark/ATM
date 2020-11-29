//
// Created by Andrew on 02-Oct-20.
//

#include <logics/exceptions/NotEnoughMoneyException.h>
#include <logics/exceptions/NoSuchCreditException.h>
#include <logics/exceptions/CreditRepayOverheadException.h>
#include <logics/exceptions/NoSuchDepositException.h>

#include <utility>
#include <data_access/CustomerDAO.h>
#include <data_access/CardDAO.h>
#include <data_access/DepositDAO.h>
#include <data_access/CreditDAO.h>
#include <logics/exceptions/NoSuchCardException.h>
#include <logics/bank_fees/CreditConditions.h>
#include "CustomerDataManager.h"

const Customer& CustomerDataManager::customer() const {
    return *_customer;
}

Money CustomerDataManager::balance() const {
    return _bankCard->balance();
}

void CustomerDataManager::replenish(Money amount) {
    _bankCard->replenish(amount);
    CardDAO::getInstance().updateCard(*_bankCard);
}

void CustomerDataManager::withdraw(Money amount) {
    if (_bankCard->balance() < amount) throw NotEnoughMoneyException(_bankCard->balance(), amount);
    _bankCard->withdraw(amount);
    CardDAO::getInstance().updateCard(*_bankCard);
}

bool CustomerDataManager::canAffordCredit(Money amount, uint period, double interest) const {
    return _customer->creditLimit() >= getCreditValueWithPercents(amount, period, interest);
}

Money
CustomerDataManager::getCreditValueWithPercents(const Money& amount, uint period, double interest) {
    return amount + (amount * interest / 12 * period);
}

Money CustomerDataManager::takeCredit(Money debt, QString name, double interest, uint period) {
    const Money& creditValueWithPercents = getCreditValueWithPercents(debt, period, interest);
    Credit* credit = new Credit(std::move(name), creditValueWithPercents, interest, creditValueWithPercents / period);
    _customer->addCredit(credit);
    CreditDAO::getInstance().saveCredit(*credit);
    CustomerDAO::getInstance().addCredit(_customer->_taxNumber, credit->id());
    _bankCard->replenishFree(debt);
    return _bankCard->balance();
}

bool CustomerDataManager::repayCredit(Money amount, uint creditId) {
    Credit* selected = nullptr;
    for (auto iter : _customer->credits())
        if (iter->id() == creditId) {
            selected = iter;
            break;
        }
    if (selected == nullptr) throw NoSuchCreditException(_customer->_taxNumber, creditId);

    if (amount == -1)
        amount = selected->payment();
    if (selected->payment() != amount) throw CreditRepayOverheadException(selected->payment(), amount);

    const Money& haveToBePayed = selected->creditBody();
    bool creditEnd = false;

    if (haveToBePayed > amount) {
        selected->replenish(amount);
        CreditDAO::getInstance().updateCredit(*selected);
    } else {
        amount = amount - haveToBePayed; // debt - already payed sum
        _customer->removeCredit(selected->id());
        CreditDAO::getInstance().deleteById(selected->id());
        CustomerDAO::getInstance().removeCredit(selected->id());
        _bankCard->replenishFree(amount);
    }

    card().withdrawFree(amount);
    CardDAO::getInstance().updateCard(card());

    return creditEnd;
}

bool CustomerDataManager::canOpenDeposit(Money potentialBalance) const {
    Money totalDepositBalance = 0;
    for (auto iter : _customer->deposits())
        totalDepositBalance += iter->sum();
    return (totalDepositBalance + potentialBalance) < Deposit::maxDepoSum;
}

Money
CustomerDataManager::openDeposit(Money initialBalance, QString name, double interest,
                                 uint months, QDate startDate, QDate endDate) {
    Deposit* depo = new Deposit(_bankCard->id(), std::move(name), initialBalance, interest,
                                endDate, startDate);
    _customer->addDeposit(depo);
    _bankCard->withdrawFree(initialBalance);
    DepositDAO::getInstance().saveDeposit(*depo);
    CustomerDAO::getInstance().addDeposit(_customer->_taxNumber, depo->id());
    return _bankCard->balance();
}

void CustomerDataManager::replenishDeposit(Money amount, uint depoId) {
    Deposit* deposit = nullptr;
    for (auto iter : _customer->deposits())
        if (iter->id() == depoId) {
            deposit = iter;
            break;
        }
    if (deposit == nullptr) throw NoSuchDepositException(_customer->_taxNumber, depoId);
    deposit->replenish(amount);
    DepositDAO::getInstance().updateDeposit(*deposit);

    card().withdrawFree(amount);
    CardDAO::getInstance().updateCard(card());
}

void CustomerDataManager::cancelDeposit(uint depoId) {
    Deposit* deposit = nullptr;
    for (auto iter : _customer->deposits())
        if (iter->id() == depoId) {
            deposit = iter;
            break;
        }
    if (deposit == nullptr) throw NoSuchDepositException(_customer->_taxNumber, depoId);
    _bankCard->replenishFree(deposit->initBalance());
    _customer->removeDeposit(depoId);
    DepositDAO::getInstance().deleteById(depoId);
    CustomerDAO::getInstance().removeDeposit(depoId);
    CardDAO::getInstance().updateCard(card());
}

QString CustomerDataManager::getPin() const {
    return _bankCard->pin();
}

QString CustomerDataManager::changePin() {
    _bankCard->regeneratePin();
    CardDAO::getInstance().updateCard(*_bankCard);
    return _bankCard->pin();
}

Card& CustomerDataManager::card() const {
    return *_bankCard;
}

Customer* const CustomerDataManager::getCustomerByTaxNumber(const QString& id) const {
    return CustomerDAO::getInstance().getById(id);
}

Customer* const CustomerDataManager::getCustomerByCardNumber(const QString& cardNumber) const {
    return CustomerDAO::getInstance().getCustomerByCardId(cardNumber);
}

Customer* CustomerDataManager::getCustomerByCredit(uint creditId) const {
    return CustomerDAO::getInstance().getCustomerByCredit(creditId);
}

Customer* CustomerDataManager::getCustomerByDepositId(uint depoId) {
    return CustomerDAO::getInstance().getCustomerByDepositId(depoId);
}

void CustomerDataManager::setCard(Card* card) {
    _bankCard = card;
}

void CustomerDataManager::replenishByCardId(QString& cardId, Money amount) {
    Card* card = CardDAO::getInstance().getById(cardId);
    if (card == nullptr) throw NoSuchCardException(QString::number(-1), cardId);
    card->replenish(amount);
    CardDAO::getInstance().updateCard(*card);
}

void CustomerDataManager::withdrawByCardId(QString& cardId, Money amount) {
    Card* card = CardDAO::getInstance().getById(cardId);
    if (card == nullptr) throw NoSuchCardException(QString::number(-1), cardId);
    if (!card->canWithdraw(amount)) throw NotEnoughMoneyException(card->balance(), amount);
    card->withdraw(amount);
    CardDAO::getInstance().updateCard(*card);
}

