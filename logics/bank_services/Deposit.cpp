//
// Created by Andrew on 30-Sep-20.
//

#include "Deposit.h"

#include <utility>
#include "../utils/general.h"

const Money Deposit::maxDepoSum = 50'000'000;

Deposit::Deposit(QString ownerCard, QString name, Money sum, double interest, QDate endDate,
				 QDate startDate, uint id, Money initialBalance) : _ownerCard(std::move(ownerCard)),
																   _name(std::move(name)),
																   _sum(sum), _interest(interest),
																   _startDate(startDate), _endDate(endDate), _id(id),
																   _initBalance(initialBalance) {}

Deposit::Deposit(const Deposit& d) : _id(d._id), _name(d._name), _initBalance(d._initBalance), _sum(d.sum()),
									 _interest(d.interest()),
									 _startDate(d.startDate()), _endDate(d.endDate()) {}

uint Deposit::id() const {
	return _id;
}

void Deposit::replenish(Money amount) {
	_sum += amount;
}

Money Deposit::sum() const {
	return _sum;
}

double Deposit::interest() const {
	return _interest;
}

const QDate& Deposit::startDate() const {
	return _startDate;
}

const QDate& Deposit::endDate() const {
	return _endDate;
}

const QString& Deposit::name() const {
	return _name;
}

const QString& Deposit::ownerCard() const {
	return _ownerCard;
}

const Money& Deposit::initBalance() const {
	return _initBalance;
}

std::ostream& operator<<(std::ostream& os, const Deposit& deposit) {
	os << "_id: " << deposit.id() << " _name: " << deposit.name().toStdString() << " _init: " << deposit.initBalance()
	   << " _sum: " << deposit.sum() << " _interest: " << deposit.interest()
	   << " _startDate: " << deposit.startDate().toString().toStdString()
	   << " _endDate: " << deposit.endDate().toString().toStdString();
	return os;
}
