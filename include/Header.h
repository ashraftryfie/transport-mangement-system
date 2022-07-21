#ifndef HEADER_H
#define HEADER_H

using namespace std;
#include "Date.h"
#include "Journey.h"
#include "Cars.h"
#include "Buses.h"
#include "Trucks.h"
#include "Passengers.h"
#include "Goods.h"
#include "LinkedList.h"

/*---------------- Files Names ----------------*/
char Transports_File[] = "Transports.DAT";
char Journeys_File[] = "Journeys.DAT";
char Size_File[] = "Size.DAT";
LinkedList<transport>lt;
LinkedList<journey>lj;
vector<int> siz_opject_read();
void siz_opject(int);
void insert_Transport(LinkedList<transport>&);
void insert_Journey(LinkedList<journey>&);
template <class t>
void insert_FileData(t &);
void Display_TransportFile();
void Display_JourneyFile();
void DisplayNumbers();
void Read_TransportFile(LinkedList<transport>&lt);
void Read_JourneyFile(LinkedList<journey>&lj);

void  Count_PassengerNumber(long long, int, int, int);
void menu();


#endif // HEADER_H
