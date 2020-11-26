//
// Created by Iron Tony on 20/10/2020.
//

#include <QtWidgets/QMessageBox>
#include <utility>
#include <views/exceptions/AbsentNavigationDestination.h>
#include "PaymentWindow.h"
#include "gui/ui_paymentwindow.h"
#include "Windows.h"
#include "commands/IncludeAllCommands.h"

PaymentWindow::PaymentWindow(OperationManager& operationManager, QWidget* parent) :
        QWidget(parent), _ui(new Ui::PaymentWindow),
        _operationManager(operationManager),
        _messageDisplay(*this),
        _paymentPageLogic(*this),
        _createPaymentPageLogic(*this),
        _myPaymentsPageLogic(*this) {
    _ui->setupUi(this);

    setupCommands();
}

PaymentWindow::~PaymentWindow() {
    delete _ui;
}

void PaymentWindow::setupListPayments() {
    _ui->listPayments->clear();
    _payments = _operationManager.getAllPayments();

    for (auto& payment : _payments) {
        new QListWidgetItem(payment->name(), _ui->listPayments);
    }

    connect(_ui->listPayments, &QListWidget::itemClicked,
            this, &PaymentWindow::onListPaymentsItemClicked);
}

void PaymentWindow::onListPaymentsItemClicked(QListWidgetItem* item) {
    int index = _ui->listPayments->row(item);
    _selectedPayment = _payments[index];
    _ui->stackedWidget->setCurrentIndex(3);
}

void PaymentWindow::navigate(int destination) {
    switch (destination) {
        case PAYMENT_MENU:
            _ui->stackedWidget->setCurrentIndex(0);
            _logicSettable->setLogic(&_paymentPageLogic);
            break;
        case CREATE_PAYMENT:
            _ui->stackedWidget->setCurrentIndex(1);
            _logicSettable->setLogic(&_createPaymentPageLogic);
            break;
        case MY_PAYMENTS:
            setupListPayments();
            _ui->stackedWidget->setCurrentIndex(2);
            _logicSettable->setLogic(&_myPaymentsPageLogic);
            break;
        case MAIN_MENU:
            emit signalBtnBackToMainMenuClicked();
            break;
        default:
            throw AbsentNavigationDestination(&"PaymentWindow navigate "[destination]);
    }
}

void PaymentWindow::setupCommands() {
    std::shared_ptr<Command> createPayment(new CreatePaymentCommand(
            *this, _operationManager, *_ui->widgetCreatePaymentPayment, _messageDisplay));
    _createPaymentPageLogic.setEnterCommand(createPayment);

    std::shared_ptr<Command> cancelPayment(new CancelPaymentCommand(
            _operationManager));
    _myPaymentsPageLogic.setClearCommand(cancelPayment);
}

void PaymentWindow::setController(ControllerLogicSettable* logicSettable) {
    _logicSettable = logicSettable;
}

void PaymentWindow::setLogicActive() {
    _logicSettable->setLogic(&_paymentPageLogic);
}

// PaymentPageLogic
PaymentWindow::PaymentPageLogic::PaymentPageLogic(Navigatable& navigatable) :
        _navigatable(navigatable) {}

void PaymentWindow::PaymentPageLogic::onBtn0Clicked() {
    _navigatable.navigate(CREATE_PAYMENT);
}

void PaymentWindow::PaymentPageLogic::onBtn1Clicked() {
    _navigatable.navigate(MY_PAYMENTS);
}

void PaymentWindow::PaymentPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(MAIN_MENU);
}

// CreatePaymentPageLogic
PaymentWindow::CreatePaymentPageLogic::CreatePaymentPageLogic(Navigatable& navigatable) :
        _navigatable(navigatable) {}

void PaymentWindow::CreatePaymentPageLogic::onBtnEnterClicked() {
    _enterCommand->execute();
}

void PaymentWindow::CreatePaymentPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(PAYMENT_MENU);
}

void PaymentWindow::CreatePaymentPageLogic::setEnterCommand(std::shared_ptr<Command> command) {
    _enterCommand = std::move(command);
}

// MyPaymentsPageLogic
PaymentWindow::MyPaymentsPageLogic::MyPaymentsPageLogic(Navigatable& navigatable) :
        _navigatable(navigatable) {}

void PaymentWindow::MyPaymentsPageLogic::onBtnClearClicked() {
    _clearCommand->execute();
}

void PaymentWindow::MyPaymentsPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(PAYMENT_MENU);
}

void PaymentWindow::MyPaymentsPageLogic::setClearCommand(std::shared_ptr<Command> command) {
    _clearCommand = std::move(command);
}
