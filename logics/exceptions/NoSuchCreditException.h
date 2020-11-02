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

class NoSuchCreditException : NoSuchCustomerPossessionException {
public:
	NoSuchCreditException(QString customerId, uint creditId) :
			NoSuchCustomerPossessionException(std::move(customerId), QString::number(creditId), "CREDIT") {};
};

//std::ostream& operator<<(std::ostream&, const NoSuchCreditException&);

#endif //ATM_NOSUCHCREDITEXCEPTION_H
