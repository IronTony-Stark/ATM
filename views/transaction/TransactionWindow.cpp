//
// Created by Iron Tony on 20/10/2020.
//

// TODO edit check for ill-formed input
// TODO Fix Segmentation Fault due to passing LineEdit before setup(ui)

#include <QtWidgets/QMessageBox>
#include <utility>
#include "TransactionWindow.h"
#include "gui/ui_transactionwindow.h"
#include "views/exceptions/AbsentNavigationDestination.h"
#include "views/transaction/Windows.h"
#include "commands/IncludeAllCommands.h"

TransactionWindow::TransactionWindow(OperationManager& operationManager, QWidget* parent) :
        QWidget(parent), _ui(new Ui::TransactionWindow),
        _messageDisplay(*this),
        _transactionPageLogic(*this) {
    _ui->setupUi(this);
    setupCommands(operationManager);
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
void TransactionWindow::ReplenishPageLogic::onBtnEnterClicked() {
    assert(_enterCommand != nullptr);
    _enterCommand->execute();
}

void TransactionWindow::ReplenishPageLogic::onBtnCancelClicked() {
    assert(_cancelCommand != nullptr);
    _cancelCommand->execute();
}

void TransactionWindow::ReplenishPageLogic::setEnterCommand(std::shared_ptr<Command> enterCommand) {
    _enterCommand = std::move(enterCommand);
}

void TransactionWindow::ReplenishPageLogic::setCancelCommand(std::shared_ptr<Command> cancelCommand) {
    _cancelCommand = std::move(cancelCommand);
}

// WithdrawPageLogic
void TransactionWindow::WithdrawPageLogic::onBtnEnterClicked() {
    assert(_enterCommand != nullptr);
    _enterCommand->execute();
}

void TransactionWindow::WithdrawPageLogic::onBtnCancelClicked() {
    assert(_cancelCommand != nullptr);
    _cancelCommand->execute();
}

void TransactionWindow::WithdrawPageLogic::setEnterCommand(std::shared_ptr<Command> enterCommand) {
    _enterCommand = std::move(enterCommand);
}

void TransactionWindow::WithdrawPageLogic::setCancelCommand(std::shared_ptr<Command> cancelCommand) {
    _cancelCommand = std::move(cancelCommand);
}

// TransferPageLogic
void TransactionWindow::TransferPageLogic::onBtnEnterClicked() {
    assert(_enterCommand != nullptr);
    _enterCommand->execute();
}

void TransactionWindow::TransferPageLogic::onBtnCancelClicked() {
    assert(_cancelCommand != nullptr);
    _cancelCommand->execute();
}

void TransactionWindow::TransferPageLogic::setEnterCommand(std::shared_ptr<Command> enterCommand) {
    _enterCommand = std::move(enterCommand);
}

void TransactionWindow::TransferPageLogic::setCancelCommand(std::shared_ptr<Command> cancelCommand) {
    _cancelCommand = std::move(cancelCommand);
}

void TransactionWindow::setupCommands(OperationManager& operationManager) {
    std::shared_ptr<Command> btnNavigateCommand(new BtnNavigateTransactionsCommand(*this));
    _replenishPageLogic.setCancelCommand(btnNavigateCommand);
    _withdrawPageLogic.setCancelCommand(btnNavigateCommand);
    _transferPageLogic.setCancelCommand(btnNavigateCommand);

    std::shared_ptr<Command> btnReplenishCommand(new BtnReplenishCommand(
            *this, operationManager, *_ui->editReplenishHowMuch));
    _replenishPageLogic.setEnterCommand(btnReplenishCommand);

    std::shared_ptr<Command> btnWithdrawCommand(new BtnWithdrawCommand(
            *this, operationManager, *_ui->editWithdrawHowMuch, _messageDisplay));
    _withdrawPageLogic.setEnterCommand(btnWithdrawCommand);

    std::shared_ptr<Command> btnTransferCommand(new BtnTransferCommand(
            *this, operationManager, *_ui->editWithdrawHowMuch, *_ui->editTransferToWhom, _messageDisplay));
    _transferPageLogic.setEnterCommand(btnTransferCommand);
}
