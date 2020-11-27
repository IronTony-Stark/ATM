//
// Created by Andrew on 23-Oct-20.
//

#include "RegularPayment.h"

#include <utility>

RegularPayment::RegularPayment(QString name, Money amount, QString sender, QString receiver, uint dayOfMonth, uint id) :
		_id(id), _name(std::move(name)), _amount(amount), _sender(std::move(sender)), _receiver(std::move(receiver)),
		_dayOfMonth(dayOfMonth) {
	if (dayOfMonth > 31) throw std::invalid_argument("day cannot be grater then 31");
}

uint RegularPayment::id() const {
	return _id;
}

const QString& RegularPayment::name() const {
	return _name;
}

const Money& RegularPayment::amount() const {
	return _amount;
}

QString RegularPayment::receiver() const {
	return _receiver;
}

QString RegularPayment::sender() const {
	return _sender;
}

uint RegularPayment::dayOfMonth() const {
	return _dayOfMonth;
}

void RegularPayment::setDayOfMonth(uint dayOfMonth) {
    if (dayOfMonth > 31) throw std::invalid_argument("day cannot be grater then 31");
    _dayOfMonth = dayOfMonth;
}


