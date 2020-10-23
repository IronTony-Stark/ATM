//
// Created by Iron Tony on 20/10/2020.
//

#include <QDateTime>
#include <logics/bank_fees/CreditConditions.h>
#include "CreditWidget.h"
#include "gui/ui_creditwidget.h"

CreditWidget::CreditWidget(QWidget* parent) :
        QWidget(parent), _ui(new Ui::CreditWidget) {
    _ui->setupUi(this);

    const QHash<Month, Interest> options = CreditConditions::creditingOptions;
    for (auto it = options.begin(); it != options.end(); ++it) {
        _ui->comboPeriod->addItem(QString::number(it.key()));
    }
}

CreditWidget::~CreditWidget() {
    delete _ui;
}

std::tuple<QString, uint, uint, uint, QDateTime, QDateTime> CreditWidget::data() {
    QString name = _ui->editName->text();
    uint amount = _ui->editSum->text().toUInt();
    uint period = _ui->comboPeriod->currentText().toUInt();
    uint payment = CreditConditions::creditingOptions.value(period);
    QDateTime start = QDateTime::currentDateTime();
    QDateTime end = start.addMonths(period);

    return std::tuple<QString, uint, uint, uint, QDateTime, QDateTime>(name, amount, period, payment, start, end);
}
