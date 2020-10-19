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

	Credit(uint id, Money creditBody, double interest, Money payment);

	Credit(const Credit&);

	void replenish(Money amount);

	[[nodiscard]] Money creditBody() const;

	[[nodiscard]] Money debt() const;

	Money payment() const;

	Credit& operator=(const Credit&) = delete;

private:
	Money _creditBody;
	Money _debt = 0;    //debt is bank's income, creditBody is money that customer borrowed
	QDateTime _dateTaken;
	Money _payment;
};


#endif //ATM_CREDIT_H
