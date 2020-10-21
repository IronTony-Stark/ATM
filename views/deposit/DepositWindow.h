//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_DEPOSITWINDOW_H
#define ATM_DEPOSITWINDOW_H

#include <QWidget>
#include <QtWidgets/QListWidgetItem>

namespace Ui {
    class DepositWindow;
}

class DepositWindow : public QWidget {
Q_OBJECT

public:
    explicit DepositWindow(QWidget* parent = nullptr);
    ~DepositWindow() override;

signals:
    void signalBtnBackToMainMenuClicked();

private slots:
    void onBtnOpenDepositClicked();
    void onBtnMyDepositsClicked();

    void onBtnOpenDepositOpen();
    void onBtnMyDepositsReplenishClicked();

    void onBtnReplenishSubmit();
    void onBtnReplenishCancel();

    void onBtnBackToMyDepositsClicked();
    void onBtnBackToDepositMenuClicked();
    void onBtnBackToMainMenuClicked();

    void onListDepositsItemClicked(QListWidgetItem*);

private:
    Ui::DepositWindow* _ui;

    void setupListDeposits();
};

#endif // ATM_DEPOSITWINDOW_H
