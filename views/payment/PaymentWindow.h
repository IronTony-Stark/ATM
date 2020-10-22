//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_PAYMENTWINDOW_H
#define ATM_PAYMENTWINDOW_H

#include <QWidget>
#include <QtWidgets/QListWidgetItem>
#include "views/main/controller/ControllerLogicSettable.h"

namespace Ui {
    class PaymentWindow;
}

class PaymentWindow : public QWidget, public ControllerLogic {
Q_OBJECT

public:
    explicit PaymentWindow(QWidget* parent = nullptr);
    ~PaymentWindow() override;

    void setController(ControllerLogicSettable* logicSettable);
    void setLogicActive();

signals:
    void signalBtnBackToMainMenuClicked();

private slots:
    void onBtnCreatePayment();
    void onBtnMyPayments();

    void onBtnCreatePaymentCreate();
    void onBtnMyPaymentCancelPayment();

    void onListPaymentsItemClicked(QListWidgetItem*);

    void onBtnBackToMyPayments();
    void onBtnBackToPaymentMenu();
    void onBtnBackToMainMenuClicked();

private:
    Ui::PaymentWindow* _ui;
    ControllerLogicSettable* _logicSettable;

    void setupListPayments();
};

#endif // ATM_PAYMENTWINDOW_H
