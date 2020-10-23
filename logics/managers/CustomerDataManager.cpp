//
// Created by Andrew on 02-Oct-20.
//

#include <logics/exceptions/NotEnoughMoneyException.h>
#include <logics/exceptions/NoSuchCreditException.h>
//#include <logics/exceptions/WrongPaymentException.h>
#include <logics/exceptions/CreditRepayOverheadException.h>
#include <logics/exceptions/NoSuchDepositException.h>

#include <utility>
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
	return _customer->creditLimit() <= amount * interest;
}

uint CustomerDataManager::takeCredit(Money debt, QString name, double interest) {
	// todo: take next free id from db and save data to db
	_customer->addCredit(new Credit(-1, std::move(name), debt, interest, debt * interest / 12));
	return -1;
}

bool CustomerDataManager::repayCredit(Money amount, uint creditId) {
	Credit* selected = nullptr;
	for (auto iter : _customer->credits())
		if (iter->_id == creditId) {
			selected = iter;
			break;
		}
	if (selected == nullptr) throw NoSuchCreditException(_customer->_taxNumber, creditId);
	if (selected->payment() != amount) throw CreditRepayOverheadException(selected->payment(), amount);

	return selected->debt() == 0;
}

bool CustomerDataManager::canOpenDeposit(Money potentialBalance) const {
	Money totalDepositBalance = 0;
	for (auto iter : _customer->deposits())
		totalDepositBalance += iter->sum();
	return (totalDepositBalance + potentialBalance) < Deposit::maxDepoSum;
}

uint CustomerDataManager::openDeposit(Money initialBalance, QString name, double interest, uint months) {
	// todo: same stuff with DB as with credit
	Deposit* depo = new Deposit(-1, std::move(name), QDate(), QDate().addMonths(months), initialBalance, interest);
	_customer->addDeposit(depo);
	return -1;
}

void CustomerDataManager::replenishDeposit(Money amount, uint depoId) {
	Deposit* deposit = nullptr;
	for (auto iter : _customer->deposits())
		if (iter->_id == depoId) {
			deposit = iter;
			break;
		}
	if (deposit == nullptr) throw NoSuchDepositException(_customer->_taxNumber, depoId);
	deposit->replenish(amount);
}

void CustomerDataManager::closeDeposit(uint depoId) {
	Deposit* deposit = nullptr;
	for (auto iter : _customer->deposits())
		if (iter->_id == depoId) {
			deposit = iter;
			break;
		}
	if (deposit == nullptr) throw NoSuchDepositException(_customer->_taxNumber, depoId);
	_bankCard->replenish(deposit->sum());
	_customer->removeDeposit(depoId);
}

QString CustomerDataManager::getPin() const {
	return _bankCard->pin();
}

QString CustomerDataManager::changePin() {
	return _bankCard->regeneratePin();
}
