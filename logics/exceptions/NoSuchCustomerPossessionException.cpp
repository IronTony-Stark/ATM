//
// Created by Andrew on 02-Oct-20.
//

#include "NoSuchCustomerPossessionException.h"

#include <utility>

NoSuchCustomerPossessionException::NoSuchCustomerPossessionException(QString customerId,
																	 QString possessionId,
																	 QString possName) :
		_customerId(std::move(customerId)), _possessionId(std::move(possessionId)), _possName(std::move(possName)) {
}

const QString& NoSuchCustomerPossessionException::possessionType() const {
	return _possName;
}

const QString& NoSuchCustomerPossessionException::customerId() const {
	return _customerId;
}

const QString& NoSuchCustomerPossessionException::possessionId() const {
	return _possessionId;
}

std::ostream& operator<<(std::ostream& os, const NoSuchCustomerPossessionException& e) {
	os << "User with tax code: " << e.customerId().toStdString()
	   << " does not possess a " << e.possessionType().toStdString()
	   << " with id: " << e.possessionId().toStdString();
	return os;
}

