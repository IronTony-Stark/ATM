cmake_minimum_required(VERSION 3.17)
project(ATM)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH $ENV{QtPath}) # e.g. C:/Qt/5.15.1/mingw81_64/


find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(ATM
        main.cpp
        logics/bank_fees/ABankFee.h
        logics/bank_fees/BankFeeProvider.cpp
        logics/bank_fees/BankFeeProvider.h
        logics/bank_services/Card.cpp
        logics/bank_services/Card.h
        logics/bank_services/Credit.cpp
        logics/bank_services/Credit.h
        logics/bank_services/Deposit.cpp
        logics/bank_services/Deposit.h
        logics/Customer.cpp
        logics/Customer.h
        logics/exceptions/NotEnoughMoneyException.cpp
        logics/exceptions/NotEnoughMoneyException.h
        logics/utils/Money.cpp
        logics/utils/Money.h
        logics/utils/general.h
        logics/utils/general.cpp
        logics/exceptions/NoSuchCardException.h
        logics/exceptions/NoSuchCreditException.h
        logics/exceptions/NoSuchDepositException.h
        logics/exceptions/NoSuchCustomerPossessionException.cpp
        logics/exceptions/NoSuchCustomerPossessionException.h
        logics/managers/CustomerDataManager.cpp
        logics/managers/CustomerDataManager.h
        logics/managers/OperationManager.cpp
        logics/managers/OperationManager.h
        logics/auth/Authorizer.cpp
        logics/auth/Authorizer.h
        logics/auth/Registrator.cpp
        logics/auth/Registrator.h
        logics/bank_fees/CreditConditions.cpp
        logics/bank_fees/CreditConditions.h
        logics/bank_fees/DepositConditions.cpp
        logics/bank_fees/DepositConditions.h
        logics/exceptions/CreditRepayOverheadException.cpp
        logics/exceptions/CreditRepayOverheadException.h
        logics/bank_services/RegularPayment.cpp
        logics/bank_services/RegularPayment.h
        data_access/CustomerDAO.cpp
        data_access/CustomerDAO.h
        data_access/CreditDAO.cpp
        data_access/CreditDAO.h
        data_access/DepositDAO.cpp
        data_access/DepositDAO.h
        data_access/PaymentDAO.cpp
        data_access/PaymentDAO.h
        data_access/DBAccessor.cpp
        data_access/DBAccessor.h

        #       Views
        views/transaction/Windows.h
        views/credit/Windows.h
        views/deposit/Windows.h
        views/payment/Windows.h
        views/main/MainWindow.cpp
        views/main/MainWindow.h
        views/main/mainwindow.ui
        views/start/StartWindow.h
        views/start/StartWindow.cpp
        views/start/startwindow.ui
        views/registration/RegistrationWindow.h
        views/registration/RegistrationWindow.cpp
        views/registration/registrationwindow.ui
        views/mainMenu/MainMenuWindow.h
        views/mainMenu/MainMenuWindow.cpp
        views/mainMenu/mainmenuwindow.ui
        views/transaction/TransactionWindow.h
        views/transaction/TransactionWindow.cpp
        views/transaction/transactionwindow.ui
        views/payment/PaymentWindow.h
        views/payment/PaymentWindow.cpp
        views/payment/paymentwindow.ui
        views/payment/paymentWidget/PaymentWidget.h
        views/payment/paymentWidget/PaymentWidget.cpp
        views/payment/paymentWidget/paymentwidget.ui
        views/deposit/DepositWindow.h
        views/deposit/DepositWindow.cpp
        views/deposit/depositwindow.ui
        views/deposit/depositWidget/DepositWidget.h
        views/deposit/depositWidget/DepositWidget.cpp
        views/deposit/depositWidget/depositwidget.ui
        views/credit/CreditWindow.h
        views/credit/CreditWindow.cpp
        views/credit/creditwindow.ui
        views/credit/creditWidget/CreditWidget.h
        views/credit/creditWidget/CreditWidget.cpp
        views/credit/creditWidget/creditwidget.ui
        views/clock/widgets/Clock.h
        views/clock/widgets/Clock.cpp
        views/clock/widgets/ClockListener.h
        views/clock/setdialog/SetDialog.h
        views/clock/setdialog/SetDialog.cpp
        views/clock/setdialog/setdialog.ui
        views/main/controller/ControllerLogic.h
        views/main/controller/ControllerLogicSettable.h
        views/Navigatable.h
        views/MessageDisplay.h
        views/Command.h
        views/exceptions/AbsentNavigationDestination.h
        views/transaction/commands/IncludeAllCommands.h
        views/credit/commands/IncludeAllCommands.h
        views/deposit/commands/IncludeAllCommands.h
        views/payment/commands/IncludeAllCommands.h
        views/transaction/commands/replenishCommand/ReplenishCommand.cpp
        views/transaction/commands/replenishCommand/ReplenishCommand.h
        views/transaction/commands/transferCommand/TransferCommand.cpp
        views/transaction/commands/transferCommand/TransferCommand.h
        views/transaction/commands/withdrawCommand/WithdrawCommand.cpp
        views/transaction/commands/withdrawCommand/WithdrawCommand.h
        views/transaction/commands/navigateTransactions/NavigateTransactionsCommand.cpp
        views/transaction/commands/navigateTransactions/NavigateTransactionsCommand.h
        views/credit/commands/takeCreditCommand/TakeCreditCommand.cpp
        views/credit/commands/takeCreditCommand/TakeCreditCommand.h
        views/credit/commands/repayCreditCommand/RepayCreditCommand.cpp
        views/credit/commands/repayCreditCommand/RepayCreditCommand.h
        views/deposit/commands/openDepositCommand/OpenDepositCommand.cpp
        views/deposit/commands/openDepositCommand/OpenDepositCommand.h
        views/deposit/commands/cancelDepositCommand/CancelDepositCommand.cpp
        views/deposit/commands/cancelDepositCommand/CancelDepositCommand.h
        views/deposit/commands/replenishDepositCommand/ReplenishDepositCommand.cpp
        views/deposit/commands/replenishDepositCommand/ReplenishDepositCommand.h
        views/payment/commands/cancelPaymentCommand/CancelPaymentCommand.cpp
        views/payment/commands/cancelPaymentCommand/CancelPaymentCommand.h
        views/payment/commands/createPaymentCommand/CreatePaymentCommand.cpp
        views/payment/commands/createPaymentCommand/CreatePaymentCommand.h
        )

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)