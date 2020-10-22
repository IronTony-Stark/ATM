//
// Created by Iron Tony on 20/10/2020.
//

// TODO edit check for ill-formed input
// TODO Fix Segmentation Fault due to passing LineEdit before setup(ui)

#include <QtWidgets/QMessageBox>
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
        _messageDisplay(*this),
        _transactionPageLogic(*this),
        _replenishPageLogic(*this, operationManager,
                            *_ui->editReplenishHowMuch),
        _withdrawPageLogic(*this, operationManager,
                           *_ui->editWithdrawHowMuch, _messageDisplay),
        _transferPageLogic(*this, operationManager, *_ui->editTransferHowMuch,
                           *_ui->editTransferToWhom, _messageDisplay) {
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
            throw AbsentNavigationDestination(&"TransactionWindow navigate "[destination]);
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
TransactionWindow::ReplenishPageLogic::ReplenishPageLogic(
        Navigatable& navigatable,
        OperationManager& operationManager,
        QLineEdit& editHowMuch) :
        _navigatable(navigatable),
        _operationManager(operationManager),
        _editHowMuch(editHowMuch) {}

void TransactionWindow::ReplenishPageLogic::onBtnEnterClicked() {
    QString amountStr = _editHowMuch.text();
    uint amount = _editHowMuch.text().toUInt();
    _operationManager.replenish(amount);
    _navigatable.navigate(TRANSACTIONS);
}

void TransactionWindow::ReplenishPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(TRANSACTIONS);
}

// WithdrawPageLogic
TransactionWindow::WithdrawPageLogic::WithdrawPageLogic(
        Navigatable& navigatable,
        OperationManager& operationManager,
        QLineEdit& editHowMuch,
        MessageDisplay& messageDisplay) :
        _navigatable(navigatable),
        _operationManager(operationManager),
        _editHowMuch(editHowMuch),
        _messageDisplay(messageDisplay) {}

void TransactionWindow::WithdrawPageLogic::onBtnEnterClicked() {
    uint amount = _editHowMuch.text().toUInt();
    try {
        _operationManager.withdraw(amount);
        _navigatable.navigate(TRANSACTIONS);
    } catch (const std::exception& e) {
        _messageDisplay.show(e.what());
    }
}

void TransactionWindow::WithdrawPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(TRANSACTIONS);
}

// TransferPageLogic
TransactionWindow::TransferPageLogic::TransferPageLogic(
        Navigatable& navigatable,
        OperationManager& operationManager,
        QLineEdit& editHowMuch,
        QLineEdit& editToWhom,
        MessageDisplay& messageDisplay) :
        _navigatable(navigatable),
        _operationManager(operationManager),
        _editHowMuch(editHowMuch),
        _editToWhom(editToWhom),
        _messageDisplay(messageDisplay) {}

void TransactionWindow::TransferPageLogic::onBtnEnterClicked() {
    QString to = _editToWhom.text();
    uint amount = _editHowMuch.text().toUInt();
    try {
        _operationManager.transfer(to, amount);
        _navigatable.navigate(TRANSACTIONS);
    } catch (const std::exception& e) {
        _messageDisplay.show(e.what());
    }
}

void TransactionWindow::TransferPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(TRANSACTIONS);
}
