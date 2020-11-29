//
// Created by Andrew on 02-Oct-20.
//

#ifndef ATM_NOSUCHDEPOSITEXCEPTION_H
#define ATM_NOSUCHDEPOSITEXCEPTION_H


#include <utility>

#include "NoSuchCustomerPossessionException.h"

class NoSuchDepositException : public NoSuchCustomerPossessionException {
public:
	NoSuchDepositException(QString customerId, uint depositId) :
			NoSuchCustomerPossessionException(std::move(customerId), QString::number(depositId), "DEPOSIT") {};
	const char* what() const noexcept override {return NoSuchCustomerPossessionException::what();};

	~NoSuchDepositException() override = default;
};


#endif //ATM_NOSUCHDEPOSITEXCEPTION_H
