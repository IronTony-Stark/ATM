//
// Created by Vladyslav Synytsyn on 22/10/2020.
//

#ifndef ATM_REGISTRATOR_H
#define ATM_REGISTRATOR_H


#include <logics/managers/CustomerDataManager.h>
#include <data_access/CustomerDAO.h>
#include "CustomerVerificationData.h"

class Registrator {
private:
    const CustomerDataManager& _customerDataManager;
    const CustomerDAO& _customerDao;

    static int generatePin();
    static const QString generateCardNumber();

public:
    explicit Registrator(const CustomerDataManager& customerDataManager, const CustomerDAO& customerDao) :
            _customerDataManager(customerDataManager), _customerDao(customerDao) {}

    ushort registerCustomer(const CustomerVerificationData& verificationData) const;
};


#endif //ATM_REGISTRATOR_H
