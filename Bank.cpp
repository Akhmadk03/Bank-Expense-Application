#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    double balance;
    vector<pair<string, double>> expenses;

public:
    Account() : balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << endl;
        cout << "New Balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
            cout << "New Balance: $" << balance << endl;
        }
    }

    void addExpense(const string& description, double amount) {
        if (amount > balance) {
            cout << "Insufficient funds to cover expense." << endl;
        } else {
            expenses.push_back({description, amount});
            balance -= amount;
            cout << "Expense added: " << description << " - $" << amount << endl;
            cout << "New Balance: $" << balance << endl;
        }
    }

    void viewExpenses() {
        cout << "Expenses:" << endl;
        for (auto& expense : expenses) {
            cout << expense.first << " - $" << expense.second << endl;
        }
    }

    void viewBalance() {
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    Account myAccount;
    int choice;
    double amount;
    string description;

    do {
        cout << "\nBank Account Manager" << endl;
        cout << "1. View Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Add Expense" << endl;
        cout << "5. View Expenses" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myAccount.viewBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                myAccount.deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                myAccount.withdraw(amount);
                break;
            case 4:
                cout << "Enter expense description: ";
                cin >> description;
                cout << "Enter expense amount: ";
                cin >> amount;
                myAccount.addExpense(description, amount);
                break;
            case 5:
                myAccount.viewExpenses();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
