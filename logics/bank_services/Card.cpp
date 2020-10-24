//
// Created by Andrew on 30-Sep-20.
//

#include <logics/exceptions/NotEnoughMoneyException.h>

#include <utility>
#include "Card.h"
#include "logics/bank_fees/BankFeeProvider.h"
#include "logics/utils/general.h"

Card::Card(ABankFee::FeeType feeType, Customer& customer, QString& pin, QString name,Money balance) :
        _cardType(feeType), _bankFee(BankFeeProvider::getInstance().getBankFee(feeType)),
        _customer(customer), _pin(pin),
        _name(std::move(name)), _balance(balance) {
    // TODO get id from database
    _id = -1;
}

Card::Card(const Card& c) : _id(c._id), _bankFee(c._bankFee), _cardType(c._cardType),
                            _balance(c._balance), _customer(c._customer) {}

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

uli Card::id() const {
	return _id;
}

Money Card::transfer(const QString& recipient, Money amount) {
	Money transferSum = amount / (1 + _bankFee.transferFee());
	// todo: get card recipient from DB and send money there
	return transferSum;
}

const QString& Card::name() const {
	return _name;
}

void Card::setName(QString newName) {
	_name = std::move(newName);
}

const QString& Card::pin() const {
	return _pin;
}

const QString& Card::regeneratePin() {
    return _pin = generatePin();
}

const QString& Card::number() const {
    // TODO return real number
    return QString();
}

const ABankFee::FeeType Card::cardType() const {
    return _cardType;
}




