//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_CREDITWINDOW_H
#define ATM_CREDITWINDOW_H

#include <QWidget>
#include <QtWidgets/QListWidgetItem>
#include <views/Navigatable.h>
#include <views/MessageDisplay.h>
#include "views/main/controller/ControllerLogicSettable.h"
#include "logics/managers/OperationManager.h"

class Command;

namespace Ui {
    class CreditWindow;
}

class CreditWindow : public QWidget, public Navigatable {
Q_OBJECT

public:
    explicit CreditWindow(OperationManager& operationManager, QWidget* parent = nullptr);
    ~CreditWindow() override;

    void navigate(int i) override;

    void setController(ControllerLogicSettable* logicSettable);
    void setLogicActive();

signals:
    void signalBtnBackToMainMenuClicked();

private slots:
    void onListCreditsItemClicked(QListWidgetItem*);

private:
    class CreditPageLogic : public ControllerLogic {
    public:
        explicit CreditPageLogic(Navigatable&);

    private:
        void onBtn0Clicked() override;
        void onBtn1Clicked() override;
        void onBtnCancelClicked() override;

        Navigatable& _navigatable;
    };

    class TakeCreditPageLogic : public ControllerLogic {
    public:
        explicit TakeCreditPageLogic(Navigatable&);

        void setEnterCommand(std::shared_ptr<Command>);

    private:
        Navigatable& _navigatable;
        std::shared_ptr<Command> _enterCommand;

        void onBtnEnterClicked() override;
        void onBtnCancelClicked() override;
    };

    class MyCreditsPageLogic : public ControllerLogic {
    public:
        explicit MyCreditsPageLogic(Navigatable&);

    private:
        Navigatable& _navigatable;

        void onBtnCancelClicked() override;
    };

    class MyCreditPageLogic : public ControllerLogic {
    public:
        explicit MyCreditPageLogic(Navigatable&);

        void setEnterCommand(std::shared_ptr<Command>);

    private:
        Navigatable& _navigatable;
        std::shared_ptr<Command> _enterCommand;

        void onBtnEnterClicked() override;
        void onBtnCancelClicked() override;
    };

    Ui::CreditWindow* _ui;
    ControllerLogicSettable* _logicSettable = nullptr;
    OperationManager& _operationManager;
    MessageDisplay _messageDisplay;

    Credit* _credits = nullptr;
    int _creditsLen = 0;
    int _selectedCredit = -1;

    CreditPageLogic _creditPageLogic;
    TakeCreditPageLogic _takeCreditPageLogic;
    MyCreditsPageLogic _myCreditsPageLogic;
    MyCreditPageLogic _myCreditPageLogic;

    void setupCommands();
    void setupListCredits();
    void setupCreditItem(Credit&);
};

#endif // ATM_CREDITWINDOW_H
