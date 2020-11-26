//
// Created by Andrew on 25-Oct-20.
//

#include "CardDAO.h"
#include "logics/Customer.h"
#include "CustomerDAO.h"
#include <QDebug>

CardDAO& CardDAO::getInstance() {
	static CardDAO instance;
	initialize();
	return instance;
}

void CardDAO::initialize() {
	static bool isInitialized = false;
	if (isInitialized || !QSqlDatabase::database().isOpen()) return;

	QSqlQuery createQuery("CREATE TABLE IF NOT EXISTS card "
						  "(id TEXT PRIMARY KEY, card_type TEXT, pin TEXT, balance REAL, is_blocked INTEGER);");
	qDebug() << "creation of the 'card' table is successful: " << createQuery.isActive();
	isInitialized = true;
}

void CardDAO::saveCard(Card& card) const {
	QSqlQuery createQuery(QSqlDatabase::database());
	createQuery.prepare(QString("INSERT INTO card (id, card_type, pin, balance, is_blocked) "
								"VALUES (:id, :card_type, :pin, :balance, :is_blocked);"));
	createQuery.bindValue(":id", card.id());
	createQuery.bindValue(":card_type", card.cardType());
	createQuery.bindValue(":pin", card.pin());
	createQuery.bindValue(":balance", static_cast<double>(card.balance()));
	createQuery.bindValue(":is_blocked", card.isBlocked());
	createQuery.exec();
}

Card* CardDAO::getById(const QString& id) const {
	QSqlQuery findQuery;
	findQuery.prepare("SELECT id, card_type, pin, balance, is_blocked FROM card WHERE id = ?;");
	findQuery.bindValue(0, QVariant(id));
	findQuery.exec();
	if (findQuery.next()) {
		return buildCard(findQuery);
	}
	return nullptr;
}

Card* CardDAO::buildCard(const QSqlQuery& query) const {
	Card* card = new Card(query.value(0).toString(), ABankFee::CardType(query.value(1).toInt()),
						  query.value(2).toString(), Money(query.value(3).toDouble()));
	if (query.value(4).toBool()) card->block();
	return card;
}

bool CardDAO::updateCard(const Card& card) const {
	QSqlQuery updQuery;
	updQuery.prepare("UPDATE card SET id = :id, card_type = :card_type, pin = :pin, "
					 "balance = :balance, is_blocked = :is_blocked WHERE id = :id");
	updQuery.bindValue(":id", card.id());
	updQuery.bindValue(":card_type", card.cardType());
	updQuery.bindValue(":pin", card.pin());
	updQuery.bindValue(":balance", static_cast<double>(card.balance()));
	updQuery.bindValue(":is_blocked", card.isBlocked());

	return updQuery.exec();
}

void CardDAO::deleteById(const QString& id) const {
	QSqlQuery deleteQuery;
	deleteQuery.prepare(QString("DELETE FROM card WHERE id = '%1'").arg(id));
	deleteQuery.exec();
}
