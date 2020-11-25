//
// Created by Andrew on 02-Oct-20.
//

#include <logics/exceptions/NotEnoughMoneyException.h>
#include <logics/exceptions/NoSuchCreditException.h>
//#include <logics/exceptions/WrongPaymentException.h>
#include <logics/exceptions/CreditRepayOverheadException.h>
#include <logics/exceptions/NoSuchDepositException.h>

#include <utility>
#include <data_access/CustomerDAO.h>
#include <data_access/CardDAO.h>
#include <data_access/DepositDAO.h>
#include <data_access/CreditDAO.h>
#include <logics/exceptions/NoSuchCardException.h>
#include "CustomerDataManager.h"

const Customer& CustomerDataManager::customer() const {
	return *_customer;
}

Money CustomerDataManager::balance() const {
	return _bankCard->balance();
}

void CustomerDataManager::replenish(Money amount) {
	_bankCard->replenish(amount);
}

void CustomerDataManager::withdraw(Money amount) {
	if (_bankCard->balance() < amount) throw NotEnoughMoneyException(_bankCard->balance(), amount);
	_bankCard->withdraw(amount);
}

bool CustomerDataManager::canAffordCredit(Money amount, double interest) const {
	return _customer->creditLimit() <= amount * interest / 12;
}

Money CustomerDataManager::takeCredit(Money debt, QString name, double interest) {
	Credit* credit = new Credit(std::move(name), debt, interest, debt * interest / 12);
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
	if (selected->payment() != amount) throw CreditRepayOverheadException(selected->payment(), amount);

	if (selected->debt() > amount) {
		selected->replenish(amount);
		return false;
	} else {
		Money diff = amount - selected->debt();
		_customer->removeCredit(selected->id());
		CreditDAO::getInstance().deleteById(selected->id());
		CustomerDAO::getInstance().removeCredit(selected->id());
		_bankCard->replenishFree(diff);
		return true;
	}
}

bool CustomerDataManager::canOpenDeposit(Money potentialBalance) const {
	Money totalDepositBalance = 0;
	for (auto iter : _customer->deposits())
		totalDepositBalance += iter->sum();
	return (totalDepositBalance + potentialBalance) < Deposit::maxDepoSum;
}

Money CustomerDataManager::openDeposit(Money initialBalance, QString name, double interest, uint months) {
	Deposit* depo = new Deposit(std::move(name), initialBalance, interest,
								QDate::currentDate(), QDate::currentDate().addMonths(months));
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
}

void CustomerDataManager::closeDeposit(uint depoId) {
	Deposit* deposit = nullptr;
	for (auto iter : _customer->deposits())
		if (iter->id() == depoId) {
			deposit = iter;
			break;
		}
	if (deposit == nullptr) throw NoSuchDepositException(_customer->_taxNumber, depoId);
	_bankCard->replenish(deposit->sum());
	_customer->removeDeposit(depoId);
	DepositDAO::getInstance().deleteById(depoId);
	CustomerDAO::getInstance().removeDeposit(depoId);
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

Customer* CustomerDataManager::getCustomerByDepositId(uint depoId) const {
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

