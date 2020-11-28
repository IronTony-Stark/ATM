//
// Created by Andrew on 30-Sep-20.
//

#include "NotEnoughMoneyException.h"
#include <ostream>
#include <sstream>

NotEnoughMoneyException::NotEnoughMoneyException(Money available, Money requested) :
		_available(available), _requested(requested) {
    std::ostringstream strs;
    strs << "Available amount of money: ";
    strs << (double)available;
    strs << ", requested: ";
    strs << (double)requested;
    _reason = strs.str();
}

Money NotEnoughMoneyException::available() const {
	return _available;
}

Money NotEnoughMoneyException::requested() const {
	return _requested;
}

const char* NotEnoughMoneyException::what() const noexcept {
    return _reason.c_str();
}

std::ostream& operator<<(std::ostream& os, const NotEnoughMoneyException& e) {
	os << "available amount of money: " << e.available() << ", requested: " << e.requested();
	return os;
}
