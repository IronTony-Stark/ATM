# ATM

## Qt Widgets ATM Simulator

### Features
- Registration
- Authentication
- Transactions
  - Replenish
  - Withdraw
  - Transfer
- Credits
- Deposits
- Regular Payments

### How to build and how to run
Probably the simplest way to launch the application is to do it from `Qt Creator`.
However, if this is not an option for you, next I will show how to do it with `command line` and `cmake`

**Before we start, please add `Qt bin` location (e.g. `C:\Qt\5.15.1\mingw81_64\bin`) to your `path` environment variable.**
Otherwise, you will have to manually copy dlls to your build directory,
define environment variables in your run configuration (e.g. `QT_QPA_PLATFORM_PLUGIN_PATH`) and configure other nasty stuff

```
- cd <project root>
- mkdir build
- cd build
- cmake -G <Generator> ..
- make
- ATM
```
`cmake -G` - To list all generators

If `make` doesn't work for you, try `cmake --build build --target ATM` from project root

**Attention:** _unable to open database file Error opening database_ means that the path to the 
database file, which is located in `./db_file/bank_database.sqlite`, is incorrect. Please, specify the correct 
path in `main.cpp` `db.setDatabaseName("correct/path");`

### DB File
| Card Number      | Pin           | Balance  |
| ---------------- | ------------- | -------- |
| 4441531154931232 | 5001          | 95512.38 |
| 5555555555555555 | 0005          | 2165     |
| 4441645380621636 | 6396          | 0        |

### Screenshots
![Start](./screenshots/start/Start.jpg)
![Info](./screenshots/start/Info.jpg)
![Time Dialog](./screenshots/start/TimeDialog.jpg)
![Registration](./screenshots/registration/Registration.jpg)
![Registration Complete](./screenshots/registration/RegistrationComplete.jpg)
![Authentication](./screenshots/start/Authentication.jpg)
![Main Menu](./screenshots/start/MainMenu.jpg)

![Transaction Menu](./screenshots/transcation/TransactionMenu.jpg)
![Replenish](./screenshots/transcation/Replenish.jpg)
![Withdraw](./screenshots/transcation/Withdraw.jpg)
![Transfer](./screenshots/transcation/Transfer.jpg)

![Credit Menu](./screenshots/credit/CreditMenu.jpg)
![Take Credit](./screenshots/credit/TakeCredit.jpg)
![My Credits](./screenshots/credit/MyCredits.jpg)
![Credit Details](./screenshots/credit/CreditDetails.jpg)

![Deposit Menu](./screenshots/deposit/DepositMenu.jpg)
![Open Deposit](./screenshots/deposit/OpenDeposit.jpg)
![My Deposits](./screenshots/deposit/MyDeposits.jpg)

![Payment Menu](./screenshots/payment/PaymentMenu.jpg)
![Create Payment](./screenshots/payment/CreatePayment.jpg)
![My Payments](./screenshots/payment/MyPayments.jpg)
