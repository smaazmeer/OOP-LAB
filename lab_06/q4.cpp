#include <iostream>
using namespace std;

class Account
{
    protected:
        int accountNumber;
        float balance;
    public:
        Account(int accNum, float bal)
        {
            accountNumber = accNum;
            balance = bal;
        }

        void displayDetails()
        {
            cout << "DISPLAYING DETAILS..." << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
            cout << "--------------------------------" << endl;
        }
};

class SavingsAccount : public Account
{
    private:
        float interestRate;
    public:
        SavingsAccount(int accNum, float bal, float rate) : Account(accNum, bal)
        {
            interestRate = rate;
        }

        void displayDetails()
        {
            cout << "DISPLAYING DETAILS..." << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
            cout << "Interest Rate: " << interestRate << "%" << endl;
            cout << "--------------------------------" << endl;
        }
};

class CheckingAccount : public Account
{
    private:
        float overDraftLimit;
    public:
        CheckingAccount(int accNum, float bal, float limit) : Account(accNum, bal)
        {
            overDraftLimit = limit;
        }

        void displayDetails()
        {
            cout << "DISPLAYING DETAILS..." << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
            cout << "Overdraft Limit: " << overDraftLimit << endl;
            cout << "--------------------------------" << endl;
        }
};

int main()
{
    SavingsAccount Aazmeer(12345, 50000, 3.5);
    CheckingAccount Irfan(67890, 20000, 10000);

    cout << "Savings Account Details:" << endl;
    Aazmeer.displayDetails();
    cout << endl;

    cout << "Checking Account Details:" << endl;
    Irfan.displayDetails();

    return 0;
}
