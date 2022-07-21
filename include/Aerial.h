#ifndef AERIAL_H
#define AERIAL_H


/*---------------------------- Aerial Class ----------------------------*/
class aerial :public transport
{
protected:
	int Num_Engines;
	double length;
public:
	aerial(){ Num_Engines = 0; length = 0; }
	aerial(int Num_Engines, double length)
	{
		this->Num_Engines = Num_Engines;
		this->length = length;
	}
	string get_name(){ return "Aerial"; }
	int get_NumEngines(){ return Num_Engines; }
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

#endif // AERIAL_H
