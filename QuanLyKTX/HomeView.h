#pragma once
#include "AuthService.h"
#include "BaseView.h"

class HomeView : public BaseView
{
private:
	Account*& user;
	AuthService* authService;
	int menuChoice;
	int loginSelected;
	bool isError;
	bool isEndApp;

	string username;
	string password;

	void showHeader(const int&, const int&);
	void handleInput() override;
	void showHome(const int&, const int&);
	void showAbout(const int&, const int&);
	void showLogin(const int&, const int&);
	void showExit(const int&, const int&);
public:
	HomeView(Account*&, AuthService*);
	virtual ~HomeView();

	int show() override;

};

