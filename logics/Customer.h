//
// Created by Andrew on 30-Sep-20.
//

#ifndef ATM_CUSTOMER_H
#define ATM_CUSTOMER_H

#include <logics/bank_services/Credit.h>
#include <logics/bank_services/Deposit.h>
#include <logics/utils/Money.h>
#include "logics/bank_services/Card.h"

class Customer {
public:
    const QString _taxNumber;
	const QString _phoneNumber;
//	const QString _passportCode;

	Customer(QString  name, QString  taxNum, QString  phoneNum, const Money revenue);

	[[nodiscard]] const QString& name() const;

	void setName(const QString&);

	[[nodiscard]] const Money& revenue() const;

	void setRevenue(const Money&);

	[[nodiscard]] const Money& creditLimit() const;

	[[nodiscard]] const QList<Card*>& cards() const;

	void addCard(Card*);

	void removeCard(uint);

	[[nodiscard]] const QList<Credit*>& credits() const;

	void addCredit(Credit*);

	void removeCredit(uint);

	[[nodiscard]] const QList<Deposit*>& deposits() const;

	void addDeposit(Deposit*);

	void removeDeposit(uint);

	~Customer();

private:
	QString _name;
	Money _revenue;
	Money _creditLimit;
	QList<Card*> _cards;
	QList<Credit*> _credits; // sum is under 45% of income
	QList<Deposit*> _deposits; // sum is up to 50 * 10^6 UAH

	template<typename Identifiable>
	uint findIndex(const QList<Identifiable>& list, uint id) {
		for (int i = 0; i < list.length(); i++) {
            if (list[i]->id() == id) {
				return i;
			}
		}
		return -1;
	}

	template<typename Pointer>
	static void releaseMemory(QList<Pointer>&);
};


#endif //ATM_CUSTOMER_H
