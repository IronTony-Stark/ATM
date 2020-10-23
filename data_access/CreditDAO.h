//
// Created by Andrew on 23-Oct-20.
//

#ifndef ATM_CREDITDAO_H
#define ATM_CREDITDAO_H


#include <QtCore/QHash>
#include <logics/bank_services/Credit.h>

class CreditDAO {
public:
    QList<Credit* const> getAll() const;

    Credit* const getById(uint id) const;

};


#endif //ATM_CREDITDAO_H
