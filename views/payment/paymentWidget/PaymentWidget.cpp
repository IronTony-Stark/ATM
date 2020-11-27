//
// Created by Iron Tony on 20/10/2020.
//

#include <QtWidgets/QMessageBox>
#include <QRegularExpressionValidator>
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
    _ui->editWhen->setValidator(new QIntValidator(
            1, 31, this));
}

PaymentWidget::~PaymentWidget() {
    delete _ui;
}

std::tuple<QString, uint, QString, uint> PaymentWidget::data() {
    QString name = _ui->editName->text();
    uint period = _ui->editHowMuch->text().toUInt();
    QString receiver = _ui->editToWhome->text();
    uint when = _ui->editWhen->text().toUInt();

    return std::tuple<QString, uint, QString, uint>(name, period, receiver, when);
}

void PaymentWidget::setup(const RegularPayment& payment) {
    _ui->editName->setText(payment.name());
    _ui->editHowMuch->setText(QString::number(static_cast<double>(payment.amount())));
    _ui->editToWhome->setText(payment.receiver());
    _ui->editWhen->setText(QString::number(payment.dayOfMonth()));
}

void PaymentWidget::setReadOnly(bool value) {
    _ui->editName->setReadOnly(value);
    _ui->editHowMuch->setReadOnly(value);
    _ui->editToWhome->setReadOnly(value);
    _ui->editWhen->setReadOnly(value);
}

void PaymentWidget::clear() {
    _ui->editName->setText("");
    _ui->editHowMuch->setText("");
    _ui->editToWhome->setText("");
    _ui->editWhen->setText("");
}

bool PaymentWidget::validateInput() {
    QString message;
    if (!_ui->editName->hasAcceptableInput())
        message = "Payment's name is invalid";
    else if (!_ui->editHowMuch->hasAcceptableInput())
        message = "Amount is invalid";
    else if (!_ui->editToWhome->hasAcceptableInput())
        message = "Receiver's card number is invalid";
    else if (!_ui->editWhen->hasAcceptableInput())
        message = "Day of month is invalid";

    if (!message.isEmpty()) {
        QMessageBox::critical(this, "ATM", message);
        return false;
    }

    return true;
}
