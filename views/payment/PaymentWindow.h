//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_PAYMENTWINDOW_H
#define ATM_PAYMENTWINDOW_H

#include <QWidget>
#include <QtWidgets/QListWidgetItem>
#include <logics/bank_services/RegularPayment.h>
#include "views/main/controller/ControllerLogicSettable.h"
#include "logics/managers/OperationManager.h"

namespace Ui {
    class PaymentWindow;
}

class PaymentWindow : public QWidget, public ControllerLogic {
Q_OBJECT

public:
    explicit PaymentWindow(OperationManager& operationManager, QWidget* parent = nullptr);
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
    ControllerLogicSettable* _logicSettable = nullptr;
    OperationManager& _operationManager;

    RegularPayment* _payments = nullptr;
    int _paymentsLen = 0;
    int _selectedPayment = -1;

    void setupListPayments();
    void setupPaymentItem(RegularPayment&);
};

#endif // ATM_PAYMENTWINDOW_H
