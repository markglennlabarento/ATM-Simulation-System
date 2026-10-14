#include "../include/ATM.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

const string ATM::DATA_FILE = "atm_data.txt";

ATM::ATM()
    : account("123456", "1234", 1000.0), transaction() {
    loadState();
}

void ATM::loadState() {
    ifstream input(DATA_FILE);
    if (!input.is_open()) {
        return;
    }

    string accountNumber;
    string pin;
    double balance = 1000.0;
    int historySize = 0;

    if (!(input >> accountNumber >> pin >> balance >> historySize)) {
        return;
    }

    input.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> entries;
    string entry;
    for (int i = 0; i < historySize; ++i) {
        if (!getline(input, entry)) {
            break;
        }
        entries.push_back(entry);
    }

    account = Account(accountNumber, pin, balance);
    transaction.setHistory(entries);
}

void ATM::saveState() const {
    ofstream output(DATA_FILE, ios::trunc);
    if (!output.is_open()) {
        return;
    }

    const vector<string> entries = transaction.getHistory();
    output << account.getAccountNumber() << '\n';
    output << account.getPin() << '\n';
    output << fixed << setprecision(2) << account.getBalance() << '\n';
    output << entries.size() << '\n';

    for (const string& entry : entries) {
        output << entry << '\n';
    }
}

bool ATM::login() {
    string enteredAccountNumber;
    string enteredPin;

    for (int attemptsLeft = 3; attemptsLeft > 0; --attemptsLeft) {
        cout << "Enter account number: ";
        cin >> enteredAccountNumber;
        cout << "Enter PIN: ";
        cin >> enteredPin;

        if (enteredAccountNumber == account.getAccountNumber() && account.verifyPin(enteredPin)) {
            cout << "Login successful." << endl;
            return true;
        }

        cout << "Invalid account number or PIN. " << (attemptsLeft - 1) << " attempt(s) remaining." << endl;
    }

    return false;
}

void ATM::showMenu() {
    cout << "\nATM Menu" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. View Transaction History" << endl;
    cout << "5. Exit" << endl;
    cout << "Select an option: ";
}

void ATM::checkBalance() {
    cout << "Current balance: $" << fixed << setprecision(2) << account.getBalance() << endl;
}

void ATM::depositMoney() {
    double amount = 0.0;
    cout << "Enter amount to deposit: $";
    cin >> amount;

    if (amount <= 0.0) {
        cout << "Invalid deposit amount." << endl;
        return;
    }

    if (account.deposit(amount)) {
        transaction.recordTransaction("Deposit", amount);
        saveState();
        cout << "Deposit successful." << endl;
    } else {
        cout << "Deposit failed." << endl;
    }
}

void ATM::withdrawMoney() {
    double amount = 0.0;
    cout << "Enter amount to withdraw: $";
    cin >> amount;

    if (amount <= 0.0) {
        cout << "Invalid withdrawal amount." << endl;
        return;
    }

    if (amount > account.getBalance()) {
        cout << "Insufficient funds." << endl;
        return;
    }

    if (account.withdraw(amount)) {
        transaction.recordTransaction("Withdrawal", amount);
        saveState();
        cout << "Withdrawal successful." << endl;
    } else {
        cout << "Withdrawal failed." << endl;
    }
}

void ATM::showHistory() {
    transaction.displayHistory();
}

void ATM::run() {
    if (!login()) {
        cout << "Maximum PIN attempts reached. Exiting." << endl;
        return;
    }

    int choice = 0;
    while (true) {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid option. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                showHistory();
                break;
            case 5:
                saveState();
                cout << "Thank you for using the ATM." << endl;
                return;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }
}