#ifndef BUSES_H
#define BUSES_H

#include "Wilderness.h"

class Buses :public Wilderness
{
	int seats;
	double TareWeight;
	double MaxWeight;
public:
	Buses()
	{
		seats = 0;
	}
	Buses(int seats, int counter)
	{
		this->seats = seats;
	}
	~Buses() {}
	string get_name()
	{
		return "Bus";
	}
	void Warning()  // Check seat if it's reserved or not
	{
		cout << "hhhh";
	}

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
	double get_CapacityEng(){ return CapacityEngine; }
	double get_length(){ return length; }
	void print()
	{
		//cout << "\n" << counter << "\t";
		cout << number << "\t";
		cout << company << "\t";
		cout << seats << "\t";
		cout << velocity << "\t";
		cout << Property << "\t";
		cout << transport_type;
		d.printDate();
	}

	void SetData(long long id)
	{
	    insert_data(id);
		cout << "Enter the capacity of engine: ";
		cin >> CapacityEngine;
		cout << "Enter the length of Bus: ";
		cin >> length;
		        while (length < 0||length>30)
        {
            cout << "Invalid value of length: " << length << endl;
            cout << "Enter Number of length again under 30: ";
            cin >> length;
        }
		cout << "Enter Number of Seats: ";
		cin >> seats;
		while (seats < 0||seats>50)
		{
			cout << "Invalid value for seats: " << seats << endl;
			cout << "Enter number of seats again under 50: ";
			cin >> seats;
		}
		strcpy(transport_type, "Bus");

	}
};

#endif // BUSES_H
