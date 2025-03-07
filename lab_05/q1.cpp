#include <iostream>
using namespace std;

class Apartment{
    private:
        const int id;
        string address;
        string* ownerName;

    public:
        Apartment(int id) : id(id){};

        Apartment(int id, string add, string name) : id(id)
        {   
            address = add;
            ownerName = new string(name);
        }

        Apartment(const Apartment &obj) : id(obj.id) 
        {
            address = obj.address;
            ownerName = obj.ownerName;
        }

        void setAddress(string a)
        {
            address = a;
        }

        void setOwnerName(string n)
        {
            *ownerName = n;
        }

        void display()
        {
            cout << "Apartment ID: " << id << endl;
            cout << "Apartment Address: " << address << endl;
            cout << "Apartment Owner's Name: " << *ownerName << endl;
        }        
};

int main()
{
    Apartment A1(1000, "PECHS", "Aazmeer");
    Apartment A2(1001, "DHA", "Irfan");
    Apartment A3(1002, "SMCHS", "Talha");

    cout << "Agent 01 Handles..." << endl;
    cout << endl;

    cout << "Apartment A1------" << endl;
    A1.display();
    cout << endl;
    
    cout << "Apartment A2------" << endl;
    A2.display();
    cout << endl;
    
    cout << "Apartment A3------" << endl;
    A3.display();
    cout << endl;
    
    Apartment A4(A1);
    
    cout << "Apartment A1 tranfered to Agent 02" << endl;
    cout << endl;
    
    cout << "Apartment A4------" << endl;
    A4.display();
    cout << endl;
    
    A1.setOwnerName("Wasay");
    cout << "Apartment A1 after new owner------" << endl;
    A1.display();
    cout << endl;

    
    cout << "Apartment A4 after new owner------" << endl;
    A4.display();
}
