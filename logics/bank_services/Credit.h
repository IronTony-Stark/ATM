//
// Created by Andrew on 30-Sep-20.
//

#ifndef ATM_CREDIT_H
#define ATM_CREDIT_H


#include <QtCore/QDateTime>
#include <logics/utils/Money.h>
#include <ostream>

class Credit {
public:
	static double creditLimitOfIncome;

	Credit(QString name, Money creditBody, double interest, Money payment);

	Credit(uint id, QString name, Money creditBody, double interest, Money payment, Money bankIncome, QDate _dateTaken);

	Credit(const Credit&);

	uint id() const;

	double interest() const;

	[[nodiscard]] const QString& name() const;

	void setName(QString newName);

	Money bankIncome() const;

	void replenish(Money amount);

	[[nodiscard]] Money creditBody() const;

	[[nodiscard]] Money debt() const;

	[[nodiscard]] Money payment() const;

	[[nodiscard]] const QDate& dateTaken() const;

	Credit& operator=(const Credit&) = delete;

	// friend std::ostream& operator<<(std::ostream& os, const Credit& credit);

private:
	friend class CreditDAO;

	uint _id;
	QString _name;
	Money _creditBody;
	double _interest;
	Money _payment;
	Money _bankIncome = 0;
	QDate _dateTaken;
};

std::ostream& operator<<(std::ostream& os, const Credit& credit);

#endif //ATM_CREDIT_H
