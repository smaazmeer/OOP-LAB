
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
        
        cout << "ID: " << id << endl;

        if (type == "AutonomousCar")
        {
            size_t pos = extra.find(":");
            if(pos == string::npos)
            {
                cout << ": not Found!" << endl;
            }
            else
            {
                string numstr = extra.substr(pos+1);
                float num = stof(numstr);
                cout << "EXTRA FLOAT VAL: " << num << endl;
            }
        }
        else if (type == "ElectricVehicle")
        {
            size_t pos = extra.find(":");
            if(pos == string::npos)
            {
                cout << ": not Found!" << endl;
            }
            else
            {
                string numstr = extra.substr(pos+1);
                int num = stoi(numstr);
                cout << "EXTRA INT VAL: " << num << endl;
            }
        }

        cout << "NAME: " << name << endl;
        cout << "TYPE: " << type << endl;
        cout << "YEAR: " << year << endl;
        cout << "EXTRA DATA: " << extra << endl;
        cout << "CERTIFICATION " << cert << endl;
        cout << endl;
    }

    file.close();

    return 0;
}      