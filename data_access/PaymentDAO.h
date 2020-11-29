//
// Created by Andrew on 23-Oct-20.
//

#ifndef ATM_PAYMENTDAO_H
#define ATM_PAYMENTDAO_H


#include <logics/bank_services/RegularPayment.h>
#include <QtSql/QSqlQuery>

class PaymentDAO {
public:
	static PaymentDAO& getInstance();

	void save(RegularPayment&) const;

	QList<RegularPayment*> getSenderCardPayments(const QString& senderId) const;

	QList<RegularPayment*> getAll() const;

	RegularPayment* const getById(uint id) const;

	void removePayment(uint id) const;

private:
	static void initialize();

	RegularPayment* buildPayment(const QSqlQuery&) const;

	PaymentDAO() = default;
};


#endif //ATM_PAYMENTDAO_H
