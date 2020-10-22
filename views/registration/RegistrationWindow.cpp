//
// Created by Iron Tony on 20/10/2020.
//

#include <QtWidgets/QMessageBox>
#include "RegistrationWindow.h"
#include "gui/ui_registrationwindow.h"

enum Windows {
    REGISTRATION,
    CARD
};

RegistrationWindow::RegistrationWindow(OperationManager& operationManager, QWidget* parent) :
        QWidget(parent), _ui(new Ui::RegistrationWindow),
        _operationManager(operationManager) {
    _ui->setupUi(this);
}

RegistrationWindow::~RegistrationWindow() {
    delete _ui;
}

void RegistrationWindow::setController(ControllerLogicSettable* logicSettable) {
    _logicSettable = logicSettable;
}

void RegistrationWindow::setLogicActive() {
    _logicSettable->setLogic(this);
}

void RegistrationWindow::onBtnEnterClicked() {
    if (state() != CARD) {
        QString name = _ui->editName->text();
        QString phone = _ui->editPhone->text();
        uint taxNumber = _ui->editTaxNumber->text().toUInt();
        QString cardType = _ui->comboCardType->currentText();
        try {
            ushort pin = _operationManager.registerCustomer(name, phone, taxNumber, cardType);
            _ui->labelPin->setText(QString::number(pin));
            _ui->stackedWidget->setCurrentIndex(CARD);
        } catch (const std::exception& e) {
            QMessageBox::critical(this, tr("ATM"), tr(e.what()));
        }
    }
}

void RegistrationWindow::onBtnCancelClicked() {
    if (state() != CARD) {
        emit signalBtnCancelClicked();
    }
}

void RegistrationWindow::onBtnCardClicked() {
    if (state() == CARD) {
        emit signalBtnCancelClicked();
        _ui->stackedWidget->setCurrentIndex(REGISTRATION);
    }
}

int RegistrationWindow::state() {
    return _ui->stackedWidget->currentIndex();
}
