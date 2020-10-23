//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_CREDITWINDOW_H
#define ATM_CREDITWINDOW_H

#include <QWidget>
#include <QtWidgets/QListWidgetItem>
#include "views/main/controller/ControllerLogicSettable.h"
#include "logics/managers/OperationManager.h"

namespace Ui {
    class CreditWindow;
}

class CreditWindow : public QWidget, public ControllerLogic {
Q_OBJECT

public:
    explicit CreditWindow(OperationManager& operationManager, QWidget* parent = nullptr);
    ~CreditWindow() override;

    void setController(ControllerLogicSettable* logicSettable);
    void setLogicActive();

signals:
    void signalBtnBackToMainMenuClicked();

private slots:
    void onBtnTakeCreditClicked();
    void onBtnMyCreditsClicked();

    void onBtnTakeCreditSubmitClicked();

    void onBtnBackToCreditMenuClicked();
    void onBtnBackToMyCreditsClicked();

    void onBtnMyCreditRepayClicked();
    void onBtnBackToMainMenuClicked();

    void onListCreditsItemClicked(QListWidgetItem*);


private:
    Ui::CreditWindow* _ui;
    ControllerLogicSettable* _logicSettable = nullptr;
    OperationManager& _operationManager;
    Credit* _credits = nullptr;
    int _creditsLen = 0;
    int _selectedCredit = -1;

    void setupListCredits();
    void setupCreditItem(Credit&);
};

#endif // ATM_CREDITWINDOW_H
