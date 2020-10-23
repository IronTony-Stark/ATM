//
// Created by Andrew on 23-Oct-20.
//

#include <logics/bank_services/RegularPayment.h>
#include <logics/bank_services/Deposit.h>
#include "PaymentDAO.h"


QList<RegularPayment> PaymentDAO::getAll() const {
//    QList<Deposit*> list;
    QList<RegularPayment> list;
    return list;
}

RegularPayment* const PaymentDAO::getById(uint id) const {
    return nullptr;
}

void PaymentDAO::save(RegularPayment* const) const {

}

void PaymentDAO::deleteRP(RegularPayment* const) const {

}
