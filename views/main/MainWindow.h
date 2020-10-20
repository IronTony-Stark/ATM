//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_MAINWINDOW_H
#define ATM_MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QStackedWidget>
#include "views/registration/RegistrationWindow.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private slots:
    void onBtnInfoClicked();
    void onBtnBackClicked();
    void onBtnRegisterClicked();

private:
    Ui::MainWindow* _ui;
    QStackedWidget* _stackedWidget;
    RegistrationWindow _registrationWindow;
};

#endif // ATM_MAINWINDOW_H
