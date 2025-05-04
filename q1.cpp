#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("vehicles.txt");
    string line;
    if (!file.is_open())
    {
        cout << "Unable to open file" << endl;
        return 1;
    }

    while (getline(file, line))
    {
        if((line[0] == '/' && line[1] == '/') || line.empty())
        {
            continue;
        }
        cout << line << endl;
    }

    file.close();

    return 0;
}