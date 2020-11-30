//
// Created by Andrew on 30-Sep-20.
//

#ifndef ATM_DEPOSIT_H
#define ATM_DEPOSIT_H


#include <QtCore/QDateTime>
#include <logics/utils/Money.h>
#include <ostream>

class Deposit {
public:
	static const Money maxDepoSum;

	Deposit(QString ownerCard, QString name, Money sum, double interest, QDate endDate,
			QDate startDate = QDate::currentDate(), uint id = -1, Money initialBalance = 0);

	Deposit(const Deposit&);

	uint id() const;

	const QString& ownerCard() const;

	void replenish(Money amount);

	Money sum() const;

	const Money& initBalance() const;

	const QString& name() const;

	double interest() const;

	const QDate& startDate() const;

	const QDate& endDate() const;

	Deposit& operator=(const Deposit&) = delete;

private:
	friend class DepositDAO;

	uint _id;
	const QString _ownerCard;
	QString _name;
	Money _initBalance;
	Money _sum;
	double _interest;
	const QDate _startDate;
	const QDate _endDate;
};

std::ostream& operator<<(std::ostream& os, const Deposit& deposit);

#endif //ATM_DEPOSIT_H
