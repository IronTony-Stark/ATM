//
// Created by Iron Tony on 20/10/2020.
//

#include <QtWidgets/QMessageBox>
#include "PaymentWindow.h"
#include "gui/ui_paymentwindow.h"

// TODO setupPayments should be called each time a user navigates to MyPaymentsWindow
PaymentWindow::PaymentWindow(OperationManager& operationManager, QWidget* parent) :
        QWidget(parent), _ui(new Ui::PaymentWindow),
        _operationManager(operationManager) {
    _ui->setupUi(this);

    connect(_ui->btnCreatePayment, &QPushButton::clicked,
            this, &PaymentWindow::onBtnCreatePayment);
    connect(_ui->btnMyPayments, &QPushButton::clicked,
            this, &PaymentWindow::onBtnMyPayments);

    connect(_ui->btnCreatePaymentCreate, &QPushButton::clicked,
            this, &PaymentWindow::onBtnCreatePaymentCreate);
    connect(_ui->btnMyPaymentCancelPayment, &QPushButton::clicked,
            this, &PaymentWindow::onBtnMyPaymentCancelPayment);

    connect(_ui->btnCreatePaymentCancel, &QPushButton::clicked,
            this, &PaymentWindow::onBtnBackToPaymentMenu);
    connect(_ui->btnMyPaymentsBack, &QPushButton::clicked,
            this, &PaymentWindow::onBtnBackToPaymentMenu);
    connect(_ui->btnMyPaymentBack, &QPushButton::clicked,
            this, &PaymentWindow::onBtnBackToMyPayments);

    connect(_ui->btnBackToMainMenu, &QPushButton::clicked,
            this, &PaymentWindow::onBtnBackToMainMenuClicked);

    setupListPayments();
}

PaymentWindow::~PaymentWindow() {
    delete _ui;
}

void PaymentWindow::onBtnCreatePayment() {
    _ui->stackedWidget->setCurrentIndex(1);
}

void PaymentWindow::onBtnMyPayments() {
    _ui->stackedWidget->setCurrentIndex(2);
}

void PaymentWindow::onBtnCreatePaymentCreate() {
    QString name;
    uint amount;
    QString receiver;
    QDateTime when;
    std::tie(name, amount, receiver, when) = _ui->widgetCreatePaymentPayment->data();
    try {
        _operationManager.setPayment(name, amount, receiver, when);
        _ui->stackedWidget->setCurrentIndex(0);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "ATM", e.what());
    }
}

void PaymentWindow::onBtnBackToPaymentMenu() {
    _ui->stackedWidget->setCurrentIndex(0);
}

void PaymentWindow::onBtnBackToMainMenuClicked() {
    emit signalBtnBackToMainMenuClicked();
}

void PaymentWindow::setupListPayments() {
    std::pair<RegularPayment*, int> payments = _operationManager.getAllPayments();
    delete[] _payments;
    _payments = payments.first;
    _paymentsLen = payments.second;

    for (int i = 0; i < _paymentsLen; ++i) {
        new QListWidgetItem(QString::number(i), _ui->listPayments);
    }

    connect(_ui->listPayments, &QListWidget::itemClicked,
            this, &PaymentWindow::onListPaymentsItemClicked);
}

void PaymentWindow::onListPaymentsItemClicked(QListWidgetItem* item) {
    int index = _ui->listPayments->row(item);
    _selectedPayment = index;
    RegularPayment& payment = _payments[index];
    setupPaymentItem(payment);
    _ui->stackedWidget->setCurrentIndex(3);
}

void PaymentWindow::onBtnBackToMyPayments() {
    _ui->stackedWidget->setCurrentIndex(2);
}

// TODO pass payment id
void PaymentWindow::onBtnMyPaymentCancelPayment() {
    _operationManager.cancelPayment(0);
    _ui->stackedWidget->setCurrentIndex(2);
}

void PaymentWindow::setController(ControllerLogicSettable* logicSettable) {
    _logicSettable = logicSettable;
}

void PaymentWindow::setLogicActive() {
    _logicSettable->setLogic(this);
}

void PaymentWindow::setupPaymentItem(RegularPayment&) {

}
