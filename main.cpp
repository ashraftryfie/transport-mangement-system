/**
*  ITE - Transport Management System Project
*  Developed by: Ashraf Tryfie
**/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include "include/Header.h"

int main() {
    menu();
    return 0;
}

void menu()
{
    Read_TransportFile(lt);
    Read_JourneyFile(lj);

    int choice;
    char ch;

    do {
        system("cls");
        system("color 0");
        cout << "\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ITE - Transport Application \xB2\xB2\xB2\xB2\xB2\xB2\xB2 " <<endl;
        cout << "\t\t -----------------------------------------------------------------------------------" << endl;
        cout << "\t\t|  1. Insert data                                                                   |" << endl;
        cout << "\t\t|  2. Create/Delete File                                                            |" << endl;
        cout << "\t\t|  3. Input Data in File                                                            |" << endl;
        cout << "\t\t|  4. Print Number Flights between 2 cities                                         |" << endl;
        cout << "\t\t|  5. Get Passengers Number of certain transport                                    |" << endl;
        cout << "\t\t|  6. Search by transport number                                                    |" << endl;
        cout << "\t\t|  7. Display all journey data for certain transport                                |" << endl;
        cout << "\t\t|  8. Display Data from file                                                        |" << endl;
        cout << "\t\t|  0. Exit                                                                          |" << endl;
        cout << "\t\t -----------------------------------------------------------------------------------\n\n" << endl;
        cout << "\t\t" << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\t\t1. Transport File" << endl;
            cout << "\t\t2. Journey File" << endl;
            cout << "\t\t0. any key to back to the menu" << endl;
            cout << "\t\t=> your choice: ";
            cin >> ch;
            if (ch == '1')
                insert_Transport(lt);
            if (ch == '2')
                insert_Journey(lj);
            else
                menu();
            break;

        case 2:
        {
            int ch ;
            system("color 4");
            fstream f;
            cout << " 1. delete all File\n";
            cout << " 2. delete a Transport file\n";
            cout << " 3. delete a journey file\n";
            cout << " 0. any key to back to the menu" << endl;
            cout << "your choice: ";
            cin >> ch;
            if(ch == 1)
            {
                f.open(Size_File,ios::out);
                f.close();
                f.open(Transports_File, ios::binary | ios::out);
                f.close();
                f.open(Journeys_File, ios::binary | ios::out);
                f.close();
            }
            else if(ch == 2)
            {
                f.open(Size_File,ios::out);
                f.close();
                f.open(Transports_File, ios::binary | ios::out);
                f.close();
            }
            else if (ch == 3)
            {
                f.open(Journeys_File, ios::binary | ios::out);
                f.close();
            }
            else menu();
            break;
        }

        case 3:

            break;

        case 4:
        {
            DisplayNumbers();
            break;
        }

        case 5:
        {
            long long n;
            Date dj;
            dj.inputDate();
            cout << "Enter number: ";
            cin >> n;
            Count_PassengerNumber(n, dj.getDay(), dj.getMonth(), dj.getYear());
            //lt.Count_PassengerNumber(n, day, month, year);
            break;
        }

        case 6:
        {
            int n;
            cout << "Enter number: ";
            cin >> n;
            lt.Search(n);
            lt.print();
            break;
        }

        case 7:
        {
            int n;
            cout << "Enter number: ";
            cin >> n;
            lj.Print_journy_data(n);
            break;
        }

        case 8:
            cout << "\t\t1. Transport File" << endl;
            cout << "\t\t2. Journey File" << endl;
            cout << "\t\tyour choice: ";
            cin >> ch;
            if (ch == '1')
                Display_TransportFile();
            else if (ch == '2')
                Display_JourneyFile();
            else
                cout << "Wrong!!" << endl;
            break;

        default:
            system("color 4");
            system("cls");
            printf("Goodbye");
            for(int i = 0; i< = 4; i++) {
                printf(".");
            }
            printf("see you soon ^_^\n");
            goto End;
            break;
        }
        system("Pause");
    }
    while(ch!=0);
    End:
    cout << "\n\n============End of Program============\n\n";
}


template <class t>
void insert_FileData(t &c) {
    int a;
    fstream file;
    if (sizeof(t) == sizeof(journey)) {
        file.open(Journeys_File, ios::binary | ios::app);
    }
    else {
        a = sizeof(c);
        siz_opject(a);
        file.open(Transports_File, ios::binary | ios::app);
    }
    file.write((char*)&c, sizeof(c));
    file.close();
}


