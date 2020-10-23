//
// Created by Andrew on 30-Sep-20.
//

#ifndef ATM_CREDIT_H
#define ATM_CREDIT_H


#include <QtCore/QDateTime>
#include <logics/utils/Money.h>

class Credit {
public:
	static double creditLimitOfIncome;

	const double _interest;

	const uint _id;

	Credit(uint id, QString name, Money creditBody, double interest, Money payment);

	Credit(const Credit&);

	[[nodiscard]] const QString& name() const;

	void setName(QString newName);

	void replenish(Money amount);

	[[nodiscard]] Money creditBody() const;

	[[nodiscard]] Money debt() const;

	[[nodiscard]] Money payment() const;

	[[nodiscard]] const QDate& dateTaken() const;

	Credit& operator=(const Credit&) = delete;

private:
	QString _name;
	Money _creditBody;
	Money _debt = 0;    //debt is bank's income, creditBody is money that customer borrowed
	Money _payment;
	QDate _dateTaken;
};


#endif //ATM_CREDIT_H
