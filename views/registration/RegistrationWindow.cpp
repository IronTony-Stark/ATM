//
// Created by Iron Tony on 20/10/2020.
//

#include <logics/managers/CustomerDataManager.h>
#include <logics/auth/Registrator.h>
#include <QtWidgets/QMessageBox>
#include "RegistrationWindow.h"
#include "gui/ui_registrationwindow.h"
#include <QDebug>

enum Windows {
    REGISTRATION,
    CARD
};

RegistrationWindow::RegistrationWindow(OperationManager& operationManager, QWidget* parent) :
        QWidget(parent), _ui(new Ui::RegistrationWindow),
        _operationManager(operationManager) {
    _ui->setupUi(this);

    // TODO validate data

    for (const auto & it : ABankFee::CARD_TYPES)
        _ui->comboCardType->addItem(QString::fromStdString(it.first));
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
        QString taxNumber = _ui->editTaxNumber->text();
        uint income = _ui->editIncome->text().toUInt();
        ABankFee::CardType cardType = getCardType();
        try {
            QString pin = _operationManager.registerCustomer(CustomerVerificationData(
                    name, taxNumber, income, phone, cardType));
            _ui->labelPin->setText(pin);
            _ui->stackedWidget->setCurrentIndex(CARD);
            clear();
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

void RegistrationWindow::clear() {
    _ui->editName->setText("");
    _ui->editPhone->setText("");
    _ui->editTaxNumber->setText("");
    _ui->editIncome->setText("");
    _ui->comboCardType->setCurrentIndex(0);
}

ABankFee::CardType RegistrationWindow::getCardType() {
    auto it = ABankFee::CARD_TYPES.find(_ui->comboCardType->currentText().toStdString());
    if (it != ABankFee::CARD_TYPES.end())
        return it->second;
    else
        throw std::logic_error("getCardType Card Not Found");
}
