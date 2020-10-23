//
// Created by Andrew on 23-Oct-20.
//

#include "RegularPayment.h"

#include <utility>

RegularPayment::RegularPayment(QString name, Money amount, uli sender, uli receiver, uint dayOfMonth) :
		_name(std::move(name)), _amount(amount), _sender(sender), _receiver(receiver), _dayOfMonth(dayOfMonth) {
	if (dayOfMonth > 28) throw std::invalid_argument("day of payment > 28, February causes troubles");
}

const QString& RegularPayment::name() const {
	return _name;
}

const Money& RegularPayment::amount() const {
	return _amount;
}

uli RegularPayment::receiver() const {
	return _receiver;
}

uli RegularPayment::sender() const {
	return _sender;
}

uint RegularPayment::dayOfMonth() const {
	return _dayOfMonth;
}
