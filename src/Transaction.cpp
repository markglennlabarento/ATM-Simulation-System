#include "../include/Transaction.h"

#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

void Transaction::recordTransaction(const string& type, double amount) {
    ostringstream stream;
    stream << type << ": $" << fixed << setprecision(2) << amount;
    history.push_back(stream.str());
}

vector<string> Transaction::getHistory() const {
    return history;
}

void Transaction::setHistory(const vector<string>& entries) {
    history = entries;
}

void Transaction::displayHistory() const {
    if (history.empty()) {
        cout << "No transaction history available." << endl;
        return;
    }

    cout << "Transaction History:" << endl;
    for (const string& entry : history) {
        cout << entry << endl;
    }
}