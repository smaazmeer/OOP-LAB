#include <iostream>
using namespace std;

class Doctor{
    private:
        string name;
        string specialization;
        string experience;

    public:
        Doctor(){};

        Doctor(string name, string specialization, string experience) : name(name), specialization(specialization), experience(experience){};

        void setName(string n)
        {
            name = n;
        }

        void setSpecialization(string n)
        {
            specialization = n;
        }

        void setExperience(string e)
        {
            experience = e;
        }

        string getName(){return name;};
        string getSpecialization(){return specialization;};
        string getExperience(){return experience;};

};

class Hospital{
    private:
        string name;
        Doctor** doctors;
        int doctorIndex;

    public:
        Hospital()
        {
            doctors = new Doctor*[3];
            doctorIndex = 0;
        }

        ~Hospital()
        {
            for (int i = 0; i < 3; i++)
            {
                delete doctors[i];
            }
            delete[] doctors;
        }

        void setName(string n)
        {
            name = n;
        }

        string getName(){return name;};

        void addDoctor(Doctor* doc)
        {
            if (doctorIndex < 3)
            {
                doctors[doctorIndex++] = doc;
                cout << "Doctor added to Hospital " << this->name << endl; 
            }
            else
            {
                cout << "Doctor limit for a hospital Reached" << endl;
            }
            
        }

        void displayDetails()
        {
            cout << "HOSPITAL " << this->name << " DETAILS---" << endl;
            cout << "Doctors working in the hospital: " << endl;
            for (int i = 0; i < doctorIndex; i++)
            {
                cout << i+1 <<". " << doctors[i]->getName() << endl;
            }
            
        }
};

int main()
{
    Hospital myHospital;
    Hospital yourHospital;

    Doctor doc1("Aazmeer", "Dentist", "3 years");
    Doctor doc2("Rameel", "Dermatologist", "1 year");
    Doctor doc3("Irfan", "Cardiologist", "5 years");
    
    myHospital.setName("City Hospital");
    yourHospital.setName("Town Hospital");

   myHospital.addDoctor(&doc1);
   myHospital.addDoctor(&doc2);
   myHospital.addDoctor(&doc3);

   yourHospital.addDoctor(&doc1);
   yourHospital.addDoctor(&doc3);


    cout << endl;
    myHospital.displayDetails();
    cout << endl;
    yourHospital.displayDetails();

    return 0;
}
