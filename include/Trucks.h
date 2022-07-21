#ifndef TRUCKS_H
#define TRUCKS_H


#include "Wilderness.h"

class Trucks :public Wilderness
{
	double TareWeight;
	double MaxWeight;
	double HighGoodsSection;
public:
	Trucks() :TareWeight(0), MaxWeight(0), HighGoodsSection(0) {}
	Trucks(double Tare, double Max, double High)
	{
		TareWeight = Tare;
		MaxWeight = Max;
		HighGoodsSection = High;
	}
	~Trucks() {}
	string get_name(){ return "Truck"; }
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
	double get_max(){ return MaxWeight; }
	void print()
	{
		cout << "\n" << number << "\t";
		cout << company << "\t";
		cout << velocity << "\t";
		cout << Property << "\t";
		cout << transport_type << "\t";
		cout << CapacityEngine << "\t";
		cout << length << "\t";
		cout << TareWeight << "\t";
		cout << MaxWeight << "\t";
		cout << HighGoodsSection << "\n";
	}

	void SetData(long long id)
	{
		insert_data(id);
		strcpy(transport_type, "Truck");
		cout << "Enter the capacity of engine: ";
		cin >> CapacityEngine;

		cout << "Enter the length of Truck: ";
		cin >> length;
		 while (length < 0||length>30)
        {
            cout << "Invalid value of length: " << length << endl;
            cout << "Enter Number of length again under 30: ";
            cin >> length;
        }
		cout << "Enter Tare Weight of this Truck: ";
		cin >> TareWeight;
		 while (TareWeight <= 0)
        {
            cout << "Invalid value of TareWeight: " << TareWeight << endl;
            cout << "Enter Number of TareWeight again : ";
            cin >> TareWeight;
        }
		cout << "Enter Max Weight of this Truck: ";
		cin >> MaxWeight;
		 while (MaxWeight <= 0)
        {
            cout << "Invalid value of MaxWeight: " << MaxWeight << endl;
            cout << "Enter Number of MaxWeight again : ";
            cin >> MaxWeight;
        }
		cout << "Enter High of Goods Section: ";
		cin >> HighGoodsSection;
	}

	void Warning()
	{

		//if (j.get_BPWeight() > MaxWeight)
			cout << "Out of Range..!!";
	}
};

#endif // TRUCKS_H
