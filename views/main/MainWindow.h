//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_MAINWINDOW_H
#define ATM_MAINWINDOW_H

#include <QMainWindow>
#include "views/main/controller/ControllerLogicSettable.h"
#include "views/main/controller/ControllerLogic.h"

namespace Ui {
    class MainWindow;
}

// TODO disable btns that cannot be used
class MainWindow : public QMainWindow, public ControllerLogicSettable, public ControllerLogic {
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

    void setLogic(ControllerLogic* logic) override;

private:
    Ui::MainWindow* _ui;
    ControllerLogic* _logic = nullptr;

    void onBtnEnterClicked() override;
    void onBtnCancelClicked() override;
    void onBtnClearClicked() override;
    void onBtn0Clicked() override;
    void onBtn1Clicked() override;
    void onBtn2Clicked() override;
    void onBtn3Clicked() override;
    void onBtn4Clicked() override;
    void onBtn5Clicked() override;
    void onBtn6Clicked() override;
    void onBtn7Clicked() override;
    void onBtn8Clicked() override;
    void onBtn9Clicked() override;
    void onBtnMoneyInClicked() override;
    void onBtnCheckClicked() override;
    void onBtnCardClicked() override;
    void onBtnPointClicked() override;
    void onBtnMoneyOutClicked() override;
};

#endif // ATM_MAINWINDOW_H
