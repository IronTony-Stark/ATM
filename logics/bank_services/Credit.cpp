//
// Created by Andrew on 30-Sep-20.
//

#include "Credit.h"

#include <utility>

double Credit::creditLimitOfIncome = 0.45;

Credit::Credit(QString name, Money creditBody, double interest, Money payment) :
		_name(std::move(name)), _creditBody(creditBody), _interest(interest), _payment(payment),
		_dateTaken(QDate()) {
	// todo: check if a person can afford a new credit
}

Credit::Credit(const Credit& c) : _id(c._id), _creditBody(c._creditBody), _interest(c._interest), _payment(c._payment),
								  _bankIncome(c._interest) {

}

uint Credit::id() const {
	return _id;
}

const QString& Credit::name() const {
	return _name;
}

void Credit::setName(QString newName) {
	if (newName.isEmpty()) throw std::invalid_argument("new name is empty");
	_name = std::move(newName);
}

Money Credit::bankIncome() const {
	return _bankIncome;
}

void Credit::replenish(Money amount) {
	if (_creditBody >= amount) {
		_creditBody -= amount;
	} else {
		amount -= _creditBody;
		_creditBody = 0;
		_bankIncome -= amount;
	}
}

Money Credit::creditBody() const {
	return _creditBody;
}

Money Credit::debt() const {
	return _bankIncome;
}

Money Credit::payment() const {
	return _payment;
}

const QDate& Credit::dateTaken() const {
	return _dateTaken;
}


