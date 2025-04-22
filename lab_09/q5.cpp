#include <iostream>
#include <string>

using namespace std;

class Shipment 
{
    protected:
        string trackingNumber;
        double weight;

    public:
        Shipment(string trackingNum, double weight) : trackingNumber(trackingNum), weight(weight) {}

        virtual void estimateDeliveryTime() = 0;
        virtual void showDetails() = 0;

        virtual ~Shipment() {}
};

class AirFreight : public Shipment 
{   
    public:
        AirFreight(string trackingNum, double weight) : Shipment(trackingNum, weight) {}

        void estimateDeliveryTime()
        {
            cout << "Air Freight estimated delivery time: 2-3 days" << endl;
        }

        void showDetails()
        {
            cout << "Air Freight Shipment Details: " << endl;
            cout << "Tracking Number: " << trackingNumber << endl;
            cout << "Weight: " << weight << " kg" << endl;
        }
};

class GroundShipment : public Shipment 
{
    public:
        GroundShipment(string trackingNum, double weight) : Shipment(trackingNum, weight) {}

        void estimateDeliveryTime()
        {
            cout << "Ground Shipment estimated delivery time: 5-7 days" << endl;
        }

        void showDetails()
        {
            cout << "Ground Shipment Details: " << endl;
            cout << "Tracking Number: " << trackingNumber << endl;
            cout << "Weight: " << weight << " kg" << endl;
        }
};

int main() 
{
    AirFreight air("AK845", 15);
    GroundShipment grd("GK690", 25);

    Shipment* base;

    base = &air;
    base->showDetails();
    base->estimateDeliveryTime();

    base = &grd;
    base->showDetails();
    base->estimateDeliveryTime();

    return 0;
}
