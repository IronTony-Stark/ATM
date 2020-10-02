//
// Created by Andrew on 30-Sep-20.
//

#ifndef ATM_CARD_H
#define ATM_CARD_H


#include <logics/bank_fees/ABankFee.h>
#include <QtCore/QString>

class Customer;

class Card {
public:
	const unsigned long int _id;
	const ABankFee& _bankFee;

	explicit Card(unsigned long int id, ABankFee::FeeType, Customer&, QString& _pin, double balance = 0);

	Card(const Card&);

	[[nodiscard]] double balance() const;

	/**
	 *if balance is sufficient then subtracts else throws exception
	 * @return <remainder, actual_withdrawal_sum>
	 */
	std::pair<double, double> withdraw(double);

	double replenish(double);

	double transfer(unsigned long int recipient, double amount);

	Card& operator=(const Card&) = delete;

private:
	QString _pin;
	double _balance;
	Customer& _customer;
};


#endif //ATM_CARD_H
