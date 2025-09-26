#include "HomePage.h"
#include "Login.h"
#include "AboutUs.h"
#include "ConsolaUI.h"


Login::Login(LoginService& service, const string& user, const string& pass)
	:loginService(service), username(user), password(pass)
{
	this->isError = false;
}
Login::~Login()
{
}


void Login::draw()
{
	int height = ConsolaUI::getConsoleHeight();
	int width = ConsolaUI::getConsoleWidth();
	ConsolaUI::ShowCursor(false);


	if (height >= 3)
	{
		ConsolaUI::drawBox(1, 1, width, height, 15);
		ConsolaUI::text(5, 3, "Trang Chu");
		ConsolaUI::text(width - 10, 3, "Dang Nhap");
		ConsolaUI::text(20, 3, "Gioi Thieu");
		ConsolaUI::gotoXY(width - 10, 4);
		for (int i = 0; i < 9; i++)
			cout << char(205);
		ConsolaUI::text(width / 2 - 20, height / 2 - 2, "Ten Dang Nhap");
		ConsolaUI::drawBox(width / 2 - 5, height / 2 - 3, 25, 2, 15);

		ConsolaUI::text(width / 2 - 20, height / 2 + 2, "Mat Khau");
		ConsolaUI::drawBox(width / 2 - 5, height / 2 + 1, 25, 2, 15);

		ConsolaUI::text(width / 2 - 18, height / 2 + 5, "Quen Mat Khau");
		ConsolaUI::drawBox(width / 2 - 20, height / 2 + 4, 16, 2, 15);

		ConsolaUI::text(width / 2 + 10, height / 2 + 5, "Dang Nhap");
		ConsolaUI::drawBox(width / 2 + 8, height / 2 + 4, 12, 2, 15);


	}

	if(this->username != "")
		ConsolaUI::text(width / 2 - 4, height / 2 - 2, this->username);
	if (this->password != "") 
	{	
		ConsolaUI::text(width / 2 - 4, height / 2 + 2, this->password);
	}
	if(this->isError == true)
		ConsolaUI::text(width / 2 - 10, height / 2 + 7, "Sai ten hoac mat khau!");
}
void Login::handleClick(int x, int y, BaseScreen*& current)
{
	int width = ConsolaUI::getConsoleWidth();
	int height = ConsolaUI::getConsoleHeight();
	ConsolaUI::text(width - 20, 3, to_string(x) + " " + to_string(y));
	// "Trang Chu"
	if ((y == 3 || y == 4) && (x >= 5 && x <= 14)) 
	{
		delete current;
		current = new HomePage(this->loginService);
		return;
	}
	// "Gioi Thieu"
	if ((y == 3 || y == 4) && (x >= 20 && x <= 30)) 
	{
		delete current;
		current = new AboutUs();
		return;
	}
	// "Nhap Ten Dang Nhap"
	if ((y >= height / 2 - 3 && y <= height / 2 - 1) && (x >= width / 2 - 5 && x <= width / 2 +20))
	{
		ConsolaUI::text(width / 2 - 4, height / 2 - 2, string(25, ' '));
		this->username = ConsolaUI::getInput(width / 2 - 5, height / 2 - 3, 25, 2, 14, 15);
		return;
	}
	// "Nhap Mat Khau"
	if ((y >= height / 2 + 1 && y <= height / 2 + 3) && (x >= width / 2 - 5 && x <= width / 2 + 20))
	{
		ConsolaUI::text(width / 2 - 4, height / 2 + 2, string(25, ' '));
		this->password = ConsolaUI::getInput(width / 2 - 5, height / 2 + 1, 25, 2, 14, 15);
		return;
	}
	// "Quen Mat Khau"
	if ((y >= height / 2 + 4 && y <= height / 2 + 6) && (x >= width / 2 - 20 && x <= width / 2 - 5))
	{
		delete current;
		current = new AboutUs();
		return;
	}
	// "Dang Nhap"
	if ((y >= height / 2 + 4 && y <= height / 2 + 6) && (x >= width / 2 + 8 && x <= width / 2 + 20))
	{
		bool ok = loginService.SignIn(this->username, this->password);
		if (ok)
		{
			delete current;
			current = new HomePage(loginService);
		}
		else
		{
			this->isError = true;
		}
		return;
	}
}