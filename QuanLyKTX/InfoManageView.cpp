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
	this->isError = 2;
}
InfoManageView::~InfoManageView()
{
	delete[] this->sidebarInfoList;
}

void InfoManageView::handleInput(int key)
{
	int width = ConsolaUI::getConsoleWidth();
	int height = ConsolaUI::getConsoleHeight();
	if (key == 72 || key == 80)
	{
		sidebarInfoSelected = (sidebarInfoSelected + (key == 72 ? -1 : 1) + sidebarInfoSize) % sidebarInfoSize;
	}
	else if (this->sidebarInfoSelected == 2 && key == 27)
	{
		this->accountService->setSignIn(false);
	}
	else if (this->sidebarInfoSelected == 1)
	{
		if (key >= '1' && key <= '3') {
			this->changePasswordSelected = key - '0';
		}
		if (this->changePasswordSelected > 0)
		{
			ConsolaUI::setTextColor(1);
			if (this->changePasswordSelected == 1) 
			{
				ConsolaUI::text(width / 2 + 12, height / 2 - 2, "                         ", 15);
				ConsolaUI::gotoXY(width / 2 + 12, height / 2 - 2);
				this->oldPass = GetLine();
			}
			else if (this->changePasswordSelected == 2) 
			{
				ConsolaUI::text(width / 2 + 12, height / 2 + 1, "                         ", 15);
				ConsolaUI::gotoXY(width / 2 + 12, height / 2 + 1);
				this->newPass = GetLine();
			}
			else if (this->changePasswordSelected == 3) 
			{
				ConsolaUI::text(width / 2 + 12, height / 2 + 4, "                         ", 15);
				ConsolaUI::gotoXY(width / 2 + 12, height / 2 + 4);
				this->reEnterNewPass = GetLine();
			}
			this->changePasswordSelected = 0;
			this->isError = 2;
		}
		if (key == 13)
		{
			this->isError = this->accountService->changePassword(
				this->accountService->getCurrentID(),
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
	Account* account = this->accountService->SearchByID(this->accountService->getCurrentID());
	Employee* temp = this->employeeService->SearchByID(account->getEmployeeID());
	switch (this->sidebarInfoSelected)
	{
	case 0:
		ConsolaUI::text(30, 7, "THONG TIN CA NHAN (NHAN VIEN)", 14);
		ConsolaUI::drawBox(32, 9, 50, 14, 8);
		ConsolaUI::text(34, 10, "Thong tin dinh danh:", 11);
		ConsolaUI::text(35, 12, "Ho Va Ten: ", 7);
		ConsolaUI::text(51, 12, temp->getFullName(), 15);
		ConsolaUI::text(35, 13, "Ma Nhan Vien: ", 7);
		ConsolaUI::text(51, 13, to_string(temp->getEmployeeID()), 15);
		ConsolaUI::text(35, 14, "Ngay Sinh: ", 7);
		ConsolaUI::gotoXY(51, 14); ConsolaUI::setTextColor(15); cout << temp->getDateOfBirth();
		ConsolaUI::text(35, 15, "Gioi Tinh: ", 7);
		ConsolaUI::text(51, 15, temp->getGender() == true ? "Nam" : "Nu", 15);

		ConsolaUI::text(34, 17, "---------------------------------------------", 8);
		ConsolaUI::text(34, 18, "Thong tin lien he & Chuc vu:", 11);
		ConsolaUI::text(35, 20, "Chuc Vu: ", 7);
		ConsolaUI::text(51, 20, temp->getPosition(), 15);
		ConsolaUI::text(35, 21, "Email: ", 7);
		ConsolaUI::text(51, 21, temp->getEmail(), 15);
		ConsolaUI::text(35, 22, "So Dien Thoai: ", 7);
		ConsolaUI::text(51, 22, temp->getPhoneNumber(), 15);
		break;
	case 1:
		ConsolaUI::text(30, 7, "DOI MAT KHAU:", 14);
		ConsolaUI::text(width / 2 - 20, height / 2 - 2, "[1] Nhap Mat Khau Cu", 15);
		ConsolaUI::text(width / 2 - 20, height / 2 + 1, "[2] Nhap Mat Khau Moi", 15);
		ConsolaUI::text(width / 2 - 20, height / 2 + 4, "[3] Nhap Lai Mat Khau Moi", 15);
		ConsolaUI::text(width / 2 + 12, height / 2 - 2, ((this->oldPass == "") ? "" : this->oldPass), 15);
		ConsolaUI::text(width / 2 + 12, height / 2 + 1, ((this->newPass == "") ? "" : this->newPass), 15);
		ConsolaUI::text(width / 2 + 12, height / 2 + 4, ((this->reEnterNewPass == "") ? "" : this->reEnterNewPass), 15);
		ConsolaUI::text(width / 2, height / 2 + 7, "Nhan [       ] De Thay Doi Mat Khau", 15);
		ConsolaUI::text(width / 2 + 7, height / 2 + 7, "Enter", 2);
		ConsolaUI::drawBox(width / 2 + 10, height / 2 - 3, 30, 2, 15);
		ConsolaUI::drawBox(width / 2 + 10, height / 2, 30, 2, 15);
		ConsolaUI::drawBox(width / 2 + 10, height / 2 + 3, 30, 2, 15);

		if (this->isError == 1)
		{
			ConsolaUI::text(width / 2 - 5, height / 2 - 5, "Doi Mat Khau Thanh Cong                ", 2);
		}
		else if (this->isError == -1)
		{
			ConsolaUI::text(width / 2 - 5, height / 2 - 5, "Khong Duoc De Trong Phan Nhap Mat Khau ", 12);
		}
		else if (this->isError == -4)
		{
			ConsolaUI::text(width / 2 - 5, height / 2 - 5, "Nhap Lai Mat Khau Khong Khop           ", 12);
		}
		else if (this->isError == -3)
		{
			ConsolaUI::text(width / 2 - 5, height / 2 - 5, "Mat Khau Cu Nhap Khong Dung            ", 12);
		}
		else if (this->isError == 0)
		{
			ConsolaUI::text(width / 2 - 5, height / 2 - 5, "Khong Duoc Su Sung Mat Khau Cu         ", 12);
		}
		break;
	case 2:
	{
		ConsolaUI::text(30, 7, "DANG XUAT TAI KHOAN:", 14);
		int boxWidth = 50;
		int boxX = width / 2 - boxWidth / 2;
		ConsolaUI::drawBox(boxX, 12, boxWidth, 7, 8);

		ConsolaUI::text(width / 2 - 17, 14, "Ban co chac chan muon dang xuat ?", 15);

		ConsolaUI::text(width / 2 - 13, 16, "Nhan [ ESC ] de xac nhan", 10);
		break;
	}
	}
}

void InfoManageView::drawSidebarInfomation(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
	ConsolaUI::text(5, 8, *(this->sidebarInfoList), (0 == this->sidebarInfoSelected) ? 11 : 8);
	ConsolaUI::text(5, 10, *(this->sidebarInfoList + 1), (1 == this->sidebarInfoSelected) ? 11 : 8);
	ConsolaUI::text(5, 12, *(this->sidebarInfoList + 2), (2 == this->sidebarInfoSelected) ? 11 : 8);
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