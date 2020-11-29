//
// Created by Andrew on 02-Oct-20.
//

#ifndef ATM_NOSUCHCREDITEXCEPTION_H
#define ATM_NOSUCHCREDITEXCEPTION_H


#include <exception>
#include <QtGui/qopengl.h>
#include <ostream>
#include <utility>
#include "NoSuchCustomerPossessionException.h"

class NoSuchCreditException : public NoSuchCustomerPossessionException {
public:
	NoSuchCreditException(QString customerId, uint creditId) :
			NoSuchCustomerPossessionException(std::move(customerId), QString::number(creditId), "CREDIT") {};

	const char* what() const noexcept override { return NoSuchCustomerPossessionException::what();};
};

#endif //ATM_NOSUCHCREDITEXCEPTION_H
