//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_STARTWINDOW_H
#define ATM_STARTWINDOW_H

#include <QWidget>
#include "views/main/controller/ControllerLogicSettable.h"
#include "views/registration/RegistrationWindow.h"
#include "views/mainMenu/MainMenuWindow.h"

namespace Ui {
    class StartWindow;
}

// TODO enter pin card number
class StartWindow : public QWidget, public ControllerLogic {
Q_OBJECT

public:
    explicit StartWindow(QWidget* parent = nullptr);
    ~StartWindow() override;

    void setController(ControllerLogicSettable* logicSettable);

private slots:
    void onBtnInfoClicked();
    void onBtnBackClicked();
    void onBtnRegisterClicked();
    void onBtnInsertCardClicked();
    void onBtnEnterPinClicked();

private:
    Ui::StartWindow* _ui;
    RegistrationWindow _registrationWindow;
    MainMenuWindow _mainMenuWindow;

    void onBtnEnterClicked() override;
    void onBtnCancelClicked() override;
};

#endif // ATM_STARTWINDOW_H
