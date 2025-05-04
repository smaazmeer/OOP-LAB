#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outfile("large_log.txt");

    if (!outfile)
    {
        cout << "File could not be created." << endl;
        return 1;
    }

    outfile << "This is first part of log\n";
    outfile << "This is second part of log\n";
    outfile << "And this is third part";
    outfile.close();

    ifstream infile("large_log.txt");

    char temp[11];
    temp[10] = '\0';

    infile.read(temp, 10);
    cout << "Initial 10 characters: " << temp << endl;
    streampos pos1 = infile.tellg();
    cout << "Pointer location after reading first chunk: " << pos1 << endl;

    infile.read(temp, 10);
    cout << "Following 10 characters: " << temp << endl;
    streampos pos2 = infile.tellg();
    cout << "Pointer location after reading second chunk: " << pos2 << endl;

    infile.close();

    return 0;
}
