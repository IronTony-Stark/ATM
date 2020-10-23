//
// Created by Iron Tony on 20/10/2020.
//

#include <QDateTime>
#include "CreditWidget.h"
#include "gui/ui_creditwidget.h"

CreditWidget::CreditWidget(QWidget* parent) :
        QWidget(parent), _ui(new Ui::CreditWidget) {
    _ui->setupUi(this);
}

CreditWidget::~CreditWidget() {
    delete _ui;
}

std::tuple<QString, uint, uint, QDateTime, QDateTime> CreditWidget::data() {
    QString name = _ui->editName->text();
    uint amount = _ui->editSum->text().toUInt();
    uint period = _ui->editPeriod->text().toUInt();
    QDateTime start = QDateTime::currentDateTime();
    QDateTime end = start.addMonths(period);
    return std::tuple<QString, uint, uint, QDateTime, QDateTime>(name, amount, period, start, end);
}
