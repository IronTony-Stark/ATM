//
// Created by Andrew on 30-Sep-20.
//

#include "NotEnoughMoneyException.h"

NotEnoughMoneyException::NotEnoughMoneyException(double available, double requested) :
		_available(available), _requested(requested) {
}

double NotEnoughMoneyException::available() const {
	return _available;
}

double NotEnoughMoneyException::requested() const {
	return _requested;
}