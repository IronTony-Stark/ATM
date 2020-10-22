//
// Created by Andrew on 02-Oct-20.
//

#include "OperationManager.h"

bool OperationManager::authorizeCustomer(const QString& cardNumber, unsigned short pinCode) {
    return false;
}

bool OperationManager::registerCustomer(const Customer& customer) {
    return false;
}

bool OperationManager::transfer(const QString& cartNumberFrom, const QString& cartNumberFromTo) {
    return false;
}

bool OperationManager::withdraw(unsigned int amount) {
    return false;
}

void OperationManager::startDeposit(unsigned int startAmount) {

}

int OperationManager::endDeposit() {
    return 0;
}

void OperationManager::cancelDeposit() {

}

void OperationManager::setPayment(unsigned long amount, const QDate& date) {

}

void OperationManager::takeCredit(unsigned int amount) {

}

void OperationManager::repayCredit(unsigned int amount) {

}
