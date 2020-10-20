//
// Created by Iron Tony on 20/10/2020.
//

#include "RegistrationWindow.h"
#include "gui/ui_registrationwindow.h"

RegistrationWindow::RegistrationWindow(QWidget* parent) :
        QWidget(parent),
        _ui(new Ui::RegistrationWindow) {
    _ui->setupUi(this);

    connect(_ui->btnCancel, &QPushButton::clicked, this, &RegistrationWindow::onBtnCancelClicked);
}

RegistrationWindow::~RegistrationWindow() {
    delete _ui;
}

void RegistrationWindow::onBtnCancelClicked() {
    emit signalBtnCancelClicked();
}
