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

const char* NoSuchCustomerPossessionException::what() const noexcept {
	QString qs = QString("no customer with id %1 possesses %2 with id %3");
	std::string resStr = qs.arg(customerId()).arg(possessionType()).arg(possessionId()).toStdString();
	char* res = new char[resStr.length() + 1];
	strcpy(res, resStr.c_str());
	return res;
}

std::ostream& operator<<(std::ostream& os, const NoSuchCustomerPossessionException& e) {
	os << "User with tax code: " << e.customerId().toStdString()
	   << " does not possess a " << e.possessionType().toStdString()
	   << " with id: " << e.possessionId().toStdString();
	return os;
}

