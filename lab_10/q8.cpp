#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream outfile("config.txt");
    outfile <<"AAAAABBBBBCCCCC";
    outfile.close();

    fstream file("config.txt",ios::in | ios::out);
    if(!file)
    {
        cout <<"Error in file" <<endl;
        return 1;
    }

    file.seekp(5);
    file.write("XXXXX",5);
    file.close();

    string line;

    ifstream infile("config.txt");
    getline(infile,line);
    cout << "UPDATED FILE: " << line <<endl;
    
    infile.close();

    return 0;

}