//
// Created by Andrew on 02-Oct-20.
//

#ifndef ATM_NOSUCHDEPOSITEXCEPTION_H
#define ATM_NOSUCHDEPOSITEXCEPTION_H


#include "NoSuchCustomerPossessionException.h"

class NoSuchDepositException : NoSuchCustomerPossessionException {
public:
	NoSuchDepositException(uint customerId, uint depositId) :
			NoSuchCustomerPossessionException(customerId, depositId, "DEPOSIT") {};
};


#endif //ATM_NOSUCHDEPOSITEXCEPTION_H
