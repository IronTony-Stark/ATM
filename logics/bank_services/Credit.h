//
// Created by Andrew on 30-Sep-20.
//

#ifndef ATM_CREDIT_H
#define ATM_CREDIT_H


#include <QtCore/QDateTime>

class Credit {
public:
	const uint _id;

	const double _interest;

	Credit(uint id, double creditBody, double interest, QDateTime&);

	void replenish(double amount);

	[[nodiscard]] double creditBody() const;

	[[nodiscard]] double debt() const;

private:
	double _creditBody;
	double _debt = 0;
	QDateTime _dateTaken;
};


#endif //ATM_CREDIT_H
