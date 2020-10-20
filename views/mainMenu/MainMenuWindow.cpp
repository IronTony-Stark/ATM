//
// Created by Iron Tony on 20/10/2020.
//

#include "MainMenuWindow.h"
#include "gui/ui_mainmenuwindow.h"

MainMenuWindow::MainMenuWindow(QWidget* parent) :
        QWidget(parent), _ui(new Ui::MainMenuWindow) {
    _ui->setupUi(this);

    connect(_ui->btnFinish, &QPushButton::clicked,
            this, &MainMenuWindow::onBtnFinishClicked);
}

MainMenuWindow::~MainMenuWindow() {
    delete _ui;
}

void MainMenuWindow::onBtnFinishClicked() {
    emit signalBtnFinishClicked();
}
