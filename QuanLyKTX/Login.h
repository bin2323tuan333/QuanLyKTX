#pragma once
#include "BaseScreen.h"
#include "LoginService.h"
#include <iostream>
using namespace std;



class Login : public BaseScreen
{
private:
	LoginService& loginService;
	string username;
	string password;
	bool isError;
public:
	Login(LoginService&, const string& = "", const string& = "");
	~Login();


	void draw() override;
	void handleClick(int x, int y, BaseScreen*& current) override;
};