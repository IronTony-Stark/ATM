//
// Created by Iron Tony on 20/10/2020.
//

#include <logics/bank_fees/DepositConditions.h>
#include <QtCore/QDateTime>
#include <QtWidgets/QMessageBox>
#include "DepositWidget.h"
#include "gui/ui_depositwidget.h"
#include "views/validator/Validators.h"

static const char* const dateFormat = "dd.MM.yyyy";

DepositWidget::DepositWidget(QWidget* parent) :
        QWidget(parent), _ui(new Ui::DepositWidget) {
    _ui->setupUi(this);

    _ui->editName->setValidator(new QRegularExpressionValidator(
            QRegularExpression(objectNameRegex), this));
    _ui->editSum->setValidator(new QRegularExpressionValidator(
            QRegularExpression(amountRegex), this));

    // Fills comboPeriod with available periods sorted asc
    const QHash<Month, Interest>& options = DepositConditions::depositingOptions;
    auto* periods = new double[options.size()];
    int i = 0;
    for (auto it = options.begin(); it != options.end(); ++it)
        periods[i++] = it.key();
    std::sort(periods, periods + options.size());
    for (int j = 0; j < options.size(); ++j)
        _ui->comboPeriod->addItem(QString::number(periods[j]));
    delete[] periods;

    connect(_ui->comboPeriod, qOverload<int>(&QComboBox::currentIndexChanged),
            this, &DepositWidget::onPeriodChanged);
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
    uint interest = _ui->labelInterestValue->text().toUInt();

    return std::tuple<QString, uint, uint, QDateTime, QDateTime, double>(name, amount, period, start, end, interest);
}

void DepositWidget::setup(const Deposit& deposit) {
    _ui->editName->setText(deposit.name());
    _ui->editSum->setText(QString::number(static_cast<double>(deposit.sum())));

    double interest = deposit.interest();
    int period = DepositConditions::depositingOptions.key(interest);
    int index = _ui->comboPeriod->findText(QString::number(period));
    _ui->comboPeriod->setCurrentIndex(index);

    _ui->labelStartValue->setText(deposit.startDate().toString(dateFormat));
    _ui->labelEndValue->setText(deposit.startDate().addMonths(period).toString(dateFormat));
}

void DepositWidget::setReadOnly(bool value) {
    _ui->editName->setReadOnly(value);
    _ui->editSum->setReadOnly(value);
    _ui->comboPeriod->setEnabled(!value);
}

void DepositWidget::clear() {
    _ui->editName->setText("");
    _ui->editSum->setText("");
    _ui->comboPeriod->setCurrentIndex(0);
    _ui->labelStartValue->setText(QDate::currentDate().toString(dateFormat));
    onPeriodChanged();
}

void DepositWidget::onPeriodChanged() {
    int period = _ui->comboPeriod->currentText().toUInt();
    _ui->labelEndValue->setText(QDate::currentDate().addMonths(period).toString(dateFormat));
    _ui->labelInterestValue->setText(QString::number(DepositConditions::depositingOptions.value(period)));
}

bool DepositWidget::validateInput() {
    QString message;
    if (!_ui->editName->hasAcceptableInput())
        message = "Deposit's name is invalid";
    else if (!_ui->editSum->hasAcceptableInput())
        message = "Amount is invalid";

    if (!message.isEmpty()) {
        QMessageBox::critical(this, "ATM", message);
        return false;
    }

    return true;
}
