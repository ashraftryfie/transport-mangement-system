#ifndef DATE_H
#define DATE_H


/*---------------------------- Date Class ----------------------------*/
class Date
{
	int day, month, year;
public:
	Date() :day(1), month(1), year(2000) {}
	Date(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	void inputDate()
	{
		cout << "\n\tEnter Day: ";
		cin >> day;
		while (day < 0 || day > 31){
			cout << "invalid input for Day(" << day << ")";
			cout << "\n\tEnter Day again: ";
			cin >> day;
		}
		cout << "\tEnter Month: ";
		cin >> month;
		while (month < 0 || month > 12){
			cout << "invalid input for month(" << month << ")";
			cout << "\n\tEnter Day again: ";
			cin >> month;
		}
		cout << "\tEnter Year: ";
		cin >> year;
		while (year < 0  || year > 2020){
			cout << "invalid input for Day(" << year << ")";
			cout << "\n\tEnter Day again: ";
			cin >> year;
		}
	}
	// Set Functions:
	void setDay(int day)
	{
		this->day = day;
	}
	void setMonth(int month)
	{
		this->month = month;
	}
	void setYear(int year)
	{
		this->year = year;
	}
	void setDate(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	// Get Functions:
	int getDay()
	{
		return day;
	}
	int getMonth()
	{
		return month;
	}
	int getYear()
	{
		return year;
	}
	~Date() {};
	// Print Data of Class:
	void printDate()
	{
		cout << "\t" << day << "/" << month << "/" << year << endl;
	}
};

#endif // DATE_H
