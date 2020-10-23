//
// Created by Andrew on 02-Oct-20.
//

#include "Money.h"
#include "general.h"


Money::Money(uint m) : _intPart(m), _decPart(0) {
}

Money::Money(int m) : _intPart(m), _decPart(0) {
}

Money::Money(double m) : _intPart(static_cast<int>(m)), _decPart(static_cast<int>(sgn(m) * abs(m * 100 - m))) {
}

Money::Money(int intPart, int decPart) : _intPart(intPart), _decPart(decPart) {
}

int Money::sign() const {
	assert(sgn(_intPart) != -sgn(_decPart));
	return sgn(_intPart) == 0 ? sgn(_decPart) : sgn(_intPart);
}

Money::operator double() const {
	return static_cast<double>(_intPart) + static_cast<double>(_decPart);
}

Money& Money::operator+=(const Money& m) {
	if (m.sign() < 0) return *this -= m.flipSign();
	_decPart += m._decPart;
	if (_decPart >= 100) {
		_decPart -= 100;
		_intPart++;
	}
	_intPart += m._intPart;
	return *this;
}

Money& Money::operator-=(const Money& m) {
	if (m.sign() < 0) return *this += m.flipSign();
	_decPart -= m._decPart;
	if (_decPart < 0) {
		_decPart += 100;
		_intPart--;
	}
	_intPart -= m._intPart;
	return *this;
}

Money& Money::operator*=(double koef) {
	_intPart *= koef;
	_decPart *= koef;
	return *this;
}

Money& Money::operator/=(double koef) {
	_intPart /= koef;
	_decPart /= koef;
	return *this;
}

Money Money::flipSign() const {
	return Money(-_intPart, -_decPart);
}

Money operator+(const Money& m1, const Money& m2) {
	Money res(m1);
	return res += m2;
}

Money operator-(const Money& m1, const Money& m2) {
	Money res(m1);
	return res -= m2;
}

Money operator*(const Money& m, double koef) {
	Money res(m);
	return res *= koef;
}

Money operator/(const Money& m, double koef) {
	return Money(m) /= koef;
}

bool operator==(const Money& m1, const Money& m2) {
	return m1._intPart == m2._intPart && m1._decPart == m2._decPart;
}

bool operator!=(const Money& m1, const Money& m2) {
	return !(m1 == m2);
}

bool operator>(const Money& m1, const Money& m2) {
	if (m1._intPart > m2._intPart) return true;
	return m1._intPart == m2._intPart && m1._decPart > m2._decPart;
}

bool operator>=(const Money& m1, const Money& m2) {
	return m1 > m2 || m1 == m2;
}

bool operator<(const Money& m1, const Money& m2) {
	return !(m1 >= m2);
}

bool operator<=(const Money& m1, const Money& m2) {
	return !(m1 > m2);
}

std::ostream& operator<<(std::ostream& os, const Money& m) {
	os << m._intPart << "." << m._decPart;
	return os;
}