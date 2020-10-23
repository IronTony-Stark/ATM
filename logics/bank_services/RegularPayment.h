//
// Created by Andrew on 23-Oct-20.
//

#ifndef ATM_REGULARPAYMENT_H
#define ATM_REGULARPAYMENT_H


#include <QtCore/QString>
#include <logics/utils/Money.h>

typedef unsigned long int uli;

class RegularPayment {
public:
	RegularPayment(QString name, Money amount, uli sender, uli receiver, uint dayOfMonth);

	const QString& name() const;

//	void setName(QString newName);

	const Money& amount() const;

//	void setName(QString newName);

	uli receiver() const;

	uli sender() const;

	uint dayOfMonth() const;

private:
	QString _name;
	Money _amount;
	uli _sender;
	uli _receiver;
	uint _dayOfMonth;
};


#endif //ATM_REGULARPAYMENT_H
