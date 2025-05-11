#include <iostream>
#include <stdexcept>
using namespace std;

class InvalidTemperatureException : public exception{};

template <typename T>
T convertToFahrenheit(T celsius)
{
    if (celsius < -273.15)
    {
        throw InvalidTemperatureException();
    }
    return (celsius * 1.8) + 32;
}

int main()
{
    try
    {
        cout << "Converting 25°C to Fahrenheit...\n";
        double result1 = convertToFahrenheit(25.0);
        cout << "Result: " << result1 << "°F\n";

        cout << "Now converting -300°C to Fahrenheit...\n";
        double result2 = convertToFahrenheit(-300.0);
        cout << "Result: " << result2 << "°F\n";
    }
    catch (InvalidTemperatureException &e)
    {
        cout << "Caught InvalidTemperatureException what(): " << e.what() << endl;
    }

    return 0;
}
