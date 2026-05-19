//Design and implement a C++ program to model a banking system where the class
//BankAccount keeps track of the total number of accounts created and the total
//balance across all accounts. Use static data members to maintain these values and
//static member functions to retrieve and display them. Additionally, implement a
//member function in the BankAccount class that takes another BankAccount object as
//an argument and displays the two account balances in ascending order

#include <iostream>
using namespace std;

class BankAccount
{
    int accNo;
    float balance;

    static int totalAcc;
    static float totalBal;

public:
    void createAccount(int no, float bal)
    {
        accNo = no;
        balance = bal;
        totalAcc++;
        totalBal += balance;
    }

    float getBalance()
    {
        return balance;
    }
    
    static void showTotal()
    {
        cout << "Total Accounts: " << totalAcc << endl;
        cout << "Total Balance: " << totalBal << endl;
    }

    void showAscending(BankAccount other)
    {
        cout << "Balances in Ascending Order: ";
        if (balance < other.balance)
            cout << balance << " " << other.balance;
        else
            cout << other.balance << " " << balance;
        cout << endl;
    }
};

int BankAccount::totalAcc = 0;
float BankAccount::totalBal = 0;

int main()
{
    BankAccount a1, a2;

    a1.createAccount(1, 82000);
    a2.createAccount(2, 10000);
 
    BankAccount::showTotal();
    a1.showAscending(a2);

    return 0;
}

