#include <iostream>
using namespace std;

class MenuItem
{
    protected:
        string dishName;
        double price;

    public:
        MenuItem(string dishName, double price) : dishName(dishName), price(price){}

        virtual void showDetails() = 0;
        virtual void prepare() = 0;
};

class Appetizer : public MenuItem
{
    public:
        Appetizer(string name, double price) : MenuItem(name, price){}

        void showDetails()
        {
            cout << "SHOWING APPETIZERS DETAILS" << endl;
            cout << "NAME: " << dishName << endl;
        }
        
        void prepare()
        {
            cout << "PREPARING APPETIZER" << endl;
            cout << "----------------------" << endl;
        }

};

class MainCourse : public MenuItem
{
    public:
        MainCourse(string name, double price) : MenuItem(name, price){}

        void showDetails()
        {
            cout << "SHOWING MAIN COURSE DETAILS" << endl;
            cout << "NAME: " << dishName << endl;
        }
        
        void prepare()
        {
            cout << "PREPARING MAIN COURSE" << endl;
            cout << "----------------------" << endl;
        }

};

int main()
{
    Appetizer app("drinks", 70);
    MainCourse cor("Biryani", 100);
    
    MenuItem* base;

    base = &app;
    base->showDetails();
    base->prepare();

    base = &cor;
    base->showDetails();
    base->prepare();


}