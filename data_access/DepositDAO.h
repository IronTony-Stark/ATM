//
// Created by Andrew on 23-Oct-20.
//

#ifndef ATM_DEPOSITDAO_H
#define ATM_DEPOSITDAO_H


#include <logics/bank_services/Deposit.h>
#include <QSqlQuery>

class DepositDAO {
public:
	static DepositDAO& getInstance();

	QList<Deposit*> getAll() const;

	Deposit* getById(uint id) const;

	Deposit& saveDeposit(Deposit&);

	boolean updateDeposit(const Deposit&);

	void deleteById(uint id);

private:
	static void initialize();

	Deposit* buildDeposit(const QSqlQuery&) const;

	DepositDAO() = default;
};


#endif //ATM_DEPOSITDAO_H
