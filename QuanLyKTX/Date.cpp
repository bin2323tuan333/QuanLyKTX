#include <iomanip>
#include "Date.h"
#include <string>
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

bool Date::isLeep()
{
	if (this->year % 400 == 0) return true;
	if (this->year % 100 == 0) return false;
	return (this->year % 4 == 0);
}

bool Date::isValid()
{
	if (this->year < 999) return false;
	if (this->month > 12 || this->month < 1) return false;

	int dayOfMonth[] = { 0, 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
	if (this->month == 2 && this->isLeep())
	{
		dayOfMonth[2] = 29;
	}

	if (this->day < 1 || this->day > dayOfMonth[this->month]) return false;

	return true;
}

int Date::getDay()
{
	return this->day;
}
int Date::getMonth()
{
	return this->month;
}
int Date::getYear()
{
	return this->year;
}

string Date::getDate()
{
	return to_string(this->day) + "/" + to_string(this->month) + "/" + to_string(this->year);
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

Date& Date::operator=(const Date& date)
{
	if (this == &date)
		return *this;

	this->day = date.day;
	this->year = date.year;
	this->month = date.month;
	return *this;
}

bool Date::operator==(const Date& date)
{
	return (this->day == date.day && 
		this->month == date.month && 
		this->year == date.year);
}