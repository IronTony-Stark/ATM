//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_REGISTRATIONWINDOW_H
#define ATM_REGISTRATIONWINDOW_H

#include <QWidget>
#include "views/main/controller/ControllerLogicSettable.h"

namespace Ui {
    class RegistrationWindow;
}

class RegistrationWindow : public QWidget {
Q_OBJECT

public:
    explicit RegistrationWindow(QWidget* parent = nullptr);
    ~RegistrationWindow() override;

    void setController(ControllerLogicSettable* logicSettable);

signals:
    void signalBtnCancelClicked();

private slots:
    void onBtnCancelClicked();
    void onBtnSubmitClicked();
    void onBtnTakeCardClicked();

private:
    Ui::RegistrationWindow* _ui;
    ControllerLogicSettable* _logicSettable;
};

#endif // ATM_REGISTRATIONWINDOW_H
