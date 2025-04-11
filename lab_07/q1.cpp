#include <iostream>
using namespace std;

class Device
{
    protected:
        int deviceID;
        string deviceName;
        string status;
        
    public:
        Device(int id, string name, string status) : deviceID(id), deviceName(name), status(status){}
        
        void turnOn()
        {
            status = "on";
            cout << "DEVICE TURNED ON" << endl;
        }
        
        void turnOff()
        {
            status = "off";
            cout << "DEVICE TURNED OFF" << endl;
        }

        void getStatus()
        {
            cout << "DEVICE STATUS: "  << status << endl;
        }

        void displayInfo()
        {
            cout << "-------------------------" << endl;
            cout << "DEVICE ID: " << deviceID << endl;
            cout << "DEVICE Name: " << deviceName << endl;
            cout << "DEVICE STATUS: "  << status << endl;
        }
};
    
class Light : public Device
{
    private:
    int brightnessLevel;
    string colorMode;

    public:
        Light(int id, string name, string status, int lvl, string mode) : Device(id, name, status), brightnessLevel(lvl), colorMode(mode){}

        void displayInfo()        
        {
            Device::displayInfo();
            cout << "BRIGHTNESS LEVEL: " << brightnessLevel << endl;
            cout << "COLOR MODE: " << colorMode << endl;
            cout << "-------------------------" << endl;
        }
};
    
class Thermostat : public Device
{
    private:
        double temperature;
        string mode;
        double targetTemperature;
    
    public:
        Thermostat(int id, string name, string status, double temp, string mode, double target) : Device(id, name, status), temperature(temp), mode(mode), targetTemperature(target){}

        void getStatus()
        {
            cout << "CURRENT TEMP: "<< temperature << endl;
        }
};

class SecurityCamera : public Device
{
    private:
        string resolution;
        string recordingStatus;
        bool nightvisionEnabled;
    
    public:
        SecurityCamera(int id, string name, string status,string res, string recstatus, bool vision) : Device(id, name, status), resolution(res), recordingStatus(recstatus), nightvisionEnabled(vision){}

        void turnOn()
        {
            recordingStatus = "ON";
            status = "ON";
            cout << "RECORDING AUTOMATICALLY..." << endl;
        }
};
    
class SmartPlug : public Device
{
    private:
        int timerSetting;
        double powerConsumption;
    
    public:
        SmartPlug(int id, string name, string status, int timer, double power) : Device(id, name, status), timerSetting(timer), powerConsumption(power){}

        void turnOff()
        {
            cout << "LOGGING POWER USAGE" << endl;
        }
};
    
int main()
{
    Light light(1001, "Light", "off", 80, "White");
    Thermostat thermostat(2001, "Thermostat", "on", 22.5, "Cooling", 24.0);
    SecurityCamera camera(3001, "Cam", "off", "1080p", "off", true);
    SmartPlug plug(4001, "Plug", "on", 120, 150.5);

    light.turnOn();
    light.displayInfo();

    thermostat.displayInfo();
    thermostat.getStatus();

    camera.turnOn();
    camera.displayInfo();

    plug.turnOff();
    plug.displayInfo();

    return 0;
}
