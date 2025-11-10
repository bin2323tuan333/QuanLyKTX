#include "HomeView.h"


HomeView::HomeView(Account*& acc, AuthService* authService)
	:user(acc), authService(authService)
{
	this->menuChoice = 0;
	this->loginSelected = 0;
	this->username = "";
	this->password = "";
	this->isError = false;
	this->isEndApp = false;
}

HomeView::~HomeView()
{
}



int HomeView::show()
{
	
	showHeader(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
	switch (menuChoice)
	{
	case 0:
	{
		showHome(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
	}
	break;
	case 1:
	{
		showAbout(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
	}
	break;
	case 2:
	{
		showLogin(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
	}
	break;
	case 3:
	{
		showExit(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
	}
	break;
	}
	handleInput();
	if (this->isEndApp == true)
	{
		return 0;
	}
	if (this->user != nullptr)
	{
		return 2;
	}
	return 1;
}

void HomeView::handleInput()
{
	ConsolaUI::setTextColor(15);
	int key = _getch();
	if (key == 0 || key == 224)
	{
		int tempKey = _getch();
		if (tempKey == 75)
		{
			if (menuChoice == 0) menuChoice = 3;
			else menuChoice--;
		}
		else if (tempKey == 77)
		{
			if (menuChoice == 3) menuChoice = 0;
			else menuChoice++;
		}
	}
	else if (this->menuChoice == 2)
	{
		if (1 == key - '0')
		{
			ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2 - 23, ConsolaUI::getConsoleHeight() / 2 + 1);
			this->username = ConsolaUI::GetLine("normal");
		}
		else if (2 == key - '0')
		{
			ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2 - 23, ConsolaUI::getConsoleHeight() / 2 + 5);
			this->password = ConsolaUI::GetLine("pass");
		}
		else if (key == 13)
		{
			this->user = this->authService->login(this->username, this->password);
			if (this->user == nullptr)
			{
				ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2 - 23, ConsolaUI::getConsoleHeight() / 2 - 3, "Sai MK", 15);
			}
		}
	}
	else if (this->menuChoice == 3)
	{
		if (key == 13)
		{
			this->isEndApp = true;
		}
	}
}


void HomeView::showHeader(const int& width, const int& height)
{
	ConsolaUI::text(12, 2, "HE THONG QUAN LY KI TUC XA", 13);
	ConsolaUI::drawBox(1, 3, width - 1, 2, 7);
	ConsolaUI::text((width - 20) / 5, 4, "HOME", menuChoice == 0 ? 1 : 8);
	ConsolaUI::text(2 * (width - 20) / 5 + 4, 4, "ABOUT", menuChoice == 1 ? 1 : 8);
	ConsolaUI::text(3 * (width - 20) / 5 + 9, 4, "LOGIN", menuChoice == 2 ? 1 : 8);
	ConsolaUI::text(4 * (width - 20) / 5 + 14, 4, "EXIT", menuChoice == 3 ? 1 : 8);
}
void HomeView::showHome(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 52, 7, "THONG TIN CHUNG", 3);
	ConsolaUI::text(width / 2 - 50, 8, "$ Ky tuc xa truong Dai hoc Bach Khoa Da Nang.", 15);
	ConsolaUI::text(width / 2 - 50, 9, "$ Voi co so vat chat hien dai, moi truong hoc tap va sinh hoat lanh manh.", 15);

	ConsolaUI::text(width / 2 - 52, 12, "CAC KHU KY TUC XA", 2);
	ConsolaUI::text(width / 2 - 50, 13, "$ Toa Nha A: 5 tang - 120 phong", 15);
	ConsolaUI::text(width / 2 - 50, 14, "$ Toa Nha B: 5 tang - 120 phong", 15);
	ConsolaUI::text(width / 2 - 50, 15, "$ Toa Nha C: 5 tang - 120 phong", 15);


	ConsolaUI::text(width / 2 - 52, 18, "TIEN ICH & DICH VU", 6);
	ConsolaUI::text(width / 2 - 50, 19, "$ Cung cap wifi toan khu", 15);
	ConsolaUI::text(width / 2 - 50, 20, "$ Thu vien 3 tang", 15);
	ConsolaUI::text(width / 2 - 50, 21, "$ Khu vui choi giai tri", 15);
	ConsolaUI::text(width / 2 - 50, 22, "$ Cang tin dat chuan quoc te", 15);
	ConsolaUI::text(width / 2 - 50, 23, "$ Phong gym & the thao", 15);
}
void HomeView::showAbout(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 15, 6, "===== GIOI THIEU MON HOC =====", 14);
	ConsolaUI::text(width / 2 - 13, 8, "PBL2: Do an co so lap trinh", 15);
	ConsolaUI::text(width / 2 - 27, 10, "De Tai Thuc Hien: Ung Dung Quan Ly Ki Tuc Xa Sinh Vien", 15);

	ConsolaUI::text(width / 5, 16, "GIANG VIEN HUONG DAN:", 13);
	ConsolaUI::text(width / 3 + 10, 16, "TS. Truong Ngoc Chau", 15);

	ConsolaUI::text(width / 5, 19, "SINH VIEN THUC HIEN:", 6);
	ConsolaUI::text(width / 3 + 10, 19, "Pham Quoc Tuan             Lop: 24T_DT4    MSSV: 102240229", 15);
	ConsolaUI::text(width / 3 + 10, 20, "Nguyen Viet Nhat Long      Lop: 24T_DT4    MSSV: 102240229", 15);


	ConsolaUI::text(width / 2 - 8, height - 1, "Da Nang, 10/2025", 15);
}
void HomeView::showLogin(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 4, height / 2 - 3, "DANG NHAP", 14);
	ConsolaUI::drawBox(width / 2 - 25, height / 2, 50, 2, (1 == this->loginSelected) ? 1 : 11);
	ConsolaUI::text(width / 2 - 20, height / 2, " 1. Ten Dang Nhap ", (1 == this->loginSelected) ? 1 : 11);
	ConsolaUI::drawBox(width / 2 - 25, height / 2 + 4, 50, 2, (2 == this->loginSelected) ? 1 : 11);
	ConsolaUI::text(width / 2 - 20, height / 2 + 4, " 2. Mat Khau ", (2 == this->loginSelected) ? 1 : 11);
	ConsolaUI::text(width / 2 - 3, height / 2 + 7, "Nhan [ Enter ] De Dang Nhap", 2);

	if (this->username != "")
		ConsolaUI::text(width / 2 - 23, height / 2 + 1, this->username, (1 == this->loginSelected) ? 1 : 11);
	if (this->password != "")
	{
		string pass = "";
		for (int i = 0; i < (this->password).length(); i++) pass += "*";
		ConsolaUI::text(width / 2 - 23, height / 2 + 5, pass, (2 == this->loginSelected) ? 1 : 11);
	}
	this->loginSelected = 0;
}
void HomeView::showExit(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 10, height / 2 - 1, "Nhan Enter De Thoat", 14);
}
