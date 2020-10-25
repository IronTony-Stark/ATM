//
// Created by Andrew on 23-Oct-20.
//

#ifndef ATM_CUSTOMERDAO_H
#define ATM_CUSTOMERDAO_H


#include <logics/Customer.h>
#include <QtCore/QString>
#include <QtSql/QSqlQuery>

class CustomerDAO {
public:
	static CustomerDAO& getInstance();

	void saveCustomer(Customer&) const;

	Customer* getById(const QString& id) const;

	Customer* getCustomerByCardId(const QString& id) const;

	bool updateCustomerCore(const Customer&) const;

	void deleteById(QString id) const;

	void addCard(const QString& customerId, const QString& cardId) const;

	void removeCard(const QString& customerId, const QString& cardId) const;

	void addCredit(const QString& customerId, uint creditId) const;

	void removeCredit(const QString& customerId, uint creditId) const;

	void addDeposit(const QString& customerId, uint depositId) const;

	void removeDeposit(const QString& customerId, uint depositId) const;

private:
	static void initialize();

	void addAuxiliary(const QString& targetTable, const QString& targetProp, const QVariant& customerId,
					  const QVariant& propValue) const;

	void removeAuxiliary(const QString& targetTable, const QString& targetProp, const QVariant& customerId,
						 const QVariant& propValue) const;

	CustomerDAO() = default;
};


#endif //ATM_CUSTOMERDAO_H
