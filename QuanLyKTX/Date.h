#pragma once
#include <iostream>
using namespace std;

class Date
{
private:
	int day, month, year;
public:
	Date(const int& = 0, const int& = 0, const int& = 0);
	Date(const Date&);
	~Date();

	static Date getCurrentDay();
	bool isLeep();
	bool isValid();

	int getDay();
	int getMonth();
	int getYear();

	string getDate();

	friend ostream& operator << (ostream&, const Date&);
	friend istream& operator >> (istream&, Date&);
	Date& operator=(const Date&);
	bool operator==(const Date&);
	bool operator!=(const Date&);
};