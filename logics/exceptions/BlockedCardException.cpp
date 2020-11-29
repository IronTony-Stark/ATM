//
// Created by Andrew on 29-Nov-20.
//

#include "BlockedCardException.h"

const char* BlockedCardException::what() const noexcept {
	QString qs = QString("card with id %1 is blocked");
	std::string resStr = qs.arg(cardId()).toStdString();
	char* res = new char[resStr.length() + 1];
	strcpy(res, resStr.c_str());
	return res;
}