void Display_TransportFile() {
    transport *t = NULL;
    LinkedList<transport> lt;
    vector<int> v;
    fstream file;
    cout << "\t\t\t************************* Transport File *************************" << endl;
    file.open(Transports_File, ios::binary | ios::in);
    file.seekg(0);
    if (file.is_open())
    {
        int x;
        v = siz_opject_read();
        //cout << "from File: " << endl;
        for (size_t i = 0; i < v.size(); i++) {
            x = v[i];
            if (v[i] == sizeof(Cars)) {
                t = new Cars;
                //cout << "Car (" << i + 1 << "):";
            }
            else if (v[i] == sizeof(Buses)) {
                t = new Buses;
                //cout << "Bus (" << i + 1 << "):";
            }
            else if(v[i] == sizeof(Trucks)) {
                t = new Trucks;
                //cout << "Truck (" << i + 1 << "):";
            }
            else if(v[i] == sizeof(PassengersPlanes)) {
                t = new PassengersPlanes;
                //cout << "PassengersPlane: (" << i + 1 << "):";
            }
            else if(v[i] == sizeof(GoodsPlanes)) {
                t = new GoodsPlanes;
                //cout << "Goods Plane: (" << i + 1 << "):";
            }
            else
                cout << "go out" << endl;
            file.read((char*)t, x);
            t->print();
            //lt.Read(t);
        }

    }
    else
        cout << "cant' opening file..." << endl;
    file.close();
}


void Display_JourneyFile() {
    journey j;
    //LinkedList<journey>lj;
    fstream file;
    cout << "\n\t\t\t************************* Journey File *************************"<< endl;
    //cout <<"ID-Trans    Type    no.Flight   from    to  load    wight"<<endl;
    file.open(Journeys_File, ios::binary | ios::in);
    file.seekg(0);
    if (file.is_open()) {
        while(file.read((char*)&j, sizeof(journey))) {
            j.print();
            lj.Read(&j);
        }
    }

    file.close();
}


void insert_Transport(LinkedList<transport>&lt) {
    int ch, n, m = 1;
    Cars car;
    Buses bus;
    Trucks truck;
    PassengersPlanes pp;
    GoodsPlanes gp;
    transport *t[5];
    t[0] = &car;
    t[1] = &bus;
    t[2] = &truck;
    t[3] = &pp;
    t[4] = &gp;
    long long id; // for insert as number of transport with checking it
    while (m > 0) {
        cout << "Choose type transport: " << endl;
        cout << "1. Car" << endl;
        cout << "2. Bus" << endl;
        cout << "3. Truck" << endl;
        cout << "4. Passengers Plane" << endl;
        cout << "5. Goods Plane" << endl;
        cout << "your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
        {
            cout << "Enter no.cars you want to add: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                Enternumber1:

                cout << "Enter Num of Transport: ";
                cin >> id;
                if(lt.check_id(id))
                {
                    int kk = 0;
                    cout << "this id is already existed..!!!" << endl;
                    cout << "press 1 to try again...0 to exit: ";
                    cin >> kk;
                    if(kk == 1)
                        goto Enternumber1;
                    else
                        menu();
                }
                lt.insertLast(t[ch-1], id);
                insert_FileData(car);
                cout << endl;
            }
            break;
        }
        case 2:
        {
            cout << "Enter no.bus you want to add: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                Enternumber2:

                cout << "Enter Num of Transport: ";
                cin >> id;
                if(lt.check_id(id))
                {
                    int kk = 0;
                    cout << "this id is already existed..!!!" << endl;
                    cout << "press 1 to try again...0 to exit: ";
                    cin >> kk;
                    if(kk == 1)
                        goto Enternumber2;
                    else
                        menu();
                }
                lt.insertLast(t[ch-1], id);
                insert_FileData(bus);
                cout << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Enter no.Trucks you want to add: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                Enternumber3:

                cout << "Enter Num of Transport: ";
                cin >> id;
                if(lt.check_id(id))
                {
                    int kk = 0;
                    cout << "this id is already existed..!!!" << endl;
                    cout << "press 1 to try again...0 to exit: ";
                    cin >> kk;
                    if(kk == 1)
                        goto Enternumber3;
                    else
                        menu();
                }
                lt.insertLast(t[ch-1], id);
                insert_FileData(truck);
                cout << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Enter no.Passengers Planes you want to add: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                Enternumber4:

                cout << "Enter Num of Transport: ";
                cin >> id;
                if(lt.check_id(id)) {
                    int kk = 0;
                    cout << "this id is already existed..!!!" << endl;
                    cout << "press 1 to try again...0 to exit: ";
                    cin >> kk;
                    if(kk == 1)
                        goto Enternumber4;
                    else
                        menu();
                }
                lt.insertLast(t[ch-1], id);
                insert_FileData(pp);
                cout << endl;
            }
            break;
        }
        case 5:
        {
            cout << "Enter no.Goods Planes you want to add: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                Enternumber5:

                cout << "Enter Num of Transport: ";
                cin >> id;
                if(lt.check_id(id))
                {
                    int kk = 0;
                    cout << "this id is already existed..!!!" << endl;
                    cout << "press 1 to try again...0 to exit: ";
                    cin >> kk;
                    if(kk == 1)
                        goto Enternumber5;
                    else
                        menu();
                }
                lt.insertLast(t[ch-1], id);
                insert_FileData(gp);
                cout << endl;
            }
            break;
        }
        default:
            break;
        }
        cout << "Press (0) to stop input (any key to continue): ";
        cin >> m;
    }
    //lt.print();
}


