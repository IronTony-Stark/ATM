//
// Created by Andrew on 19-Oct-20.
//

#include "CreditRepayOverheadException.h"

CreditRepayOverheadException::CreditRepayOverheadException(Money maximum, Money actual) :
		_maximum(maximum), _actual(actual) {

}

Money CreditRepayOverheadException::maximum() const {
	return _maximum;
}

Money CreditRepayOverheadException::actual() const {
	return _actual;
}


