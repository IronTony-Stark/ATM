//
// Created by Andrew on 30-Sep-20.
//

#ifndef ATM_CUSTOMER_H
#define ATM_CUSTOMER_H


#include <logics/bank_services/Credit.h>
#include <logics/bank_services/Deposit.h>

class Customer {
public:
	const uint taxNumber;
	QString name;
	QString phoneNum;
	const QString passportCode;
	unsigned int revenue;
	QList<Credit> credits; // payments are up to 45% of monthly income
	QList<Deposit> deposits; // sum is up to 50 * 10^6 UAH
private:
	uint creditLimit;
};


#endif //ATM_CUSTOMER_H
