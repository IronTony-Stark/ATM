//
// Created by Andrew on 23-Oct-20.
//

#ifndef ATM_CREDITDAO_H
#define ATM_CREDITDAO_H

#include <QString>
#include "logics/bank_services/Credit.h"
#include <QSqlQuery>
#include <QtCore/QHash>
#include <logics/bank_services/Credit.h>

class CreditDAO {
public:
	static CreditDAO& getInstance();

	QList<Credit*> getAll() const;

	Credit* getById(uint id) const;

	Credit& saveCredit(Credit&) const;

	boolean updateCredit(const Credit&) const;

	void deleteById(uint id) const;

private:
	static void initialize();

	Credit* buildCredit(const QSqlQuery&) const;

	CreditDAO() = default;
};


#endif //ATM_CREDITDAO_H
