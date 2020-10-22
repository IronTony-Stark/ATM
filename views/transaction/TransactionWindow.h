//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_TRANSACTIONWINDOW_H
#define ATM_TRANSACTIONWINDOW_H

#include <QWidget>
#include "views/Navigatable.h"
#include "views/main/controller/ControllerLogicSettable.h"
#include "logics/managers/OperationManager.h"

namespace Ui {
    class TransactionWindow;
}

class TransactionWindow : public QWidget, public Navigatable {
Q_OBJECT

public:
    explicit TransactionWindow(OperationManager& operationManager, QWidget* parent = nullptr);
    ~TransactionWindow() override;

    void navigate(int i) override;

    void setController(ControllerLogicSettable* logicSettable);
    void setLogicActive();

signals:
    void signalBtnBackToMainMenuClicked();

private:
    class TransactionPageLogic : public ControllerLogic {
    public:
        explicit TransactionPageLogic(Navigatable&);

    private:
        void onBtn0Clicked() override;
        void onBtn1Clicked() override;
        void onBtn2Clicked() override;
        void onBtnCancelClicked() override;

        Navigatable& _navigatable;
    };

    class ReplenishPageLogic : public ControllerLogic {
    public:
        explicit ReplenishPageLogic(Navigatable&);

    private:
        void onBtnEnterClicked() override;
        void onBtnCancelClicked() override;

        Navigatable& _navigatable;
    };

    class WithdrawPageLogic : public ControllerLogic {
    public:
        explicit WithdrawPageLogic(Navigatable&);

    private:
        void onBtnEnterClicked() override;
        void onBtnCancelClicked() override;

        Navigatable& _navigatable;
    };

    class TransferPageLogic : public ControllerLogic {
    public:
        explicit TransferPageLogic(Navigatable&);

    private:
        void onBtnEnterClicked() override;
        void onBtnCancelClicked() override;

        Navigatable& _navigatable;
    };

    Ui::TransactionWindow* _ui;
    ControllerLogicSettable* _logicSettable = nullptr;
    OperationManager& _operationManager;
    TransactionPageLogic _transactionPageLogic;
    ReplenishPageLogic _replenishPageLogic;
    WithdrawPageLogic _withdrawPageLogic;
    TransferPageLogic _transferPageLogic;
};

#endif // ATM_TRANSACTIONWINDOW_H
