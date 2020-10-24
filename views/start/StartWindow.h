//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_STARTWINDOW_H
#define ATM_STARTWINDOW_H

#include <QWidget>
#include <views/clock/widgets/Clock.h>
#include "views/main/controller/ControllerLogicSettable.h"
#include "views/registration/RegistrationWindow.h"
#include "views/mainMenu/MainMenuWindow.h"
#include "logics/managers/OperationManager.h"

namespace Ui {
    class StartWindow;
}

class StartWindow : public QWidget, public ControllerLogic {
Q_OBJECT

public:
    explicit StartWindow(QWidget* parent = nullptr);
    ~StartWindow() override;

    void setController(ControllerLogicSettable* logicSettable);

    void setClock(Clock*);

private:
    Ui::StartWindow* _ui;
    ControllerLogicSettable* _logicSettable = nullptr;
    OperationManager _operationManager;
    RegistrationWindow _registrationWindow;
    MainMenuWindow _mainMenuWindow;
    int _pinAttempts = 3;

    void onBtn0Clicked() override;
    void onBtn1Clicked() override;
    void onBtnCardClicked() override;
    void onBtnEnterClicked() override;
    void onBtnCancelClicked() override;

    int state();
};

#endif // ATM_STARTWINDOW_H
