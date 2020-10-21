//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_DEPOSITWIDGET_H
#define ATM_DEPOSITWIDGET_H

#include <QWidget>

namespace Ui {
    class DepositWidget;
}

class DepositWidget : public QWidget {
Q_OBJECT

public:
    explicit DepositWidget(QWidget* parent = nullptr);
    ~DepositWidget() override;

private:
    Ui::DepositWidget* _ui;
};

#endif // ATM_DEPOSITWIDGET_H
