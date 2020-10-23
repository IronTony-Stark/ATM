//
// Created by Andrew on 30-Sep-20.
//

#ifndef ATM_CARD_H
#define ATM_CARD_H


#include <logics/bank_fees/ABankFee.h>
#include <QtCore/QString>
#include <logics/utils/Money.h>

class Customer;

class Card {
public:
	const unsigned long int _id;
	const ABankFee& _bankFee;

	explicit Card(unsigned long int id, ABankFee::FeeType, Customer&, QString& _pin, QString name, Money balance = 0);

	Card(const Card&);

	[[nodiscard]] Money balance() const;

	/**
	 *if balance is sufficient then subtracts else throws exception
	 * @return <remainder, actual_withdrawal_sum>
	 */
	std::pair<Money, Money> withdraw(Money);

	Money replenish(Money);

	Money transfer(unsigned long int recipient, Money amount);

	const QString& name() const;

	void setName(QString newName);

	const QString pin() const;

	const QString regeneratePin();

	Card& operator=(const Card&) = delete;

private:
	QString _name;
	QString _pin;
	Money _balance;
	Customer& _customer;
};


#endif //ATM_CARD_H
