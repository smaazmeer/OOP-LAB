#include <iostream>
using namespace std;

class Patient
{
    protected:
        string name;
        string id;

    public:
        Patient(string name, string id) : name(name), id(id){}

        virtual void displayTreatment() = 0;
        virtual void calculateCost() = 0;

};

class InPatient : public Patient
{
    public:
        InPatient(string name, string id) : Patient(name, id){}

        void displayTreatment()
        {
            cout << "DISPLAYING INPATIENT TREATMENT" << endl;
        }

        void calculateCost()
        {
            cout << "CALCULATING INPATIENT COST" << endl;
        }
};

class OutPatient : public Patient
{
    public:
        OutPatient(string name, string id) : Patient(name, id){}

        void displayTreatment()
        {
            cout << "DISPLAYING OutPATIENT TREATMENT" << endl;
        }

        void calculateCost()
        {
            cout << "CALCULATING OutPATIENT COST" << endl;
        }
};

int main()
{
    InPatient in("Meer", "0545");
    OutPatient out("Irfan", "8456");

    Patient* base;

    base = &in;
    base->displayTreatment();
    base->calculateCost();

    base = &out;
    base->displayTreatment();
    base->calculateCost();
}