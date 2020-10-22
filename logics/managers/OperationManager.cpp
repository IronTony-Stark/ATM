//
// Created by Andrew on 02-Oct-20.
//

#include "OperationManager.h"

// todo withdraw, transfer, register can throw std::exception
bool OperationManager::authorizeCustomer(const QString& cardNumber, unsigned short pinCode) {
    return true;
}

void OperationManager::blockCustomer(const QString& cardNumber) {

}

ushort OperationManager::registerCustomer(const QString& name, const QString& phone, uint taxNumber, QString cardType) {
    return 1;
}

void OperationManager::withdraw(unsigned int amount) {

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

void OperationManager::replenish(uint howMuch) {
}

void OperationManager::transfer(const QString& cartNumberFromTo, uint amount) {

}
