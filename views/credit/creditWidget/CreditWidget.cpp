//
// Created by Iron Tony on 20/10/2020.
//

#include <QDateTime>
#include <logics/bank_fees/CreditConditions.h>
#include <logics/bank_services/Credit.h>
#include "CreditWidget.h"
#include "gui/ui_creditwidget.h"

static const char* const dateFormat = "dd.MM.yyyy";

CreditWidget::CreditWidget(QWidget* parent) :
        QWidget(parent), _ui(new Ui::CreditWidget) {
    _ui->setupUi(this);

    // Fills comboPeriod with available periods sorted asc
    const QHash<Month, Interest>& options = CreditConditions::creditingOptions;
    auto* periods = new double[options.size()];
    int i = 0;
    for (auto it = options.begin(); it != options.end(); ++it)
        periods[i++] = it.key();
    std::sort(periods, periods + options.size());
    for (int j = 0; j < options.size(); ++j)
        _ui->comboPeriod->addItem(QString::number(periods[j]));
    delete[] periods;

    connect(_ui->comboPeriod, qOverload<int>(&QComboBox::currentIndexChanged),
            this, &CreditWidget::onPeriodChanged);
}

CreditWidget::~CreditWidget() {
    delete _ui;
}

std::tuple<QString, uint, uint, uint, QDateTime, QDateTime> CreditWidget::data() {
    QString name = _ui->editName->text();
    uint amount = _ui->editSum->text().toUInt();
    uint period = _ui->comboPeriod->currentText().toUInt();
    uint interest = CreditConditions::creditingOptions.value(period);
    QDateTime start = QDateTime::currentDateTime();
    QDateTime end = start.addMonths(period);

    return std::tuple<QString, uint, uint, uint, QDateTime, QDateTime>(name, amount, period, interest, start, end);
}

void CreditWidget::setup(const Credit& credit) {
    _ui->editName->setText(credit.name());
    _ui->editSum->setText(QString::number(static_cast<double>(credit.creditBody())));

    double interest = credit.interest();
    int period = CreditConditions::creditingOptions.key(interest);
    int index = _ui->comboPeriod->findText(QString::number(period));
    _ui->comboPeriod->setCurrentIndex(index);

    _ui->labelStartValue->setText(credit.dateTaken().toString(dateFormat));
    _ui->labelEndValue->setText(credit.dateTaken().addMonths(period).toString(dateFormat));
}

void CreditWidget::setReadOnly(bool value) {
    _ui->editName->setReadOnly(value);
    _ui->editSum->setReadOnly(value);
    _ui->comboPeriod->setEnabled(!value);
}

void CreditWidget::clear() {
    _ui->editName->setText("");
    _ui->editSum->setText("");
    _ui->comboPeriod->setCurrentIndex(0);
    _ui->labelStartValue->setText(QDate::currentDate().toString(dateFormat));
    int period = _ui->comboPeriod->currentText().toUInt();
    _ui->labelEndValue->setText(QDate::currentDate().addMonths(period).toString(dateFormat));
}

void CreditWidget::onPeriodChanged() {
    int period = _ui->comboPeriod->currentText().toUInt();
    _ui->labelEndValue->setText(QDate::currentDate().addMonths(period).toString(dateFormat));
}

