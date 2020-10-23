//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_PAYMENTWINDOW_H
#define ATM_PAYMENTWINDOW_H

#include <QWidget>
#include <QtWidgets/QListWidgetItem>
#include <logics/bank_services/RegularPayment.h>
#include <views/Navigatable.h>
#include <views/MessageDisplay.h>
#include "views/main/controller/ControllerLogicSettable.h"
#include "logics/managers/OperationManager.h"

class Command;

namespace Ui {
    class PaymentWindow;
}

class PaymentWindow : public QWidget, public Navigatable {
Q_OBJECT

public:
    explicit PaymentWindow(OperationManager& operationManager, QWidget* parent = nullptr);
    ~PaymentWindow() override;

    void navigate(int i) override;

    void setController(ControllerLogicSettable* logicSettable);
    void setLogicActive();

signals:
    void signalBtnBackToMainMenuClicked();

private slots:
    void onListPaymentsItemClicked(QListWidgetItem*);

private:
    class PaymentPageLogic : public ControllerLogic {
    public:
        explicit PaymentPageLogic(Navigatable&);

    private:
        void onBtn0Clicked() override;
        void onBtn1Clicked() override;
        void onBtnCancelClicked() override;

        Navigatable& _navigatable;
    };

    class CreatePaymentPageLogic : public ControllerLogic {
    public:
        explicit CreatePaymentPageLogic(Navigatable&);

        void setEnterCommand(std::shared_ptr<Command>);

    private:
        Navigatable& _navigatable;
        std::shared_ptr<Command> _enterCommand;

        void onBtnEnterClicked() override;
        void onBtnCancelClicked() override;
    };

    class MyPaymentsPageLogic : public ControllerLogic {
    public:
        explicit MyPaymentsPageLogic(Navigatable&);

        void setClearCommand(std::shared_ptr<Command>);

    private:
        Navigatable& _navigatable;
        std::shared_ptr<Command> _clearCommand;

        void onBtnClearClicked() override;
        void onBtnCancelClicked() override;
    };

    Ui::PaymentWindow* _ui;
    ControllerLogicSettable* _logicSettable = nullptr;
    OperationManager& _operationManager;
    MessageDisplay _messageDisplay;

    RegularPayment* _payments = nullptr;
    int _paymentsLen = 0;
    int _selectedPayment = -1;

    PaymentPageLogic _paymentPageLogic;
    CreatePaymentPageLogic _createPaymentPageLogic;
    MyPaymentsPageLogic _myPaymentsPageLogic;

    void setupCommands();
    void setupListPayments();
    void setupPaymentItem(RegularPayment&);
};

#endif // ATM_PAYMENTWINDOW_H
