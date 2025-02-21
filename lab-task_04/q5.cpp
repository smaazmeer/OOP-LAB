#include <iostream>
using namespace std;

class Car {
    private:
        string* brand;
        string* model;
        float* rental_price;
        bool* availability_status;
        float revenue;
        int* regNumber;

        int days;
        float price;

    public:
        Car() // Default Constructor
        {
            brand = new string("Unknown");
            model = new string("Generic");
            rental_price = new float(0.0);
            availability_status = new bool(true);
            this->revenue = 0.0;
        }
        
        Car(int reg, string b, string m, float p, bool s) // Parameterized constructor
        {
            regNumber = new int(reg);
            brand = new string(b);
            model = new string(m);
            rental_price = new float(p);
            availability_status = new bool(s);
            this->revenue = 0.0;

        }
        
        Car(const Car &oldCar) // Copy Constructor
        {
            cout << "COPY CONSTRUCTOR CALLED" << endl;
            brand = new string(*oldCar.brand);
            model = new string(*oldCar.model);
            rental_price = new float(*oldCar.rental_price);
            availability_status = new bool(*oldCar.availability_status);
            this->revenue = oldCar.revenue;
            regNumber = new int(*oldCar.regNumber);
            
        }

        ~Car()
        {
            cout << "DESTRUCTOR CALLED" << endl;
            delete brand;
            delete model;
            delete rental_price;
            delete availability_status;
            delete regNumber;
        }

        void setAvailabilityStatus(bool a)
        {
            *availability_status = a;
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
                setAvailabilityStatus(false);
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
                updateRevenue(p);
                return;
            }
            else if(days > 10) 
            {
                p = p * 0.9;
                cout << "Rental Price after 10% discount: $" << p << endl;
                updateRevenue(p);
                return;
            }
            else
            {
                cout << "Rental Price: $" << p << endl;
                updateRevenue(p);
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

        void updateRevenue(float p)
        {
            revenue += p;
        }

        void displayRevenue()
        {
            cout << "Total Revenue generated: $" << revenue <<endl;
        }

        void displayCarDetails()
        {
            cout << "Registration Number: " << *regNumber<< endl;
            cout << "Brand: " << *brand<< endl;
            cout << "Model: " << *model<< endl;
            cout << "Rental Price: " << *rental_price<< endl;
            cout << "Rental Status: " << *availability_status<< endl;
            cout << "Total Revenue generated: " << revenue<< endl;
        }
};



int main()
{
    Car carA(1001, "Toyota", "Corolla", 100, true);
    
    
    carA.rentalRequest();
    carA.setAvailabilityStatus(true);

    carA.rentalRequest();
    carA.setAvailabilityStatus(true);

    carA.rentalRequest();
    carA.setAvailabilityStatus(true);

    carA.rentalRequest();

    carA.displayRevenue();

    carA.displayCarDetails();

    return 0;
}