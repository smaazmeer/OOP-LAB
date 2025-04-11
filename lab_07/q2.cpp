#include <iostream>
using namespace std;

class Product
{
    protected:
        int productID;
        string productName;
        double price;
        int stockQuantity;

    public:
        Product(int id, string name, double pr, int stock = 0)
        {
            productID = id;
            productName = name;
            price = pr;
            stockQuantity = stock;
        }

        virtual double applyDiscount()
        {
            return price;
        }

        virtual double calculateTotalPrice(int quantity)
        {
            return applyDiscount() * quantity;
        }

        virtual void displayProductInfo()
        {
            cout << "Product ID: " << productID << endl;
            cout << "Name: " << productName << endl;
            cout << "Price: " << price << endl;
            cout << "Stock: " << stockQuantity << endl;
        }

        Product operator+(const Product &p)
        {
            return Product(productID, productName, price + p.price, stockQuantity + p.stockQuantity);
        }

        friend ostream &operator<<(ostream &out, const Product &p)
        {
            out << "Product ID: " << p.productID << endl;
            out << "Name: " << p.productName << endl;
            out << "Price: " << p.price << endl;
            out << "Stock: " << p.stockQuantity << endl;
            return out;
        }
};

class Electronics : public Product
{
    private:
        int warrantyPeriod;
        string brand;

    public:
        Electronics(int id, string name, double pr, int stock, int warranty, string br)
            : Product(id, name, pr, stock)
        {
            warrantyPeriod = warranty;
            brand = br;
        }

        void displayProductInfo()
        {
            Product::displayProductInfo();
            cout << "Warranty Period: " << warrantyPeriod << " months" << endl;
            cout << "Brand: " << brand << endl;
        }
};

class Clothing : public Product
{
    private:
        string size;
        string color;
        string fabricMaterial;

    public:
        Clothing(int id, string name, double pr, int stock, string s, string c, string f)
            : Product(id, name, pr, stock)
        {
            size = s;
            color = c;
            fabricMaterial = f;
        }

        double applyDiscount()
        {
            return price * 0.9;
        }
};

class FoodItem : public Product
{
    private:
        string expirationDate;
        int calories;

    public:
        FoodItem(int id, string name, double pr, int stock, string exp, int cal)
            : Product(id, name, pr, stock)
        {
            expirationDate = exp;
            calories = cal;
        }

        double calculateTotalPrice(int quantity)
        {
            if (quantity >= 10)
            {
                return price * quantity * 0.85;
            }
            return price * quantity;
        }
};

class Book : public Product
{
    private:
        string author;
        string genre;

    public:
        Book(int id, string name, double pr, int stock, string a, string g)
            : Product(id, name, pr, stock)
        {
            author = a;
            genre = g;
        }

        void displayProductInfo()
        {
            Product::displayProductInfo();
            cout << "Author: " << author << endl << "Genre: " << genre << endl;
        }
};

int main()
{
    Electronics e(101, "Smartphone", 50000, 20, 24, "Samsung");
    Clothing c(102, "Shirt", 1500, 50, "L", "Blue", "Cotton");
    FoodItem f(103, "Choclate", 300, 100, "21-05-2025", 250);
    Book b(104, "Investing 101", 1200, 30, "Aazmeer", "Investing");

    cout << "--- Electronics ---" << endl;
    e.displayProductInfo();
    cout << "\n--- Clothing ---" << endl;
    c.displayProductInfo();
    cout << "\n--- Food Item ---" << endl;
    f.displayProductInfo();
    cout << "\n--- Book ---" << endl;
    b.displayProductInfo();

    cout << "\nTotal price for 12 food items (bulk discount): " << f.calculateTotalPrice(12) << endl;

    Product p1 = f;
    Product p2 = f;
    Product p3 = p1 + p2;
    cout << "\n--- Combined Product Info ---" << endl;
    cout << p3;

    cout << "\n--- Output with operator<< ---" << endl;
    cout << c;

    return 0;
}
