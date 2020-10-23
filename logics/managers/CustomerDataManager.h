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
    Customer* const getCustomerByCardNumber(const QString& cardNumber) const;

	Money balance() const;

	void replenish(Money amount);

	void withdraw(Money amount);

	bool canAffordCredit(Money amount, double interest) const;

	uint takeCredit(Money debt, QString name, double interest);

	bool repayCredit(Money amount, uint creditId);

	bool canOpenDeposit(Money potentialBalance) const;

	uint openDeposit(Money initialBalance, QString name, double interest, uint months);

	void replenishDeposit(Money amount, uint depoId);

	void closeDeposit(uint depoId);

	QString getPin() const;

	QString changePin();

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
