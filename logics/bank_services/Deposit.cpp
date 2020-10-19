//
// Created by Andrew on 30-Sep-20.
//

#include "Deposit.h"
#include "../utils/general.h"

Deposit::Deposit(uint id, double interest, QDate startDate, QDate period, double initialBalance) :
		_id(id), _interest(interest), _startDate(), _endDate(addDates(startDate, period)), _sum(initialBalance) {}

Deposit::Deposit(const Deposit& d) : _id(d._id), _interest(d._interest), _earnings(d.earnings()), _sum(d.sum()) {}

void Deposit::replenish(double amount) {
	_sum += amount;
}

double Deposit::sum() const {
	return _sum;
}

double Deposit::earnings() const {
	return _earnings;
}

QDate Deposit::timeRemaining() const {
	return subtractDates(_endDate, QDate::currentDate());
}

