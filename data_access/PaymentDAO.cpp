//
// Created by Andrew on 23-Oct-20.
//

#include <logics/bank_services/RegularPayment.h>
#include <logics/bank_services/Deposit.h>
#include <QDebug>
#include "PaymentDAO.h"

PaymentDAO& PaymentDAO::getInstance() {
	static PaymentDAO instance;
	initialize();
	return instance;
}

void PaymentDAO::initialize() {
// RegularPayment(QString name, Money amount, QString sender, QString receiver, uint dayOfMonth, uint id);
	static bool isInitialized = false;
	if (isInitialized || !QSqlDatabase::database().isOpen()) return;
	QSqlQuery createQuery("CREATE TABLE IF NOT EXISTS payment (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, "
						  "amount REAL, sender_id TEXT, receiver_id TEXT, day_of_month INTEGER);");
	qDebug() << "creation of table 'payment' is successful: " << createQuery.isActive();
	isInitialized = true;
}

void PaymentDAO::save(RegularPayment& payment) const {
	QSqlQuery insertQuery;
	insertQuery.prepare("INSERT INTO payment (name, amount, sender_id, receiver_id, day_of_month) "
						"VALUES (:name, :amount, :sender_id, :receiver_id, :day_of_month);");
	insertQuery.bindValue(":name", payment.name());
	insertQuery.bindValue(":amount", static_cast<double>(payment.amount()));
	insertQuery.bindValue(":sender_id", payment.sender());
	insertQuery.bindValue(":receiver_id", payment.receiver());
	insertQuery.bindValue(":day_of_month", payment.dayOfMonth());
	insertQuery.exec();
	payment._id = insertQuery.lastInsertId().toUInt();
}

QList<RegularPayment*> PaymentDAO::getAll() const {
	QSqlQuery selectQuery("SELECT id, name, amount, sender_id, receiver_id, day_of_month FROM payment;");
	QList<RegularPayment*> res;
	while (selectQuery.next()) {
		RegularPayment* payment = buildPayment(selectQuery);
		res.append(payment);
	}
	return res;
}

QList<RegularPayment*> PaymentDAO::getSenderCardPayments(const QString& senderId) const {
	QSqlQuery selectQuery("SELECT id, name, amount, sender_id, receiver_id, day_of_month FROM payment WHERE sender_id = ?;");
	selectQuery.bindValue(0, senderId);
    selectQuery.exec();
	QList<RegularPayment*> res;
	while (selectQuery.next()) {
		RegularPayment* payment = buildPayment(selectQuery);
		res.append(payment);
	}
	return res;
}

RegularPayment* const PaymentDAO::getById(uint id) const {
	QSqlQuery selectQuery;
	selectQuery.prepare("SELECT id, name, amount, sender_id, receiver_id, day_of_month FROM payment WHERE id = ?;");
	selectQuery.bindValue(0, id);
	selectQuery.exec();
	if (selectQuery.next())
		return buildPayment(selectQuery);
	return nullptr;
}

RegularPayment* PaymentDAO::buildPayment(const QSqlQuery& query) const {
	return new RegularPayment(query.value(1).toString(), Money(query.value(2).toDouble()),
							  query.value(3).toString(), query.value(4).toString(),
							  query.value(5).toUInt(), query.value(0).toUInt());
}

void PaymentDAO::removePayment(uint id) const {
	QSqlQuery deleteQuery(QString("DELETE FROM payment WHERE id = %1").arg(id));
}






