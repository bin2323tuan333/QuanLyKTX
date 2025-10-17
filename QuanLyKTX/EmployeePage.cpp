#include "EmployeePage.h"
#include "ConsolaUI.h"
#include <sstream>

EmployeePage::EmployeePage(AccountService* accountService, EmployeeService* employeeService, StudentService* studentService)
	:accountService(accountService), employeeService(employeeService), studentService(studentService), isRunning(true)
{
	this->menuSelected = 0;
	this->menuSize = 5;
	this->menuList = new string[this->menuSize]
	{
		"Trang Ca Nhan",
		"Quan Ly Sinh Vien",
		"Quan Ly Phong",
		"Quan Ly Hop Dong",
		"Quan Ly Hoa Don"
	};

	this->sidebarRoomSelected = 0;
	this->sidebarRoomSize = 2;
	this->sidebarRoomList = new string[this->sidebarRoomSize]
	{
		"Xem Danh Sach Phong",
		"Loc Theo Trang Thai"
		//Xem Chi Tiet Phong
	};

	this->sidebarContractSelected = 0;
	this->sidebarContractSize = 2;
	this->sidebarContractList = new string[this->sidebarContractSize]
	{
		"Tao Hop Dong Moi",
		"Ket Thuc Hop Dong"
		//Chuyen Phong
		//Gia Han Hop Dong

	};

	this->sidebarInvoiceSelected = 0;
	this->sidebarInvoiceSize = 2;
	this->sidebarInvoiceList = new string[this->sidebarInvoiceSize]
	{
		"Tao Hoa Don",
		"Cap Nhat Trang Thai"
		//Tu Dong Tao Hoa Don
	};


	this->infoManageView = new InfoManageView(
		this->accountService, 
		this->employeeService
	);
	this->studentManageView = new StudentManageView(
		this->studentService
	);
	
}

EmployeePage::~EmployeePage()
{
	delete[] this->menuList;
	delete[] this->sidebarStudentList;
	delete[] this->sidebarRoomList;
	delete[] this->sidebarContractList;
	delete[] this->sidebarInvoiceList;


	delete this->infoManageView;
	delete this->studentManageView;
}


void EmployeePage::show()
{
	this->isRunning = true;
	while (isRunning)
	{
		drawEmployeePage();

		int key = _getch();
		if (key == 0 || key == 224) // Phim mui ten
		{
			key = _getch();
			handleArrowLR(key, this->menuSelected, this->menuSize);
		}
		switch (this->menuSelected)
		{
		case 0:
			this->infoManageView->handleInput(key);
			break;
		case 1:
			this->studentManageView->handleInput(key);
			break;
		case 2:
			//handleArrowUD(key, this->sidebarRoomSelected, this->sidebarRoomSize);
			break;
		case 3:
			//handleArrowUD(key, this->sidebarContractSelected, this->sidebarContractSize);
			break;
		case 4:
			//handleArrowUD(key, this->sidebarInvoiceSelected, this->sidebarInvoiceSize);
			break;
		}
		if (!this->accountService->isSignIn())
		{
			this->isRunning = false;
		}
	}
}



void EmployeePage::drawEmployeePage()
{
	int width = ConsolaUI::getConsoleWidth();
	int height = ConsolaUI::getConsoleHeight();

	ConsolaUI::clearScreen();
	ConsolaUI::ShowCursor(false);
	ConsolaUI::drawBox(0, 0, width, height, 7);

	drawHeader(width, height);
	drawFooter(width, height);
	switch (menuSelected)
	{
	case 0:
		this->infoManageView->show();
		break;
	case 1:
		this->studentManageView->show();
		break;
	case 2:
		drawSidebarRoom(width, height);
		drawRoomServiceContent(width, height);
		break;
	case 3:
		drawSidebarContract(width, height);
		drawContractServiceContent(width, height);
		break;
	case 4:
		drawSidebarInvoice(width, height);
		drawInvoiceServiceContent(width, height);
		break;
	};
}

