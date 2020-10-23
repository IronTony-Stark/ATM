//
// Created by Andrew on 23-Oct-20.
//

#ifndef ATM_DEPOSITDAO_H
#define ATM_DEPOSITDAO_H


#include <logics/bank_services/Deposit.h>

class DepositDAO {
public:
    QList<Deposit* const> getAll() const;
    Deposit* const getById(uint id) const;
};


#endif //ATM_DEPOSITDAO_H
