#pragma once
#include <iostream>
using namespace std;

class HomePage
{
private:
	int menuSize;
	string* menuList;
	int menuSelected;

public:
	HomePage();
	~HomePage();
	int show();
	void drawHomePage();
	void drawLoginPage();
	void drawAboutUsPage();

private:
	void drawHeader(const int&, const int&);
	void drawMenuItems(const int&, const int&);
	void drawFooter(const int&, const int&);
	void drawHomeContent(const int&, const int&);
	void drawLoginContent(const int&, const int&);
	void drawAboutUsContent(const int&, const int&);
	
	void drawSelectedItem(int, bool);
	void handleArrowKeys(int, int&, const int&);
	bool handleNormalKeys(int, int&, const int&);
};