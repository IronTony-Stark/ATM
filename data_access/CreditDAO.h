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
	static CreditDAO& getInstance();

	QList<Credit*> getAll() const;

	Credit* getById(uint id) const;

	Credit& saveCredit(Credit&);

	boolean updateCredit(const Credit&);

	void deleteById(uint id);

private:
	static void initialize();

	CreditDAO() = default;
};


#endif //ATM_CREDITDAO_H
