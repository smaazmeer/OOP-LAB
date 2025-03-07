#include <iostream>
using namespace std;

class Vehicle{
    protected:
        string brand;
        int speed;
    
    public:
        Vehicle(string brand, int speed) : brand(brand), speed(speed){}

        void displayDetails()
        {
            cout << "DISPLAYING VEHICLE DETAILS..." << endl;
            cout << "Brand: " << brand << endl;
            cout << "Speed: " << speed << endl;
            cout << "-------------"<< endl;
        }
};

class Car : public Vehicle
{
    protected:
        int seats;

    public:
        Car(int seats, string brand, int speed) : Vehicle(brand, speed), seats(seats){}

        void displayDetails()
        {
            cout << "DISPLAYING CAR DETAILS..." << endl;
            cout << "Brand: " << brand << endl;
            cout << "Speed: " << speed << endl;
            cout << "Seats: " << seats << endl;
            cout << "----------------------" << endl;
        }
};

class ElectricCar : public Car
{
    private:
        int batteryLife;

    public:
        ElectricCar(int batteryLife, string brand, int speed, int seats) : Car(seats, brand, speed), batteryLife(batteryLife){}

        void displayDetails()
        {
            cout << "DISPLAYING ELECTRIC CAR DETAILS..." << endl;
            cout << "Brand: " << brand << endl;
            cout << "Speed: " << speed << endl;
            cout << "Seats: " << seats << endl;
            cout << "Battery Life: " << batteryLife << endl;
            cout << "----------------------" << endl;
        }
};

int main()
{
    string brand;
    int speed, seats, batteryLife;

    cout << "Enter Electric Car Brand: ";
    cin >> brand;

    cout << "Enter Electric Car Speed: ";
    cin >> speed;

    cout << "Enter Number of Seats: ";
    cin >> seats;

    cout << "Enter Battery Life (in hours): ";
    cin >> batteryLife;

    ElectricCar eCar(batteryLife, brand, speed, seats);
    eCar.displayDetails();

    return 0;
}
