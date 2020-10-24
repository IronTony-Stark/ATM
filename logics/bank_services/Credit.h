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

	Credit(QString name, Money creditBody, double interest, Money payment);

	Credit(const Credit&);

	uint id() const;

	[[nodiscard]] const QString& name() const;

	void setName(QString newName);

	Money bankIncome() const;

	void replenish(Money amount);

	[[nodiscard]] Money creditBody() const;

	[[nodiscard]] Money debt() const;

	[[nodiscard]] Money payment() const;

	[[nodiscard]] const QDate& dateTaken() const;

	Credit& operator=(const Credit&) = delete;

private:
	friend class CreditDAO;

	uint _id;
	QString _name;
	Money _creditBody;
	Money _bankIncome = 0;
	Money _payment;
	QDate _dateTaken;
};


#endif //ATM_CREDIT_H
