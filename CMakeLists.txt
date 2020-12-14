cmake_minimum_required(VERSION 3.14)

project(MOOP_ATM)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Test REQUIRED)

add_executable(MOOP_ATM
        main.cpp

        # Views
        views/Navigatable.h
        views/MessageDisplay.h
        views/Command.h
        views/exceptions/AbsentNavigationDestination.h
        views/validator/Validators.h
        views/main/MainWindow.cpp
        views/main/MainWindow.h
        views/main/mainwindow.ui
        views/main/controller/ControllerLogic.h
        views/main/controller/ControllerLogicSettable.h
        views/mainMenu/MainMenuWindow.h
        views/mainMenu/MainMenuWindow.cpp
        views/mainMenu/mainmenuwindow.ui
        views/start/StartWindow.h
        views/start/StartWindow.cpp
        views/start/startwindow.ui
        views/registration/RegistrationWindow.h
        views/registration/RegistrationWindow.cpp
        views/registration/registrationwindow.ui
        views/transaction/Windows.h
        views/transaction/TransactionWindow.h
        views/transaction/TransactionWindow.cpp
        views/transaction/transactionwindow.ui
        views/transaction/commands/IncludeAllCommands.h
        views/transaction/commands/replenishCommand/ReplenishCommand.cpp
        views/transaction/commands/replenishCommand/ReplenishCommand.h
        views/transaction/commands/transferCommand/TransferCommand.cpp
        views/transaction/commands/transferCommand/TransferCommand.h
        views/transaction/commands/withdrawCommand/WithdrawCommand.cpp
        views/transaction/commands/withdrawCommand/WithdrawCommand.h
        views/transaction/commands/navigateTransactions/NavigateTransactionsCommand.cpp
        views/transaction/commands/navigateTransactions/NavigateTransactionsCommand.h
        views/credit/Windows.h
        views/credit/CreditWindow.h
        views/credit/CreditWindow.cpp
        views/credit/creditwindow.ui
        views/credit/creditWidget/CreditWidget.h
        views/credit/creditWidget/CreditWidget.cpp
        views/credit/creditWidget/creditwidget.ui
        views/credit/commands/IncludeAllCommands.h
        views/credit/commands/takeCreditCommand/TakeCreditCommand.cpp
        views/credit/commands/takeCreditCommand/TakeCreditCommand.h
        views/credit/commands/repayCreditCommand/RepayCreditCommand.cpp
        views/credit/commands/repayCreditCommand/RepayCreditCommand.h
        views/deposit/Windows.h
        views/deposit/DepositWindow.h
        views/deposit/DepositWindow.cpp
        views/deposit/depositwindow.ui
        views/deposit/depositWidget/DepositWidget.h
        views/deposit/depositWidget/DepositWidget.cpp
        views/deposit/depositWidget/depositwidget.ui
        views/deposit/commands/IncludeAllCommands.h
        views/deposit/commands/openDepositCommand/OpenDepositCommand.cpp
        views/deposit/commands/openDepositCommand/OpenDepositCommand.h
        views/deposit/commands/cancelDepositCommand/CancelDepositCommand.cpp
        views/deposit/commands/cancelDepositCommand/CancelDepositCommand.h
        views/deposit/commands/replenishDepositCommand/ReplenishDepositCommand.cpp
        views/deposit/commands/replenishDepositCommand/ReplenishDepositCommand.h
        views/payment/Windows.h
        views/payment/PaymentWindow.h
        views/payment/PaymentWindow.cpp
        views/payment/paymentwindow.ui
        views/payment/paymentWidget/PaymentWidget.h
        views/payment/paymentWidget/PaymentWidget.cpp
        views/payment/paymentWidget/paymentwidget.ui
        views/payment/commands/IncludeAllCommands.h
        views/payment/commands/cancelPaymentCommand/CancelPaymentCommand.cpp
        views/payment/commands/cancelPaymentCommand/CancelPaymentCommand.h
        views/payment/commands/createPaymentCommand/CreatePaymentCommand.cpp
        views/payment/commands/createPaymentCommand/CreatePaymentCommand.h
        views/clock/widgets/Clock.h
        views/clock/widgets/Clock.cpp
        views/clock/widgets/ClockListener.h
        views/clock/setdialog/SetDialog.h
        views/clock/setdialog/SetDialog.cpp
        views/clock/setdialog/setdialog.ui

        # Logics
        logics/bank_fees/ABankFee.h
        logics/bank_fees/BankFeeProvider.cpp
        logics/bank_fees/BankFeeProvider.h
        logics/bank_fees/CreditConditions.cpp
        logics/bank_fees/CreditConditions.h
        logics/bank_fees/DepositConditions.cpp
        logics/bank_fees/DepositConditions.h
        logics/bank_fees/ABankFee.cpp
        logics/bank_services/Card.cpp
        logics/bank_services/Card.h
        logics/bank_services/Credit.cpp
        logics/bank_services/Credit.h
        logics/bank_services/Deposit.cpp
        logics/bank_services/Deposit.h
        logics/bank_services/RegularPayment.cpp
        logics/bank_services/RegularPayment.h
        logics/Customer.cpp
        logics/Customer.h
        logics/utils/Money.cpp
        logics/utils/Money.h
        logics/utils/general.h
        logics/utils/general.cpp
        logics/utils/TimeDrivenEventsHandler.cpp
        logics/utils/TimeDrivenEventsHandler.h
        logics/exceptions/NotEnoughMoneyException.cpp
        logics/exceptions/NotEnoughMoneyException.h
        logics/exceptions/NoSuchCardException.h
        logics/exceptions/NoSuchCreditException.h
        logics/exceptions/NoSuchDepositException.h
        logics/exceptions/NoSuchCustomerPossessionException.cpp
        logics/exceptions/NoSuchCustomerPossessionException.h
        logics/exceptions/CreditRepayOverheadException.cpp
        logics/exceptions/CreditRepayOverheadException.h
        logics/exceptions/CustomerRegistrationException.cpp
        logics/exceptions/CustomerRegistrationException.h
        logics/exceptions/DepositMaxSumReachedException.cpp
        logics/exceptions/DepositMaxSumReachedException.h
        logics/exceptions/BlockedCardException.cpp
        logics/exceptions/BlockedCardException.h
        logics/managers/CustomerDataManager.cpp
        logics/managers/CustomerDataManager.h
        logics/managers/OperationManager.cpp
        logics/managers/OperationManager.h
        logics/auth/Authorizer.cpp
        logics/auth/Authorizer.h
        logics/auth/Registrator.cpp
        logics/auth/Registrator.h
        logics/auth/CustomerVerificationData.h
        data_access/CardDAO.cpp
        data_access/CardDAO.h
        data_access/CustomerDAO.cpp
        data_access/CustomerDAO.h
        data_access/CreditDAO.cpp
        data_access/CreditDAO.h
        data_access/DepositDAO.cpp
        data_access/DepositDAO.h
        data_access/PaymentDAO.cpp
        data_access/PaymentDAO.h

        # Tests
        tests/Test_CardDAO.cpp
        tests/Test_CardDAO.h
        tests/Test_CreditDAO.cpp
        tests/Test_CreditDAO.h
        tests/Test_DepositDAO.cpp
        tests/Test_DepositDAO.h
        tests/Test_CustomerDAO.cpp
        tests/Test_CustomerDAO.h
        )

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql
        Qt5::Test
        )
