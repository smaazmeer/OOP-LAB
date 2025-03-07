#include <iostream>
using namespace std;

class products
{
    private:
        const int uniqueID;
        string name;
        int quantityInStock;

    public:
        products(int id) : uniqueID(id){};

        products(int id, string name, int quant) : uniqueID(id), name(name), quantityInStock(quant){};

        void setName(string n)
        {
            name = n;
        }

        void setQuantity(int q)
        {
            quantityInStock = q;
        }

        int getID(){return uniqueID;};
        string getName(){return name;};
        int getQuantity(){return quantityInStock;};

        void displayDetails()
        {
            cout << "-------------------------------" << endl;
            cout << "Product ID: " << uniqueID << endl;
            cout << "Product Name: " << name << endl;
            cout << "Poduct Quantity: " << quantityInStock << endl;
            cout << "-------------------------------" << endl;
        }
};

class WareHouse{
    private:
        products** Inventory;
        int invenIndex;
        products* temp;
    public:
        WareHouse()
        {
            Inventory = new products*[10];
            invenIndex = 0;
        }

        ~WareHouse()
        {
            for (int i = 0; i < 10; i++)
            {
                delete Inventory[i];
            }
            delete Inventory;
        }

        void storeProducts(string name, int quantity)
        {
            if (invenIndex < 10)
            {
                Inventory[invenIndex]->setName(name);
                Inventory[invenIndex++]->setQuantity(quantity);
                cout << quantity << " " << name << " added to the inventory" << endl;
            }
            else
            {
                cout << "Product Limit in Inventory Reached!" << endl;
            }
            
        }
        
        void sortInventory()
        {
            for (int i = 0; i < invenIndex; i++)
            {
                for (int j = 0; j < invenIndex; j++)
                {
                    if (Inventory[j]->getName() > Inventory[j+1]->getName())
                    {
                        temp = Inventory[j];
                        Inventory[j] =  Inventory[j+1];
                        Inventory[j+1] = temp;
                    }
                }
                
            }
            
        }

        void SearchItem(int id)
        {
            for (int i = 0; i < invenIndex; i++)
            {
                if (Inventory[i]->getID() == id)
                {
                    Inventory[i]->displayDetails();
                    break;
                }
                
            }
            
        }

        
};