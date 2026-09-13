#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    BankAccount(int number, string name, double initialBalance) {
        accountNumber = number;
        holderName = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount.\n";
            return;
        }

        balance += amount;
        cout << "Amount deposited successfully.\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
            return;
        }

        if (amount > balance) {
            cout << "Insufficient balance.\n";
            return;
        }

        balance -= amount;
        cout << "Amount withdrawn successfully.\n";
    }

    void displayAccount() const {
        cout << "\n---------- Account Details ----------\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << holderName << endl;
        cout << "Balance       : ₹"
             << fixed << setprecision(2) << balance << endl;
        cout << "-------------------------------------\n";
    }
};

int main() {
    int accountNumber;
    string holderName;
    double initialBalance;

    cout << "====================================\n";
    cout << "       BANK ACCOUNT MANAGEMENT      \n";
    cout << "====================================\n";

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    cin.ignore();

    cout << "Enter Account Holder Name: ";
    getline(cin, holderName);

    cout << "Enter Initial Balance: ₹";
    cin >> initialBalance;

    if (initialBalance < 0) {
        cout << "Initial balance cannot be negative.\n";
        return 0;
    }

    BankAccount account(accountNumber, holderName, initialBalance);

    int choice;
    double amount;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. View Account Details\n";
        cout << "4. Exit\n";
        cout << "==========================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter deposit amount: ₹";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Enter withdrawal amount: ₹";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                account.displayAccount();
                break;

            case 4:
                cout << "\nThank you for using the system.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}