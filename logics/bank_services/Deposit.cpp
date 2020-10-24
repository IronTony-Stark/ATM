//
// Created by Andrew on 30-Sep-20.
//

#include "Deposit.h"

#include <utility>
#include "../utils/general.h"

const Money Deposit::maxDepoSum = 50'000'000;

Deposit::Deposit(QString name, QDate startDate, QDate endDate, Money initialBalance, double interest) :
		_name(std::move(name)), _startDate(), _endDate(endDate), _sum(initialBalance), _interest(interest) {}

Deposit::Deposit(const Deposit& d) : _id(d._id), _earnings(d.earnings()), _sum(d.sum()) {}

uint Deposit::id() const {
	return _id;
}

void Deposit::replenish(Money amount) {
	_sum += amount;
}

Money Deposit::sum() const {
	return _sum;
}

Money Deposit::earnings() const {
	return _earnings;
}

double Deposit::interest() const {
	return _interest;
}

const QDate& Deposit::startDate() const {
	return _startDate;
}

const QDate& Deposit::endDate() const {
	return _endDate;
}

QDate Deposit::timeRemaining() const {
	return subtractDates(_endDate, QDate::currentDate());
}

const QString& Deposit::name() const {
	return _name;
}

void Deposit::setName(QString newName) {
	if (newName.isEmpty()) throw std::invalid_argument("new name is empty");
	_name = std::move(newName);
}

void Deposit::cancel() {
    // TODO implement
}

