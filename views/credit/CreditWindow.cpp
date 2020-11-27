//
// Created by Iron Tony on 20/10/2020.
//

#include <QtWidgets/QMessageBox>
#include <utility>
#include <views/exceptions/AbsentNavigationDestination.h>
#include "CreditWindow.h"
#include "Windows.h"
#include "gui/ui_creditwindow.h"
#include "commands/IncludeAllCommands.h"

CreditWindow::CreditWindow(OperationManager& operationManager, QWidget* parent) :
        QWidget(parent), _ui(new Ui::CreditWindow),
        _operationManager(operationManager),
        _messageDisplay(*this),
        _creditPageLogic(*this),
        _takeCreditPageLogic(*this),
        _myCreditsPageLogic(*this),
        _myCreditPageLogic(*this) {
    _ui->setupUi(this);

    _ui->widgetTakeCreditCredit->setReadOnly(false);
    _ui->widgetMyCreditCredit->setReadOnly(true);

    setupCommands();
}

CreditWindow::~CreditWindow() {
    delete _ui;
}

void CreditWindow::onListCreditsItemClicked(QListWidgetItem* item) {
    int index = _ui->listCredits->row(item);
    _selectedCredit = _credits[index];
    navigate(MY_CREDIT);
}

void CreditWindow::navigate(int destination) {
    switch (destination) {
        case CREDITS_MENU:
            _ui->stackedWidget->setCurrentIndex(0);
            _logicSettable->setLogic(&_creditPageLogic);
            break;
        case TAKE_CREDIT:
            _ui->widgetTakeCreditCredit->clear();
            _ui->stackedWidget->setCurrentIndex(1);
            _logicSettable->setLogic(&_takeCreditPageLogic);
            break;
        case MY_CREDITS:
            setupListCredits();
            _ui->stackedWidget->setCurrentIndex(2);
            _logicSettable->setLogic(&_myCreditsPageLogic);
            break;
        case MY_CREDIT:
            assert(_selectedCredit != nullptr);
            _ui->widgetMyCreditCredit->setup(*_selectedCredit);
            _ui->stackedWidget->setCurrentIndex(3);
            _logicSettable->setLogic(&_myCreditPageLogic);
            break;
        case MAIN_MENU:
            emit signalBtnBackToMainMenuClicked();
            break;
        default:
            throw AbsentNavigationDestination(&"CreditWindow navigate "[destination]);
    }
}

void CreditWindow::setupCommands() {
    std::shared_ptr<Command> takeCreditCommand(new TakeCreditCommand(
            *this, *_ui->widgetTakeCreditCredit, _operationManager, _messageDisplay));
    _takeCreditPageLogic.setEnterCommand(takeCreditCommand);

    std::shared_ptr<Command> repayCreditCommand(new RepayCreditCommand(
            _operationManager, _messageDisplay));
    _myCreditPageLogic.setEnterCommand(repayCreditCommand);
}

void CreditWindow::setupListCredits() {
    _ui->listCredits->clear();
    _credits = _operationManager.getAllCredits();

    for (auto& credit : _credits) {
        new QListWidgetItem(credit->name(), _ui->listCredits);
    }

    connect(_ui->listCredits, &QListWidget::itemClicked,
            this, &CreditWindow::onListCreditsItemClicked);
}

void CreditWindow::setController(ControllerLogicSettable* logicSettable) {
    _logicSettable = logicSettable;
}

void CreditWindow::setLogicActive() {
    double limit = static_cast<double>(_operationManager.getCurrentCustomerCreditLimit());
    _ui->labelTakeCreditLimitValue->setText(QString::number(limit));
    _logicSettable->setLogic(&_creditPageLogic);
}

CreditWindow::CreditPageLogic::CreditPageLogic(Navigatable& navigatable)
        : _navigatable(navigatable) {}

void CreditWindow::CreditPageLogic::onBtn0Clicked() {
    _navigatable.navigate(TAKE_CREDIT);
}

void CreditWindow::CreditPageLogic::onBtn1Clicked() {
    _navigatable.navigate(MY_CREDITS);
}

void CreditWindow::CreditPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(MAIN_MENU);
}

// TakeCreditPageLogic
CreditWindow::TakeCreditPageLogic::TakeCreditPageLogic(Navigatable& navigatable)
        : _navigatable(navigatable) {}

void CreditWindow::TakeCreditPageLogic::onBtnEnterClicked() {
    assert(_enterCommand != nullptr);
    _enterCommand->execute();
}

void CreditWindow::TakeCreditPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(CREDITS_MENU);
}

void CreditWindow::TakeCreditPageLogic::setEnterCommand(std::shared_ptr<Command> command) {
    _enterCommand = std::move(command);
}

// MyCreditsPageLogic
CreditWindow::MyCreditsPageLogic::MyCreditsPageLogic(Navigatable& navigatable)
        : _navigatable(navigatable) {}

void CreditWindow::MyCreditsPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(CREDITS_MENU);
}

// MyCreditPageLogic
CreditWindow::MyCreditPageLogic::MyCreditPageLogic(Navigatable& navigatable)
        : _navigatable(navigatable) {}

void CreditWindow::MyCreditPageLogic::onBtnEnterClicked() {
    assert(_enterCommand != nullptr);
    _enterCommand->execute();
}

void CreditWindow::MyCreditPageLogic::onBtnCancelClicked() {
    _navigatable.navigate(MY_CREDITS);
}

void CreditWindow::MyCreditPageLogic::setEnterCommand(std::shared_ptr<Command> command) {
    _enterCommand = std::move(command);
}
