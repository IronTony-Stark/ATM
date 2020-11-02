//
// Created by Andrew on 02-Oct-20.
//

#ifndef ATM_NOSUCHCARDEXCEPTION_H
#define ATM_NOSUCHCARDEXCEPTION_H


#include <QtGui/qopengl.h>
#include <ostream>
#include <utility>
#include "NoSuchCustomerPossessionException.h"

class NoSuchCardException : NoSuchCustomerPossessionException {
public:
	NoSuchCardException(QString customerId, const QString& cardId) :
			NoSuchCustomerPossessionException(std::move(customerId), cardId, "CARD") {}
};

//std::ostream& operator<<(std::ostream&, const NoSuchCardException&);

#endif //ATM_NOSUCHCARDEXCEPTION_H
