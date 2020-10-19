//
// Created by Andrew on 30-Sep-20.
//

#include "Credit.h"

double Credit::creditLimitOfIncome = 0.45;

Credit::Credit(uint id, Money creditBody, double interest, Money payment) :
		_id(id), _creditBody(creditBody), _interest(interest), _payment(payment), _dateTaken(QDateTime()) {
	// todo: check if a person can afford a new credit
}

Credit::Credit(const Credit& c) : _id(c._id), _creditBody(c._creditBody), _interest(c._interest), _payment(c._payment),
								  _debt(c._interest) {

}

void Credit::replenish(Money amount) {
	if (_creditBody >= amount) {
		_creditBody -= amount;
	} else {
		amount -= _creditBody;
		_creditBody = 0;
		_debt -= amount;
	}
}

Money Credit::creditBody() const {
	return _creditBody;
}

Money Credit::debt() const {
	return _debt;
}

Money Credit::payment() const {
	return _payment;
}


