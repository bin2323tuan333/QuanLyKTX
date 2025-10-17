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

    if (sidebarStudentSelected == 1) {
        if (key == 'F' || key == 'f') {
            ConsolaUI::gotoXY(66, 9);
            this->studentIDToSearch = GetInt();
            this->isShowBoxDeleteStudent = false;
            this->isShowBoxUpdateStudent = false;
        }
        if (this->studentToAct != nullptr) {
            if (key == 'X' || key == 'x') this->isShowBoxDeleteStudent = true;
            else if (key == 'U' || key == 'u') this->isShowBoxUpdateStudent = true;

            if (this->isShowBoxDeleteStudent) {
                if (key == 'Y' || key == 'y') {
                    this->isDeleteComplete = this->studentService->Delete(*this->studentToAct);
                    this->studentToAct = nullptr;
                    this->isShowBoxDeleteStudent = false;
                }
                else if (key == 'N' || key == 'n' || key == 27) {
                    this->isShowBoxDeleteStudent = false;
                }
            }
        }
    }

    if (sidebarStudentSelected == 0) {
        if (key == '1') 
        {
            ConsolaUI::gotoXY(58, 8); this->studentToAdd->setFullName(GetLine()); 
        }
        else if (key == '2') 
        { 
            ConsolaUI::gotoXY(58, 9); this->tempDay = GetInt(); 
        }
        else if (key == '3') 
        { 
            ConsolaUI::gotoXY(58, 10); this->tempMonth = GetInt(); 
        }
        else if (key == '4') 
        { 
            ConsolaUI::gotoXY(58, 11); this->tempYear = GetInt(); 
        }
        else if (key == '5') 
        { 
            ConsolaUI::gotoXY(58, 12); this->studentToAdd->setGender(GetLine()); 
        }
        else if (key == '6') 
        { 
            ConsolaUI::gotoXY(58, 13); string id = GetLine(); this->studentToAdd->setStudentID(stoi(id)); 
        }
        else if (key == '7') 
        { 
            ConsolaUI::gotoXY(58, 14); this->studentToAdd->setClassName(GetLine()); 
        }
        else if (key == '8') 
        { 
            ConsolaUI::gotoXY(58, 15); this->studentToAdd->setFaculty(GetLine()); 
        }
        else if (key == '9') 
        { 
            ConsolaUI::gotoXY(58, 16); this->studentToAdd->setPhoneNumber(GetLine()); 
        }
        else if (key == '0') 
        { 
            ConsolaUI::gotoXY(58, 17); this->studentToAdd->setEmail(GetLine()); 
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

        ConsolaUI::text(80, 25, "Nhan [ ENTER ] De Them Sinh Vien", 15);
        ConsolaUI::text(87, 25, "ENTER", 2);
        if (this->isAddStudentSucessfull) {
            ConsolaUI::text(45, 20, "THEM SINH VIEN THANH CONG!", 2);
        }
        else {
            ConsolaUI::text(45, 20, "HAY NHAP DUNG THONG TIN SINH VIEN", 15);
        }
        break;

    case 1:
        ConsolaUI::text(30, 7, "TIM KIEM THEO MA SINH VIEN:", 14);
        ConsolaUI::text(35, 9, "F. Nhap Ma Sinh Vien: ", 15);
        ConsolaUI::drawBox(65, 8, 25, 2, 15);

        if (this->studentIDToSearch != 0) {
            this->studentToAct = this->studentService->SearchByID(this->studentIDToSearch);
            if (this->studentToAct != nullptr) {
                if (!this->isShowBoxDeleteStudent && !this->isShowBoxUpdateStudent) {
                    ConsolaUI::text(35, 11, ">> SINH VIEN DA DUOC TIM THAY! <<", 10);
                    ConsolaUI::text(35, 13, "Ten:             " + this->studentToAct->getFullName(), 15);
                    ConsolaUI::text(35, 14, "Ma SV:           " + to_string(this->studentToAct->getStudentID()), 15);
                    ConsolaUI::text(35, 15, "Ngay Sinh:       ", 15);
                    ConsolaUI::gotoXY(57, 15); cout << this->studentToAct->getDateOfBirth();
                    ConsolaUI::text(35, 25, "[X] Xoa", 2);
                    ConsolaUI::text(65, 25, "[U] Cap Nhat", 2);
                }

                if (this->isShowBoxDeleteStudent) {
                    ConsolaUI::drawBox(40, 14, 40, 8, 12);
                    ConsolaUI::text(45, 16, "Ban Co Muon Xoa Sinh Vien Nay?", 15);
                    ConsolaUI::text(45, 18, "[Y]: Co  [N]: Khong", 15);
                }
                if (this->isDeleteComplete) {
                    ConsolaUI::text(35, 11, ">> XOA SINH VIEN THANH CONG! <<", 10);
                }
            }
            else {
                ConsolaUI::text(35, 11, ">> KHONG TIM THAY MA SINH VIEN: " + to_string(this->studentIDToSearch) + " <<", 12);
            }
        }
        break;
    }
}


string StudentManageView::GetLine() {
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