//
// Created by Iron Tony on 20/10/2020.
//

#include <logics/bank_fees/DepositConditions.h>
#include <QtCore/QDateTime>
#include "DepositWidget.h"
#include "gui/ui_depositwidget.h"

DepositWidget::DepositWidget(QWidget* parent) :
        QWidget(parent), _ui(new Ui::DepositWidget) {
    _ui->setupUi(this);

    const QHash<Month, Interest> options = DepositConditions::depositingOptions;
    for (auto it = options.begin(); it != options.end(); ++it) {
        _ui->comboPeriod->addItem(QString::number(it.key()));
    }
}

DepositWidget::~DepositWidget() {
    delete _ui;
}

std::tuple<QString, uint, uint, QDateTime, QDateTime, double> DepositWidget::data() {
    QString name = _ui->editName->text();
    uint amount = _ui->editSum->text().toUInt();
    uint period = _ui->comboPeriod->currentText().toUInt();
    QDateTime start = QDateTime::currentDateTime();
    QDateTime end = start.addMonths(period);
    uint percentage = _ui->labelPercentageValue->text().toUInt();

    return std::tuple<QString, uint, uint, QDateTime, QDateTime, double>(name, amount, period, start, end, percentage);
}
