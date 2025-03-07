#include <iostream>
using namespace std;

class Employee
{
    protected:
        string name;
        float salary;
    
    public:
        Employee(string name, float salary) : name(name), salary(salary){}

        void setName(string n){name = n;};
        void setSalary(float s){salary = s;};

        string getName(){return name;};
        float getSalary(){return salary;};

        void displayDetails()
        {
            cout << "DISPLAYING EMPLOYEE DETAILS..." << endl;
            cout << "Employee Name: " << name << endl;
            cout << "Employee Salary: " << salary << endl;
            cout << "--------------------------------------" << endl;
        }
};

class Manager : public Employee
{
    private:
        float bonus;

    public:
        Manager(string name, float salary, float bonus) : Employee(name, salary), bonus(bonus){}

        void displayDetails()
        {
                cout << "DISPLAYING Manager DETAILS..." << endl;
                cout << "Manager Name: " << name << endl;
                cout << "Manager Salary: " << salary << endl;
                cout << "Manager Bonus: " << bonus << endl;
                cout << "--------------------------------------" << endl;
        }

        void setBonus(float b){bonus = b;};

        float getBonus(){return bonus;};
};

int main()
{
    string name;
    float salary, bonus;

    cout << "Enter Manager Name: ";
    cin >> name;

    cout << "Enter Manager Salary: ";
    cin >> salary;

    cout << "Enter Manager Bonus: ";
    cin >> bonus;

    Manager manager(name, salary, bonus);
    manager.displayDetails();

    return 0;
}
