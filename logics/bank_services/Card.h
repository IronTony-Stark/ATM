//
// Created by Andrew on 30-Sep-20.
//

#ifndef ATM_CARD_H
#define ATM_CARD_H


#include <logics/bank_fees/ABankFee.h>
#include <QtCore/QString>
#include <logics/utils/Money.h>

class Customer;

typedef unsigned long int uli;

class Card {
public:
	const ABankFee& _bankFee;
	const ABankFee::FeeType _cardType;

	explicit Card(ABankFee::FeeType, Customer&, QString& _pin, QString name, Money balance = (uint) 0);

	Card(const Card&);

	uli id() const;

	[[nodiscard]] Money balance() const;

	/**
	 *if balance is sufficient then subtracts else throws exception
	 * @return <remainder, actual_withdrawal_sum>
	 */
	std::pair<Money, Money> withdraw(Money);

	Money replenish(Money);

	Money transfer(const QString& recipient, Money amount);

	const QString& name() const;

	void setName(QString newName);

	const QString& pin() const;

	const QString& number() const;

	const ABankFee::FeeType cardType() const;

	const QString& regeneratePin();

	Card& operator=(const Card&) = delete;

private:

	uli _id;
	QString _name;
	// TODO change to ushort
	QString _pin;
	Money _balance;
	Customer& _customer;
};


#endif //ATM_CARD_H
