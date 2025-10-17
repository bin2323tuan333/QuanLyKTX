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

	this->sidebarStudentSelected = 0;
	this->sidebarStudentSize = 2;
	this->sidebarStudentList = new string[this->sidebarStudentSize]
	{
		"Them Moi Sinh Vien",
		"Tim Kiem Theo Ma SV"
		//Tim Theo Ten
		//Loc Theo Lop, Khoa, Toa, Phong.
	};
	this->studentIDToSearch = 0;
	this->keyToSearchStudent = 0;
	this->keyToActStudent = 0;
	this->studentToAct = nullptr;
	this->studentToAdd = new Student();
	this->isAddStudentSucessfull = false;
	this->isShowBoxDeleteStudent = false;
	this->isDeleteComplete = false;
	this->isUpdateComplete = false;

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


	this->infoManageView = new InfoManageView(this->accountService, this->employeeService);
	
}

EmployeePage::~EmployeePage()
{
	delete[] this->menuList;
	delete[] this->sidebarStudentList;
	delete[] this->sidebarRoomList;
	delete[] this->sidebarContractList;
	delete[] this->sidebarInvoiceList;

	delete this->studentToAdd;

	delete this->infoManageView;
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




void EmployeePage::drawStudentServiceContent(const int& width, const int& height)
{
	switch (this->sidebarStudentSelected)
	{
	case 0:
		ConsolaUI::text(30, 7, "THEM SINH VIEN MOI:", 14);
		ConsolaUI::text(35, 8, "1. Ten Sinh Vien: ", 15);

		//Tach Ngay Sinh thanh 3 truong
		ConsolaUI::text(35, 9, "2. Ngay Sinh (ngay): ", 15);
		ConsolaUI::text(35, 10, "3. Ngay Sinh (thang):", 15);
		ConsolaUI::text(35, 11, "4. Ngay Sinh (nam):  ", 15);

		ConsolaUI::text(35, 12, "5. Gioi Tinh: ", 15);
		ConsolaUI::text(35, 13, "6. Ma So Sinh Vien: ", 15);
		ConsolaUI::text(35, 14, "7. Lop: ", 15);
		ConsolaUI::text(35, 15, "8. Khoa: ", 15);
		ConsolaUI::text(35, 16, "9. So Dien Thoai: ", 15);
		ConsolaUI::text(35, 17, "0. Email: ", 15);

		//Show thong tin da nhap
		ConsolaUI::text(58, 8, this->studentToAdd->getFullName(), 7);
		if (this->tempDay > 0)
			ConsolaUI::text(58, 9, to_string(this->tempDay), 7);
		if (this->tempMonth > 0)
			ConsolaUI::text(58, 10, to_string(this->tempMonth), 7);
		if (this->tempYear > 0)
			ConsolaUI::text(58, 11, to_string(this->tempYear), 7);
		ConsolaUI::text(58, 12, this->studentToAdd->getGender(), 7);
		if (this->studentToAdd->getStudentID() != 0)
			ConsolaUI::text(58, 13, to_string(this->studentToAdd->getStudentID()), 7);
		ConsolaUI::text(58, 14, this->studentToAdd->getClassName(), 7);
		ConsolaUI::text(58, 15, this->studentToAdd->getFaculty(), 7);
		ConsolaUI::text(58, 16, this->studentToAdd->getPhoneNumber(), 7);
		ConsolaUI::text(58, 17, this->studentToAdd->getEmail(), 7);

		// Nut Them Sinh Vien
		ConsolaUI::text(80, 28, "Nhan ENTER De Them Sinh Vien", 15);
		ConsolaUI::text(85, 28, "ENTER", 2);

		// Thong Bao Them Sinh Vien Thanh Cong
		if (this->isAddStudentSucessfull)
		{
			ConsolaUI::text(45, 20, "THEM SINH VIEN THANH CONG!", 2);
		}
		else
		{
			ConsolaUI::text(45, 20, "HAY NHAP DUNG THONG TIN SINH VIEN!", 15);
		}
		break;
	case 1:
		ConsolaUI::text(30, 7, "TIM KIEM THEO MA SINH VIEN:", 14);
		ConsolaUI::text(35, 9, "F. Nhap Ma Sinh Vien: ", 15);
		ConsolaUI::drawBox(65, 8, 25, 2, 15);

		for (int i = 13; i <= 20; i++)
		{
			ConsolaUI::text(35, i, "                                                                  ", 15);
		}

		if (this->studentIDToSearch != 0)
		{
			this->studentToAct = this->studentService->SearchByID(this->studentIDToSearch);
			if (this->studentToAct != nullptr)
			{
				// Show Thong Tin Sinh Vien Da Duoc Tim Kiem
				if(!this->isShowBoxDeleteStudent &&
					!this->isShowBoxUpdateStudent)
				{
					ConsolaUI::text(35, 11, ">> SINH VIEN DA DUOC TIM THAY! (ID: " + to_string(this->studentIDToSearch) + ") <<", 10);
					ConsolaUI::text(35, 13, "Ten:                  " + this->studentToAct->getFullName(), 15);
					ConsolaUI::text(35, 14, "Ma So Sinh Vien:      " + to_string(this->studentToAct->getStudentID()), 15);
					ConsolaUI::text(35, 15, "Ngay Sinh:            ", 15);
					ConsolaUI::gotoXY(57, 15); cout << this->studentToAct->getDateOfBirth();
					ConsolaUI::text(35, 16, "Gioi Tinh:            " + this->studentToAct->getGender(), 15);
					ConsolaUI::text(35, 17, "Lop:                  " + this->studentToAct->getClassName(), 15);
					ConsolaUI::text(35, 18, "Khoa:                 " + this->studentToAct->getFaculty(), 15);
					ConsolaUI::text(35, 19, "SDT:                  " + this->studentToAct->getPhoneNumber(), 15);
					ConsolaUI::text(35, 20, "Email:                " + this->studentToAct->getEmail(), 15);
				}

				// Nut Thao Tac Xoa Va Cap Nhat
				ConsolaUI::text(35, 25, "[ X ] Xoa", 2);
				ConsolaUI::text(65, 25, "[ U ] Cap Nhat", 2);
				if (this->isShowBoxDeleteStudent)
				{
					ConsolaUI::drawBox(35, 12, width - 45, 10, 15);
					for (int i = 0; i < 9; i++)
					{
						ConsolaUI::text(36, 12 + i + 1, "                                                      ", 12);
					}
					ConsolaUI::text(45, 15, "Ban Co Muon Xoa Sinh Vien Nay Khong?", 15);
					ConsolaUI::text(45, 18, "[ Y ] : Co", 15);
					ConsolaUI::text(45, 19, "[ N ] : Khong", 15);
					ConsolaUI::text(45, 20, "[ Esc ] : Thoat", 15);
				}
				else if (this->isShowBoxUpdateStudent)
				{
					ConsolaUI::drawBox(35, 12, width - 45, 12, 15);
					for (int i = 0; i < 11; i++)
					{
						ConsolaUI::text(36, 12 + i + 1, "                                                      ", 12);
					}
					ConsolaUI::text(37, 13, "1. Ten Sinh Vien: ", 15);

					//Tach Ngay Sinh thanh 3 truong
					ConsolaUI::text(37, 14, "2. Ngay Sinh (ngay): ", 15);
					ConsolaUI::text(37, 15, "3. Ngay Sinh (thang):", 15);
					ConsolaUI::text(37, 16, "4. Ngay Sinh (nam):  ", 15);

					ConsolaUI::text(37, 17, "5. Gioi Tinh: ", 15);
					ConsolaUI::text(37, 18, "6. Ma So Sinh Vien: ", 15);
					ConsolaUI::text(37, 19, "7. Lop: ", 15);
					ConsolaUI::text(37, 20, "8. Khoa: ", 15);
					ConsolaUI::text(37, 21, "9. So Dien Thoai: ", 15);
					ConsolaUI::text(37, 22, "0. Email: ", 15);

					// Thong Tin Sinh Vien Hien Tai
					ConsolaUI::text(65, 13, this->studentToAct->getFullName(), 15);
					ConsolaUI::text(65, 14, to_string(this->studentToAct->getDateOfBirth().getDay()), 15);
					ConsolaUI::text(65, 15, to_string(this->studentToAct->getDateOfBirth().getMonth()), 15);
					ConsolaUI::text(65, 16, to_string(this->studentToAct->getDateOfBirth().getYear()), 15);
					ConsolaUI::text(65, 17, this->studentToAct->getGender(), 15);
					ConsolaUI::text(65, 18, to_string(this->studentToAct->getStudentID()), 15);
					ConsolaUI::text(65, 19, this->studentToAct->getClassName(), 15);
					ConsolaUI::text(65, 20, this->studentToAct->getFaculty(), 15);
					ConsolaUI::text(65, 21, this->studentToAct->getPhoneNumber(), 15);
					ConsolaUI::text(65, 22, this->studentToAct->getEmail(), 15);


					// Nut Xac Nhan Cap Nhat Thong Tin
					ConsolaUI::text(45, 23, "[ Y ] : Cap Nhat", 15);
					ConsolaUI::text(65, 23, "[ Esc ] : Thoat", 15);
				}
			}
			else
			{
				ConsolaUI::text(35, 11, ">> KHONG TIM THAY MA SINH VIEN: " + to_string(this->studentIDToSearch) + " <<", 12);
			}
		}
		else
		{
			ConsolaUI::text(35, 11, ">> NHAN PHIM '1' DE NHAP MA SINH VIEN <<", 15);
		}
		break;
	}
}

void EmployeePage::drawSidebarStudent(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
	ConsolaUI::text(5, 8, *(this->sidebarStudentList), (0 == this->sidebarStudentSelected) ? 11 : 8);
	ConsolaUI::text(5, 12, *(this->sidebarStudentList + 1), (1 == this->sidebarStudentSelected) ? 11 : 8);
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