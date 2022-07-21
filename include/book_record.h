#ifndef BOOK_RECORD_H
#define BOOK_RECORD_H


class booking_record
{
    public:
    bool isBooked;
    double weight;
    booking_record();
    int get_resere();
    double get_weight();
    void Read();
    ~booking_record();
};

booking_record::booking_record()
{
	isBooked = 0;
	weight = 0.0;
}

int booking_record::get_resere(){

	return isBooked;
}
double booking_record::get_weight(){
	return weight;

}

void booking_record::Read()
{
	int c = 0;
	do
	{
		cin >> isBooked;
	} while (isBooked != 0 && isBooked != 1);

	if (isBooked == 1)
	{
		do{
			if (c == 1)
				cout << "\n* Error , enter wieght bag again : \t";
			cout << "Enter wieght bag : \t";
			cin >> weight;
			c = 1;
		} while (weight <= 0);
	}

}

booking_record::~booking_record()
{

}

#endif // BOOK_RECORD_H
