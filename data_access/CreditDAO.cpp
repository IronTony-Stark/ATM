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

Credit& CreditDAO::saveCredit(Credit& credit) {
	QSqlQuery createQuery(QSqlDatabase::database());
	createQuery.prepare(QString("INSERT INTO credit (interest, name, credit_body, bank_income, payment, date_taken) "
								"VALUES (:interest, :name, :credit_body, :bank_income, :payment, :date_taken);"));
	createQuery.bindValue(":interest", QVariant(credit._interest));
	createQuery.bindValue(":name", QVariant(credit.name()));
	createQuery.bindValue(":credit_body", QVariant(static_cast<double>(credit.creditBody())));
	createQuery.bindValue(":bank_income", QVariant(static_cast<double>(credit.bankIncome())));
	createQuery.bindValue(":payment", QVariant(static_cast<double>(credit.payment())));
	createQuery.bindValue(":date_taken", QVariant(credit.dateTaken()));
	createQuery.exec();
	uint id = createQuery.lastInsertId().toUInt();
	credit._id = id;
//    credit._id = createQuery.lastInsertId().toUInt();
	return credit;
}

void CreditDAO::initialize() {
	static bool isInitialized = false;
	if (isInitialized) return;
	QSqlQuery createQuery("CREATE TABLE IF NOT EXISTS credit "
						  "(id INTEGER PRIMARY KEY AUTOINCREMENT, interest DECIMAL, name TEXT, "
						  "credit_body DECIMAL, bank_income DECIMAL, payment DECIMAL, date_taken TEXT);");
	isInitialized = true;
}

QList<Credit* const> CreditDAO::getAll() const {
	return QList<Credit* const>();
}

Credit* CreditDAO::getById(uint id) const {
	return nullptr;
}
