#pragma once
#include <iostream>
#include "AccountService.h"
using namespace std;

class HomePage
{
private:
	AccountService* accountService;

	int menuSize;
	string* menuList;
	int menuSelected;
	int loginFormSize;
	string* loginFormList;
	int loginFormSelected;

	string username;
	string password;
	bool isRunning;
	bool isError;

public:
	HomePage(AccountService*);
	~HomePage();
	void show();
	void drawHomePage();

private:
	void drawHeader(const int&, const int&);
	void drawMenuItems(const int&, const int&);
	void drawFooter(const int&, const int&);
	void drawHomeContent(const int&, const int&);
	void drawLoginContent(const int&, const int&);
	void drawAboutUsContent(const int&, const int&);
	

	void handleArrowKeys(int, int&, const int&);
	bool handleNormalKeys(int, int&, const int&);
};