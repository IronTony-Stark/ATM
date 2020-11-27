//
// Created by Iron Tony on 20/10/2020.
//

#include <logics/managers/CustomerDataManager.h>
#include <logics/auth/Registrator.h>
#include <QtWidgets/QMessageBox>
#include "RegistrationWindow.h"
#include "gui/ui_registrationwindow.h"
#include "views/validator/Validators.h"

enum Windows {
    REGISTRATION,
    CARD
};

RegistrationWindow::RegistrationWindow(OperationManager& operationManager, QWidget* parent) :
        QWidget(parent), _ui(new Ui::RegistrationWindow),
        _operationManager(operationManager) {
    _ui->setupUi(this);

    _ui->editName->setValidator(new QRegularExpressionValidator(
            QRegularExpression(userNameRegex), this));
    _ui->editPhone->setValidator(new QRegularExpressionValidator(
            QRegularExpression(phoneRegex), this));
    _ui->editTaxNumber->setValidator(new QRegularExpressionValidator(
            QRegularExpression(taxRegex), this));
    _ui->editIncome->setValidator(new QRegularExpressionValidator(
            QRegularExpression(incomeRegex), this));

    for (const auto& it : ABankFee::CARD_TYPES)
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
        if (!validateInput())
            return;

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

bool RegistrationWindow::validateInput() {
    QString message;
    if (!_ui->editName->hasAcceptableInput())
        message = "Name is invalid";
    else if (!_ui->editPhone->hasAcceptableInput())
        message = "Phone number is invalid";
    else if (!_ui->editTaxNumber->hasAcceptableInput())
        message = "Tax number is invalid";
    else if (!_ui->editIncome->hasAcceptableInput())
        message = "Income is invalid";

    if (!message.isEmpty()) {
        QMessageBox::critical(this, "ATM", message);
        return false;
    }

    return true;
}
