#include <iostream>
using namespace std;

class Car {
    private:
        string brand;
        string model;
        float rental_price;
        bool availability_status;
        int days;
        float price;
    public:
        Car()
        {
            brand = "Unknown";
            model = "Generic";
            rental_price = 0.0;
            availability_status = true;
        }

        Car(string b, string m, float p, bool s)
        {
            brand = b;
            model = m;
            rental_price = p;
            availability_status = s;
        }

        void setBrand(string b)
        {
            brand = b;
        }

        void setModel(string m)
        {
            model = m;
        }

        void setRentalPrice(float p)
        {
            rental_price = p;
        }

        string getBrand()
        {
            return brand;
        }

        string getModel()
        {
            return model;
        }

        float getRentalPrice()
        {
            return rental_price;
        }

        void rentalRequest()
        {
            if (availability_status)
            {
                applyDiscount(rental_price);
                cout << "Car successfully Rented"<< endl;
                availability_status = false;
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
};

int main()
{
    Car carA;
    carA.setBrand("Toyota");
    carA.setModel("Corolla");
    carA.setRentalPrice(100);
    carA.rentalRequest();
    carA.rentalRequest();

    return 0;
}