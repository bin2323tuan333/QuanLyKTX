#include "StudentManageView.h"
#include "ConsolaUI.h"
#include <sstream>
#include <iostream>
#include <conio.h>

StudentManageView::StudentManageView(StudentService* service)
	: studentService(service)
{
	this->sidebarStudentSelected = 0;
	this->sidebarStudentSize = 2;
	this->sidebarStudentList = new string[this->sidebarStudentSize]
	{
		"Them Moi Sinh Vien",
		"Tim Kiem Theo Ma SV"
	};

	this->studentIDToSearch = 0;
	this->studentToAct = nullptr;
	this->studentToAdd = new Student();
	this->isAddStudentSucessfull = false;
	this->isShowBoxDeleteStudent = false;
	this->isDeleteComplete = false;
	this->isUpdateComplete = false;
	this->tempDay = 0;
	this->tempMonth = 0;
	this->tempYear = 0;
}

StudentManageView::~StudentManageView()
{
	delete[] this->sidebarStudentList;
	delete this->studentToAdd;
}

void StudentManageView::handleInput(int key)
{
	if (key == 72 || key == 80)
	{
		sidebarStudentSelected = (sidebarStudentSelected + (key == 72 ? -1 : 1) + sidebarStudentSize) % sidebarStudentSize;
	}

	if (sidebarStudentSelected == 1)
	{
		if (key == 'F' || key == 'f')
		{
			ConsolaUI::gotoXY(66, 9);
			this->studentIDToSearch = GetInt();
			this->isShowBoxDeleteStudent = false;
			this->isShowBoxUpdateStudent = false;
		}
		this->studentToAct = this->studentService->SearchByID(this->studentIDToSearch);
		if (this->studentToAct != nullptr) 
		{
			if (key == 'X' || key == 'x') 
			{
				this->isShowBoxDeleteStudent = true;
				this->isShowBoxUpdateStudent = false;
			}
			else if (key == 'U' || key == 'u') 
			{
				this->isShowBoxUpdateStudent = true;
				this->isShowBoxDeleteStudent = false;
				this->studentToUpdate = *this->studentToAct;
			}
			

			if (this->isShowBoxDeleteStudent) 
			{
				if (key == 'Y' || key == 'y' || key == 13) 
				{
					this->isDeleteComplete = this->studentService->Delete(*this->studentToAct);
					this->studentToAct = nullptr;
					this->isShowBoxDeleteStudent = false;
				}
				else if (key == 'N' || key == 'n' || key == 27) 
				{
					this->isShowBoxDeleteStudent = false;
				}
			}
			else if (this->isShowBoxUpdateStudent)
			{
				if (key == 'Y' || key == 'y' || key == 13)
				{
					Date tempDate(this->tempDay, this->tempMonth, this->tempYear);
					this->studentToUpdate.setDateOfBirth(tempDate);
					this->isDeleteComplete = this->studentService->Update(this->studentToUpdate);
					this->isShowBoxUpdateStudent = false;
				}
				else if (key == 'N' || key == 'n' || key == 27)
				{
					this->isShowBoxUpdateStudent = false;
				}
				else if (key == '1')
				{
					ConsolaUI::text(65, 13, "                                ", 1);
					ConsolaUI::gotoXY(65, 13);
					this->studentToUpdate.setFullName(GetLine());
				}
				else if (key == '2')
				{
					ConsolaUI::text(65, 14, "                                ", 1);
					ConsolaUI::gotoXY(65, 14);
					this->tempDay = GetInt();
				}
				else if (key == '3')
				{
					ConsolaUI::text(65, 15, "                                ", 1);
					ConsolaUI::gotoXY(65, 15);
					this->tempMonth = GetInt();
				}
				else if (key == '4')
				{
					ConsolaUI::text(65, 16, "                                ", 1);
					ConsolaUI::gotoXY(65, 16);
					this->tempYear = GetInt();
				}
				else if (key == '5')
				{
					ConsolaUI::text(65, 17, "                                ", 1);
					ConsolaUI::gotoXY(65, 17);
					this->studentToUpdate.setGender(GetLine());
				}
				else if (key == '6')
				{
					ConsolaUI::text(65, 18, "                                ", 1);
					ConsolaUI::gotoXY(65, 18);
					this->studentToUpdate.setStudentID(GetInt());
				}
				else if (key == '7')
				{
					ConsolaUI::text(65, 19, "                                ", 1);
					ConsolaUI::gotoXY(65, 19);
					this->studentToUpdate.setClassName(GetLine());
				}
				else if (key == '8')
				{
					ConsolaUI::text(65, 20, "                                ", 1);
					ConsolaUI::gotoXY(65, 20);
					this->studentToUpdate.setFaculty(GetLine());
				}
				else if (key == '9')
				{
					ConsolaUI::text(65, 21, "                                ", 1);
					ConsolaUI::gotoXY(65, 21);
					this->studentToUpdate.setPhoneNumber(GetLine());
				}
				else if (key == '0')
				{
					ConsolaUI::text(65, 22, "                                ", 1);
					ConsolaUI::gotoXY(65, 22);
					this->studentToUpdate.setEmail(GetLine());
				}
			}
		}
	}

	if (sidebarStudentSelected == 0) 
	{
		if (key == '1')
		{
			ConsolaUI::gotoXY(65, 8); this->studentToAdd->setFullName(GetLine());
		}
		else if (key == '2')
		{
			ConsolaUI::gotoXY(65, 9); this->tempDay = GetInt();
		}
		else if (key == '3')
		{
			ConsolaUI::gotoXY(65, 10); this->tempMonth = GetInt();
		}
		else if (key == '4')
		{
			ConsolaUI::gotoXY(65, 11); this->tempYear = GetInt();
		}
		else if (key == '5')
		{
			ConsolaUI::gotoXY(65, 12); this->studentToAdd->setGender(GetLine());
		}
		else if (key == '6')
		{
			ConsolaUI::gotoXY(65, 13); string id = GetLine(); this->studentToAdd->setStudentID(stoi(id));
		}
		else if (key == '7')
		{
			ConsolaUI::gotoXY(65, 14); this->studentToAdd->setClassName(GetLine());
		}
		else if (key == '8')
		{
			ConsolaUI::gotoXY(65, 15); this->studentToAdd->setFaculty(GetLine());
		}
		else if (key == '9')
		{
			ConsolaUI::gotoXY(65, 16); this->studentToAdd->setPhoneNumber(GetLine());
		}
		else if (key == '0')
		{
			ConsolaUI::gotoXY(65, 17); this->studentToAdd->setEmail(GetLine());
		}
		else if (key == 13)
		{
			Date dob(this->tempDay, this->tempMonth, this->tempYear);
			this->studentToAdd->setDateOfBirth(dob);
			this->isAddStudentSucessfull = this->studentService->Add(*this->studentToAdd);
			delete this->studentToAdd;
			this->studentToAdd = new Student();
			this->tempDay = 0; this->tempMonth = 0; this->tempYear = 0;
		}
	}
}

