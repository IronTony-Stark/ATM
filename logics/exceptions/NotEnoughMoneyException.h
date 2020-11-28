//
// Created by Andrew on 30-Sep-20.
//

#ifndef ATM_NOTENOUGHMONEYEXCEPTION_H
#define ATM_NOTENOUGHMONEYEXCEPTION_H


#include <stdexcept>
#include <logics/utils/Money.h>

class NotEnoughMoneyException : public std::exception {
public:
	NotEnoughMoneyException(Money available, Money requested);

	[[nodiscard]] Money available() const;

	[[nodiscard]] Money requested() const;

	const char * what() const noexcept override;

private:
	Money _available;
	Money _requested;
	std::string _reason;
};

std::ostream& operator<<(std::ostream&, const NotEnoughMoneyException&);


#endif //ATM_NOTENOUGHMONEYEXCEPTION_H
