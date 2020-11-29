//
// Created by Andrew on 19-Oct-20.
//

#include <QtCore/QString>
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

const char* CreditRepayOverheadException::what() const noexcept {
	QString qs = QString("max allowed repay sum is %1, but %2 is passed");
	std::string resStr = qs.arg((double)maximum()).arg((double)actual()).toStdString();
	char* res = new char[resStr.length() + 1];
	strcpy(res, resStr.c_str());
	return res;
}


