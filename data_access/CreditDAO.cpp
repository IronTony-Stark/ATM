//
// Created by Andrew on 23-Oct-20.
//

#include "CreditDAO.h"
#include "CustomerDAO.h"
#include <QVariant>
#include <QDebug>

CreditDAO& CreditDAO::getInstance() {
	static CreditDAO instance;
	initialize();
	return instance;
}

void CreditDAO::initialize() {
	static bool isInitialized = false;
	if (isInitialized || !QSqlDatabase::database().isOpen()) return;

	QSqlQuery createQuery("CREATE TABLE IF NOT EXISTS credit "
						  "(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, credit_body DECIMAL, interest DECIMAL, "
						  "payment DECIMAL, bank_income DECIMAL, date_taken TEXT);");
	qDebug() << "creation of a 'credit' table is successful: " << createQuery.isActive();
	isInitialized = true;
}

Credit& CreditDAO::saveCredit(Credit& credit) const {
	QSqlQuery createQuery;
	createQuery.prepare("INSERT INTO credit (name, credit_body, interest, payment, bank_income, date_taken) "
						"VALUES (:name, :credit_body, :interest, :payment, :bank_income, :date_taken);");
	createQuery.bindValue(":name", credit.name());
	createQuery.bindValue(":credit_body", static_cast<double>(credit.creditBody()));
	createQuery.bindValue(":interest", credit._interest);
	createQuery.bindValue(":payment", static_cast<double>(credit.payment()));
	createQuery.bindValue(":bank_income", static_cast<double>(credit.bankIncome()));
	createQuery.bindValue(":date_taken", credit.dateTaken());
	createQuery.exec();
	credit._id = createQuery.lastInsertId().toUInt();
	return credit;
}

QList<Credit*> CreditDAO::getAll() const {
	// Using SELECT * is not recommended because the order of the fields in the query is undefined.
	QSqlQuery findAllQuery("SELECT id, name, credit_body, interest, payment, bank_income, date_taken FROM credit");
	QList<Credit*> res;
	while (findAllQuery.next()) {
		Credit* credit = buildCredit(findAllQuery);
		res.append(credit);
	}
	return res;
}

Credit* CreditDAO::getById(uint id) const {
	QSqlQuery findQuery;
	findQuery.prepare("SELECT id, name, credit_body, interest, payment, bank_income, date_taken "
					  "FROM credit WHERE id = ?;");
	findQuery.bindValue(0, QVariant(id));
	findQuery.exec();
	if (findQuery.next()) {
		return buildCredit(findQuery);
	}
	return nullptr;
}

Credit* CreditDAO::buildCredit(const QSqlQuery& query) const {
	return new Credit(query.value(0).toUInt(), query.value(1).toString(),
					  Money(query.value(2).toDouble()),
					  query.value(3).toDouble(),
					  Money(query.value(4).toDouble()),
					  Money(query.value(5).toDouble()),
					  QDate::fromString(query.value(6).toString()));;
}

boolean CreditDAO::updateCredit(const Credit& credit) const {
	QSqlQuery updQuery;
	updQuery.prepare("UPDATE credit SET name = :name, credit_body = :credit_body, interest = :interest, "
					 "payment = :payment, bank_income = :bank_income, date_taken = :date_taken WHERE id = :id");
	updQuery.bindValue(":name", credit.name());
	updQuery.bindValue(":credit_body", static_cast<double>(credit.creditBody()));
	updQuery.bindValue(":interest", credit.interest());
	updQuery.bindValue(":payment", static_cast<double>(credit.payment()));
	updQuery.bindValue(":bank_income", static_cast<double>(credit.bankIncome()));
	updQuery.bindValue(":date_taken", credit.dateTaken());
	updQuery.bindValue(":id", credit.id());
	return updQuery.exec();
}

void CreditDAO::deleteById(uint id) const {
	QSqlQuery deleteQuery;
	deleteQuery.prepare(QString("DELETE FROM credit WHERE id = %1").arg(id));
	deleteQuery.exec();
}
