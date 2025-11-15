#pragma once
#include "DB.h"
#include "IAuthService.h"

class Account;
class Person;
class AuthService : public IAuthService
{
private:
	DB* database;
public:
	AuthService();
	~AuthService();

	Account* login(const string&, const string&) override;
	int changePassword(Account*, const string&, const string&, const string&) override;
	bool genAccount(Person*) override;
	int getIdAuto() override;
};



