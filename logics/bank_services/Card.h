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

	bool canWithdraw(Money amount) const;

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

	bool isBlocked() const;

	void block();

	const ABankFee::CardType cardType() const;

	const QString& regeneratePin();

	Card& operator=(const Card&) = delete;

	bool operator==(const Card& rhs) const;

	bool operator!=(const Card& rhs) const;


private:
	QString _id;
	QString _pin;
	Money _balance;
	bool _isBlocked = false;
};

#endif //ATM_CARD_H
