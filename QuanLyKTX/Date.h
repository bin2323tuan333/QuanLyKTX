#pragma once
#include <iostream>
using namespace std;

class Date
{
private:
	int day, month, year;
public:
	Date(const int& = 1, const int& = 1, const int& = 2000);
	Date(const Date&);
	~Date();

	static Date getCurrentDay();
	static Date increaseDate(const Date&, int);
	bool isLeep();
	bool isValid();

	int getDay();
	int getMonth();
	int getYear();
	void setDay(const int&);
	void setMonth(const int&);
	void setYear(const int&);

	string getDate();
	static int getMaxDayOfMonth(const int&, const int&);
	static Date stringToDate(const string&);

	friend ostream& operator << (ostream&, const Date&);
	friend istream& operator >> (istream&, Date&);
	Date& operator=(const Date&);
	bool operator==(const Date&);
	bool operator!=(const Date&);
	bool operator>(const Date&);
	bool operator>=(const Date&);
	bool operator<(const Date&);
	bool operator<=(const Date&);
};