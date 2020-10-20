#ifndef ATM_MAINWINDOW_H
#define ATM_MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private slots:
    void onBtnInfoClicked();
    void onBtnBack();

private:
    Ui::MainWindow* _ui;
    QStackedWidget* _stackedWidget;
};

#endif // ATM_MAINWINDOW_H
