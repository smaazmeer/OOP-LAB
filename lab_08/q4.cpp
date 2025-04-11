#include <iostream>

using namespace std;

class Car
{
    private:
        string model;
        double price;

    public:
        Car()
        {
            model = "";
            price = 0;
        }

        Car(string m, double p)
        {
            model = m;
            price = p;
        }

        friend class InventoryManager;
        friend void comparePrice(const Car &a, const Car &b);
};

class InventoryManager
{
    public:
        void updatePrice(Car &car, double newPrice)
        {
            car.price = newPrice;
        }

        void displayCar(const Car &car)
        {
            cout << "Model: " << car.model << endl;
            cout << "Price: " << car.price << endl;
        }
};

void comparePrice(const Car &a, const Car &b)
{
    if (a.price > b.price)
    {
        cout << a.model << " is more expensive" << endl;
    }
    else if (b.price > a.price)
    {
        cout << b.model << " is more expensive" << endl;
    }
    else
    {
        cout << "Both cars have the same price" << endl;
    }
}

int main()
{
    Car car1("Sedan", 25000);
    Car car2("SUV", 30000);

    InventoryManager manager;

    cout << "Initial Car Details:" << endl;
    manager.displayCar(car1);
    manager.displayCar(car2);

    manager.updatePrice(car1, 32000);

    cout << "After Updating Price:" << endl;
    manager.displayCar(car1);

    comparePrice(car1, car2);

    return 0;
}
