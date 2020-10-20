//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_MAINMENUWINDOW_H
#define ATM_MAINMENUWINDOW_H

#include <QWidget>
#include "views/transaction/TransactionWindow.h"
#include "views/credit/CreditWindow.h"
#include "views/deposit/DepositWindow.h"
#include "views/payment/PaymentWindow.h"

namespace Ui {
    class MainMenuWindow;
}

class MainMenuWindow : public QWidget {
Q_OBJECT

public:
    explicit MainMenuWindow(QWidget* parent = nullptr);
    ~MainMenuWindow() override;

signals:
    void signalBtnFinishClicked();

private slots:
    void onBtnFinishClicked();

private:
    Ui::MainMenuWindow* _ui;
    TransactionWindow _transactionWindow;
    CreditWindow _creditWindow;
    DepositWindow _depositWindow;
    PaymentWindow _paymentWindow;
};

#endif // ATM_MAINMENUWINDOW_H
