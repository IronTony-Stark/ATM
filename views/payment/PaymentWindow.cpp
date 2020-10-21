//
// Created by Iron Tony on 20/10/2020.
//

#include "PaymentWindow.h"
#include "gui/ui_paymentwindow.h"

PaymentWindow::PaymentWindow(QWidget* parent) :
        QWidget(parent), _ui(new Ui::PaymentWindow) {
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
    _ui->stackedWidget->setCurrentIndex(0);
}

void PaymentWindow::onBtnBackToPaymentMenu() {
    _ui->stackedWidget->setCurrentIndex(0);
}

void PaymentWindow::onBtnBackToMainMenuClicked() {
    emit signalBtnBackToMainMenuClicked();
}

void PaymentWindow::setupListPayments() {
    new QListWidgetItem("Test 1", _ui->listPayments);
    new QListWidgetItem("Test 2", _ui->listPayments);
    new QListWidgetItem("Test 3", _ui->listPayments);

    connect(_ui->listPayments, &QListWidget::itemClicked,
            this, &PaymentWindow::onListPaymentsItemClicked);
}

void PaymentWindow::onListPaymentsItemClicked(QListWidgetItem*) {
    _ui->stackedWidget->setCurrentIndex(3);
}

void PaymentWindow::onBtnBackToMyPayments() {
    _ui->stackedWidget->setCurrentIndex(2);
}

void PaymentWindow::onBtnMyPaymentCancelPayment() {
    _ui->stackedWidget->setCurrentIndex(2);
}
