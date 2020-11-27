//
// Created by Iron Tony on 20/10/2020.
//

#include <QtWidgets/QMessageBox>
#include <utility>
#include <views/exceptions/AbsentNavigationDestination.h>
#include <views/validator/Validators.h>
#include "DepositWindow.h"
#include "gui/ui_depositwindow.h"
#include "Windows.h"
#include "commands/IncludeAllCommands.h"

DepositWindow::DepositWindow(OperationManager& operationManager, QWidget* parent) :
        QWidget(parent), _ui(new Ui::DepositWindow),
        _operationManager(operationManager),
        _messageDisplay(*this),
        _depositPageLogic(*this),
        _openDepositPageLogic(*this),
        _myDepositsPageLogic(*this) {
    _ui->setupUi(this);

    _ui->editMyDepositsReplenish->setValidator(new QRegularExpressionValidator(
            QRegularExpression(amountRegex), this));

    _ui->widgetOpenDepositDeposit->setReadOnly(false);
    _ui->widgetMyDepositsDeposit->setReadOnly(true);

    setupCommands();
}

DepositWindow::~DepositWindow() {
    delete _ui;
}

void DepositWindow::onListDepositsItemClicked(QListWidgetItem* item) {
    int index = _ui->listDeposits->row(item);
    _selectedDeposit = _deposits[index];
    _ui->widgetMyDepositsDeposit->setup(*_selectedDeposit);
    _ui->stackedWidget->setCurrentIndex(3);
}

void DepositWindow::navigate(int destination) {
    switch (destination) {
        case DEPOSIT_MENU:
            _ui->stackedWidget->setCurrentIndex(0);
            _logicSettable->setLogic(&_depositPageLogic);
            break;
        case OPEN_DEPOSIT:
            _ui->widgetOpenDepositDeposit->clear();
            _ui->stackedWidget->setCurrentIndex(1);
            _logicSettable->setLogic(&_openDepositPageLogic);
            break;
        case MY_DEPOSITS:
            setupListDeposits();
            _ui->editMyDepositsReplenish->setText("");
            _ui->stackedWidget->setCurrentIndex(2);
            _logicSettable->setLogic(&_myDepositsPageLogic);
            break;
        case MAIN_MENU:
            emit signalBtnBackToMainMenuClicked();
            break;
        default:
            throw AbsentNavigationDestination(&"DepositWindow navigate "[destination]);
    }
}

void DepositWindow::setupCommands() {
    std::shared_ptr<Command> openDepositCommand(new OpenDepositCommand(
            *this, _operationManager, *_ui->widgetOpenDepositDeposit, _messageDisplay));
    _openDepositPageLogic.setEnterCommand(openDepositCommand);

    std::shared_ptr<Command> replenishDepositCommand(new ReplenishDepositCommand(
            _selectedDeposit, _operationManager, *_ui->editMyDepositsReplenish, _messageDisplay));
    _myDepositsPageLogic.setEnterCommand(replenishDepositCommand);

    std::shared_ptr<Command> cancelDepositCommand(new CancelDepositCommand(
            *this, _selectedDeposit, _operationManager, _messageDisplay));
    _myDepositsPageLogic.setClearCommand(cancelDepositCommand);
}

void DepositWindow::setupListDeposits() {
    _ui->listDeposits->clear();
    _deposits = _operationManager.getAllDeposits();

    for (auto& deposit : _deposits) {
        new QListWidgetItem(deposit->name(), _ui->listDeposits);
    }

    connect(_ui->listDeposits, &QListWidget::itemClicked,
            this, &DepositWindow::onListDepositsItemClicked);
}

void DepositWindow::setController(ControllerLogicSettable* logicSettable) {
    _logicSettable = logicSettable;
}

void DepositWindow::setLogicActive() {
    _logicSettable->setLogic(&_depositPageLogic);
}

// DepositPageLogic
DepositWindow::DepositPageLogic::DepositPageLogic(Navigatable& navigatable) :
        _navigatable(navigatable) {}

void DepositWindow::DepositPageLogic::onBtn0Clicked() {
    _navigatable.navigate(OPEN_DEPOSIT);
}

void DepositWindow::DepositPageLogic::onBtn1Clicked() {
    _navigatable.navigate(MY_DEPOSITS);
}

void DepositWindow::DepositPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(MAIN_MENU);
}

// OpenDepositPageLogic
DepositWindow::OpenDepositPageLogic::OpenDepositPageLogic(Navigatable& navigatable) :
        _navigatable(navigatable) {}

void DepositWindow::OpenDepositPageLogic::onBtnEnterClicked() {
    _enterCommand->execute();
}

void DepositWindow::OpenDepositPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(DEPOSIT_MENU);
}

void DepositWindow::OpenDepositPageLogic::setEnterCommand(std::shared_ptr<Command> command) {
    _enterCommand = std::move(command);
}

// MyDepositsPageLogic
DepositWindow::MyDepositsPageLogic::MyDepositsPageLogic(Navigatable& navigatable) :
        _navigatable(navigatable) {}

void DepositWindow::MyDepositsPageLogic::onBtnEnterClicked() {
    _enterCommand->execute();
}

void DepositWindow::MyDepositsPageLogic::onBtnClearClicked() {
    _clearCommand->execute();
}

void DepositWindow::MyDepositsPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(DEPOSIT_MENU);
}

void DepositWindow::MyDepositsPageLogic::setEnterCommand(std::shared_ptr<Command> command) {
    _enterCommand = std::move(command);
}

void DepositWindow::MyDepositsPageLogic::setClearCommand(std::shared_ptr<Command> command) {
    _clearCommand = std::move(command);
}
