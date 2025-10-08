#include <iomanip>
#include "Date.h"
#include <ctime>


Date::Date(const int& d, const int& m, const int& y)
	: day(d), month(m), year(y)
{
}
Date::Date(const Date& D)
	: day(D.day), month(D.month), year(D.year)
{
}
Date::~Date()
{
 }

Date Date::getCurrentDay()
{
	time_t now = time(0);
	tm localTime;
	localtime_s(&localTime, &now);

	return Date(localTime.tm_mday, localTime.tm_mon + 1, localTime.tm_year + 1900);
}

bool Date::laNamNhuan()
{
	if (this->year % 400 == 0) return true;
	if (this->year % 100 == 0) return false;
	return (this->year % 4 == 0);
}

bool Date::laTonTai()
{
	if (this->year < 999) return false;
	if (this->month > 12 || this->month < 1) return false;

	int dayOfMonth[] = { 0, 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
	if (this->month == 2 && this->laNamNhuan())
	{
		dayOfMonth[2] = 29;
	}

	if (this->day < 1 || this->day > dayOfMonth[this->month]) return false;

	return true;
}

ostream& operator << (ostream& out, const Date& D)
{
	out << setfill('0');
	out << setw(2) << right << D.day << "/" << setw(2) << right <<  D.month << "/" << setw(4) << right << D.year;
	return out;
}

istream& operator >> (istream& in, Date& D)
{
	cout << "Day: "; in >> D.day;
	cout << "Month: "; in >> D.month;
	cout << "Year: "; in >> D.year;
	return in;
}