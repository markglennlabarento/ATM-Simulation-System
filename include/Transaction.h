#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>

using namespace std;

class Transaction {
private:
    vector<string> history;

public:
    void recordTransaction(
        const string& type,
        double amount
    );

    vector<string> getHistory() const;
    void setHistory(const vector<string>& entries);
    void displayHistory() const;
};

#endif