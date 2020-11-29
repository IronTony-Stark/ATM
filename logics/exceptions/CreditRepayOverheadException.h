//
// Created by Andrew on 19-Oct-20.
//

#ifndef ATM_CREDITREPAYOVERHEADEXCEPTION_H
#define ATM_CREDITREPAYOVERHEADEXCEPTION_H

#include <exception>
#include <logics/utils/Money.h>

class CreditRepayOverheadException : public std::exception {
public:
	CreditRepayOverheadException(Money maximum, Money actual);

	[[nodiscard]] Money maximum() const;

	[[nodiscard]] Money actual() const;

	const char * what() const noexcept override;

private:
	Money _maximum;
	Money _actual;
};


#endif //ATM_CREDITREPAYOVERHEADEXCEPTION_H
