//
// Created by Andrew on 30-Sep-20.
//

/*
 * yse, there is code duplication, go make difference
 * */
#include "Customer.h"
#include <utility>
#include <logics/exceptions/NoSuchCardException.h>
#include <logics/exceptions/NoSuchCreditException.h>
#include <logics/exceptions/NoSuchDepositException.h>

Customer::Customer(const QString& name, uint taxNum, QString passportCode, Money revenue) :
		_taxNumber(taxNum), _passportCode(std::move(passportCode)), _revenue(revenue),
		_creditLimit(revenue * Credit::creditLimitOfIncome) {

}

void Customer::setName(const QString& newName) {
	_name = newName;
}

const QString& Customer::name() const {
	return _name;
}

const Money& Customer::revenue() const {
	return _revenue;
}

void Customer::setRevenue(const Money& m) {
	_revenue = m;
	_creditLimit = _revenue * Credit::creditLimitOfIncome;
}

const Money& Customer::creditLimit() const {
	return _creditLimit;
}

const QList<Card*>& Customer::cards() const {
	return _cards;
}

const QList<Credit*>& Customer::credits() const {
	return _credits;
}

const QList<Deposit*>& Customer::deposits() const {
	return _deposits;
}

void Customer::addCard(Card* c) {
	_cards.append(c);
	// todo: dao
}

void Customer::removeCard(uint id) {
	int index = findIndex(_cards, id);
	if (index == -1) throw NoSuchCardException(_taxNumber, id);
	_cards.removeAt(index);
	//todo: dao
}

void Customer::addCredit(Credit* c) {
	_credits.append(c);
	//todo: dao
}

void Customer::removeCredit(uint id) {
	int index = findIndex(_credits, id);
	if (index == -1) throw NoSuchCreditException(_taxNumber, id);
	_credits.removeAt(index);
	//todo: dao
}

void Customer::addDeposit(Deposit* d) {
	_deposits.append(d);
	// todo: dao
}

void Customer::removeDeposit(uint id) {
	int index = findIndex(_deposits, id);
	if (index == -1) throw NoSuchDepositException(_taxNumber, id);
	_deposits.removeAt(index);
	//todo: dao
}


Customer::~Customer() {
	releaseMemory(_cards);
	releaseMemory(_credits);
	releaseMemory(_deposits);

}

template<typename Pointer>
void Customer::releaseMemory(QList<Pointer>& list) {
	for (uint i = 0; i < list.length(); i++) {
		delete list[i];
		list[i] = nullptr;
	}
}

