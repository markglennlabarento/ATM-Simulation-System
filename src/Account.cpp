#include "../include/Account.h"

using namespace std;

Account::Account(string number, string pin, double balance)
    : accountNumber(number), pin(pin), balance(balance) {
    if (this->balance < 0.0) {
        this->balance = 0.0;
    }
}

void Account::setBalance(double newBalance) {
    balance = newBalance;
    if (balance < 0.0) {
        balance = 0.0;
    }
}

string Account::getAccountNumber() const {
    return accountNumber;
}

string Account::getPin() const {
    return pin;
}

bool Account::verifyPin(string enteredPin) const {
    return pin == enteredPin;
}

double Account::getBalance() const {
    return balance;
}

bool Account::deposit(double amount) {
    if (amount <= 0.0) {
        return false;
    }

    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (amount <= 0.0 || amount > balance) {
        return false;
    }

    balance -= amount;
    return true;
}