//
// Created by Andrew on 30-Sep-20.
//

#ifndef ATM_DEPOSIT_H
#define ATM_DEPOSIT_H


#include <QtCore/QDateTime>
#include <logics/utils/Money.h>

class Deposit {
public:
	static const Money maxDepoSum;

	const uint _id;

	Deposit(uint id, QString name, QDate startDate, QDate endDate, Money initialBalance, double interest);

	Deposit(const Deposit&);

	void replenish(Money amount);

	[[nodiscard]] Money sum() const;

	[[nodiscard]] Money earnings() const;

	[[nodiscard]] const QString& name() const;

	void setName(QString newName);

	[[nodiscard]] double interest() const;

	[[nodiscard]] const QDate& startDate() const;

	[[nodiscard]] const QDate& endDate() const;

	[[nodiscard]] QDate timeRemaining() const;

	Deposit& operator=(const Deposit&) = delete;

private:
	QString _name;
	double _interest;
	Money _sum;
	Money _earnings = 0;
	const QDate _startDate;
	const QDate _endDate;
};


#endif //ATM_DEPOSIT_H
