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
		"Quan Ly Hoa Don",
		"Quan Ly Hop Dong"
	};

	this->currentView = nullptr;
}

EmployeePage::~EmployeePage()
{
	delete[] this->menuList;
	if (this->currentView != nullptr)
		delete this->currentView;
}


void EmployeePage::show()
{
	this->isRunning = true;

	this->currentView = new InfoManageView(
		this->accountService,
		this->employeeService
	);
	
	while (isRunning)
	{
		drawEmployeePage();

		int key = _getch();
		int previousSelected = this->menuSelected;
		if (key == 0 || key == 224) // Phim mui ten
		{
			key = _getch();
			handleArrowLR(key, this->menuSelected, this->menuSize);
		}
		this->currentView->handleInput(key);
		if(previousSelected != this->menuSelected)
		{
			delete this->currentView;

			switch (this->menuSelected)
			{
			case 0:
				this->currentView = new InfoManageView(
					this->accountService,
					this->employeeService
				);
				break;
			case 1:
				this->currentView = new StudentManageView(
					this->studentService
				);
				break;
			case 2:
				this->currentView = new RoomManageView(
					this->roomService
				);
				break;
			case 3:
				this->currentView = new InvoiceManageView(
					this->invoiceService
				);
				break;
			case 4:
				this->currentView = new ContractManageView(
					this->contractService,
					this->studentService,
					this->roomService
				);
				break;
			}
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
	this->currentView->show();
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