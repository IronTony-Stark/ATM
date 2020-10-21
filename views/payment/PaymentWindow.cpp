//
// Created by Iron Tony on 20/10/2020.
//

#include "PaymentWindow.h"
#include "gui/ui_paymentwindow.h"

PaymentWindow::PaymentWindow(QWidget* parent) :
        QWidget(parent), _ui(new Ui::PaymentWindow) {
    _ui->setupUi(this);

    connect(_ui->btnBackToMainMenu, &QPushButton::clicked,
            this, &PaymentWindow::onBtnBackToMainMenuClicked);
}

PaymentWindow::~PaymentWindow() {
    delete _ui;
}

void PaymentWindow::onBtnBackToMainMenuClicked() {
    emit signalBtnBackToMainMenuClicked();
}
