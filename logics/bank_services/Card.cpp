//
// Created by Andrew on 30-Sep-20.
//

#include <logics/exceptions/NotEnoughMoneyException.h>

#include <utility>
#include <data_access/CardDAO.h>
#include "logics/bank_fees/BankFeeProvider.h"
#include "logics/utils/general.h"

Card::Card(QString id, ABankFee::CardType feeType, QString pin, Money balance) :
		_id(std::move(id)), _cardType(feeType), _bankFee(BankFeeProvider::getInstance().getBankFee(feeType)),
		_pin(std::move(pin)), _balance(balance) {
}

Card::Card(const Card& c) : _id(c._id), _bankFee(c._bankFee), _cardType(c._cardType),
							_balance(c._balance) {}

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

QString Card::id() const {
	return _id;
}

std::pair<Money, Money> Card::transfer(const QString& recipient, Money amount) {
	Money transferSum = amount / (1 + _bankFee.transferFee());
	if (_balance < amount) throw NotEnoughMoneyException(_balance, amount);
	_balance -= transferSum;

	Card* recEntity = CardDAO::getInstance().getById(recipient);
	recEntity->replenishFree(amount);
	CardDAO::getInstance().updateCard(*recEntity);
	delete recEntity;
	return std::pair(transferSum, amount);
}

const QString& Card::pin() const {
	return _pin;
}

const QString& Card::regeneratePin() {
    return _pin = generatePin();
}

const QString& Card::number() const {
	return _id;
}

const ABankFee::CardType Card::cardType() const {
	return _cardType;
}

void Card::withdrawFree(Money m) {
	if (m > _balance) throw NotEnoughMoneyException(_balance, m);
	_balance -= m;
}

void Card::replenishFree(Money m) {
	_balance += m;
}

