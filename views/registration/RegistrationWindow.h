//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_REGISTRATIONWINDOW_H
#define ATM_REGISTRATIONWINDOW_H

#include <QWidget>
#include "views/main/controller/ControllerLogicSettable.h"
#include "logics/managers/OperationManager.h"

namespace Ui {
    class RegistrationWindow;
}

class RegistrationWindow : public QWidget, public ControllerLogic {
Q_OBJECT

public:
    explicit RegistrationWindow(OperationManager&, QWidget* parent = nullptr);
    ~RegistrationWindow() override;

    void setController(ControllerLogicSettable* logicSettable);
    void setLogicActive();

signals:
    void signalBtnCancelClicked();

private:
    Ui::RegistrationWindow* _ui;
    ControllerLogicSettable* _logicSettable = nullptr;
    OperationManager& _operationManager;

    void onBtnEnterClicked() override;
    void onBtnCancelClicked() override;
    void onBtnCardClicked() override;

    int state();
};

#endif // ATM_REGISTRATIONWINDOW_H
