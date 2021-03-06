//
// Created by Andrew on 23-Oct-20.
//

#ifndef ATM_REGULARPAYMENT_H
#define ATM_REGULARPAYMENT_H


#include <QtCore/QString>
#include <logics/utils/Money.h>

class RegularPayment {
public:
	RegularPayment(QString name, Money amount, QString sender, QString receiver, uint dayOfMonth, uint id = -1);

	uint id() const;

	const QString& name() const;

	const Money& amount() const;

	QString receiver() const;

	QString sender() const;

	uint dayOfMonth() const;

	void setDayOfMonth(uint);

private:
	friend class PaymentDAO;

	uint _id;
	QString _name;
	Money _amount;
	QString _sender;
	QString _receiver;
	uint _dayOfMonth;
};


#endif //ATM_REGULARPAYMENT_H
