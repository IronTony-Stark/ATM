//
// Created by Andrew on 30-Sep-20.
//

#include "Deposit.h"
#include "../utils/dates.h"

Deposit::Deposit(uint id, double interest, QDate startDate, QDate period, double initialBalance) :
		_id(id), _interest(interest), _startDate(), _endDate(addDates(startDate, period)), _sum(initialBalance) {}

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