void insert_Journey(LinkedList<journey>&lj) {
    long long id;
    journey j;

    Enternumber:

    cout << "Enter Num of Transport: ";
    cin >> id;
    if(!lt.check_id(id)) {
        int kk = 0;
        cout << "this transport is not existed..!!!" << endl;
        cout << "press 1 to try again...0 to exit: ";
        cin >> kk;
        if(kk == 1)
            goto Enternumber;
        else
            menu();
    }
    lj.insertLast(&j, id);
    insert_FileData(j);
    cout << endl;
}


void siz_opject(int a) {
    fstream f;
    f.open(Size_File, ios::binary | ios::app);
    f.write((char*)&a, sizeof(int));
    f.close();
}


vector<int> siz_opject_read()
{
    int x;
    vector<int> v;
    fstream f;
    f.seekg(0);
    f.open(Size_File, ios::in);
    while (f.read((char*)&x, sizeof(int)))
    {
        v.push_back(x);
    }
    return v;
}


void Read_TransportFile(LinkedList<transport>&lt) {
    transport *t = NULL;
    vector<int> v;
    fstream file;
    file.open(Transports_File, ios::binary | ios::in);
    file.seekg(0);
    if (file.is_open())
    {
        int x;
        v = siz_opject_read();
        for (size_t i = 0; i < v.size(); i++)
        {
            x = v[i];
            if (v[i] == sizeof(Cars)) {
                t = new Cars;
            }
            else if (v[i] == sizeof(Buses)) {
                t = new Buses;
            }
            else if(v[i] == sizeof(Trucks)) {
                t = new Trucks;
            }
            else break;

            file.read((char*)t, x);
            lt.Read(t);
        }
    }
    file.close();
}


void Read_JourneyFile(LinkedList<journey>&lj) {
    journey j;
    fstream file;
    file.open(Journeys_File, ios::binary | ios::in);
    file.seekg(0);
    //if (file.is_open())
    {
        while(file.read((char*)&j, sizeof(journey))) {
            lj.Read(&j);
        }
    }

    file.close();
}


void Count_PassengerNumber(long long id,int day, int month, int year) {
    journey j;
    fstream file;
    bool found = false;
    file.open(Journeys_File, ios::binary | ios::in);
    file.seekg(0);
    if (file.is_open()) {
        while(file.read((char*)&j, sizeof(journey))) {
            if (id == j.get_number())
                if( day == j.getDay() )
                    if( month == j.getMonth() )
                        if( year == j.getYear() ) {
                            found = true;
                            cout << j.get_NP() << endl;
                        }
        }
    }
    if (found == false)
        cout << "\nNot found..!!!" << endl;
    file.close();
}


void DisplayNumbers() {
    journey j;
    LinkedList<journey>lj;
    int id;
    char from[25], to[25];
    cout << "Enter num : ";
    cin >> id;
    cout << "Enter City from: ";
    cin >> from;
    cout << "Enter City to: ";
    cin >> to;
    fstream file;
    cout << "******************** Journey File ********************"<< endl;
    file.open("Journeys.DAT", ios::binary | ios::in);
    file.seekg(0);
    if (file.is_open())
    {
        while(file.read((char*)&j, sizeof(journey)))
        {
            lj.Read(&j);
        }
    }
    lj.Search(id,to, from);
    //lj.print();
    file.close();
}
