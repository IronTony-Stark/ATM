//
// Created by Andrew on 23-Oct-20.
//

#include "DepositDAO.h"
#include "CustomerDAO.h"
#include <QDebug>

DepositDAO& DepositDAO::getInstance() {
	static DepositDAO instance;
	initialize();
	return instance;
}

void DepositDAO::initialize() {
	static bool isInitialized = false;
	if (isInitialized || !QSqlDatabase::database().isOpen()) return;

	QSqlQuery createQuery("CREATE TABLE IF NOT EXISTS deposit "
						  "(id INTEGER PRIMARY KEY AUTOINCREMENT, owner_card TEXT, name TEXT, sum DECIMAL, "
						  "interest DECIMAL, start_date TEXT, end_date TEXT);");
	qDebug() << "creation of a 'deposit' table is successful: " << createQuery.isActive();
	isInitialized = true;
}

Deposit& DepositDAO::saveDeposit(Deposit& deposit) {
	QSqlQuery createQuery(QSqlDatabase::database());
	createQuery.prepare("INSERT INTO deposit (owner_card, name, sum, interest, start_date, end_date) "
						"VALUES (:owner_card, :name, :sum, :interest, :start_date, :end_date);");
	createQuery.bindValue(":owner_card", deposit.ownerCard());
	createQuery.bindValue(":name", deposit.name());
	createQuery.bindValue(":sum", static_cast<double>(deposit.sum()));
	createQuery.bindValue(":interest", deposit.interest());
	createQuery.bindValue(":start_date", deposit.startDate().toString());
	createQuery.bindValue(":end_date", deposit.endDate());
	createQuery.exec();
	deposit._id = createQuery.lastInsertId().toUInt();
	return deposit;
}

QList<Deposit*> DepositDAO::getAll() const {
	// Using SELECT * is not recommended because the order of the fields in the query is undefined.
	QSqlQuery findAllQuery("SELECT id, owner_card, name, sum, interest, start_date, end_date FROM deposit;");
	QList<Deposit*> res;
	while (findAllQuery.next()) {
		Deposit* deposit = buildDeposit(findAllQuery);
		res.append(deposit);
	}
	return res;
}

Deposit* DepositDAO::getById(uint id) const {
	QSqlQuery findQuery;
	findQuery.prepare("SELECT id, owner_card, name, sum, interest, start_date, end_date "
					  "FROM deposit WHERE id = ?;");
	findQuery.bindValue(0, QVariant(id));
	findQuery.exec();
	if (findQuery.next()) {
		return buildDeposit(findQuery);
	}
	return nullptr;
}

Deposit* DepositDAO::buildDeposit(const QSqlQuery& queryRes) const {
	return new Deposit(queryRes.value(1).toString(),
					   queryRes.value(2).toString(),
					   Money(queryRes.value(3).toDouble()),
					   queryRes.value(4).toDouble(),
					   QDate::fromString(queryRes.value(5).toString(), "yyyy-MM-dd"),
					   QDate::fromString(queryRes.value(6).toString(), "yyyy-MM-dd"),
					   queryRes.value(0).toUInt());
}

boolean DepositDAO::updateDeposit(const Deposit& deposit) {
	QSqlQuery updQuery;
	updQuery.prepare("UPDATE deposit SET name = :name, sum = :sum, interest = :interest, "
					 "start_date = :start_date, end_date = :end_date WHERE id = :id;");
	updQuery.bindValue(":name", deposit.name());
	updQuery.bindValue(":sum", static_cast<double>(deposit.sum()));
	updQuery.bindValue(":interest", deposit.interest());
	updQuery.bindValue(":start_date", deposit.startDate());
	updQuery.bindValue(":end_date", deposit.endDate());
	updQuery.bindValue(":id", deposit.id());
	return updQuery.exec();
}

void DepositDAO::deleteById(uint id) {
	QSqlQuery deleteQuery;
	deleteQuery.prepare(QString("DELETE FROM deposit WHERE id = %1;").arg(id));
	deleteQuery.exec();
}
