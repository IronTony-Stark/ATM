//
// Created by Andrew on 02-Oct-20.
//

#ifndef ATM_CUSTOMERDATAMANAGER_H
#define ATM_CUSTOMERDATAMANAGER_H


#include <logics/Customer.h>

class CustomerDataManager {
public:
	const Customer& customer() const;

	Card& card() const;

	Customer* const getCustomerByTaxNumber(const QString&) const;

	Customer* const getCustomerByCardNumber(const QString&) const;

	static Customer* getCustomerByDepositId(uint);

	Money balance() const;

	void replenish(Money amount);

	void withdraw(Money amount);

	bool canAffordCredit(Money amount, uint period, double interest) const;
    static Money getCreditValueWithPercents(const Money& amount, uint period, double interest) ;

	Money takeCredit(Money debt, QString name, double interest, uint period);

	bool repayCredit(Money amount, uint creditId);

	QList<RegularPayment*> regularPayments() const;

	bool canOpenDeposit(Money potentialBalance) const;

	Money openDeposit(Money initialBalance, QString name, double interest, uint months, QDate startDate,
                      QDate endDate);

	void replenishDeposit(Money amount, uint depoId);

	void cancelDeposit(uint depoId);

private:
	friend class Registrator;

	friend class Authorizer;

	/*
	 * Authorizer&Registrator - friend who can set a Card and a Customer
	 * */
	Customer* _customer = nullptr;
	Card* _bankCard = nullptr;
};


#endif //ATM_CUSTOMERDATAMANAGER_H
