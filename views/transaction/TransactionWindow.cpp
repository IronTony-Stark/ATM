//
// Created by Iron Tony on 20/10/2020.
//

#include "TransactionWindow.h"
#include "gui/ui_transactionwindow.h"
#include "views/exceptions/AbsentNavigationDestination.h"

enum Windows {
    TRANSACTIONS,
    REPLENISH,
    WITHDRAW,
    TRANSFER,
    MAIN_MENU,
};

TransactionWindow::TransactionWindow(OperationManager& operationManager, QWidget* parent) :
        QWidget(parent), _ui(new Ui::TransactionWindow),
        _operationManager(operationManager),
        _transactionPageLogic(*this),
        _replenishPageLogic(*this),
        _withdrawPageLogic(*this),
        _transferPageLogic(*this) {
    _ui->setupUi(this);
}

TransactionWindow::~TransactionWindow() {
    delete _ui;
}

void TransactionWindow::setController(ControllerLogicSettable* logicSettable) {
    _logicSettable = logicSettable;
}

void TransactionWindow::setLogicActive() {
    _logicSettable->setLogic(&_transactionPageLogic);
}

void TransactionWindow::navigate(int destination) {
    switch (destination) {
        case TRANSACTIONS:
            _logicSettable->setLogic(&_transactionPageLogic);
            _ui->stackedWidget->setCurrentIndex(TRANSACTIONS);
            break;
        case REPLENISH:
            _logicSettable->setLogic(&_replenishPageLogic);
            _ui->stackedWidget->setCurrentIndex(REPLENISH);
            break;
        case WITHDRAW:
            _logicSettable->setLogic(&_withdrawPageLogic);
            _ui->stackedWidget->setCurrentIndex(WITHDRAW);
            break;
        case TRANSFER:
            _logicSettable->setLogic(&_transferPageLogic);
            _ui->stackedWidget->setCurrentIndex(TRANSFER);
            break;
        case MAIN_MENU:
            emit signalBtnBackToMainMenuClicked();
            break;
        default:
            throw AbsentNavigationDestination(&"TransactionWindow navigate " [ destination]);
    }
}

// TransactionPageLogic
TransactionWindow::TransactionPageLogic::TransactionPageLogic(Navigatable& navigatable) :
        _navigatable(navigatable) {}

void TransactionWindow::TransactionPageLogic::onBtn0Clicked() {
    _navigatable.navigate(REPLENISH);
}

void TransactionWindow::TransactionPageLogic::onBtn1Clicked() {
    _navigatable.navigate(WITHDRAW);
}

void TransactionWindow::TransactionPageLogic::onBtn2Clicked() {
    _navigatable.navigate(TRANSFER);
}

void TransactionWindow::TransactionPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(MAIN_MENU);
}

// ReplenishPageLogic
TransactionWindow::ReplenishPageLogic::ReplenishPageLogic(Navigatable& navigatable) :
        _navigatable(navigatable) {}

void TransactionWindow::ReplenishPageLogic::onBtnEnterClicked() {
    _navigatable.navigate(TRANSACTIONS);
}

void TransactionWindow::ReplenishPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(TRANSACTIONS);
}

// WithdrawPageLogic
TransactionWindow::WithdrawPageLogic::WithdrawPageLogic(Navigatable& navigatable) :
        _navigatable(navigatable) {}

void TransactionWindow::WithdrawPageLogic::onBtnEnterClicked() {
    _navigatable.navigate(TRANSACTIONS);
}

void TransactionWindow::WithdrawPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(TRANSACTIONS);
}

// TransferPageLogic
TransactionWindow::TransferPageLogic::TransferPageLogic(Navigatable& navigatable) :
        _navigatable(navigatable) {}

void TransactionWindow::TransferPageLogic::onBtnEnterClicked() {
    _navigatable.navigate(TRANSACTIONS);
}

void TransactionWindow::TransferPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(TRANSACTIONS);
}
