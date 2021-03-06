//
// Created by Andrew on 02-Oct-20.
//

#ifndef ATM_NOSUCHCARDEXCEPTION_H
#define ATM_NOSUCHCARDEXCEPTION_H


#include <QtGui/qopengl.h>
#include <ostream>
#include <utility>
#include "NoSuchCustomerPossessionException.h"

class NoSuchCardException : public NoSuchCustomerPossessionException {
public:
	NoSuchCardException(QString customerId, const QString& cardId) :
			NoSuchCustomerPossessionException(std::move(customerId), cardId, "CARD") {}

	const char* what() const noexcept override { return NoSuchCustomerPossessionException::what();};

	~NoSuchCardException() override = default;
};

#endif //ATM_NOSUCHCARDEXCEPTION_H
