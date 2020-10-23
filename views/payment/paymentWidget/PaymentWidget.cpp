//
// Created by Iron Tony on 20/10/2020.
//

#include "PaymentWidget.h"
#include "gui/ui_paymentwidget.h"

PaymentWidget::PaymentWidget(QWidget* parent) :
        QWidget(parent), _ui(new Ui::PaymentWidget) {
    _ui->setupUi(this);
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
