//
// Created by Andrew on 02-Oct-20.
//

#ifndef ATM_NOSUCHCREDITEXCEPTION_H
#define ATM_NOSUCHCREDITEXCEPTION_H


#include <exception>
#include <QtGui/qopengl.h>
#include <ostream>
#include "NoSuchCustomerPossessionException.h"

class NoSuchCreditException : NoSuchCustomerPossessionException {
public:
	NoSuchCreditException(uint customerId, uint creditId) :
			NoSuchCustomerPossessionException(customerId, creditId, "CREDIT") {};
};

//std::ostream& operator<<(std::ostream&, const NoSuchCreditException&);

#endif //ATM_NOSUCHCREDITEXCEPTION_H
