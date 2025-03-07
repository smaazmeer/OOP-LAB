#include <iostream>
using namespace std;

class AlarmSystem{
    private:
        string security_level;

    public:
        AlarmSystem(){};

        AlarmSystem(string securityLevel) : security_level(securityLevel){};

        ~AlarmSystem()
        {
            cout << "ALARM SYSTEM Destructor called" << endl;
        }

        void setSecurityLevel(string l){security_level = l;};

        string getSecurityLevel(){return security_level;};
};

class SmartHome{
    private:
        AlarmSystem Alarm;
    
    public:
        SmartHome(){Alarm.setSecurityLevel("None");};
        ~SmartHome()
        {
            cout << "SMART HOME Destructor called" << endl;
        }

        void displayDetails()
        {
            cout << "SMART HOME DETAILS:" << endl;
            cout << "SMART HOME SECURITY LEVEL: " << Alarm.getSecurityLevel() << endl;

        }

        void addSecurity(string level)
        {
            Alarm.setSecurityLevel(level);
            cout << "Security Level '" << Alarm.getSecurityLevel() << "' added to the system" << endl;
        }
};

int main()
{
    SmartHome myHome;
    myHome.addSecurity("High");
    myHome.displayDetails();

    return 0;
}