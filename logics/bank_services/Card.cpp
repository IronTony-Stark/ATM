//
// Created by Andrew on 30-Sep-20.
//

#include <logics/exceptions/NotEnoughMoneyException.h>
#include "Card.h"
#include "logics/bank_fees/BankFeeProvider.h"
#include "logics/utils/general.h"

Card::Card(unsigned long int id, ABankFee::FeeType feeType, Customer& customer, QString& pin, Money balance) :
		_id(id), _bankFee(BankFeeProvider::getInstance().getBankFee(feeType)), _customer(customer), _pin(pin),
		_balance(balance) {
}

Card::Card(const Card& c) : _id(c._id), _bankFee(c._bankFee), _balance(c._balance), _customer(c._customer) {}

Money Card::balance() const {
	return _balance;
}

std::pair<Money, Money> Card::withdraw(Money amount) {
	Money withdrawSum = amount * _bankFee.withdrawFee();
	if (withdrawSum > _balance) throw NotEnoughMoneyException(_balance, withdrawSum);
	_balance -= withdrawSum;
	return {_balance, withdrawSum};
}

Money Card::replenish(Money amount) {
	Money replenishmentSum = amount / (1 + _bankFee.replenishFee());
	_balance += replenishmentSum;
	return _balance;
}

Money Card::transfer(unsigned long recipient, Money amount) {
	Money transferSum = amount / (1 + _bankFee.transferFee());
	// todo: get card recipient from DB and send money there
	return transferSum;
}

const QString Card::pin() const {
	return _pin;
}

const QString Card::regeneratePin() {
	return _pin = generatePin();
}


