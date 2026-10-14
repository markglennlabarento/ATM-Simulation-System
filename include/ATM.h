#ifndef ATM_H
#define ATM_H

#include "Account.h"
#include "Transaction.h"

using namespace std;

class ATM {
private:
    static const string DATA_FILE;

    Account account;
    Transaction transaction;

    void loadState();
    void saveState() const;
    bool login();

    void showMenu();
    void checkBalance();
    void depositMoney();
    void withdrawMoney();
    void showHistory();

public:
    ATM();
    void run();
};

#endif