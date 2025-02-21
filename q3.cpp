#include <iostream>
using namespace std;

class Car {
    private:
        string* brand;
        string* model;
        float* rental_price;
        bool* availability_status;
        int days;
        float price;
    public:
        Car() // Default Constructor
        {
            brand = new string("Unknown");
            model = new string("Generic");
            rental_price = new float(0.0);
            availability_status = new bool(true);
        }

        Car(string b, string m, float p, bool s) // Parameterized constructor
        {
            brand = new string(b);
            model = new string(m);
            rental_price = new float(p);
            availability_status = new bool(s);
        }
        
        Car(const Car &oldCar) // Copy Constructor
        {
            cout << "COPY CONSTRUCTOR CALLED" << endl;
            brand = new string(*oldCar.brand);
            model = new string(*oldCar.model);
            rental_price = new float(*oldCar.rental_price);
            availability_status = new bool(*oldCar.availability_status);
        }

        ~Car()
        {
            cout << "DESTRUCTOR CALLED" << endl;
            delete brand;
            delete model;
            delete rental_price;
            delete availability_status;
        }

        void setBrand(string b)
        {
            *brand = b;
        }

        void setModel(string m)
        {
            *model = m;
        }

        void setRentalPrice(float p)
        {
            *rental_price = p;
        }

        string getBrand()
        {
            return *brand;
        }

        string getModel()
        {
            return *model;
        }

        float getRentalPrice()
        {
            return *rental_price;
        }

        void rentalRequest()
        {
            if (*availability_status)
            {
                applyDiscount(*rental_price);
                cout << "Car successfully Rented"<< endl;
                *availability_status = false;
            }
            else
            {
                cout << "Car is already Rented" << endl;
            }
            
        }

        void applyDiscount(int p)
        {
            cout << "Enter number of days you want to rent the car for: ";
            cin >> days;
            p *= days;
            if (days > 5 && days <= 10)
            {
                p = p * 0.95;
                cout << "Rental Price after 5% discount: $" << p << endl;
                return;
            }
            else if(days > 10) 
            {
                p = p * 0.9;
                cout << "Rental Price after 10% discount: $" << p << endl;
                return;
            }
            else
            {
                cout << "Rental Price: $" << p << endl;
                return;
            }
            
        }

        void displayInfo()
        {
            cout << "Car Brand: " << *brand << endl;
            cout << "Car Model: " << *model << endl;
            cout << "Car Availability Status: " << *availability_status << endl;
            cout << "Car Rental Price: " << *rental_price << endl;
        }
};



int main()
{
    Car carA;
    carA.setBrand("Toyota");
    carA.setModel("Corolla");
    carA.setRentalPrice(100);
    cout << "CAR A DETAILS-----------" << endl;
    carA.displayInfo();
    cout << endl;
    
    Car carB = carA;
    
    cout << "CAR B DETAILS----------" << endl;
    carB.displayInfo();
    cout << endl;
    
    carA.setBrand("Honda");
    carA.setModel("civic");
    carA.setRentalPrice(200);
    cout << "MODIFIED CAR A DETAILS--------" << endl;
    carA.displayInfo();
    cout << endl;

    
    cout << "CAR B DETAILS----------" << endl;
    carB.displayInfo();
    cout << endl;

    carA.rentalRequest();
    carB.rentalRequest();
    carA.rentalRequest();
    

    return 0;
}