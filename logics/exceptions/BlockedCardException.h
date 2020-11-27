//
// Created by Andrew on 26-Nov-20.
//

#ifndef MOOP_ATM_BLOCKEDCARDEXCEPTION_H
#define MOOP_ATM_BLOCKEDCARDEXCEPTION_H


#include <QtCore/QString>

class BlockedCardException : std::exception {
public:
	explicit BlockedCardException(QString cardId) : _cardId(std::move(cardId)) {}

	const QString& cardId() const { return _cardId; };

private:
	QString _cardId;
};


#endif //MOOP_ATM_BLOCKEDCARDEXCEPTION_H
