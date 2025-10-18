#include "EmployeePage.h"
#include "ConsolaUI.h"
#include <sstream>

EmployeePage::EmployeePage(
	AccountService* accountService,
	EmployeeService* employeeService,
	StudentService* studentService,
	RoomService* roomService,
	InvoiceService* invoiceService,
	ContractService* contractService
)
	:accountService(accountService), 
	employeeService(employeeService), 
	studentService(studentService),
	roomService(roomService),
	invoiceService(invoiceService),
	contractService(contractService),
	isRunning(true)
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


	this->infoManageView = new InfoManageView(
		this->accountService, 
		this->employeeService
	);
	this->studentManageView = new StudentManageView(
		this->studentService
	);
	this->roomManageView = new RoomManageView(
		this->roomService
	);
	this->invoiceManageView = new InvoiceManageView(
		this->invoiceService
	);
	this->contractManageView = new ContractManageView(
		this->contractService
	);
}

EmployeePage::~EmployeePage()
{
	delete[] this->menuList;
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
			this->roomManageView->handleInput(key);
			break;
		case 3:
			this->contractManageView->handleInput(key);
			break;
		case 4:
			this->invoiceManageView->handleInput(key);
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
		this->roomManageView->show();
		break;
	case 3:
		this->contractManageView->show();
		break;
	case 4:
		this->invoiceManageView->show();
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