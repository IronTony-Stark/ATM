//
// Created by Andrew on 30-Sep-20.
//

#include "Credit.h"

Credit::Credit(uint id, double creditBody, double interest, QDateTime& date) :
		_id(id), _creditBody(creditBody), _interest(interest), _dateTaken(date) {
	// todo: check if person can afford a new credit
}

void Credit::replenish(double amount) {
	if (_creditBody >= amount) {
		_creditBody -= amount;
	} else {
		amount -= _creditBody;
		_creditBody = 0;
		_debt -= amount;
	}
}

double Credit::creditBody() const {
	return _creditBody;
}

double Credit::debt() const {
	return _debt;
}
