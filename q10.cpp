#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile("data_records.txt");
    if (!infile)
    {
        cout << "Could not open the file." << endl;
        return 1;
    }

    infile.seekg(18, ios::beg);

    string line;
    getline(infile, line);
    cout << "Line at offset 18: " << line << endl;

    infile.close();
    return 0;
}
