//
// Created by Vladyslav Synytsyn on 22/10/2020.
//

#include "Authorizer.h"

void Authorizer::authorizeCustomer(Customer* const customer, Card* const card) const {
    if (_customerDataManager._customer != nullptr){
        Customer* prevCustomer = _customerDataManager._customer;
        _customerDataManager._customer = customer;
        delete prevCustomer;
        _customerDataManager._bankCard = nullptr;
    } else {
        _customerDataManager._customer = customer;
    }
    if (_customerDataManager._bankCard != nullptr){
        Card* prevCard = _customerDataManager._bankCard;
        _customerDataManager._bankCard = card;
        delete prevCard;
    } else {
        _customerDataManager._bankCard = card;
    }
}

Authorizer::Authorizer(CustomerDataManager& manager) : _customerDataManager(manager){}
