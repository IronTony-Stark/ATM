//
// Created by Andrew on 23-Oct-20.
//
#include <QDebug>
#include "CustomerDAO.h"
#include "CardDAO.h"
#include "CreditDAO.h"
#include "DepositDAO.h"

CustomerDAO& CustomerDAO::getInstance() {
	static CustomerDAO instance;
	initialize();
	return instance;
}

void CustomerDAO::initialize() {
	static bool isInitialized = false;
	if (isInitialized || !QSqlDatabase::database().isOpen()) return;
	QSqlQuery createQuery("CREATE TABLE IF NOT EXISTS customer "
						  "(id TEXT PRIMARY KEY, name TEXT, phoneNum TEXT, revenue DECIMAL);");
	qDebug() << "creation of a 'customer' table is successful: " << createQuery.isActive();

	QSqlQuery createCustomerCardQuery("CREATE TABLE IF NOT EXISTS customer_card (customer_id TEXT, card_id TEXT, "
									  "PRIMARY KEY (customer_id, card_id));");
	qDebug() << "creation of a 'customer_card' table is successful: " << createCustomerCardQuery.isActive();

	QSqlQuery createCustomerCreditQuery(
			"CREATE TABLE IF NOT EXISTS customer_credit (customer_id TEXT, credit_id INTEGER, "
			"PRIMARY KEY (customer_id, credit_id));");
	qDebug() << "creation of a 'customer_credit' table is successful: " << createCustomerCreditQuery.isActive();

	QSqlQuery createCustomerDepositQuery(
			"CREATE TABLE IF NOT EXISTS customer_deposit (customer_id TEXT, deposit_id INTEGER, "
			"PRIMARY KEY (customer_id, deposit_id));");
	qDebug() << "creation of a 'customer_deposit' table is successful: " << createCustomerDepositQuery.isActive();

	isInitialized = true;
}

void CustomerDAO::saveCustomer(Customer& customer) const {
	QSqlQuery saveQuery;
	saveQuery.prepare("INSERT INTO customer (id, name, phoneNum, revenue) "
					  "VALUES (:id, :name, :phoneNum, :revenue);");
	saveQuery.bindValue(":id", customer._taxNumber);
	saveQuery.bindValue(":name", customer.name());
	saveQuery.bindValue(":phoneNum", customer.phoneNumber());
	saveQuery.bindValue(":revenue", static_cast<double>(customer.revenue()));
	saveQuery.exec();

	for (auto card : customer.cards()) {
		QSqlQuery saveCardQuery;
		saveCardQuery.prepare("INSERT INTO customer_card (customer_id, card_id) "
							  "VALUES (:customer_id, :card_id);");
		saveCardQuery.bindValue(":customer_id", customer._taxNumber);
		saveCardQuery.bindValue(":card_id", card->id());
		saveCardQuery.exec();
	}

	for (auto credit : customer.credits()) {
		QSqlQuery saveCreditQuery;
		saveCreditQuery.prepare("INSERT INTO customer_credit (customer_id, credit_id) "
								"VALUES (:customer_id, :credit_id);");
		saveCreditQuery.bindValue(":customer_id", customer._taxNumber);
		saveCreditQuery.bindValue(":credit_id", credit->id());
		saveCreditQuery.exec();
	}

	for (auto deposit : customer.deposits()) {
		QSqlQuery saveDepositQuery;
		saveDepositQuery.prepare("INSERT INTO customer_deposit (customer_id, deposit_id) "
								 "VALUES (:customer_id, :deposit_id);");
		saveDepositQuery.bindValue(":customer_id", customer._taxNumber);
		saveDepositQuery.bindValue(":deposit_id", deposit->id());
		saveDepositQuery.exec();
	}
}

