#ifndef CHECKING_H
#define CHECKING_H


void siz_opject(int a)
{
    fstream f;
    f.open("siz.dat", ios::binary | ios::app);
    f.write((char*)&a, sizeof(int));
    f.close();
}


vector<int> siz_opject_read()
{
    int x;
    vector<int> v;
    fstream f;
    f.open("siz.dat", ios::in);
    while (f.read((char*)&x, sizeof(int)))
    {
        v.push_back(x);
    }
    return v;
}

bool check_id(int)
{
    transport *t = NULL;
    vector<int>v;
    fstream file;
    bool found = false;
    file.open("Transports.DAT", ios::binary | ios::in);
    file.seekg(0);
    if (file.is_open())
    {
        int x;
        v = siz_opject_read();
        for (size_t i = 0; i < v.size(); i++)
        {
            x = v[i];
            if (v[i] == sizeof(Cars))
            {
                t = new Cars;
            }
            else if (v[i] == sizeof(Buses))
            {
                t = new Buses;
            }
            else if(v[i] == sizeof(Trucks))
            {
                t = new Trucks;
            }
            else break;

            file.read((char*)t, x);
            if(t->get_number() == id){
                found = true;
                cout << "\nthis id is already exsist...!\n";
            }
        }
    }
    return found;
    file.close();
}

#endif // CHECKING_H
