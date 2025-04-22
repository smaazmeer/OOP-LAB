#include <iostream>
using namespace std;

class WeatherSensor
{
    public:
        virtual void readData() = 0;
        virtual void displayReport() = 0;
        virtual ~WeatherSensor() {}
};

class Thermometer : public WeatherSensor
{
    private:
        float temperature;

    public:
        void readData()
        {
            temperature = 25.3; // auto assigning value read by the sensor
        }

        void displayReport()
        {
            cout << "Thermometer Reading: " << temperature << " °C" << endl;
        }
};

class Barometer : public WeatherSensor
{
    private:
        float pressure;

    public:
        void readData()
        {
            pressure = 1062.4; // auto assigning value read by the sensor
        }

        void displayReport()
        {
            cout << "Barometer Reading: " << pressure << " hPa" << endl;
        }
};

int main()
{
    Thermometer s1;
    Barometer s2;

    WeatherSensor* base;

    base = &s1;
    
    base->readData();
    base->displayReport();
    
    base = &s2;
    base->readData();
    base->displayReport();

    return 0;
}
