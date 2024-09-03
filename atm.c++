#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, pair<string, double>> accounts; // Stores user ID, password, and balance
    string choice;
    string userID, password;
    double balance = 0.0;
    double deposit, withdraw;

    cout << "Hello. Welcome to the ATM machine\n";

    while (true) {
        cout << "\nPlease Choose an option below:\n";
        cout << "l -> Login\n";
        cout << "c -> Create a new account\n";
        cout << "q -> Quit\n";
        cout << "Enter your choice (l, c, q): ";
        cin >> choice;

        if (choice == "q") {
            cout << "Goodbye!";
            break;
        }
        
        if (choice == "c") {
            cout << "\nCreate an account\n";
            cout << "Please enter your user ID: ";
            cin >> userID;
            cout << "Please enter your password: ";
            cin >> password;
            // Creating an account with a 0 balance
            accounts[userID] = make_pair(password, 0.0);  
            cout << "Account created successfully!";
        } 
        else if (choice == "l") {
            cout << "\nLOG IN\n";
            cout << "Please enter your user ID: ";
            cin >> userID;
            cout << "Please enter your password: ";
            cin >> password;

            if (accounts.find(userID) != accounts.end() && accounts[userID].first == password) {
                cout << "Access Granted!\n";
                balance = accounts[userID].second;  // Load user's balance
                
                while (true) {
                    cout << "\nW -> Withdraw money\n";
                    cout << "D -> Deposit money\n";
                    cout << "B -> Request Balance\n";
                    cout << "q -> Quit\n";
                    cout << "Enter your choice (W, D, B, q): ";
                    cin >> choice;

                    if (choice == "q") {
                        accounts[userID].second = balance;  // Update balance before quitting
                        cout << "Goodbye!";
                        break;
                    } 
                    else if (choice == "D") {
                        cout << "\nDeposit money\n";
                        cout << "Amount to deposit: $";
                        cin >> deposit;
                        balance += deposit;
                        cout << "Deposit successful. Your Current balance: $" << balance << endl;
                    } 
                    else if (choice == "W") {
                        cout << "\nWithdraw money\n";
                        cout << "Amount to withdraw: $";
                        cin >> withdraw;
                        if (withdraw > balance) {
                            cout << "Insufficient funds!\n";
                        } else {
                            balance -= withdraw;
                            cout << "Withdrawal successful! Current balance: $" << balance << endl;
                        }
                    } 
                    else if (choice == "B") {
                        cout << "\nCheck balance\n";
                        cout << "Current balance: $" << balance << endl;
                    } 
                    else {
                        cout << "Invalid option!\n";
                    }
                }
            } else {
                cout << "*** Login failed ***\n";
            }
        } 
        else {
            cout << "Wrong option! Please try again.\n";
        }
    }

    return 0;
}