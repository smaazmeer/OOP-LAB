#include <iostream>

using namespace std;

class Account
{
    private:
        int accountNumber;
        double balance;

    public:
        Account()
        {
            accountNumber = 0;
            balance = 0;
        }

        Account(int acc, double bal)
        {
            accountNumber = acc;
            balance = bal;
        }

        void display()
        {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
        }

        friend class Manager;
        friend void transferFunds(Account &from, Account &to, double amount);
};

class Manager
{
    public:
        void deposit(Account &acc, double amount)
        {
            acc.balance += amount;
        }

        void withdraw(Account &acc, double amount)
        {
            if (acc.balance >= amount)
            {
                acc.balance -= amount;
            }
            else
            {
                cout << "Insufficient funds" << endl;
            }
        }
};

void transferFunds(Account &from, Account &to, double amount)
{
    if (from.balance >= amount)
    {
        from.balance -= amount;
        to.balance += amount;
    }
    else
    {
        cout << "Transfer failed: insufficient funds" << endl;
    }
}

int main()
{
    Account acc1(1001, 5000);
    Account acc2(1002, 3000);

    Manager manager;

    cout << "Initial State:" << endl;
    acc1.display();
    acc2.display();

    manager.deposit(acc1, 2000);
    manager.withdraw(acc2, 1000);

    cout << "After deposit and withdrawal:" << endl;
    acc1.display();
    acc2.display();

    transferFunds(acc1, acc2, 2500);

    cout << "After transfer:" << endl;
    acc1.display();
    acc2.display();

    return 0;
}
