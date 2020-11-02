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
	const ABankFee& _bankFee;
	const ABankFee::CardType _cardType;

	explicit Card(QString id, ABankFee::CardType, QString _pin, Money balance = (uint) 0);

	Card(const Card&);

	~Card() = default;

	QString id() const;

	[[nodiscard]] Money balance() const;

	/**
	 *if balance is sufficient then subtracts else throws exception
	 * @return <remainder, actual_withdrawal_sum>
	 */
	std::pair<Money, Money> withdraw(Money);

	void withdrawFree(Money);

	Money replenish(Money);

	void replenishFree(Money);

	std::pair<Money, Money> transfer(const QString& recipient, Money amount);

	const QString& pin() const;

	const QString& number() const;

	const ABankFee::CardType cardType() const;

	const QString& regeneratePin();

	Card& operator=(const Card&) = delete;

private:
	QString _id;
	QString _pin;
	Money _balance;
};


#endif //ATM_CARD_H
