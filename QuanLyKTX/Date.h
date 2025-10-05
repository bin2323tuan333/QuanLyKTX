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
	bool laNamNhuan();
	bool laTonTai();

	friend ostream& operator << (ostream&, const Date&);
	friend istream& operator >> (istream&, Date&);
};