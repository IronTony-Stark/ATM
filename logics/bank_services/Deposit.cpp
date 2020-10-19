//
// Created by Andrew on 30-Sep-20.
//

#include "Deposit.h"
#include "../utils/general.h"

const Money Deposit::maxDepoSum = 50'000'000;

Deposit::Deposit(uint id, QDate startDate, QDate endDate, Money initialBalance, double interest) :
		_id(id), _startDate(), _endDate(endDate), _sum(initialBalance), _interest(interest) {}

Deposit::Deposit(const Deposit& d) : _id(d._id), _earnings(d.earnings()), _sum(d.sum()) {}

void Deposit::replenish(Money amount) {
	_sum += amount;
}

Money Deposit::sum() const {
	return _sum;
}

Money Deposit::earnings() const {
	return _earnings;
}

QDate Deposit::timeRemaining() const {
	return subtractDates(_endDate, QDate::currentDate());
}

