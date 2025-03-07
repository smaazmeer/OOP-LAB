#include <iostream>
using namespace std;

class employees
{
    private:
        string name;
        string designation;

    public:
        employees(){};

        void setName(string n){name = n;};
        void setDesignation(string d){designation = d;};

        string getName(){return name;};
        string getDesignation(){return designation;};

};

class projects{
    private:
        string title;
        string deadline;
        employees** assignEmployee;
        int employeeIndex;        

    public:        
        projects()
        {
            assignEmployee = new employees*[10];
            employeeIndex = 0;
        }

        void setTitle(string t){title = t;};
        void setDeadline(string d){deadline = d;};

        string getTitle(){return title;};
        string getDeadline(){return deadline;};

        void addEmployees(employees* emp)
        {
            if(employeeIndex < 10)
            {
                assignEmployee[employeeIndex++] = emp;
                cout << emp->getName() << " Assigned to Project " << this->getTitle() << endl;
            }
            else
            {
                cout << "Max Employee Limit reached" << endl;
            }
        }

        void displayDetails()
        {
            cout << "Project Title: " << title << endl;
            cout << "Project deadline: " << deadline << endl;
            cout << "Employees Working on the project-- " << endl;

            for (int i = 0; i < employeeIndex; i++)
            {
                cout << i+1 << ". " << assignEmployee[i]->getName() << endl;
            }
        }

        ~projects(){
            for (int i = 0; i < 10 ; i++)
            {
                delete assignEmployee[i];
            }
            delete assignEmployee;
        }
};

int main()
{
    employees e1, e2, e3;

    e1.setName("Ali");
    e1.setDesignation("Data Analsyt");

    e2.setName("Irfan");
    e2.setDesignation("Engineer");

    e3.setName("Aazmeer");
    e3.setDesignation("Trader");
    
    projects p1;
    p1.setTitle("Company Website");
    p1.setDeadline("31/05/2025");
    
    projects p2;
    p2.setTitle("Company App");
    p2.setDeadline("01/04/2025");

    p1.addEmployees(&e1);
    p1.addEmployees(&e2);
    p1.addEmployees(&e3);
    
    p2.addEmployees(&e1);
    p2.addEmployees(&e3);

    cout << "\n--- Project 01 Details ---\n";
    p1.displayDetails();

    cout << "\n--- Project 02 Details ---\n";
    p2.displayDetails();

    return 0;
}
