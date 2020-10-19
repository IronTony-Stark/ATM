//
// Created by Andrew on 30-Sep-20.
//

#include <logics/exceptions/NotEnoughMoneyException.h>
#include "Card.h"
#include "logics/bank_fees/BankFeeProvider.h"

Card::Card(unsigned long int id, ABankFee::FeeType feeType, Customer& customer, QString& pin, double balance) :
		_id(id), _bankFee(BankFeeProvider::getInstance().getBankFee(feeType)), _customer(customer), _pin(pin),
		_balance(balance) {
}

Card::Card(const Card& c) : _id(c._id), _bankFee(c._bankFee), _balance(c._balance), _customer(c._customer) {}

double Card::balance() const {
	return _balance;
}

std::pair<double, double> Card::withdraw(double amount) {
	double withdrawSum = amount * _bankFee.withdrawFee();
	if (withdrawSum > _balance) throw NotEnoughMoneyException(_balance, withdrawSum);
	_balance -= withdrawSum;
	return {_balance, withdrawSum};
}

double Card::replenish(double amount) {
	double replenishmentSum = amount / (1 + _bankFee.replenishFee());
	_balance += replenishmentSum;
	return _balance;
}

double Card::transfer(unsigned long recipient, double amount) {
	double transferSum = amount / (1 + _bankFee.transferFee());
	// todo: get card recipient from DB and send money there
	return transferSum;
}


