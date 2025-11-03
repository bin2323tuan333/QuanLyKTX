#include "ContractManageView.h"
#include "ConsolaUI.h"
#include <sstream>

ContractManageView::ContractManageView(ContractService* contractService, StudentService* studentService, RoomService* roomService)
	:contractService(contractService), studentService(studentService), roomService(roomService)
{
	this->sidebarContractSelected = 0;
	this->sidebarContractSize = 3;
	this->sidebarContractList = new string[this->sidebarContractSize]
	{
		"Tim Kiem Hop Dong",
		"Tao Hop Dong Moi",
		"Tim Theo Ma Hop Dong"
	};

	this->studentIDToSearch = 0;
	this->contractIDToSearch = 0;
	this->chooseToAdd = 0;
	this->maxPage = 0;

	this->tempStudent = Student();
	tempStudent.setDateOfBirth(Date::getCurrentDay());
	this->currentIndex = 1;
	this->dateIndex = 1;
	this->isDateEdit = false;
}

ContractManageView::~ContractManageView()
{
	delete[] this->sidebarContractList;
}

void ContractManageView::handleInput(int key)
{
	if (key == 72 || key == 80)
	{
		this->sidebarContractSelected = (this->sidebarContractSelected + (key == 72 ? -1 : 1) + this->sidebarContractSize) % this->sidebarContractSize;
	}
	if (this->sidebarContractSelected == 0)
	{
		if (key == 'F' || key == 'f')
		{
			ConsolaUI::gotoXY(66, 9);
			this->studentIDToSearch = GetInt();
		}
	}
	else if (this->sidebarContractSelected == 1)
	{
		if (key == '1' || key == '2' || key == '3')
			this->chooseToAdd = key - '0';
		if (key == 27) this->chooseToAdd = 0;
		if (this->chooseToAdd == 1)
		{
			if (this->isDateEdit == true)
			{
				Date tempDate = this->tempStudent.getDateOfBirth();
				if (key == 'a' || key == 'A')
				{
					if (this->dateIndex == 1) this->dateIndex = 3;
					else this->dateIndex--;
				}
				else if (key == 'd' || key == 'D')
				{
					if (this->dateIndex == 3) this->dateIndex = 1;
					else this->dateIndex++;
				}
				else if (key == 'w' || key == 'W')
				{
					if (this->dateIndex == 1)
					{
						int temp = tempDate.getDay();
						if (temp == Date::getMaxDayOfMonth(tempDate.getMonth())) temp = 1;
						else temp++;
						tempDate.setDay(temp);
					}
					else if (this->dateIndex == 2)
					{
						int temp = tempDate.getMonth();
						if (temp == 12) temp = 1;
						else ++temp;
						tempDate.setMonth(temp);
					}
					else if (this->dateIndex == 3)
					{
						int temp = tempDate.getYear();
						++temp;
						tempDate.setYear(temp);
					}
				}
				else if (key == 's' || key == 'S')
				{
					if (this->dateIndex == 1)
					{
						int temp = tempDate.getDay();
						if (temp == 1) temp = Date::getMaxDayOfMonth(tempDate.getMonth());
						else temp--;
						tempDate.setDay(temp);
					}
					else if (this->dateIndex == 2)
					{
						int temp = tempDate.getMonth();
						if (temp == 1) temp = 12;
						else --temp;
						tempDate.setMonth(temp);
					}
					else if (this->dateIndex == 3)
					{
						int temp = tempDate.getYear();
						--temp;
						tempDate.setYear(temp);
					}
				}
				else if (key == 13 || key == 27)
				{
					this->isDateEdit = false;
				}
				if (!tempDate.isValid())
				{
					tempDate.setDay(1);
				}
				this->tempStudent.setDateOfBirth(tempDate);
			}
			else if (key == 'w' || key == 'W')
			{
				if (this->currentIndex == 1) this->currentIndex = 8;
				else this->currentIndex--;
			}
			else if (key == 's' || key == 'S')
			{
				if (this->currentIndex == 8) this->currentIndex = 1;
				else this->currentIndex++;
			}
			else if (key == 'Y' || key == 'y')
			{
				this->chooseToAdd = 0;
			}
			else if (key == 'N' || key == 'n')
			{
				this->chooseToAdd = 0;
				this->tempStudent = Student();
			}
			else if (key == 13)
			{
				switch (this->currentIndex)
				{
				case 1:
				{
					ConsolaUI::gotoXY(55, 12);
					this->tempStudent.setFullName(GetLine());
					break;
				}
				case 2:
				{
					this->isDateEdit = true;
					break;
				}
				case 3:
				{
					bool currentGender = this->tempStudent.getGender();
					this->tempStudent.setGender((currentGender == true) ? false : true);
					break;
				}
				case 4:
				{
					ConsolaUI::gotoXY(55, 15);
					this->tempStudent.setStudentID(GetInt());
					break;
				}
				case 5:
				{
					ConsolaUI::gotoXY(55, 16);
					this->tempStudent.setClassName(GetLine());
					break;
				}
				case 6:
				{
					ConsolaUI::gotoXY(55, 17);
					this->tempStudent.setFaculty(GetLine());
					break;
				}
				case 7:
				{
					ConsolaUI::gotoXY(55, 18);
					this->tempStudent.setPhoneNumber(GetLine());
					break;
				}
				case 8:
				{
					ConsolaUI::gotoXY(55, 19);
					this->tempStudent.setEmail(GetLine());
					break;
				}
				}
			}
		}
		else if (this->chooseToAdd == 2)
		{

		}
		else if (this->chooseToAdd == 3)
		{

		}
	}
	else if (this->sidebarContractSelected == 2)
	{
		if (key == 'F' || key == 'f')
		{
			ConsolaUI::gotoXY(66, 9);
			this->contractIDToSearch = GetInt();
		}
	}
}

