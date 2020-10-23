//
// Created by Andrew on 23-Oct-20.
//

#ifndef ATM_PAYMENTDAO_H
#define ATM_PAYMENTDAO_H


#include <logics/bank_services/RegularPayment.h>

class PaymentDAO {
public:
    QList<RegularPayment> getAll() const;
    RegularPayment* const getById(uint id) const;
    void save(RegularPayment*) const;
    void deleteRP(RegularPayment*) const;
};


#endif //ATM_PAYMENTDAO_H
