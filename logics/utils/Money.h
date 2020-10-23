//
// Created by Andrew on 02-Oct-20.
//

#ifndef ATM_MONEY_H
#define ATM_MONEY_H


#include <QtGui/qopengl.h>
#include <ostream>

struct Money {
	uint _intPart;
	uint _decPart;

	[[nodiscard]] int sign() const;

	Money(uint);

    Money(int);

	Money(double);

	Money(int, int);

	explicit operator double() const;

	Money& operator+=(const Money&);

	Money& operator-=(const Money&);

	Money& operator*=(double);

	Money& operator/=(double);

private:
	[[nodiscard]] Money flipSign() const;
};

Money operator+(const Money&, const Money&);

Money operator-(const Money&, const Money&);

Money operator*(const Money&, double);

Money operator/(const Money&, double);

bool operator==(const Money&, const Money&);

bool operator!=(const Money&, const Money&);

bool operator>(const Money&, const Money&);

bool operator>=(const Money&, const Money&);

bool operator<(const Money&, const Money&);

bool operator<=(const Money&, const Money&);

std::ostream& operator<<(std::ostream&, const Money&);

#endif //ATM_MONEY_H
