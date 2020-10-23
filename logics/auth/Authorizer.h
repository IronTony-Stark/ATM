//
// Created by Vladyslav Synytsyn on 22/10/2020.
//

#ifndef ATM_AUTHORIZER_H
#define ATM_AUTHORIZER_H


#include <logics/managers/CustomerDataManager.h>

class Authorizer {
private:
    CustomerDataManager& _customerDataManager;

public:
    Authorizer(CustomerDataManager& manager);

    void authorizeCustomer(Customer* customer, Card* card) const;
};


#endif //ATM_AUTHORIZER_H