void EmployeePage::drawHeader(const int& width, const int& height)
{
	ConsolaUI::setTextColor(15);
	ConsolaUI::text(10, 2, "HE THONG QUAN LY KI TUC XA", 13);
	drawMenuItems(width, height);
}
void EmployeePage::drawMenuItems(const int& width, const int& height)
{
	ConsolaUI::drawBox(1, 3, width - 2, 2, 7);
	ConsolaUI::text(5, 4, *(this->menuList), (0 == menuSelected) ? 1 : 8);
	ConsolaUI::text(23, 4, *(this->menuList + 1), (1 == menuSelected) ? 1 : 8);
	ConsolaUI::text(45, 4, *(this->menuList + 2), (2 == menuSelected) ? 1 : 8);
	ConsolaUI::text(65, 4, *(this->menuList + 3), (3 == menuSelected) ? 1 : 8);
	ConsolaUI::text(85, 4, *(this->menuList + 4), (4 == menuSelected) ? 1 : 8);
}
void EmployeePage::drawFooter(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 27, height + 1, "Su dung cac phim [<-] [->] de di chuyen giua cac trang", 2);
}




void EmployeePage::drawRoomServiceContent(const int& width, const int& height)
{
	switch (this->sidebarRoomSelected)
	{
	case 0:
		ConsolaUI::text(30, 7, "XEM DANH SACH PHONG:", 14);
		break;
	case 1:
		ConsolaUI::text(30, 7, "LOC THEO TRANG THAI:", 14);
		break;
	}
}
void EmployeePage::drawSidebarRoom(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
	ConsolaUI::text(5, 8, *(this->sidebarRoomList), (0 == this->sidebarRoomSelected) ? 11 : 8);
	ConsolaUI::text(5, 12, *(this->sidebarRoomList + 1), (1 == this->sidebarRoomSelected) ? 11 : 8);
}

void EmployeePage::drawContractServiceContent(const int& width, const int& height)
{
	switch (this->sidebarContractSelected)
	{
	case 0:
		ConsolaUI::text(30, 7, "TAO HOP DONG MOI:", 14);
		break;
	case 1:
		ConsolaUI::text(30, 7, "KET THUC HOP DONG:", 14);
		break;
	}
}
void EmployeePage::drawSidebarContract(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
	ConsolaUI::text(5, 8, *(this->sidebarContractList), (0 == this->sidebarContractSelected) ? 11 : 8);
	ConsolaUI::text(5, 12, *(this->sidebarContractList + 1), (1 == this->sidebarContractSelected) ? 11 : 8);
}


void EmployeePage::drawInvoiceServiceContent(const int& width, const int& height)
{
	switch (this->sidebarInvoiceSelected)
	{
	case 0:
		ConsolaUI::text(30, 7, "TAO HOA DON:", 14);
		break;
	case 1:
		ConsolaUI::text(30, 7, "CAP NHAT TRANG THAI:", 14);
		break;
	}
}
void EmployeePage::drawSidebarInvoice(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
	ConsolaUI::text(5, 8, *(this->sidebarInvoiceList), (0 == this->sidebarInvoiceSelected) ? 11 : 8);
	ConsolaUI::text(5, 12, *(this->sidebarInvoiceList + 1), (1 == this->sidebarInvoiceSelected) ? 11 : 8);
}


void EmployeePage::handleArrowLR(int key, int& index, const int& size)
{
	switch (key)
	{
	case 75:
		index = (index - 1 + size) % size;
		break;
	case 77:
		index = (index + 1) % size;
		break;
	}
}
void EmployeePage::handleArrowUD(int key, int& index, const int& size)
{
	switch (key)
	{
	case 72:
		index = (index - 1 + size) % size;
		break;
	case 80:
		index = (index + 1) % size;
		break;
	}
}

void EmployeePage::handleNormalKeys(int key, int& index)
{
	if (key >= '1' && key <= '9')
	{
		index = key - '0';
	}
}

string EmployeePage::GetLine()
{
	string ss;
	ConsolaUI::ShowCursor(true);
	while (true)
	{
		int key = _getch();
		if (key == '\r' || key == '\n')
		{
			break;
		}
		if (key == '\b')
		{
			if (ss.length() > 0)
			{
				ss.resize(ss.length() - 1);
				cout << "\b \b";
			}
		}
		else
		{
			ss += char(key);
			cout << char(key);
		}
	}
	ConsolaUI::ShowCursor(false);
	return ss;
}

int EmployeePage::GetInt()
{
	string inputString = GetLine();
	stringstream ss(inputString);
	int result = 0;
	ss >> result;
	return result;
}