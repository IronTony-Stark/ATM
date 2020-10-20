//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_MAINMENUWINDOW_H
#define ATM_MAINMENUWINDOW_H

#include <QWidget>

namespace Ui {
    class MainMenuWindow;
}

class MainMenuWindow : public QWidget {
Q_OBJECT

public:
    explicit MainMenuWindow(QWidget* parent = nullptr);
    ~MainMenuWindow() override;

signals:
    void signalBtnFinishClicked();

private slots:
    void onBtnFinishClicked();

private:
    Ui::MainMenuWindow* _ui;
};

#endif // ATM_MAINMENUWINDOW_H
