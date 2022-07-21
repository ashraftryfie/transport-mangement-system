#ifndef PASSENGERS_H
#define PASSENGERS_H


#include "Aerial.h"

class PassengersPlanes :public aerial
{
	int numSeats;
	double TareWeight;
	double MaxWeight;
	//int counter; // for passengers
public:
	static int MaxWeightBags; // 25 as max size for each passenger
	PassengersPlanes(){ numSeats = 0; }
	PassengersPlanes(int numSeats){ this->numSeats = numSeats; }
	~PassengersPlanes() {}
	string get_name(){ return "Passengers Plane"; }

	long long get_number()
	{
		return number;
	}
	double get_velocity()
	{
		return velocity;
	}
	char* get_company()
	{
		return company;
	}
	char* get_property()
	{
		return Property;
	}
	char* get_type()
	{
		return transport_type;
	}
	void print()
	{
		cout << "\n" << number << "\t";
		cout << company << "\t";
		cout << Num_Engines << "\t";
		cout << length << "\t";
		cout << Num_Engines << "\t";
        cout << length << "\t";
		cout << velocity << "\t";
		cout << numSeats << "\t";
		cout << Property << "\t";
		cout << transport_type << "\n";
		d.printDate();
	}
	void SetData(long long id)
	{
		insert_data(id);
		cout << "Enter Number of Engines: ";
		cin >> Num_Engines;
		cout << "Enter length of plane: ";
		cin >> length;
		while (length < 0||length>200)
        {
            cout << "Invalid value of length: " << length << endl;
            cout << "Enter Number of length again under 200: ";
            cin >> length;
        }
		cout << "Enter Number of Seats: ";
		cin >> numSeats;
		while (numSeats < 0||numSeats>500)
        {
            cout << "Invalid value of num Seats: " << numSeats << endl;
            cout << "Enter Number of num Seats again under 500: ";
            cin >> numSeats;
        }
	}

	void Warning()
	{
		//if (j.get_BPWeight() > MaxWeightBags)
			cout << "Go out ";
		//else
			cout << "Welcome to Syria";
	}
};
int PassengersPlanes::MaxWeightBags = 25;


#endif // PASSENGERS_H
