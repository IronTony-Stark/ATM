//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_DEPOSITWINDOW_H
#define ATM_DEPOSITWINDOW_H

#include <QWidget>

namespace Ui {
    class DepositWindow;
}

class DepositWindow : public QWidget {
Q_OBJECT

public:
    explicit DepositWindow(QWidget* parent = nullptr);
    ~DepositWindow() override;

private:
    Ui::DepositWindow* _ui;
};

#endif // ATM_DEPOSITWINDOW_H
