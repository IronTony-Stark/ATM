//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_DEPOSITWIDGET_H
#define ATM_DEPOSITWIDGET_H

#include <QWidget>
#include <logics/bank_services/Deposit.h>

namespace Ui {
    class DepositWidget;
}

class DepositWidget : public QWidget {
Q_OBJECT

public:
    explicit DepositWidget(QWidget* parent = nullptr);
    ~DepositWidget() override;

    std::tuple<QString, uint, uint, QDateTime, QDateTime, double> data();
    void setup(const Deposit&);
    void setReadOnly(bool);
    void clear();
    bool validateInput();

private slots:
    void onPeriodChanged();

private:
    Ui::DepositWidget* _ui;
};

#endif // ATM_DEPOSITWIDGET_H
