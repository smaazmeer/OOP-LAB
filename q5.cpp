
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
        else if(type == "HybridTruck")
        {
            size_t colonpos = extra.find(":");
            size_t pipepos = extra.find("|");

            if(colonpos == string::npos || pipepos == string::npos)
            {
                cout << ": or | not Found!" << endl;
            }
            else
            {
                string battery = extra.substr(pipepos+1);
                size_t battpos = battery.find(":");
                if(battpos == string::npos)
                {
                cout << ": not Found!" << endl;
                }
                int cargo = stoi(extra.substr(colonpos+1, pipepos-colonpos-1));
                cout << "CARGO INT VAL: " << cargo << endl;
                string battstr = battery.substr(battpos+1);
                int pipe = stoi(battstr);
                cout << "BATTERY INT VAL: " << pipe << endl;
            }
        }
        else
        {
            cout << "VEHICLE NOT FOUND!" << endl;
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