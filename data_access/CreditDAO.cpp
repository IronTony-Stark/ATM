//
// Created by Andrew on 23-Oct-20.
//

#include "CreditDAO.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

CreditDAO& CreditDAO::getInstance() {
	static CreditDAO instance;
	initialize();
	return instance;
}

void CreditDAO::initialize() {
	static bool isInitialized = false;
	if (!QSqlDatabase::database().isOpen()) return;
	if (isInitialized) return;
	QSqlQuery createQuery("CREATE TABLE IF NOT EXISTS credit "
						  "(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, credit_body DECIMAL, interest DECIMAL, "
						  "payment DECIMAL, bank_income DECIMAL, date_taken TEXT);");
	qDebug() << "creation of a table is successful: " << createQuery.isActive();
	isInitialized = true;
}

Credit& CreditDAO::saveCredit(Credit& credit) {
	QSqlQuery createQuery(QSqlDatabase::database());
	createQuery.prepare(QString("INSERT INTO credit (name, credit_body, interest, payment, bank_income, date_taken) "
								"VALUES (:name, :credit_body, :interest, :payment, :bank_income, :date_taken);"));
	createQuery.bindValue(":name", QVariant(credit.name()));
	createQuery.bindValue(":credit_body", QVariant(static_cast<double>(credit.creditBody())));
	createQuery.bindValue(":interest", QVariant(credit._interest));
	createQuery.bindValue(":payment", QVariant(static_cast<double>(credit.payment())));
	createQuery.bindValue(":bank_income", QVariant(static_cast<double>(credit.bankIncome())));
	createQuery.bindValue(":date_taken", QVariant(credit.dateTaken().toString()));
	createQuery.exec();
	uint id = createQuery.lastInsertId().toUInt();
	credit._id = id;
//    credit._id = createQuery.lastInsertId().toUInt();
	return credit;
}

QList<Credit*> CreditDAO::getAll() const {
	// Using SELECT * is not recommended because the order of the fields in the query is undefined.
	QSqlQuery findAllQuery("SELECT id, name, credit_body, interest, payment, bank_income, date_taken FROM credit");
	QList<Credit*> res;
	while (findAllQuery.next()) {
		Credit* credit = new Credit(findAllQuery.value(0).toUInt(), findAllQuery.value(1).toString(),
									Money(findAllQuery.value(2).toDouble()),
									findAllQuery.value(3).toDouble(),
									Money(findAllQuery.value(4).toDouble()),
									Money(findAllQuery.value(5).toDouble()),
									QDate::fromString(findAllQuery.value(6).toString()));
		res.append(credit);
	}
	return res;
}

Credit* CreditDAO::getById(uint id) const {
	QSqlQuery findQuery;
	findQuery.prepare("SELECT name, credit_body, interest, payment, bank_income, date_taken "
					  "FROM credit WHERE id = ?;");
	findQuery.bindValue(0, QVariant(id));
	findQuery.exec();
	if (findQuery.next()) {
		return new Credit(id, findQuery.value(0).toString(), Money(findQuery.value(1).toDouble()),
						  findQuery.value(2).toDouble(), Money(findQuery.value(3).toDouble()),
						  Money(findQuery.value(4).toDouble()),
						  QDate::fromString(findQuery.value(6).toString()));
	}
	return nullptr;
}

boolean CreditDAO::updateCredit(const Credit& credit) {
	QSqlQuery updQuery;
	updQuery.prepare("UPDATE credit SET name = :name, credit_body = :credit_body, interest = :interest, "
					 "payment = :payment, bank_income = :bank_income, date_taken = :date_taken WHERE id = :id");
	updQuery.bindValue(":name", credit.name());
	updQuery.bindValue(":credit_body", static_cast<double>(credit.creditBody()));
	updQuery.bindValue(":interest", credit.interest());
	updQuery.bindValue(":payment", static_cast<double>(credit.payment()));
	updQuery.bindValue(":bank_income", static_cast<double>(credit.bankIncome()));
	updQuery.bindValue(":date_taken", credit.dateTaken()); // just date?
	updQuery.bindValue(":id", credit.id());
	return updQuery.exec();
}

void CreditDAO::deleteById(uint id) {
	QSqlQuery deleteQuery;
	deleteQuery.prepare(QString("DELETE FROM credit WHERE id = %1").arg(id));
	deleteQuery.exec();
}
