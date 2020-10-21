//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_MAINWINDOW_H
#define ATM_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow* _ui;
};

#endif // ATM_MAINWINDOW_H
