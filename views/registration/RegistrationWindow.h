//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_REGISTRATIONWINDOW_H
#define ATM_REGISTRATIONWINDOW_H

#include <QWidget>

namespace Ui {
    class RegistrationWindow;
}

class RegistrationWindow : public QWidget {
Q_OBJECT

public:
    explicit RegistrationWindow(QWidget* parent = nullptr);
    ~RegistrationWindow() override;

private:
    Ui::RegistrationWindow* _ui;
};

#endif // ATM_REGISTRATIONWINDOW_H
