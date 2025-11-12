#pragma once
#include "DB.h"


class AuthService
{
private:
	DB* database;
public:
	AuthService();
	~AuthService();

	Account* login(const string&, const string&);
	int changePassword(Account*, const string&, const string&, const string&);
	bool genAccount(Person*);
	int getIdAuto();
};



