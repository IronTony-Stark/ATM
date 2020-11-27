//
// Created by Iron Tony on 20/10/2020.
//

#include <QtWidgets/QMessageBox>
#include "PaymentWidget.h"
#include "gui/ui_paymentwidget.h"
#include "views/validator/Validators.h"

PaymentWidget::PaymentWidget(QWidget* parent) :
        QWidget(parent), _ui(new Ui::PaymentWidget) {
    _ui->setupUi(this);

    _ui->editName->setValidator(new QRegularExpressionValidator(
            QRegularExpression(objectNameRegex), this));
    _ui->editHowMuch->setValidator(new QRegularExpressionValidator(
            QRegularExpression(amountRegex), this));
    _ui->editToWhome->setValidator(new QRegularExpressionValidator(
            QRegularExpression(cardNumberRegex), this));
}

PaymentWidget::~PaymentWidget() {
    delete _ui;
}

std::tuple<QString, uint, QString, QDateTime> PaymentWidget::data() {
    QString name = _ui->editName->text();
    uint period = _ui->editHowMuch->text().toUInt();
    QString receiver = _ui->editToWhome->text();
    QDateTime when = _ui->editWhen->dateTime();

    return std::tuple<QString, uint, QString, QDateTime>(name, period, receiver, when);
}

bool PaymentWidget::validateInput() {
    QString message;
    if (!_ui->editName->hasAcceptableInput())
        message = "Payment's name is invalid";
    else if (!_ui->editHowMuch->hasAcceptableInput())
        message = "Amount is invalid";
    else if (!_ui->editToWhome->hasAcceptableInput())
        message = "Receiver's card number is invalid";

    if (!message.isEmpty()) {
        QMessageBox::critical(this, "ATM", message);
        return false;
    }

    return true;
}