void StudentManageView::show()
{
	int width = ConsolaUI::getConsoleWidth();
	int height = ConsolaUI::getConsoleHeight();
	drawSidebarStudent(width, height);
	drawStudentServiceContent(width, height);
}

void StudentManageView::drawSidebarStudent(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
	ConsolaUI::text(5, 8, *(this->sidebarStudentList), (0 == this->sidebarStudentSelected) ? 11 : 8);
	ConsolaUI::text(5, 12, *(this->sidebarStudentList + 1), (1 == this->sidebarStudentSelected) ? 11 : 8);
}

void StudentManageView::drawStudentServiceContent(const int& width, const int& height)
{
	switch (this->sidebarStudentSelected)
	{
	case 0:
		ConsolaUI::text(30, 7, "THEM SINH VIEN MOI:", 14);
		ConsolaUI::text(35, 8, "1. Ten Sinh Vien: ", 15);
		ConsolaUI::text(35, 9, "2. Ngay Sinh (ngay): ", 15);
		ConsolaUI::text(35, 10, "3. Ngay Sinh (thang):", 15);
		ConsolaUI::text(35, 11, "4. Ngay Sinh (nam):  ", 15);
		ConsolaUI::text(35, 12, "5. Gioi Tinh: ", 15);
		ConsolaUI::text(35, 13, "6. Ma So Sinh Vien: ", 15);
		ConsolaUI::text(35, 14, "7. Lop: ", 15);
		ConsolaUI::text(35, 15, "8. Khoa: ", 15);
		ConsolaUI::text(35, 16, "9. So Dien Thoai: ", 15);
		ConsolaUI::text(35, 17, "0. Email: ", 15);

		ConsolaUI::text(65, 8, (this->studentToAdd->getFullName() == "") ? "" : this->studentToAdd->getFullName(), 15);
		ConsolaUI::text(65, 9, (this->tempDay == 0) ? "" : to_string(this->tempDay), 15);
		ConsolaUI::text(65, 10, (this->tempMonth == 0) ? "" : to_string(this->tempMonth), 15);
		ConsolaUI::text(65, 11, (this->tempYear == 0) ? "" : to_string(this->tempYear), 15);
		ConsolaUI::text(65, 12, (this->studentToAdd->getGender() == "") ? "" : this->studentToAdd->getGender(), 15);
		ConsolaUI::text(65, 13, (this->studentToAdd->getStudentID() == 0) ? "" : to_string(this->studentToAdd->getStudentID()), 15);
		ConsolaUI::text(65, 14, (this->studentToAdd->getClassName() == "") ? "" : this->studentToAdd->getClassName(), 15);
		ConsolaUI::text(65, 15, (this->studentToAdd->getFaculty() == "") ? "" : this->studentToAdd->getFaculty(), 15);
		ConsolaUI::text(65, 16, (this->studentToAdd->getPhoneNumber() == "") ? "" : this->studentToAdd->getPhoneNumber(), 15);
		ConsolaUI::text(65, 17, (this->studentToAdd->getEmail() == "") ? "" : this->studentToAdd->getEmail(), 15);


		ConsolaUI::text(80, 25, "Nhan [ ENTER ] De Them Sinh Vien", 15);
		ConsolaUI::text(87, 25, "ENTER", 2);
		if (this->isAddStudentSucessfull)
		{
			ConsolaUI::text(45, 20, "THEM SINH VIEN THANH CONG!", 2);
		}
		else
		{
			ConsolaUI::text(45, 20, "HAY NHAP DUNG THONG TIN SINH VIEN", 15);
		}
		break;

	case 1:
		ConsolaUI::text(30, 7, "TIM KIEM THEO MA SINH VIEN:", 14);
		ConsolaUI::text(35, 9, "F. Nhap Ma Sinh Vien: ", 15);
		ConsolaUI::drawBox(65, 8, 25, 2, 15);

		if (this->studentIDToSearch != 0)
		{
			
			if (this->studentToAct != nullptr)
			{
				if (!this->isShowBoxDeleteStudent && !this->isShowBoxUpdateStudent)
				{
					// Show Thong Tin Sinh Vien Da Duoc Tim Kiem
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

					// Nut Thao Tac Xoa Va Cap Nhat
					ConsolaUI::text(35, 25, "[ X ] Xoa", 2);
					ConsolaUI::text(65, 25, "[ U ] Cap Nhat", 2);
				}

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
					ConsolaUI::text(65, 13, this->studentToUpdate.getFullName(), 15);
					ConsolaUI::text(65, 14, to_string(this->studentToUpdate.getDateOfBirth().getDay()), 15);
					ConsolaUI::text(65, 15, to_string(this->studentToUpdate.getDateOfBirth().getMonth()), 15);
					ConsolaUI::text(65, 16, to_string(this->studentToUpdate.getDateOfBirth().getYear()), 15);
					ConsolaUI::text(65, 17, this->studentToUpdate.getGender(), 15);
					ConsolaUI::text(65, 18, to_string(this->studentToUpdate.getStudentID()), 15);
					ConsolaUI::text(65, 19, this->studentToUpdate.getClassName(), 15);
					ConsolaUI::text(65, 20, this->studentToUpdate.getFaculty(), 15);
					ConsolaUI::text(65, 21, this->studentToUpdate.getPhoneNumber(), 15);
					ConsolaUI::text(65, 22, this->studentToUpdate.getEmail(), 15);


					// Nut Xac Nhan Cap Nhat Thong Tin
					ConsolaUI::text(45, 23, "[ Y ] : Cap Nhat", 15);
					ConsolaUI::text(65, 23, "[ Esc ] : Thoat", 15);
				}
				if (this->isDeleteComplete)
				{
					ConsolaUI::text(35, 11, ">> XOA SINH VIEN THANH CONG! <<", 10);
				}
			}
			else
			{
				ConsolaUI::text(35, 11, ">> KHONG TIM THAY MA SINH VIEN: " + to_string(this->studentIDToSearch) + " <<", 12);
			}
		}
		break;
	}
}


string StudentManageView::GetLine()
{
	string ss;
	ConsolaUI::ShowCursor(true);
	while (true) {
		int key = _getch();
		if (key == '\r' || key == '\n') break;
		if (key == '\b') {
			if (ss.length() > 0) {
				ss.pop_back();
				cout << "\b \b";
			}
		}
		else {
			ss += char(key);
			cout << char(key);
		}
	}
	ConsolaUI::ShowCursor(false);
	return ss;
}

int StudentManageView::GetInt() {
	string inputString = GetLine();
	stringstream ss(inputString);
	int result = 0;
	ss >> result;
	return result;
}