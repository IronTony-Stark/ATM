//
// Created by Iron Tony on 22/10/2020.
//

#ifndef ATM_MESSAGEDISPLAY_H
#define ATM_MESSAGEDISPLAY_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>

class MessageDisplay {
public:
    explicit MessageDisplay(QWidget& parent) : _parent(parent) {}

    void show(const QString& msg, bool isCritical = true) {
        if (isCritical)
            QMessageBox::critical(&_parent, "ATM", msg);
        else
            QMessageBox::information(&_parent, "ATM", msg);
    }

private:
    QWidget& _parent;
};

#endif //ATM_MESSAGEDISPLAY_H
