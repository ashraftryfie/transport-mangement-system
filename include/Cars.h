#ifndef CARS_H
#define CARS_H

#include "Wilderness.h"

class Cars : public Wilderness
{
    int doors;
public:
    Cars()
    {
        doors = 0;
    }
    Cars(int doors)
    {
        this->doors = doors;
    }
    ~Cars() {}
    string get_name()
    {
        return "Car";
    }
    void setDoors(int doors)
    {
        this->doors = doors;
    }
    void Warning() {}
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
        cout << "\n" << number << "\t";
        cout << doors << "\t";
        cout << company << "\t";
        cout << velocity << "\t";
        cout << Property << "\t";
        cout << transport_type << "\t";
        cout << CapacityEngine << "\t";
        cout << length << "\t";
        d.printDate();
        system("color 3");
    }
    void SetData(long long id)
    {
        insert_data(id);
        cout << "Enter the capacity of engine: ";
        cin >> CapacityEngine;
        while (CapacityEngine < 0||CapacityEngine>10)
        {
            cout << "Invalid value of Capacity Engine: " << CapacityEngine << endl;
            cout << "Enter Number of Capacity Engine again under 10: ";
            cin >> CapacityEngine;
        }

        cout << "Enter the length of Car: ";
        cin >> length;
        while (length < 0||length>15)
        {
            cout << "Invalid value of length: " << length << endl;
            cout << "Enter Number of length again under 15: ";
            cin >> length;
        }
        cout << "Enter Number of doors: ";
        cin >> doors;
        while (doors < 0||doors>7)
        {
            cout << "Invalid value of doors: " << doors << endl;
            cout << "Enter Number of doors again under 7: ";
            cin >> doors;
        }
        strcpy(transport_type, "Car");

    }

};

#endif // CARS_H
