#include <iostream>
using namespace std;

class Device
{
    protected:
        int deviceID;
        bool status;
    public:
        Device(int id, bool s)
        {
            deviceID = id;
            status = s;
        }

        void displayDetails()
        {
            cout << "Device ID: " << deviceID << endl;
            if (status)
            {
                cout << "Status: On" << endl;
            }
            else
            {
                cout << "Status: Off" << endl;
            }
        }
};

class SmartPhone :virtual public Device
{
    protected:
        float screenSize;
    public:
        SmartPhone(int id, bool s, float size) : Device(id, s), screenSize(size){}
        
        void displayDetails()
        {
            Device::displayDetails();
            cout << "Screen Size: " << screenSize<< endl;
        }
};

class SmartWatch : virtual public Device
{
    protected:
        bool heartRateMonitor;
    public:
        SmartWatch(int id, bool s, bool hrm) : Device(id, s), heartRateMonitor(hrm){}

        void displayDetails()
        {
            Device::displayDetails();
            if (heartRateMonitor)
            {
                cout << "Heart Rate Monitor: Yes" << endl;
            }
            else
            {
                cout << "Heart Rate Monitor: No" << endl;
            }
        }
};

class SmartWearable : public SmartPhone, public SmartWatch
    {
    private:
        int stepCounter;
    public:
        SmartWearable(int id, bool s, float size, bool hrm, int steps)
        : Device(id, s), 
        SmartPhone(id, s, size), 
        SmartWatch(id, s, hrm),
        stepCounter(steps){}
        
        void displayDetails()
        {
            SmartPhone::displayDetails();
            if (heartRateMonitor)
            {
                cout << "Heart Rate Monitor: Yes" << endl;
            }
            else
            {
                cout << "Heart Rate Monitor: No" << endl;
            }
            cout << "Step Counter: " << stepCounter << endl;
        }
};

int main()
{
    SmartWearable myDevice(101, true, 6.5, true, 12000);
    cout << "DISPLAYING DETAILS..." << endl;
    myDevice.displayDetails();

    return 0;
}
