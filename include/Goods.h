#ifndef GOODS_H
#define GOODS_H


#include "Aerial.h"

class GoodsPlanes :public aerial
{
	double TareWeight;
	double MaxWeight;
public:
	GoodsPlanes(){ TareWeight = 0; MaxWeight = 0; }
	GoodsPlanes(double TareWeight, double MaxWeight){ this->TareWeight = TareWeight; this->MaxWeight = MaxWeight; }
	~GoodsPlanes() {}
	string get_name(){ return "Goods Plane"; }
	long long get_number(){ return number; }
	double get_velocity(){ return velocity; }
	char* get_company(){ return company; }
	char* get_property(){ return Property; }
	char* get_type(){ return transport_type; }
	double get_max(){ return MaxWeight; }
	double get_tare(){ return TareWeight; }
	void print()
	{

		cout << "\n" << number << "\t";
		cout << company << "\t";
		cout << TareWeight << "\t";
        cout << MaxWeight << "\t";
		cout << Num_Engines << "\t";
		cout << length << "\t";
		cout << velocity << "\t";
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
		        while (length < 0||length>100)
        {
            cout << "Invalid value of length: " << length << endl;
            cout << "Enter Number of length again under 100: ";
            cin >> length;
        }

		cout << "Enter TareWeight of this Plane: ";
		cin >> TareWeight;
		 while (TareWeight <= 0)
        {
            cout << "Invalid value of TareWeight: " << TareWeight << endl;
            cout << "Enter Number of TareWeight again : ";
            cin >> TareWeight;
        }
		cout << "Enter MaxWeight of this Plane: ";
		cin >> MaxWeight;
		 while (MaxWeight <= 0)
        {
            cout << "Invalid value of MaxWeight: " << MaxWeight << endl;
            cout << "Enter Number of MaxWeight again : ";
            cin >> MaxWeight;
        }
	}

	void Warning()
	{
		//if (j.get_BasedWeight() > MaxWeight)
			cout << "Go out";
		//else
			cout << "Welcome";
	}
};

#endif // GOODS_H
