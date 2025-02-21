#include <iostream>
using namespace std;

class Car {
    private:
        string brand;
        string model;
        float rental_price;
        bool availability_status;

    public:
        Car()
        {
            brand = "Unknown";
            model = "Generic";
            rental_price = 0.0;
            availability_status = true;
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
                cout << "Car successfully Rented"<< endl;
                availability_status = false;
            }
            else
            {
                cout << "Car is already Rented" << endl;
            }
            
        }
};

int main()
{
    Car carA;
    carA.setBrand("Toyota");
    carA.setModel("Corolla");
    carA.setRentalPrice(300.5);
    carA.rentalRequest();
    carA.rentalRequest();

    return 0;
}