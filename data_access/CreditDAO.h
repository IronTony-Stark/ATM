//
// Created by Andrew on 23-Oct-20.
//

#ifndef ATM_CREDITDAO_H
#define ATM_CREDITDAO_H

#include <QString>
#include "logics/bank_services/Credit.h"

#include <QtCore/QHash>
#include <logics/bank_services/Credit.h>

class CreditDAO {
public:
	QList<Credit* const> getAll() const;

	Credit* getById(uint id) const;

	static CreditDAO& getInstance();

	Credit& saveCredit(Credit&);

private:
	static void initialize();

	CreditDAO() = default;
};


#endif //ATM_CREDITDAO_H
