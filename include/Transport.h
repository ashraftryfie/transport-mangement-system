#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "LinkedList.h"

/*---------------------------- Transport Class ----------------------------*/
class transport
{
protected:
	long long number;
	char company[25];
	double velocity;
	char Property[25]; // "Public" or "Private" or "National"
	char transport_type[25]; // Planes: haulage(Goods) or passengers - Cars - Buses - Trucks
	Date d; // Date of Recording this transport
public:
	transport()
	{
		number = 0;
		strcpy(company, "\0");
		velocity = 0;
		strcpy(Property, "\0");
		strcpy(transport_type, "\0");
	}
	~transport() { }
	virtual string get_name() = 0;
	virtual void Warning() = 0;
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

	void insert_data(long long id);
	virtual void SetData(long long) = 0;
	virtual void print() = 0;
};

void transport::insert_data(long long id)
{
	char p;
	number = id;
	cout << "Enter Name of Company:";
	cin >> company;
	cout << "Choose Type of Property:" << endl;
	cout << "\t1. Public" << endl;
	cout << "\t2. Private" << endl;
	cout << "\t3. National" << endl;
	cout << "your choice: ";
	cin >> p;
	switch (p)
	{
	case '1':
		strcpy(Property, "Public");
		break;
	case '2':
		strcpy(Property, "Private");
		break;
	case '3':
		strcpy(Property, "National");
		break;
	}
	cout << "Enter amount of velocity:";
	cin >> velocity;
	while (velocity < 0||velocity>500){
        cout << "Invalid Value for velocity..!!\nRenter the velocity of Transport again under 500: ";
        cin >> velocity;
	}
	cout << "Enter Date of Record:";
	d.inputDate();
}

#endif // TRANSPORT_H
