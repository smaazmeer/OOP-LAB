#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ifstream file("vehicles.txt");
    string line, type, id, name, year, extra, cert;
    int year_value;

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

        istringstream details(line);
        getline(details, type, ',');
        getline(details, id, ',');
        getline(details, name, ',');
        getline(details, year, ',');
        getline(details, extra, ',');
        getline(details, cert, ',');

        year_value = stoi(year);

        cout << "ID: " << id << endl;
        cout << "NAME: " << name << endl;
        cout << "TYPE: " << type << endl;
        cout << "YEAR: " << year << endl;
        cout << "YEAR INT VALUE: " << year_value << endl;
        cout << "EXTRA DATA: " << extra << endl;
        cout << "CERTIFICATION " << cert << endl;
        cout << endl;
    }

    file.close();

    return 0;
}