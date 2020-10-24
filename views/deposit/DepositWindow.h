//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_DEPOSITWINDOW_H
#define ATM_DEPOSITWINDOW_H

#include <QWidget>
#include <QtWidgets/QListWidgetItem>
#include <views/Navigatable.h>
#include <views/MessageDisplay.h>
#include "views/main/controller/ControllerLogicSettable.h"
#include "logics/managers/OperationManager.h"

class Command;

namespace Ui {
    class DepositWindow;
}

class DepositWindow : public QWidget, public Navigatable {
Q_OBJECT

public:
    explicit DepositWindow(OperationManager& operationManager, QWidget* parent = nullptr);
    ~DepositWindow() override;

    void navigate(int i) override;

    void setController(ControllerLogicSettable* logicSettable);
    void setLogicActive();

signals:
    void signalBtnBackToMainMenuClicked();

private slots:
    void onListDepositsItemClicked(QListWidgetItem*);

private:
    class DepositPageLogic : public ControllerLogic {
    public:
        explicit DepositPageLogic(Navigatable&);

    private:
        void onBtn0Clicked() override;
        void onBtn1Clicked() override;
        void onBtnCancelClicked() override;

        Navigatable& _navigatable;
    };

    class OpenDepositPageLogic : public ControllerLogic {
    public:
        explicit OpenDepositPageLogic(Navigatable&);

        void setEnterCommand(std::shared_ptr<Command>);

    private:
        Navigatable& _navigatable;
        std::shared_ptr<Command> _enterCommand;

        void onBtnEnterClicked() override;
        void onBtnCancelClicked() override;
    };

    class MyDepositsPageLogic : public ControllerLogic {
    public:
        explicit MyDepositsPageLogic(Navigatable&);

        void setEnterCommand(std::shared_ptr<Command>);
        void setClearCommand(std::shared_ptr<Command>);

    private:
        Navigatable& _navigatable;
        std::shared_ptr<Command> _enterCommand;
        std::shared_ptr<Command> _clearCommand;

        void onBtnEnterClicked() override;
        void onBtnClearClicked() override;
        void onBtnCancelClicked() override;
    };

    Ui::DepositWindow* _ui;
    ControllerLogicSettable* _logicSettable = nullptr;
    OperationManager& _operationManager;
    MessageDisplay _messageDisplay;

    Deposit* _deposits = nullptr;
    int _depositsLen = 0;
    int _selectedDeposit = -1;

    DepositPageLogic _depositPageLogic;
    OpenDepositPageLogic _openDepositPageLogic;
    MyDepositsPageLogic _myDepositsPageLogic;

    void setupCommands();
    void setupListDeposits();
    void setupDepositItem(Deposit&);
};

#endif // ATM_DEPOSITWINDOW_H
