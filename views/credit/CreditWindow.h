//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_CREDITWINDOW_H
#define ATM_CREDITWINDOW_H

#include <QWidget>
#include <QtWidgets/QListWidgetItem>
#include "views/main/controller/ControllerLogicSettable.h"

namespace Ui {
    class CreditWindow;
}

class CreditWindow : public QWidget {
Q_OBJECT

public:
    explicit CreditWindow(QWidget* parent = nullptr);
    ~CreditWindow() override;

    void setController(ControllerLogicSettable* logicSettable);

signals:
    void signalBtnBackToMainMenuClicked();

private slots:
    void onBtnTakeCreditClicked();
    void onBtnMyCreditsClicked();

    void onBtnTakeCreditSubmitClicked();

    void onBtnBackToCreditMenuClicked();
    void onBtnBackToMyCreditsClicked();

    void onBtnBackToMainMenuClicked();

    void onListCreditsItemClicked(QListWidgetItem*);

private:
    Ui::CreditWindow* _ui;
    ControllerLogicSettable* _logicSettable;

    void setupListCredits();
};

#endif // ATM_CREDITWINDOW_H
