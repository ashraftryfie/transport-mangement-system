#ifndef WILDERNESS_H
#define WILDERNESS_H


#include "Transport.h"

/*---------------------------- Wilderness Class ----------------------------*/
class Wilderness :public transport
{
protected:
	double CapacityEngine;
	double length;
public:
	Wilderness(){ CapacityEngine = 0; length = 0; }
	Wilderness(double CapacityEngine, double length){
		this->CapacityEngine = CapacityEngine;
		this->length = length;
	}
	~Wilderness() {}
	string get_name(){ return "Wilderness"; }
	double get_CapacityEng(){ return CapacityEngine; }
	double get_length(){ return length; }
	/*void Warning();
	long long get_number(){ return number; }
	double get_velocity() { return velocity; }
	char* get_company(){ return company; }
	char* get_property(){ return Property; }
	char* get_type(){ return transport_type; }
	void insert_data();
    void SetData();
	void InputJourney();
	void print();*/
};

#endif // WILDERNESS_H
