//
// Created by Iron Tony on 20/10/2020.
//

#include "RegistrationWindow.h"
#include "gui/ui_registrationwindow.h"

RegistrationWindow::RegistrationWindow(QWidget* parent) :
        QWidget(parent), _ui(new Ui::RegistrationWindow) {
    _ui->setupUi(this);

    connect(_ui->btnCancel, &QPushButton::clicked,
            this, &RegistrationWindow::onBtnCancelClicked);
    connect(_ui->btnSubmit, &QPushButton::clicked,
            this, &RegistrationWindow::onBtnSubmitClicked);
    connect(_ui->btnTakeCard, &QPushButton::clicked,
            this, &RegistrationWindow::onBtnTakeCardClicked);
}

RegistrationWindow::~RegistrationWindow() {
    delete _ui;
}

void RegistrationWindow::onBtnCancelClicked() {
    emit signalBtnCancelClicked();
}

void RegistrationWindow::onBtnSubmitClicked() {
    _ui->stackedWidget->setCurrentIndex(1);
}

void RegistrationWindow::onBtnTakeCardClicked() {
    emit signalBtnCancelClicked();
    _ui->stackedWidget->setCurrentIndex(0);
}
