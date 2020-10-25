//
// Created by Vladyslav Synytsyn on 22/10/2020.
//

#ifndef ATM_CUSTOMERVERIFICATIONDATA_H
#define ATM_CUSTOMERVERIFICATIONDATA_H


#include <QtCore/QString>
#include <logics/bank_fees/ABankFee.h>

class CustomerVerificationData {
private:
    QString& _name;
    QString& _taxNumber;
    int _income;
    QString& _phoneNumber;
	ABankFee::CardType _cardType;

public:

    CustomerVerificationData(
			QString& name,
			QString& taxNumber,
			int income,
			QString& phoneNumber,
			ABankFee::CardType cardType
    ) : _name(name), _taxNumber(taxNumber), _income(income), _phoneNumber(phoneNumber), _cardType(cardType) {};

    const QString& getName() const { return _name; }

    const QString& getTaxNumber() const { return _taxNumber; };

    int getIncome() const { return _income; };

	const ABankFee::CardType getCardType() const { return _cardType; }

    const QString& getPhoneNumber() const { return _phoneNumber; }

    const QString& setPhoneNumber(const QString& phoneNumber);

    bool validatePhoneNumber(const QString& phoneNumber);
};


#endif //ATM_CUSTOMERVERIFICATIONDATA_H
