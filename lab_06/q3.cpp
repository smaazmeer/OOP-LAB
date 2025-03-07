#include <iostream>
using namespace std;

class Person
{   
    protected:
        string name;
        int age;    
    public:
        Person(string name, int age) : name(name), age(age){}

        void displayDetails()
        {
            cout << "DISPLAYING PERSON DETAILS..." << endl;
            cout << "NAME: " << name << endl;
            cout << "AGE: " << age << endl;
            cout << "------------------------" <<endl;
        }
};

class Teacher : virtual public Person
{
    protected:
        string subject;
    public:
        Teacher(string name, int age, string subject) : Person(name, age), subject(subject){}

        void displayDetails()
        {  
            cout << "DISPLAYING TEACHER DETAILS..." << endl;
            cout << "NAME: " << name << endl;
            cout << "AGE: " << age << endl;
            cout << "SUBJECT: " << subject << endl;
            cout << "------------------------" <<endl;
        }
};

class Researcher : virtual public Person
{
    protected:
        string researchArea;
    public:
        Researcher(string name, int age, string researchArea) : Person(name, age), researchArea(researchArea){}

        void displayDetails()
        {
            cout << "DISPLAYING Researcher DETAILS..." << endl;
            cout << "NAME: " << name << endl;
            cout << "AGE: " << age << endl;
            cout << "Research Area: " << researchArea << endl;
            cout << "------------------------" <<endl;
        }

};

class Professor : public Teacher, public Researcher
{
    private:
        int publications;
    
    public:
        Professor(string name, int age, string subject, string researchArea, int publications) :
        Person(name, age),
        Teacher(name, age, subject),
        Researcher(name, age, researchArea),
        publications(publications){}

        void displayDetails()
        {
            cout << "DISPLAYING Professor DETAILS..." << endl;
            cout << "NAME: " << name << endl;
            cout << "AGE: " << age << endl;
            cout << "SUBJECT: " << subject << endl;
            cout << "Research Area: " << researchArea << endl;
            cout << "Publcations: " << publications << endl;
            cout << "------------------------" <<endl;
        }
};

int main()
{
    string name, subject, researchArea;
    int age, publications;

    cout << "Enter Professor's Name: ";
    cin >> name;

    cout << "Enter Professor's Age: ";
    cin >> age;
    cin.ignore();  

    cout << "Enter Subject Expertise: ";
    cin >> name;

    cout << "Enter Research Area: ";
    cin >> researchArea;

    cout << "Enter Number of Publications: ";
    cin >> publications;

    Professor prof(name, age, subject, researchArea, publications);

    prof.displayDetails();

    return 0;
}
