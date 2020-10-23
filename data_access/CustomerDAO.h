//
// Created by Andrew on 23-Oct-20.
//

#ifndef ATM_CUSTOMERDAO_H
#define ATM_CUSTOMERDAO_H


#include <logics/Customer.h>
#include <QtCore/QString>

class CustomerDAO {
public:
    void save(const Customer* const) const;
};


#endif //ATM_CUSTOMERDAO_H
