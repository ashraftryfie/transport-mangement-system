#ifndef JOURNEY_H
#define JOURNEY_H


#include "book_record.h"
struct book_record{
    bool isBooked;
    double weight;
};

/*---------------------------- Journey Class ----------------------------*/
class journey
{
private:
    long long number;
    char transport_type[25];
    int FlightNumber;
    char from[20];
    char to[20];
    Date df;
    double LoadWeight;
    double BasedWeight;
    int NP; // number Passenger
    book_record b[100];
public:
    journey()
    {
        FlightNumber = 0;
        strcpy(from, "\0");
        strcpy(to, "\0");
        LoadWeight = 0;
        NP = 0;
    }
    journey(int fn, char*from, char*to, int Size, double load, double based, bool alarm)
    {
        FlightNumber = fn;
        strcpy(this->from, from);
        strcpy(this->to, to);
        LoadWeight = load;
    }
    ~journey(){}
    long long get_number(){ return number; }
    char* get_type(){ return transport_type; }
    int get_FlightNum()
    {
        return FlightNumber;
    }
    char* get_from()
    {
        return from;
    }
    char* get_to()
    {
        return to;
    }
    double get_LoadWeight()
    {
        return LoadWeight;
    }
    int get_NP()
    {
        return NP;
    }
    int getDay()
	{
		return df.getDay();
	}
	int getMonth()
	{
		return df.getMonth();
	}
	int getYear()
	{
		return df.getYear();
	}
//	bool CheckReserved(){ return *b.ReservedSeat; }
//	double get_BPWeight(){ return b.BPWeight; }

//	double get_BasedWeight(){ return BasedWeight; }
//	bool get_OverweightAlarm(){ /*transport t; -> check t ->  weight*/ return OverweightAlarm; }
//	void Set_LoadWeight(double LoadWeight){ this->LoadWeight = LoadWeight;}
    void give_type();
    void SetData(long long);
    void print()
    {
        system("color 6");
        cout << "\n\t\t" << number << "\t";
        cout << transport_type << "\t";
        cout << FlightNumber << "\t";
        cout << from << "\t";
        cout << to << "\t";
        if(!strcmp(transport_type,"Car")==0){
        cout << LoadWeight << "\t";
        cout << NP << "\t";
        for(int i = 0; i < NP; i++)
            cout << "PBag("<< i+1 <<")" << b[i].weight << "\t";
        }
        df.printDate();
    }


    /*********** Passengers ***********/
    /*void Calc_LoadWeightP(){
    	LoadWeight += get_BPWeight();
    }
    void Calc_BasedWeightP(){
    	BasedWeight += get_LoadWeight();
    }*/
    /*********** Goods ***********/
    /*double Calc_BasedWeightG(double tare){
    	BasedWeight = get_LoadWeight() + tare;
    	return BasedWeight;
    }*/

};

void journey::SetData(long long id)
{
    number = id;
    give_type();
    cout << "\t\tEnter Flight Number: ";
    cin >> FlightNumber;
    cout << "\t\tEnter City that you travel from: ";
    cin >> from;
    cout << "\t\tEnter City that you travel to: ";
    cin >> to;
    if (strcmp(transport_type,"Passengers Plane")==0 || strcmp(transport_type,"Bus")==0)
    {
        cout << "\t\tEnter the number of passengers: ";
        cin >> NP;
        for(int i = 0; i < NP; i++)
        {
            b[i].isBooked = true;
            cout << "\t\tEnter Weight of Passenger(" << i << "): ";
            cin >> b[i].weight;
            LoadWeight += b[i].weight;
        }
    }
    if(strcmp(transport_type,"Truck")==0 || strcmp(transport_type,"Goods Plane")==0)
    {
        cout << "\t\tEnter Load Weight: ";
        cin >> LoadWeight;
    }
    cout << "\t\tEnter Date of Journey:";
    df.inputDate();
}


void journey::give_type(){
        char ch;
        cout << "\t\tChoose type transport: " << endl;
        cout << "\t\t1. Car" << endl;
        cout << "\t\t2. Bus" << endl;
        cout << "\t\t3. Truck" << endl;
        cout << "\t\t4. Passengers Plane" << endl;
        cout << "\t\t5. Goods Plane" << endl;
        cout << "\t\tyour choice: ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            strcpy(transport_type, "Car");
            break;

        case '2':
            strcpy(transport_type, "Bus");
            break;

        case '3':
            strcpy(transport_type, "Truck");
            break;

        case '4':
            strcpy(transport_type, "Passengers Plane");
            break;

        case '5':
            strcpy(transport_type, "Goods Plane");
            break;
        default:
            break;
        }
}

#endif // JOURNEY_H
