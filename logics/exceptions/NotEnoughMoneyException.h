//
// Created by Andrew on 30-Sep-20.
//

#ifndef ATM_NOTENOUGHMONEYEXCEPTION_H
#define ATM_NOTENOUGHMONEYEXCEPTION_H


#include <stdexcept>

class NotEnoughMoneyException : std::exception {
public:
	NotEnoughMoneyException(double available, double requested);

	[[nodiscard]] double available() const;

	[[nodiscard]] double requested() const;

private:

	double _available;
	double _requested;
};

std::ostream& operator<<(std::ostream&, const NotEnoughMoneyException&);


#endif //ATM_NOTENOUGHMONEYEXCEPTION_H
