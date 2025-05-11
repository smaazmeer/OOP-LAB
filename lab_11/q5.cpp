#include <iostream>
#include <stdexcept>
using namespace std;

class NegativeStockException : public exception{};
class OverCapacityStockException : public exception{};

template <typename T>
class InventoryItem
{
    private:
        T quantity;
        const int maxLimit;

    public:
        InventoryItem(T quantity)
            : quantity(quantity), maxLimit(100)
        {
        }

        void validateStock()
        {
            if (quantity < 0)
            {
                throw NegativeStockException();
            }
            else if (quantity > maxLimit)
            {
                throw OverCapacityStockException();
            }
            else
            {
                cout << "Stock level is acceptable." << endl;
            }
        }
};

int main()
{
    try
    {
        InventoryItem<int> item1(50);
        cout << "Checking stock level of 50..." << endl;
        item1.validateStock();

        InventoryItem<double> item2(120);
        cout << "Setting stock level to 120..." << endl;
        item2.validateStock();
    }
    catch (OverCapacityStockException &e)
    {
        cout << "Caught OverCapacity Exception: " << e.what() << endl;
    }

    try
    {
        InventoryItem<int> item3(-5);
        cout << "Setting stock level to -5..." << endl;
        item3.validateStock();
    }
    catch (NegativeStockException &e)
    {
        cout << "Caught NegativeStockException: " << e.what() << endl;
    }

    return 0;
}
