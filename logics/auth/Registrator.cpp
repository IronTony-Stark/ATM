//
// Created by Vladyslav Synytsyn on 22/10/2020.
//

#include <QtCore/QRandomGenerator>
#include "Registrator.h"

#include <QDebug>
#include <logics/exceptions/CustomerRegistrationException.h>

ushort Registrator::registerCustomer(const CustomerVerificationData& verificationData) const {
    Customer* const customer = _customerDataManager.getCustomerByTaxNumber(verificationData.getTaxNumber());
    if (customer != nullptr) {
        QList<Card*> cards = customer->cards();
        for (int i = 0; i < cards.count(); ++i) {
            if (cards[i]->cardType() == verificationData.getCardType()) {
                throw CustomerRegistrationException(
                    "The person with given taxNumber and chosen card type has already registered");
            }
        }
    }

    Customer* const newCustomer = new Customer(
            verificationData.getName(),
            verificationData.getTaxNumber(),
            verificationData.getPhoneNumber(),
            verificationData.getIncome());

    ushort pin = generatePin();
    const QString number = generateCardNumber();
	Card* newCard = new Card(number, verificationData.getCardType(), reinterpret_cast<QString&>(pin));
    newCustomer->addCard(newCard);

	_customerDao.saveCustomer(*customer);
    return pin;
}

int Registrator::generatePin() {
    QRandomGenerator generator;
    generator.seed(QDateTime::currentSecsSinceEpoch());
    return generator.bounded(1000, 10000);
}

const QString Registrator::generateCardNumber() {
    // TODO generate real number
    return QString("1234");
}
