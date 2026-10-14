# ATM Simulation System

A console-based **ATM Simulation System** developed in C++ using Object-Oriented Programming (OOP). This project simulates basic ATM operations, including account authentication, balance inquiry, deposits, withdrawals, and transaction history.

## Features

- **Account Authentication** — Log in using an account number and PIN.
- **Balance Inquiry** — View the current account balance.
- **Cash Deposit** — Deposit money into the account.
- **Cash Withdrawal** — Withdraw money with balance validation.
- **Transaction History** — View recorded deposits and withdrawals.
- **Input Validation** — Handle invalid amounts and menu selections.
- **Logout** — End the current ATM session.

## Technologies Used

- C++
- C++17
- Standard Template Library (STL)
- GCC / G++ Compiler

## Project Structure

```text
ATM-Simulation-System/
├── include/
│   ├── Account.h
│   ├── ATM.h
│   └── Transaction.h
├── src/
│   ├── main.cpp
│   ├── Account.cpp
│   ├── ATM.cpp
│   └── Transaction.cpp
├── README.md
└── .gitignore
```

## Object-Oriented Programming Concepts

This project demonstrates the following OOP concepts:

- **Encapsulation** — Protect account information and balance using private attributes.
- **Classes and Objects** — Represent accounts, transactions, and the ATM.
- **Constructors** — Initialize account information and starting balances.
- **Abstraction** — Hide implementation details behind public methods.
- **Modularity** — Separate class declarations and implementations into different files.

## Requirements

- A C++ compiler that supports C++17, such as GCC/G++.
- A terminal or IDE, such as Visual Studio Code.
- Basic knowledge of C++ and OOP.

## How to Compile

Open a terminal in the project root directory and run:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic \
    src/main.cpp \
    src/Account.cpp \
    src/ATM.cpp \
    src/Transaction.cpp \
    -o atm
```

### Run the Application

**Windows:**

```powershell
.\atm.exe
```

**Linux:**

```bash
./atm
```

## Sample Menu

```text
================================
       ATM SIMULATION SYSTEM
================================
1. Check Balance
2. Deposit Money
3. Withdraw Money
4. Transaction History
5. Logout
================================
Enter your choice:
```

## Future Improvements

- Support multiple bank accounts.
- Add account registration.
- Store account and transaction data in files.
- Add transaction dates and timestamps.
- Implement PIN change functionality.
- Add a daily withdrawal limit.
- Connect the system to a database.
- Improve authentication and security.

## Limitations

This project is an educational console application. Account information and transaction history may only exist during the current session unless file or database persistence is implemented.

It is not intended for real banking or financial transactions.

## Author

Developed as a C++ programming project to practice Object-Oriented Programming, modular code organization, and basic banking operations.

## License

This project is intended for educational and personal learning purposes.
