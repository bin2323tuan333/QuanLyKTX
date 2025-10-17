#include "InfoManageView.h"
#include "ConsolaUI.h"

InfoManageView::InfoManageView(AccountService* accountService, EmployeeService* employeeService)
	:accountService(accountService), employeeService(employeeService)
{
	this->sidebarInfoSelected = 0;
	this->sidebarInfoSize = 3;
	this->sidebarInfoList = new string[this->sidebarInfoSize]
	{
		"Thong Tin Ca Nhan",
		"Doi Mat Khau",
		"Dang Xuat"
	};
	this->changePasswordSelected = 0;
	this->oldPass = "";
	this->newPass = "";
	this->reEnterNewPass = "";
	this->isChangePass = false;
}
InfoManageView::~InfoManageView()
{
	delete[] this->sidebarInfoList;
}


void InfoManageView::handleInput(int key)
{
	if (key == 0 || key == 224)
	{
		key = _getch();
		if (key == 72 || key == 80)
		{
			sidebarInfoSelected = (sidebarInfoSelected + (key == 72 ? -1 : 1) + sidebarInfoSize) % sidebarInfoSize;
		}
	}
	else if (this->sidebarInfoSelected == 2 && key == 27)
	{
		this->accountService->setSignIn(false);
	}
	else if (this->sidebarInfoSelected == 1)
	{
		if (key >= '1' && key <= '3') {
			changePasswordSelected = key - '0';
		}
		if (key == 13)
		{
			this->isChangePass = this->accountService->changePassword(
				this->accountService->getEmployeeID(),
				this->oldPass,
				this->newPass,
				this->reEnterNewPass
			);
			this->oldPass = "";
			this->newPass = "";
			this->reEnterNewPass = "";
		}
	}
}

void InfoManageView::show()
{
	int width = ConsolaUI::getConsoleWidth();
	int height = ConsolaUI::getConsoleHeight();
	drawSidebarInfomation(width, height);
	drawInfomationContent(width, height);
}

void InfoManageView::drawInfomationContent(const int& width, const int& height)
{
	Employee* temp = this->employeeService->getEmployeeById(/*this->accountService->getEmployeeID()*/1001);
	switch (this->sidebarInfoSelected)
	{
	case 0:
		ConsolaUI::text(30, 7, "THONG TIN NHAN VIEN:", 14);
		ConsolaUI::text(33, 8, "Ho Va Ten: ", 15);
		ConsolaUI::text(63, 8, temp->getFullName(), 15);
		ConsolaUI::text(33, 10, "Ma Nhan Vien:", 15);
		ConsolaUI::text(63, 10, to_string(temp->getEmployeeID()), 15);
		ConsolaUI::text(33, 12, "Ngay Sinh:", 15);
		ConsolaUI::gotoXY(63, 12); ConsolaUI::setTextColor(15); cout << temp->getDateOfBirth();
		ConsolaUI::text(33, 14, "Gioi Tinh:", 15);
		ConsolaUI::text(63, 14, temp->getGender(), 15);
		ConsolaUI::text(33, 16, "Chuc Vu:", 15);
		ConsolaUI::text(63, 16, temp->getPosition(), 15);
		ConsolaUI::text(33, 18, "Email:", 15);
		ConsolaUI::text(63, 18, temp->getEmail(), 15);
		ConsolaUI::text(33, 20, "So Dien Thoai:", 15);
		ConsolaUI::text(63, 20, temp->getPhoneNumber(), 15);
		break;
	case 1:
		ConsolaUI::text(30, 7, "DOI MAT KHAU:", 14);
		ConsolaUI::text(width / 2 - 20, height / 2 - 2, "1. Nhap Mat Khau Cu", (1 == this->changePasswordSelected) ? 11 : 8);
		ConsolaUI::text(width / 2 - 20, height / 2 + 1, "2. Nhap Mat Khau Moi", (2 == this->changePasswordSelected) ? 11 : 8);
		ConsolaUI::text(width / 2 - 20, height / 2 + 4, "3. Nhap Lai Mat Khau Moi", (3 == this->changePasswordSelected) ? 11 : 8);
		ConsolaUI::text(width / 2 + 12, height / 2 - 2, ((this->oldPass == "") ? "" : this->oldPass), (1 == this->changePasswordSelected) ? 11 : 8);
		ConsolaUI::text(width / 2 + 12, height / 2 + 1, ((this->newPass == "") ? "" : this->newPass), (2 == this->changePasswordSelected) ? 11 : 8);
		ConsolaUI::text(width / 2 + 12, height / 2 + 4, ((this->reEnterNewPass == "") ? "" : this->reEnterNewPass), (3 == this->changePasswordSelected) ? 11 : 8);
		ConsolaUI::text(width / 2, height / 2 + 7, "Nhan           De Thay Doi Mat Khau", 15);
		ConsolaUI::text(width / 2 + 5, height / 2 + 7, "[ Enter ]", 2);

		if (this->isChangePass)
		{
			ConsolaUI::text(width / 2 - 5, height / 2 - 5, "Doi Mat Khau Thanh Cong", 2);
		}

		ConsolaUI::drawBox(width / 2 + 10, height / 2 - 3, 30, 2, (1 == this->changePasswordSelected) ? 11 : 8);
		ConsolaUI::drawBox(width / 2 + 10, height / 2, 30, 2, (2 == this->changePasswordSelected) ? 11 : 8);
		ConsolaUI::drawBox(width / 2 + 10, height / 2 + 3, 30, 2, (3 == this->changePasswordSelected) ? 11 : 8);
		ConsolaUI::setTextColor(15);
		switch (this->changePasswordSelected)
		{
		case 1:
			ConsolaUI::gotoXY(width / 2 + 12, height / 2 - 2);
			this->oldPass = GetLine();
			break;
		case 2:
			ConsolaUI::gotoXY(width / 2 + 12, height / 2 + 1);
			this->newPass = GetLine();
			break;
		case 3:
			ConsolaUI::gotoXY(width / 2 + 12, height / 2 + 4);
			this->reEnterNewPass = GetLine();
			break;
		}
		this->changePasswordSelected = 0;

		break;
	case 2:
		ConsolaUI::text(30, 7, "DANG XUAT TAI KHOAN:", 14);
		ConsolaUI::text(53, 15, "Nhan ESC De Dang Xuat", 15);
		break;
	}
}

void InfoManageView::drawSidebarInfomation(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
	ConsolaUI::text(5, 8, *(this->sidebarInfoList), (0 == this->sidebarInfoSelected) ? 11 : 8);
	ConsolaUI::text(5, 12, *(this->sidebarInfoList + 1), (1 == this->sidebarInfoSelected) ? 11 : 8);
	ConsolaUI::text(5, 16, *(this->sidebarInfoList + 2), (2 == this->sidebarInfoSelected) ? 11 : 8);
}




string InfoManageView::GetLine()
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