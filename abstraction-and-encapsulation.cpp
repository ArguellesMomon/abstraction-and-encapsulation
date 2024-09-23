#include <iostream>
#include <limits>
using namespace std;

class Account {
protected:
    double balance;
public:
    Account(double initialBalance = 0) : balance(initialBalance) {}
    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }
    virtual void withdraw(double amount) = 0;
    virtual void checkBalance() const {
        cout << "Current balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    const double MIN_BALANCE = 1000.0;
public:
    SavingsAccount(double initialBalance = 1000) : Account(initialBalance) {
        if (initialBalance < MIN_BALANCE) {
            balance = MIN_BALANCE;
        }
    }
    void withdraw(double amount) override {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        } else if (balance - amount < MIN_BALANCE) {
            cout << "Insufficient balance! Minimum balance must be " << MIN_BALANCE << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful! New balance: " << balance << endl;
        }
    }
};

class CurrentAccount : public Account {
public:
    CurrentAccount(double initialBalance = 0) : Account(initialBalance) {}
    void withdraw(double amount) override {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        } else if (balance - amount < 0) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful! New balance: " << balance << endl;
        }
    }
};

void getInput(double &amount) {
    while (!(cin >> amount)) {
        cout << "Invalid input! Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void getInput(int &choice) {
    while (!(cin >> choice)) {
        cout << "Invalid input! Please enter a valid number: ";
        cin.clear(); // clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void savingsAccountMenu(SavingsAccount &account) {
    int choice;
    double amount;

    do {
        cout << "\nSavings Account Menu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Back\n";
        cout << "Enter your choice: ";
        getInput(choice);
   		system("cls");

        switch (choice) {
        
            case 1:
                cout << "Enter deposit amount: ";
                getInput(amount);
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                getInput(amount);
                account.withdraw(amount);
                break;
            case 3:
                account.checkBalance();
                break;
            case 4:
                cout << "Returning to main menu.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
}

void currentAccountMenu(CurrentAccount &account) {
    int choice;
    double amount;

    do {
        cout << "\nCurrent Account Menu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Back\n";
        cout << "Enter your choice: ";
        getInput(choice);
		system("cls");

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                getInput(amount);
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                getInput(amount);
                account.withdraw(amount);
                break;
            case 3:
                account.checkBalance();
                break;
            case 4:
                cout << "Returning to main menu.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
}

int main() {
		cout << "====================================\n";
	    cout << "  Welcome to Simple Bank System!\n";
	    cout << "  Manage your Savings and Current\n";
	    cout << "  accounts with ease.\n";
	    cout << "====================================\n";
	    
    SavingsAccount savings(1000);
    CurrentAccount current(0);
    
    int choice;
    do {
        cout << "\nMain Menu:\n";
        cout << "1. Savings Account\n";
        cout << "2. Current Account\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        getInput(choice);
		system("cls");
        switch (choice) {
            case 1:
                savingsAccountMenu(savings);
                break;
            case 2:
                currentAccountMenu(current);
                break;
            case 3:
                cout << "Thank you for using the Simple Bank System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}