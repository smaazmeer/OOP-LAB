#include<iostream>
#include<fstream>
using namespace std;


int main()
{

    ofstream file("sensor_log.txt");
    if(!file)
    {
        cout << "Error creating file" << endl;
        return 1;
    }
    
    file << "Sensor 1: 25.5 C\n";
    streampos pos_1 = file.tellp();
    cout <<"First line: " << pos_1 <<endl;

    file <<"Sensor 2: 98.1 %RH\n";
    streampos pos_2 = file.tellp();
    cout <<"Second line: " << pos_2 <<endl;
    
    file.close();
    return 0;
}