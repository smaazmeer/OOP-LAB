#include <iostream>
#include <stdexcept>
using namespace std;


class ConnectionFailedException : public DatabaseException{};
class QueryTimeoutException : public DatabaseException{};

class DatabaseException : public exception
{
    public:
        string what()
        {
            return "A database error occurred.";
        }
};

template <typename T>
class DatabaseConnector
{
    private:
        T dbName;

    public:
        DatabaseConnector(T name) : dbName(name){}

        void connect()
        {
            if (dbName == "invalid_db")
            {
                throw ConnectionFailedException();
            }
            else if (dbName == "slow_db")
            {
                throw QueryTimeoutException();
            }
            else
            {
                cout << "Successfully connected to database: " << dbName << endl;
            }
        }
};

int main()
{
    try
    {
        cout << "Trying to reach slow_db...\n";
        DatabaseConnector<string> db2("slow_db");
        db2.connect();
    }
    catch (QueryTimeoutException& e)
    {
        cout << "Caught a general DatabaseException what(): " << e.what() << endl;
    }

    try
    {
        cout << "Trying to connect to invalid_db...\n";
        DatabaseConnector<string> db1("invalid_db");
        db1.connect();
    }
    catch (ConnectionFailedException& e)
    {
        cout << "Caught ConnectionFailedException what(): " << e.what() << endl;
    }

    return 0;
}