void ContractManageView::show()
{
	int width = ConsolaUI::getConsoleWidth();
	int height = ConsolaUI::getConsoleHeight();
	drawSidebarContract(width, height);
	drawContractServiceContent(width, height);
}

void ContractManageView::drawContractServiceContent(const int& width, const int& height)
{
	switch (this->sidebarContractSelected)
	{
	case 0:
	{
		/*ConsolaUI::text(30, 7, "TIM KIEM HOP DONG:", 14);
		ConsolaUI::text(35, 9, "[F] Nhap Ma So Sinh Vien: ", 15);
		ConsolaUI::drawBox(65, 8, 25, 2, 15);
		if (this->studentIDToSearch != 0)
		{
			LinkedList<Contract> contracts = this->contractService->GetContractsByStudentId(this->studentIDToSearch);
			if (contracts.getSize() > 0)
			{
				int itemsPerPage = height - 13;
				int totalPages = (contracts.getSize() + itemsPerPage - 1) / itemsPerPage;
				this->maxPage = totalPages - 1;

				ConsolaUI::text(30, 12, "TIM THAY " + to_string(contracts.getSize()) + " HOP DONG:", 10);
				ConsolaUI::text(32, 14, "Ma HD", 7);
				ConsolaUI::text(40, 14, "Ngay Bat Dau", 7);
				ConsolaUI::text(55, 14, "Ngay Ket Thuc", 7);
				ConsolaUI::text(70, 14, "Trang Thai", 7);
				ConsolaUI::text(85, 14, "Ma Phong", 7);

				ConsolaUI::text(32, 14 + 1, "-------------------------------------------------------------", 8);
				for (int i = 0; i < itemsPerPage; i++)
				{
					int yPos = 9 + i;
					if (i + this->contractListIndex * itemsPerPage < contracts.getSize())
					{
						Contract* contract = contracts.getAt(i + this->contractListIndex * itemsPerPage);
						ConsolaUI::text(32, 16 + i, to_string(contract->getContractId()), 15);
						ConsolaUI::gotoXY(40, 16 + i); ConsolaUI::setTextColor(15); cout << contract->getStartDate();
						ConsolaUI::gotoXY(55, 16 + i); ConsolaUI::setTextColor(15); cout << contract->getEndDate();
						if (contract->isActive())
							ConsolaUI::text(70, 16 + i, "Con hieu luc", 10);
						else
							ConsolaUI::text(70, 16 + i, "Da het han", 12);
						ConsolaUI::text(85, 16 + i, to_string(contract->getRoomId()), 15);
					}
					else break;
				}
				ConsolaUI::text(60, height - 3, "Trang " + to_string(this->contractListIndex + 1) + "/" + to_string(totalPages), 7);
				ConsolaUI::text(35, height - 1, "[ Q ] Trang Truoc", 3);
				ConsolaUI::text(75, height - 1, "[ P ] Trang Sau", 3);
			}
			else
				ConsolaUI::text(35, 12, "KHONG TIM THAY hop dong nao voi Ma SV nay!", 12);
			
		}
		break;*/
	}
	case 1:
	{
		//ConsolaUI::text(30, 7, "TAO HOP DONG MOI (THEM SINH VIEN)", 14);

		//switch (chooseToAdd)
		//{
		//case 0:
		//{
		//	ConsolaUI::drawBox(33, 11, 60, 8, 8);
		//	ConsolaUI::text(35, 13, "[1] Nhap Thong Tin Sinh Vien.", 11);
		//	ConsolaUI::text(35, 15, "[2] Nhap Thong Tin Phong.", 11);
		//	ConsolaUI::text(35, 17, "[3] Nhap Thong Tin Hop Dong.", 11);
		//	break;
		//}
		//case 1:
		//{
		//	ConsolaUI::drawBox(33, 11, 60, 9, 8);
		//	ConsolaUI::text(32, 10, "Thong tin Sinh vien:", 11);
		//	ConsolaUI::text(35, 12, "Ho va ten       :", this->currentIndex == 1 ? 3 : 15);
		//	ConsolaUI::text(35, 13, "Ngay sinh       :", this->currentIndex == 2 ? 3 : 15);
		//	ConsolaUI::text(35, 14, "Gioi tinh       :", this->currentIndex == 3 ? 3 : 15);
		//	ConsolaUI::text(35, 15, "Ma so sinh vien :", this->currentIndex == 4 ? 3 : 15);
		//	ConsolaUI::text(35, 16, "Lop             :", this->currentIndex == 5 ? 3 : 15);
		//	ConsolaUI::text(35, 17, "Khoa            :", this->currentIndex == 6 ? 3 : 15);
		//	ConsolaUI::text(35, 18, "So dien thoai   :", this->currentIndex == 7 ? 3 : 15);
		//	ConsolaUI::text(35, 19, "Email           :", this->currentIndex == 8 ? 3 : 15);

		//	
		//	ConsolaUI::text(55, 12, this->tempStudent.getFullName() == "" ? "__________" : this->tempStudent.getFullName(), 15);
		//	ConsolaUI::text(55, 13, (this->tempStudent.getDateOfBirth().getDay() < 10 ? "0" : "") + to_string(this->tempStudent.getDateOfBirth().getDay()) + "/", this->isDateEdit == true ? (this->dateIndex == 1 ? 10 : 15) : 15);
		//	ConsolaUI::text(58, 13, (this->tempStudent.getDateOfBirth().getMonth() < 10 ? "0" : "") + to_string(this->tempStudent.getDateOfBirth().getMonth()) + "/", this->isDateEdit == true ? (this->dateIndex == 2 ? 10 : 15) : 15);
		//	ConsolaUI::text(61, 13, to_string(this->tempStudent.getDateOfBirth().getYear()), this->isDateEdit == true ? (this->dateIndex == 3 ? 10 : 15) : 15);
		//	ConsolaUI::text(55, 14, this->tempStudent.getGender() == true ? "Nam" : "Nu", 15);
		//	ConsolaUI::text(55, 15, this->tempStudent.getStudentID() == 0 ? "__________" : to_string(this->tempStudent.getStudentID()), 15);
		//	ConsolaUI::text(55, 16, this->tempStudent.getClassName() == "" ? "__________" : this->tempStudent.getClassName(), 15);
		//	ConsolaUI::text(55, 17, this->tempStudent.getFaculty() == "" ? "__________" : this->tempStudent.getFaculty(), 15);
		//	ConsolaUI::text(55, 18, this->tempStudent.getPhoneNumber() == "" ? "__________" : this->tempStudent.getPhoneNumber(), 15);
		//	ConsolaUI::text(55, 19, this->tempStudent.getEmail() == "" ? "__________" : this->tempStudent.getEmail(), 15);

		//	ConsolaUI::text(35, 21, "[W - S] Di Chuyen Giua Cac O", 10);
		//	ConsolaUI::text(75, 21, "[Y] Xac nhan", 10);
		//	ConsolaUI::text(75, 22, "[N] Huy", 12);
		//	break;
		//}
		//case 2:
		//{
		//	ConsolaUI::text(32, 10, "Thong tin Phong:", 11);
		//	ConsolaUI::text(35, 12, "Chon Toa nha :", 15);
		//	ConsolaUI::text(35, 14, "Chon phong   :", 15);
		//	ConsolaUI::text(35, 25, "Gia phong    :", 7);

		//	ConsolaUI::drawBox(50, 21, 30, 5, 7);
		//	ConsolaUI::text(52, 22, "<   Toa A     >", 7);
		//	ConsolaUI::text(52, 24, "< P101 (2/4)  >", 7);
		//	ConsolaUI::text(52, 25, "1.500.000 VND", 10);
		//	break;
		//}
		//case 3:
		//{
		//	ConsolaUI::text(32, 27, "Thong tin Hop dong:", 11);
		//	ConsolaUI::text(35, 29, "Ngay vao     :", 15);
		//	ConsolaUI::text(35, 30, "Ngay ket thuc:", 15);
		//	ConsolaUI::text(35, 31, "Tien dat coc :", 15);

		//	ConsolaUI::drawBox(50, 28, 30, 4, 7);
		//	ConsolaUI::text(52, 29, "[ 27/10/2025 ]", 7);
		//	ConsolaUI::text(52, 30, "[ 27/10/2026 ]", 7);
		//	ConsolaUI::text(52, 31, "[ 1.500.000  ] VND", 7);
		//	break;
		//}
		//}
		///*ConsolaUI::text(30, 34, "[ Mui ten ] Di chuyen. [ Enter ] Chon.", 8);
		//ConsolaUI::text(30, 35, "[ F10 ] Luu Hop dong.", 10);
		//ConsolaUI::text(30, 36, "[ ESC ] Huy bo.", 12);*/
		//break;
	}
	case 2:
		/*ConsolaUI::text(30, 7, "TIM THEO MA HOP DONG:", 14);
		ConsolaUI::text(35, 9, "[F] Nhap Ma So Hop Dong: ", 15);
		ConsolaUI::drawBox(65, 8, 25, 2, 15);
		if (this->contractIDToSearch != 0)
		{
			Contract* contract = this->contractService->SearchByID(this->contractIDToSearch);
			if (contract != nullptr)
			{
				Student* student = this->studentService->SearchByID(contract->getStudentId());
				Room* room = this->roomService->SearchByID(contract->getRoomId());
				if (student == nullptr || room == nullptr)
				{
					ConsolaUI::text(35, 12, "LOI: Data khong dong bo (Thieu SV/Phong)", 12);
					break;
				}
				ConsolaUI::text(30, 11, "KET QUA TIM KIEM:", 10);
				ConsolaUI::drawBox(32, 12, 55, 14, 8);

				ConsolaUI::text(34, 13, "Thong tin Sinh vien:", 11);
				ConsolaUI::text(35, 14, "Ho Ten:", 7);
				ConsolaUI::text(52, 14, student->getFullName(), 15);
				ConsolaUI::text(35, 15, "Ma SV:", 7);
				ConsolaUI::text(52, 15, to_string(student->getStudentID()), 15);

				ConsolaUI::text(34, 17, "Thong tin Phong o:", 11);
				ConsolaUI::text(35, 18, "Ten Phong:", 7);
				ConsolaUI::text(52, 18, room->getRoomName(), 15);
				ConsolaUI::text(35, 19, "Toa nha:", 7);
				ConsolaUI::text(52, 19, room->getBuilding(), 15);

				ConsolaUI::text(34, 21, "Thong tin Hop dong:", 11);
				ConsolaUI::text(35, 22, "Trang thai:", 7);
				ConsolaUI::text(52, 22, contract->isActive() ? "Con hieu luc" : "Da het han", contract->isActive() ? 10 : 12);
				ConsolaUI::text(35, 23, "Ngay vao:", 7);
				ConsolaUI::gotoXY(52, 23); ConsolaUI::setTextColor(15); cout << contract->getStartDate();
				ConsolaUI::text(35, 24, "Ngay ra:", 7);
				ConsolaUI::gotoXY(52, 24); ConsolaUI::setTextColor(15); cout << contract->getEndDate();
			}
		}*/
		break;
	}
}
void ContractManageView::drawSidebarContract(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
	ConsolaUI::text(5, 8, *(this->sidebarContractList), (0 == this->sidebarContractSelected) ? 11 : 8);
	ConsolaUI::text(5, 10, *(this->sidebarContractList + 1), (1 == this->sidebarContractSelected) ? 11 : 8);
	ConsolaUI::text(5, 12, *(this->sidebarContractList + 2), (2 == this->sidebarContractSelected) ? 11 : 8);
}

string ContractManageView::GetLine()
{
	string ss;
	ConsolaUI::ShowCursor(true);
	while (true)
	{
		int key = _getch();
		if (key == '\r' || key == '\n') break;
		if (key == '\b')
		{
			if (ss.length() > 0)
			{
				ss.pop_back();
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

int ContractManageView::GetInt()
{
	string inputString = GetLine();
	stringstream ss(inputString);
	int result = 0;
	ss >> result;
	return result;
}