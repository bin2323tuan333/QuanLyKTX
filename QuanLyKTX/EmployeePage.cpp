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
		"Quan Ly Hop Dong",
		"Quan Ly Hoa Don"
	};

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

	this->sidebarStudentSelected = 0;
	this->sidebarStudentSize = 4;
	this->sidebarStudentList = new string[this->sidebarStudentSize]
	{
		"Them Moi Sinh Vien",
		"Xoa Sinh Vien",
		"Cap Nhat Thong Tin",
		"Tim Kiem Theo Ma SV"
		//Tim Theo Ten
		//Loc Theo Lop, Khoa, Toa, Phong.
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

}

EmployeePage::~EmployeePage()
{
	delete[] this->menuList;
	delete[] this->sidebarInfoList;
	delete[] this->sidebarStudentList;
	delete[] this->sidebarRoomList;
	delete[] this->sidebarContractList;
	delete[] this->sidebarInvoiceList;
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
				handleArrowUD(key, this->sidebarStudentSelected, this->sidebarStudentSize);
				break;
			case 2:
				handleArrowUD(key, this->sidebarRoomSelected, this->sidebarRoomSize);
				break;
			case 3:
				handleArrowUD(key, this->sidebarContractSelected, this->sidebarContractSize);
				break;
			case 4:
				handleArrowUD(key, this->sidebarInvoiceSelected, this->sidebarInvoiceSize);
				break;
			}
		}
		if (this->menuSelected == 0 && this->sidebarInfoSelected == 2 && key == 27)
		{
			this->accountService->setSignIn(false);
			this->isRunning = false;
		}
		if (this->menuSelected == 0 && this->sidebarInfoSelected == 1)
		{
			handleNormalKeys(key, this->changePasswordSelected);
			if (key == 13)
			{
				this->isChangePass = this->accountService->changePassword(this->accountService->getEmployeeID(), this->oldPass, this->newPass, this->reEnterNewPass);
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
void EmployeePage::drawInfomationContent(const int& width, const int& height)
{
	Employee& temp = this->employeeService->getEmployeeById(/*this->accountService->getEmployeeID()*/1001);
	switch (this->sidebarInfoSelected)
	{
	case 0:
		ConsolaUI::text(30, 7, "THONG TIN NHAN VIEN:", 14);
		ConsolaUI::text(33, 8, "Ho Va Ten: ", 15);
		ConsolaUI::text(63, 8, temp.getFullName(), 15);
		ConsolaUI::text(33, 10, "Ma Nhan Vien:", 15);
		ConsolaUI::text(63, 10, to_string(temp.getEmployeeID()), 15);
		ConsolaUI::text(33, 12, "Ngay Sinh:", 15);
		ConsolaUI::gotoXY(63, 12); ConsolaUI::setTextColor(15); cout << temp.getDateOfBirth();
		ConsolaUI::text(33, 14, "Gioi Tinh:", 15);
		ConsolaUI::text(63, 14, temp.getGender(), 15);
		ConsolaUI::text(33, 16, "Chuc Vu:", 15);
		ConsolaUI::text(63, 16, temp.getPosition(), 15);
		ConsolaUI::text(33, 18, "Email:", 15);
		ConsolaUI::text(63, 18, temp.getEmail(), 15);
		ConsolaUI::text(33, 20, "So Dien Thoai:", 15);
		ConsolaUI::text(63, 20, temp.getPhoneNumber(), 15);
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
void EmployeePage::drawSidebarInfomation(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
	ConsolaUI::text(5, 8, *(this->sidebarInfoList), (0 == this->sidebarInfoSelected) ? 11 : 8);
	ConsolaUI::text(5, 12, *(this->sidebarInfoList + 1), (1 == this->sidebarInfoSelected) ? 11 : 8);
	ConsolaUI::text(5, 16, *(this->sidebarInfoList + 2), (2 == this->sidebarInfoSelected) ? 11 : 8);
}


void EmployeePage::drawStudentServiceContent(const int& width, const int& height)
{
	switch (this->sidebarStudentSelected)
	{
	case 0:
		ConsolaUI::text(30, 7, "THEM SINH VIEN MOI:", 14);
		ConsolaUI::text(35, 8, "1. Ten Sinh Vien: ", 8);
		ConsolaUI::text(35, 10, "2. Ngay Sinh: ", 8);
		ConsolaUI::text(35, 12, "3. Gioi Tinh: ", 8);
		ConsolaUI::text(35, 14, "4. Ma So Sinh Vien: ", 8);
		ConsolaUI::text(35, 16, "5. Lop: ", 8);
		ConsolaUI::text(35, 18, "6. Khoa: ", 8);
		ConsolaUI::text(35, 20, "7. So Dien Thoai: ", 8);
		ConsolaUI::text(35, 22, "8. Email: ", 8);
		ConsolaUI::text(80, 25, "Nhan ENTER De Them Sinh Vien", 15);
		ConsolaUI::text(85, 25, "ENTER", 2);
		break;
	case 1:
		ConsolaUI::text(30, 7, "XOA SINH VIEN:", 14);
		break;
	case 2:
		ConsolaUI::text(30, 7, "CAP NHAT THONG TIN SINH VIEN:", 14);
		break;
	case 3:
		ConsolaUI::text(30, 7, "TIM KIEN THEO MA SINH VIEN:", 14);
		break;
	}
}
void EmployeePage::drawSidebarStudent(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
	ConsolaUI::text(5, 8, *(this->sidebarStudentList), (0 == this->sidebarStudentSelected) ? 11 : 8);
	ConsolaUI::text(5, 12, *(this->sidebarStudentList + 1), (1 == this->sidebarStudentSelected) ? 11 : 8);
	ConsolaUI::text(5, 16, *(this->sidebarStudentList + 2), (2 == this->sidebarStudentSelected) ? 11 : 8);
	ConsolaUI::text(5, 20, *(this->sidebarStudentList + 3), (3 == this->sidebarStudentSelected) ? 11 : 8);
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
	return ss;
}