Customer* CustomerDAO::getById(const QString& id) const {
	QSqlQuery selectQuery(QString("SELECT name, phoneNum, revenue FROM customer WHERE id = '%1';").arg(id));
	if (!selectQuery.next()) return nullptr;

	Customer* customer = new Customer(id, selectQuery.value(0).toString(),
									  selectQuery.value(1).toString(),
									  Money(selectQuery.value(2).toDouble()));

	QSqlQuery selectCardsQuery(QString("SELECT card_id FROM customer_card WHERE customer_id = '%1';").arg(id));
	while (selectCardsQuery.next()) {
		Card* card = CardDAO::getInstance().getById(selectCardsQuery.value(0).toString());
		customer->addCard(card);
	}

	QSqlQuery selectCreditsQuery(QString("SELECT credit_id FROM customer_credit WHERE customer_id = '%1';").arg(id));
	while (selectCreditsQuery.next()) {
		Credit* credit = CreditDAO::getInstance().getById(selectCreditsQuery.value(0).toUInt());
		customer->addCredit(credit);
	}

	QSqlQuery selectDepositsQuery(QString("SELECT deposit_id FROM customer_deposit WHERE customer_id = '%1';").arg(id));
	while (selectDepositsQuery.next()) {
		Deposit* deposit = DepositDAO::getInstance().getById(selectDepositsQuery.value(0).toUInt());
		customer->addDeposit(deposit);
	}

	return customer;
}

Customer* CustomerDAO::getCustomerByCardId(const QString& id) const {
	QSqlQuery selectCustomerIdQuery(QString("SELECT customer_id FROM customer_card WHERE card_id = '%1';").arg(id));
	if (!selectCustomerIdQuery.next()) return nullptr;
	return getById(selectCustomerIdQuery.value(0).toString());
}

bool CustomerDAO::updateCustomerCore(const Customer& customer) const {
	QSqlQuery updateQuery;
	updateQuery.prepare(QString("UPDATE customer SET name = :name, phoneNum = :phoneNum, revenue = :revenue "
								"WHERE id = '%1';").arg(customer._taxNumber));
	updateQuery.bindValue(":name", customer.name());
	updateQuery.bindValue(":phoneNum", customer.phoneNumber());
	updateQuery.bindValue(":revenue", static_cast<double>(customer.revenue()));
	return updateQuery.exec();
}

void CustomerDAO::deleteById(QString id) const {
	QSqlQuery deleteQuery(QString("DELETE FROM customer WHERE id = '%1'").arg(id));
	QSqlQuery deleteCardsQuery(QString("DELETE FROM customer_card WHERE customer_id = '%1';").arg(id));
	QSqlQuery deleteCreditsQuery(QString("DELETE FROM customer_credit WHERE customer_id = '%1';").arg(id));
	QSqlQuery deleteDepositsQuery(QString("DELETE FROM customer_deposit WHERE customer_id = '%1';").arg(id));
}

void CustomerDAO::addCard(const QString& customerId, const QString& cardId) const {
	addAuxiliary("customer_card", "card_id", customerId, cardId);
}

void CustomerDAO::removeCard(const QString& customerId, const QString& cardId) const {
	removeAuxiliary("customer_card", "card_id", customerId, QString("'%1'").arg(cardId));
}

void CustomerDAO::addCredit(const QString& customerId, uint creditId) const {
	addAuxiliary("customer_credit", "credit_id", customerId, creditId);
}

void CustomerDAO::removeCredit(const QString& customerId, uint creditId) const {
	removeAuxiliary("customer_credit", "credit_id", customerId, creditId);
}

void CustomerDAO::addDeposit(const QString& customerId, uint depositId) const {
	addAuxiliary("customer_deposit", "deposit_id", customerId, depositId);
}

void CustomerDAO::removeDeposit(const QString& customerId, uint depositId) const {
	removeAuxiliary("customer_deposit", "deposit_id", customerId, depositId);
}

void
CustomerDAO::addAuxiliary(const QString& targetTable, const QString& targetProp,
						  const QVariant& customerId, const QVariant& propValue) const {
	QSqlQuery insertQuery;
	insertQuery.prepare(QString("INSERT INTO %1 (customer_id, %2) "
								"VALUES (:customer_id, :%3);").arg(targetTable).arg(targetProp).arg(targetProp));
	insertQuery.bindValue(":customer_id", customerId);
	insertQuery.bindValue(QString(":%1").arg(targetProp), propValue);
	insertQuery.exec();
}

void
CustomerDAO::removeAuxiliary(const QString& targetTable, const QString& targetProp,
							 const QVariant& customerId, const QVariant& propValue) const {
	QString strQuery = QString("DELETE FROM %1 WHERE customer_id = '%2' AND %3 = %4;")
			.arg(targetTable)
			.arg(customerId.toString())
			.arg(targetProp)
			.arg(propValue.toString());
	QSqlQuery deleteQuery(strQuery);
}
