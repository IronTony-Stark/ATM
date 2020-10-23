//
// Created by Vladyslav Synytsyn on 22/10/2020.
//

#include "Authorizer.h"

void Authorizer::authorizeCustomer(Customer* const customer, Card* const card) const {
    _customerDataManager._customer = customer;
    _customerDataManager._bankCard = card;
}

Authorizer::Authorizer(CustomerDataManager& manager) : _customerDataManager(manager){}
