#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class InventoryItem
{
    private:
        int itemID;
        char itemName[20];

    public:
        InventoryItem() {}

        InventoryItem(int id, const char* name)
        {
            itemID = id;
            strncpy(itemName, name, sizeof(itemName) - 1);
            itemName[sizeof(itemName) - 1] = '\0';
        }

        void printItem()
        {
            cout << "Item Details -> ID: " << itemID << ", Name: " << itemName << endl;
        }
};

int main()
{
    InventoryItem savedItem(501, "Mouse");

    ofstream fileOut("inventory.dat", ios::binary);
    fileOut.write((char*)(&savedItem), sizeof(savedItem));
    fileOut.close();

    InventoryItem loadedItem;

    ifstream fileIn("inventory.dat", ios::binary);
    fileIn.read((char*)(&loadedItem), sizeof(loadedItem));
    fileIn.close();

    cout << "Data read from binary file:" << endl;
    loadedItem.printItem();

    return 0;
}
