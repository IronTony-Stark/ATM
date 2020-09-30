//
// Created by Andrew on 30-Sep-20.
//

#ifndef ATM_DEPOSIT_H
#define ATM_DEPOSIT_H


#include <QtCore/QDateTime>

class Deposit {
public:
	const uint _id;
	const double _interest;
	const QDate _endDate;

	Deposit(uint id, double interest, QDate startDate, QDate period, double initialBalance = 0);

	void replenish(double amount);

	[[nodiscard]] double sum() const;

	[[nodiscard]] double earnings() const;

	[[nodiscard]] QDate timeRemaining() const;

private:
	double _sum;
	double _earnings = 0;
	QDate _startDate;
};


#endif //ATM_DEPOSIT_H
