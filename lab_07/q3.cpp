#include <iostream>
using namespace std;

class Ticket
{
    private:
        int ticketID;
        string passengerName;
        double price;
        string date;
        string destination;

    public:
        Ticket(int id, string name, double pr, string dt, string dest)
        {
            ticketID = id;
            passengerName = name;
            price = pr;
            date = dt;
            destination = dest;
        }

        virtual void reserve()
        {
            cout << "Ticket reserved for " << passengerName << endl;
        }

        virtual void cancel()
        {
            cout << "Ticket canceled for " << passengerName << endl;
        }

        virtual void displayTicketInfo()
        {
            cout << "Ticket ID: " << ticketID << endl;
            cout << "Passenger: " << passengerName << endl;
            cout << "Price: " << price << endl;
            cout << "Date: " << date << endl;
            cout << "Destination: " << destination << endl;
        }
};

class FlightTicket : public Ticket
{
    private:
        string airlineName;
        string flightNumber;
        string seatClass;

    public:
        FlightTicket(int id, string name, double pr, string dt, string dest, string airline, string flight, string seat) : Ticket(id, name, pr, dt, dest)
        {
            airlineName = airline;
            flightNumber = flight;
            seatClass = seat;
        }

        void displayTicketInfo()
        {
            Ticket::displayTicketInfo();
            cout << "Airline: " << airlineName << endl;
            cout << "Flight Number: " << flightNumber << endl;
            cout << "Seat Class: " << seatClass << endl;
        }
};

class TrainTicket : public Ticket
{
    private:
        string trainNumber;
        string coachType;
        string departureTime;

    public:
        TrainTicket(int id, string name, double pr, string dt, string dest,
        string train, string coach, string time) : Ticket(id, name, pr, dt, dest)
        {
            trainNumber = train;
            coachType = coach;
            departureTime = time;
        }

        void reserve()
        {
            cout << "Train seat auto-assigned." << endl;
            Ticket::reserve();
        }
};

class BusTicket : public Ticket
{
    private:
        string busCompany;
        string seatNumber;

    public:
        BusTicket(int id, string name, double pr, string dt, string dest,
        string company, string seat) : Ticket(id, name, pr, dt, dest)
        {
            busCompany = company;
            seatNumber = seat;
        }

        void cancel()
        {
            cout << "Last minute refund issued." << endl;
            Ticket::cancel();
        }
};

class ConcertTicket : public Ticket
{
    private:
        string artistName;
        string venue;
        string seatType;

    public:
        ConcertTicket(int id, string name, double pr, string dt, string dest,
                    string artist, string v, string seat)
            : Ticket(id, name, pr, dt, dest)
        {
            artistName = artist;
            venue = v;
            seatType = seat;
        }

        void displayTicketInfo()
        {
            Ticket::displayTicketInfo();
            cout << "Artist: " << artistName << endl;
            cout << "Venue: " << venue << endl;
            cout << "Seat Type: " << seatType << endl;
        }
};

int main()
{
    FlightTicket ft(1, "Ali", 150000, "20-04-2025", "New York", "PIA", "PK123", "Business");
    TrainTicket tt(2, "Irfan", 5000, "21-04-2025", "Lahore", "GreenLine", "AC", "08:00 AM");
    BusTicket bt(3, "Aazmeer", 1200, "22-04-2025", "Islamabad", "Skyways", "B12");
    ConcertTicket ct(4, "Rameel", 3000, "25-04-2025", "Karachi", "HAVI", "FAST", "VIP");

    cout << "--- Flight Ticket ---" << endl;
    ft.displayTicketInfo();

    cout << "\n--- Train Ticket ---" << endl;
    tt.reserve();

    cout << "\n--- Bus Ticket ---" << endl;
    bt.cancel();

    cout << "\n--- Concert Ticket ---" << endl;
    ct.displayTicketInfo();

    return 0;
}
