#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class Account {
private:
    string accountNumber;
    string pin;
    double balance;

public:
    Account(string number, string pin, double balance);

    void setBalance(double newBalance);
    string getAccountNumber() const;
    string getPin() const;
    bool verifyPin(string enteredPin) const;
    double getBalance() const;
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif