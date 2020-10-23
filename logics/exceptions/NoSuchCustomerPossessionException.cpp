//
// Created by Andrew on 02-Oct-20.
//

#include "NoSuchCustomerPossessionException.h"

#include <utility>

NoSuchCustomerPossessionException::NoSuchCustomerPossessionException(QString customerId,
																	 uint possessionId,
																	 QString possName) :
		_customerId(customerId), _possessionId(possessionId), _possName(std::move(possName)) {
}

const QString& NoSuchCustomerPossessionException::possessionType() const {
	return _possName;
}

QString NoSuchCustomerPossessionException::customerId() const {
	return _customerId;
}

uint NoSuchCustomerPossessionException::possessionId() const {
	return _possessionId;
}

std::ostream& operator<<(std::ostream& os, const NoSuchCustomerPossessionException& e) {
	os << "User with tax code: " << e.customerId().toStdString()
	   << " does not possess a " << e.possessionType().toStdString()
	   << " with id: " << e.possessionId();
	return os;
}

