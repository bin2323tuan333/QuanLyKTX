#pragma once
#include "DB.h"
#include "IAuthService.h"

class AuthService : public IAuthService
{
private:
	DB* database;
public:
	AuthService();
	~AuthService();

	IAccount* login(const string&, const string&) override;
	int changePassword(IAccount*, const string&, const string&, const string&) override;
	bool genAccount(IPerson*) override;
	int getIdAuto() override;
};



