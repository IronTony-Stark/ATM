//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_TRANSACTIONWINDOW_H
#define ATM_TRANSACTIONWINDOW_H

#include <QWidget>
#include <QtWidgets/QLineEdit>
#include "views/MessageDisplay.h"
#include "views/Navigatable.h"
#include "views/main/controller/ControllerLogicSettable.h"
#include "logics/managers/OperationManager.h"

class Command;

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
        void setEnterCommand(std::shared_ptr<Command>);
        void setCancelCommand(std::shared_ptr<Command>);

    private:
        std::shared_ptr<Command> _enterCommand;
        std::shared_ptr<Command> _cancelCommand;

        void onBtnEnterClicked() override;
        void onBtnCancelClicked() override;
    };

    class WithdrawPageLogic : public ControllerLogic {
    public:
        void setEnterCommand(std::shared_ptr<Command>);
        void setCancelCommand(std::shared_ptr<Command>);

    private:
        std::shared_ptr<Command> _enterCommand;
        std::shared_ptr<Command> _cancelCommand;

        void onBtnEnterClicked() override;
        void onBtnCancelClicked() override;
    };

    class TransferPageLogic : public ControllerLogic {
    public:
        void setEnterCommand(std::shared_ptr<Command>);
        void setCancelCommand(std::shared_ptr<Command>);

    private:
        std::shared_ptr<Command> _enterCommand;
        std::shared_ptr<Command> _cancelCommand;

        void onBtnEnterClicked() override;
        void onBtnCancelClicked() override;
    };

    Ui::TransactionWindow* _ui;
    ControllerLogicSettable* _logicSettable = nullptr;
    MessageDisplay _messageDisplay;

    TransactionPageLogic _transactionPageLogic;
    ReplenishPageLogic _replenishPageLogic;
    WithdrawPageLogic _withdrawPageLogic;
    TransferPageLogic _transferPageLogic;

    void setupCommands(OperationManager& operationManager);
};

#endif // ATM_TRANSACTIONWINDOW_H
