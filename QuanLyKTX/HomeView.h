#pragma once
#include "BaseView.h"

class IAccount;
class IAuthService;
class HomeView : public BaseView
{
private:
	IAccount*& user;
	IAuthService* authService;
	int menuChoice, loginSelected;
	bool isError, isEndApp;
	string username, password;

	void handleInput() override;
	void showHeader(const int&, const int&);
	void showHome(const int&, const int&);
	void showAbout(const int&, const int&);
	void showLogin(const int&, const int&);
	void showExit(const int&, const int&);
public:
	HomeView(IAccount*&, IAuthService*);
	virtual ~HomeView();

	int show() override;

};

