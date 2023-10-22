#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
    string account;
    string userName;
    string password;
    double balance;
    static int count;
    static double rate;
    double interest();

public:
    Account();
    void save();
    void withdraw();
    void printInfo();
};

int Account::count = 0;
double Account::rate = 0.0025;

Account::Account()
{
    cout << "[Creating a new account...]" << endl;
    cout << "Your account number: ";
    cin >> account;
    cout << "Your user name: ";
    cin >> userName;
    cout << "Your password: ";
    cin >> password;
    balance = 0.0;
    cout << "Account created successfully.\n" << endl;
}

void Account::save()
{
    cout << "[Saving...]" << endl;
    double money;
    string pswd;
    cout << "How much do you want to save: $";
    cin >> money;
    cout << "Input your password: ";
    cin >> pswd;
    if (pswd == password)
    {
        balance += money;
        cout << "$" << money << " has been saved into your account.\n" << endl;
    }
    else
    {
        cout << "Wrong password.\n" << endl;
    }
}

void Account::withdraw()
{
    cout << "[Withdrawing...]" << endl;
    double money;
    string pswd;
    cout << "How much do you want to withdraw: $";
    cin >> money;
    cout << "Input your password: ";
    cin >> pswd;
    if (pswd == password)
    {
        balance -= money;
        cout << "$" << money << " has been withdrawn.\n" << endl;
    }
    else
    {
        cout << "Wrong password.\n" << endl;
    }
}

double Account::interest()
{
    return balance * rate;
}

/*
============= INFO =============
Account:        account
User name:      userName
Balance:        $balance
Current rate:   rate
Interest:       $interest()
================================
*/
void Account::printInfo()
{
    cout << "[Printing your account information...]\n"
         << "============= INFO =============\n"
         << "Account:\t" << account << "\n"
         << "User name:\t" << userName << "\n"
         << "Balance:\t$" << balance << "\n"
         << "Current rate:\t" << rate << "\n"
         << "Interest:\t$" << interest() << "\n"
         << "================================" << endl;
}

int main()
{
    cout << "welcome.\n" << endl;
    // create
    Account a;
    // operate
    a.save(); // test wrong password
    a.save();
    a.withdraw(); // test wrong password
    a.withdraw();
    // show info
    a.printInfo();
    return 0;
}