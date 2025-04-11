#include <iostream>
#include <string>
using namespace std;

class Person
{
    private:
        string name;
        int age;
        string contactNumber;
        string address;

    public:
        Person(string n, int a, string c, string addr = "")
        {
            name = n;
            age = a;
            contactNumber = c;
            address = addr;
        }

        virtual void displayInfo()
        {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Contact: " << contactNumber << endl;
            if (address != "")
            {
                cout << "Address: " << address << endl;
            }
        }

        virtual void updateInfo(string newContact, string newAddress)
        {
            contactNumber = newContact;
            address = newAddress;
        }
};

class Patient : public Person
{
    private:
        int patientID;
        string medicalHistory;
        string doctorAssigned;

    public:
        Patient(string n, int a, string c, int pid, string history, string doctor, string addr = "")
            : Person(n, a, c, addr)
        {
            patientID = pid;
            medicalHistory = history;
            doctorAssigned = doctor;
        }

        void displayInfo()
        {
            Person::displayInfo();
            cout << "Patient ID: " << patientID << endl;
            cout << "Medical History: " << medicalHistory << endl;
            cout << "Doctor Assigned: " << doctorAssigned << endl;
        }
};

class Doctor : public Person
{
    private:
        string specialization;
        double consultationFee;
        string patientsList;

    public:
        Doctor(string n, int a, string c, string spec, double fee, string plist, string addr = "")
            : Person(n, a, c, addr)
        {
            specialization = spec;
            consultationFee = fee;
            patientsList = plist;
        }

        void displayInfo()
        {
            Person::displayInfo();
            cout << "Specialization: " << specialization << endl;
            cout << "Consultation Fee: " << consultationFee << endl;
            cout << "Patients List: " << patientsList << endl;
        }
};

class Nurse : public Person
{
    private:
        string assignedWard;
        string shiftTimings;

    public:
        Nurse(string n, int a, string c, string ward, string shift, string addr = "")
            : Person(n, a, c, addr)
        {
            assignedWard = ward;
            shiftTimings = shift;
        }

        void displayInfo()
        {
            Person::displayInfo();
            cout << "Assigned Ward: " << assignedWard << endl;
            cout << "Shift Timings: " << shiftTimings << endl;
        }
};

class Administrator : public Person
{
    private:
        string department;
        double salary;

    public:
        Administrator(string n, int a, string c, string dept, double sal, string addr = "")
            : Person(n, a, c, addr)
        {
            department = dept;
            salary = sal;
        }

        void updateInfo(string newDept, double newSalary)
        {
            department = newDept;
            salary = newSalary;
        }

        void displayInfo()
        {
            Person::displayInfo();
            cout << "Department: " << department << endl;
            cout << "Salary: " << salary << endl;
        }
};

int main()
{
    Patient p1("Aazmeer", 25, "0333111222", 1001, "Asthma", "Dr. Irfan", "Bunji");
    Doctor d1("Irfan", 45, "0300123456", "Cardiology", 5000, "Aazmeer, Talha", "Lahore");
    Nurse n1("Rameel", 32, "0344555666", "Ward 5", "Night", "Multan");
    Administrator a1("Talha", 40, "0311777888", "HR", 90000, "Islamabad");

    cout << "--- Patient Info ---" << endl;
   p1.displayInfo();

    cout << endl << "--- Doctor Info ---" << endl;
    d1.displayInfo();

    cout << endl << "--- Nurse Info ---" << endl;
    n1.displayInfo();

    cout << endl << "--- Administrator Info ---" << endl;
    a1.displayInfo();

    return 0;
}
