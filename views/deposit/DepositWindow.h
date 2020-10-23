//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_DEPOSITWINDOW_H
#define ATM_DEPOSITWINDOW_H

#include <QWidget>
#include <QtWidgets/QListWidgetItem>
#include "views/main/controller/ControllerLogicSettable.h"
#include "logics/managers/OperationManager.h"

namespace Ui {
    class DepositWindow;
}

class DepositWindow : public QWidget, public ControllerLogic {
Q_OBJECT

public:
    explicit DepositWindow(OperationManager& operationManager, QWidget* parent = nullptr);
    ~DepositWindow() override;

    void setController(ControllerLogicSettable* logicSettable);
    void setLogicActive();

signals:
    void signalBtnBackToMainMenuClicked();

private slots:
    void onBtnOpenDepositClicked();
    void onBtnMyDepositsClicked();

    void onBtnOpenDepositOpen();
    void onBtnMyDepositsReplenishClicked();

    void onBtnReplenishSubmit();
    void onBtnReplenishCancel();

    void onBtnMyDepositCancelClicked();
    void onBtnBackToMyDepositsClicked();
    void onBtnBackToDepositMenuClicked();
    void onBtnBackToMainMenuClicked();

    void onListDepositsItemClicked(QListWidgetItem*);

private:
    Ui::DepositWindow* _ui;
    ControllerLogicSettable* _logicSettable = nullptr;
    OperationManager& _operationManager;
    Deposit* _deposits = nullptr;
    int _depositsLen = 0;
    int _selectedDeposit = -1;

    void setupListDeposits();
    void setupDepositItem(Deposit&);
};

#endif // ATM_DEPOSITWINDOW_H
