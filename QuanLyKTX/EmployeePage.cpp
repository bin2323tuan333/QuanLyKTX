#include "EmployeePage.h"
#include "ConsolaUI.h"

EmployeePage::EmployeePage(AccountService* accountService, EmployeeService* employeeService)
	:accountService(accountService), employeeService(employeeService), isRunning(true)
{
	this->menuSelected = 0;
	this->menuSize = 5;
	this->menuList = new string[this->menuSize]
	{
		"Trang Ca Nhan",
		"Quan Ly Sinh Vien",
		"Quan Ly Phong",
		"Quan Ly Hoa Don",
		"Dang Ky Va Lam Thu Tuc"
	};

	this->sidebarInfoSelected = 0;
	this->sidebarInfoSize = 3;
	this->sidebarInfoList = new string[this->sidebarInfoSize]
	{
		"Thong tin ca nhan",
		"Chinh sua thong tin",
		"Dang xuat"
	};

}

EmployeePage::~EmployeePage()
{
	delete[] this->menuList;
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
			switch (this->menuSelected)
			{
			case 0:
				handleArrowUD(key, this->sidebarInfoSelected, this->sidebarInfoSize);
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			}
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
		drawSidebarInfomation(width, height);
		drawInfomationContent(width, height);
		break;
	case 1:
		drawSidebarStudent(width, height);
		drawStudentServiceContent(width, height);
		break;
	case 2:
		drawSidebarRoom(width, height);
		drawRoomServiceContent(width, height);
		break;
	case 3:
		drawSidebarInvoice(width, height);
		drawInvoiceServiceContent(width, height);
		break;
	case 4:
		drawSidebarRegister(width, height);
		drawRegisterServiceContent(width, height);
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
void EmployeePage::drawInfomationContent(const int& width, const int& height)
{
	Employee& temp = this->employeeService->getEmployeeById(/*this->accountService->getEmployeeID()*/1);
	switch (this->sidebarInfoSelected)
	{
	case 0:
		ConsolaUI::text(30, 7, "THONG TIN NHAN VIEN:", 14);
		ConsolaUI::text(33, 8, "Ho Va Ten: ", 15);
		ConsolaUI::text(53, 8, temp.getFullName(), 15);
		ConsolaUI::text(33, 10, "Ma Nhan Vien:", 15);
		ConsolaUI::text(53, 10, to_string(temp.getEmployeeID()), 15);
		ConsolaUI::text(33, 12, "Ngay Sinh:", 15);
		ConsolaUI::gotoXY(53, 12); ConsolaUI::setTextColor(15); cout << temp.getDateOfBirth();
		ConsolaUI::text(33, 14, "Gioi Tinh:", 15);
		ConsolaUI::text(53, 14, temp.getGender(), 15);
		ConsolaUI::text(33, 16, "Chuc Vu:", 15);
		ConsolaUI::text(53, 16, temp.getPosition(), 15);
		ConsolaUI::text(33, 18, "Email:", 15);
		ConsolaUI::text(53, 18, temp.getEmail(), 15);
		ConsolaUI::text(33, 20, "So Dien Thoai:", 15);
		ConsolaUI::text(53, 20, temp.getPhoneNumber(), 15);
		break;
	case 1:
		ConsolaUI::text(30, 7, "CHINH SUA THONG TIN NHAN VIEN:", 14);
		ConsolaUI::text(33, 8, "Ho Va Ten: ", 15);
		ConsolaUI::text(53, 8, temp.getFullName(), 15);
		ConsolaUI::text(33, 10, "Ma Nhan Vien:", 15);
		ConsolaUI::text(53, 10, to_string(temp.getEmployeeID()), 15);
		ConsolaUI::text(33, 12, "Ngay Sinh:", 15);
		ConsolaUI::gotoXY(53, 12); ConsolaUI::setTextColor(15); cout << temp.getDateOfBirth();
		ConsolaUI::text(33, 14, "Gioi Tinh:", 15);
		ConsolaUI::text(53, 14, temp.getGender(), 15);
		ConsolaUI::text(33, 16, "Chuc Vu:", 15);
		ConsolaUI::text(53, 16, temp.getPosition(), 15);
		ConsolaUI::text(33, 18, "Email:", 15);
		ConsolaUI::text(53, 18, temp.getEmail(), 15);
		ConsolaUI::text(33, 20, "So Dien Thoai:", 15);
		ConsolaUI::text(53, 20, temp.getPhoneNumber(), 15);
		break;
	case 2:
		break;
	}
}
void EmployeePage::drawSidebarInfomation(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
	ConsolaUI::text(5, 8, *(this->sidebarInfoList), (0 == this->sidebarInfoSelected) ? 11 : 8);
	ConsolaUI::text(5, 12, *(this->sidebarInfoList + 1), (1 == this->sidebarInfoSelected) ? 11 : 8);
	ConsolaUI::text(5, 16, *(this->sidebarInfoList + 2), (2 == this->sidebarInfoSelected) ? 11 : 8);
}


void EmployeePage::drawStudentServiceContent(const int& width, const int& height)
{

}
void EmployeePage::drawSidebarStudent(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
}


void EmployeePage::drawRoomServiceContent(const int& width, const int& height)
{

}
void EmployeePage::drawSidebarRoom(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
}


void EmployeePage::drawInvoiceServiceContent(const int& width, const int& height)
{

}
void EmployeePage::drawSidebarInvoice(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
}


void EmployeePage::drawRegisterServiceContent(const int& width, const int& height)
{

}
void EmployeePage::drawSidebarRegister(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
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

void EmployeePage::handleNormalKeys(int key, int& index, const int& size)
{
	switch (key)
	{
	case 27:
		index = -1;
	default:
		if (key >= '1' && key <= '9')
		{
			int num = key - '1';
			if (num < size)
			{
				index = num;
			}
		}
	}
}