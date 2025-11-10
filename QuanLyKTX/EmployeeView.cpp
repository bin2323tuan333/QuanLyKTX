#include "EmployeeView.h"

EmployeeView::EmployeeView(Account*& user, AuthService* auth, UserService* userService, RoomService* roomService, BillingService* billing, ContractService* con)
	:user(user), authService(auth), userService(userService), roomService(roomService), billingService(billing), contractService(con)
{
	this->menuChoice = 0;
	this->choiceToAct = 0;
	this->isShow = false;
	this->isLogout = false;
	this->oldPass = "";
	this->newPass = "";
	this->reNewPass = "";
	this->changePassError = 0;
	this->studentId = 0;
	this->currentIndex = 1;
	this->studentToAct = Student();
	this->isDateEdit = false;
	this->dateIndex = 1;

	this->roomId = 0;
	this->invoiceId = 0;
	this->contractId = 0;
	this->preStudentId = 0;
}

EmployeeView::~EmployeeView()
{
}

int EmployeeView::show()
{
	if (this->menuChoice > 4) this->menuChoice = 0;
	else if (this->menuChoice < 0) this->menuChoice = 4;
	showHeader(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
	switch (menuChoice)
	{
	case 0:
	{
		if (this->choiceToAct > 2) this->choiceToAct = 0;
		else if (this->choiceToAct < 0) this->choiceToAct = 2;
		if (this->isShow == false)
			showInfoMenu(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
		else
		{
			switch (this->choiceToAct)
			{
			case 0:
			{
				showInfo(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 1:
			{
				showChangePass(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			}
		}
	}
	break;
	case 1:
	{
		if (this->choiceToAct > 3) this->choiceToAct = 0;
		else if (this->choiceToAct < 0) this->choiceToAct = 3;
		if (this->currentIndex < 1) this->currentIndex = 8;
		else if (this->currentIndex > 8) this->currentIndex = 1;
		if (this->isShow == false)
			showStudentMenu(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
		else
		{
			switch (this->choiceToAct)
			{
			case 0:
			{
				showAllStudents(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 1:
			{
				showFindStudent(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 2:
			{
				showAddStudent(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 3:
			{
				showStudentsNotRegister(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			}
		}
	}
	break;
	case 2:
	{
		if (this->choiceToAct > 3) this->choiceToAct = 0;
		else if (this->choiceToAct < 0) this->choiceToAct = 3;
		if (this->isShow == false)
			showRoomMenu(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
		else
		{
			switch (this->choiceToAct)
			{
			case 0:
			{
				showAllRooms(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 1:
			{
				showFindRoomById(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 2:
			{
				showFindVacantRooms(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 3:
			{
				showFindAvailableRooms(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			}
		}
	}
	break;
	case 3:
	{
		if (this->choiceToAct > 5) this->choiceToAct = 0;
		else if (this->choiceToAct < 0) this->choiceToAct = 5;
		if (this->isShow == false)
			showInvoiceMenu(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
		else
		{
			switch (this->choiceToAct)
			{
			case 0:
			{
				showAllInvoices(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 1:
			{
				showCreateNewInvoice(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 2:
			{
				showFindInvoicesByStudentId(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 3:
			{
				showFindInvoiceById(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 4:
			{
				showUnpaidInvoices(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 5:
			{
				showPaidInvoices(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			}
		}

	}
	break;
	case 4:
	{
		if (this->choiceToAct > 5) this->choiceToAct = 0;
		else if (this->choiceToAct < 0) this->choiceToAct = 5;
		if (this->isShow == false)
			showContractMenu(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
		else
		{
			switch (this->choiceToAct)
			{
			case 0:
			{
				showAllContracts(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 1:
			{
				showCreateContract(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 2:
			{
				showFindContractsByStudentId(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 3:
			{
				showFindContractById(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 4:
			{
				showInvalidContracts(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			case 5:
			{
				showValidContracts(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
			}
			break;
			}
		}
	}
	break;
	}
	handleInput();
	if (this->isLogout) return 2;
	return 1;
}
void EmployeeView::handleInput()
{
	ConsolaUI::setTextColor(15);
	int key = _getch();
	if (key == 224 || key == 0)						// Phim Mui Ten
	{
		int tempKey = _getch();
		if (this->isDateEdit == false)
		{
			if (tempKey == 75)							// Nut Sang Trai
			{
				this->menuChoice--;
				this->isShow = false;
				this->choiceToAct = 0;
			}
			else if (tempKey == 77)						// Nut Sang Phai
			{
				this->menuChoice++;
				this->isShow = false;
				this->choiceToAct = 0;
			}
			else if (tempKey == 72)						// Nut Len Tren
			{
				if (this->isShow == false)				// Danh Cho Menu
					this->choiceToAct--;
				else
					this->currentIndex--;
			}
			else if (tempKey == 80)						// Nut Xuong Duoi
			{
				if (this->isShow == false)				// Danh Cho Menu
					this->choiceToAct++;
				else
					this->currentIndex++;
			}
		}
		else if (this->isDateEdit == true)
		{
			Date tempDate = this->studentToAct.getDateOfBirth();
			if (tempKey == 75)
			{
				if (this->dateIndex == 1) this->dateIndex = 3;
				else this->dateIndex--;
			}
			else if (tempKey == 77)
			{
				if (this->dateIndex == 3) this->dateIndex = 1;
				else this->dateIndex++;
			}
			else if (tempKey == 72)
			{
				if (this->dateIndex == 1)
				{
					int temp = tempDate.getDay();
					if (temp == Date::getMaxDayOfMonth(tempDate.getMonth(), tempDate.getYear())) temp = 1;
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
			else if (tempKey == 80)
			{
				if (this->dateIndex == 1)
				{
					int temp = tempDate.getDay();
					if (temp == 1) temp = Date::getMaxDayOfMonth(tempDate.getMonth(), tempDate.getYear());
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
			this->studentToAct.setDateOfBirth(tempDate);
		}
	}
	else if (key == 'p' || key == 'P')
	{
		this->pageIndex++;
	}
	else if (key == 'q' || key == 'Q')
	{
		this->pageIndex--;
	}
	else if (key == 13 && this->isShow == false)
	{
		this->isShow = true;
		if (this->choiceToAct == 2 && this->menuChoice == 0)
		{
			DB::Instance()->saveData();
			this->user = nullptr;
			this->isLogout = true;
		}
	}
	else if (key == 27)
	{
		this->isShow = false;
	}
	else if (this->menuChoice == 0)
	{
		if (choiceToAct == 1 && this->isShow == true)
		{
			if (key == '1')
			{
				ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2 + 2, ConsolaUI::getConsoleHeight() / 2 - 2, "                         ", 15);
				ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2 + 2, ConsolaUI::getConsoleHeight() / 2 - 2);
				this->oldPass = ConsolaUI::GetLine();
			}
			else if (key == '2')
			{
				ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2 + 2, ConsolaUI::getConsoleHeight() / 2 + 1, "                         ", 15);
				ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2 + 2, ConsolaUI::getConsoleHeight() / 2 + 1);
				this->newPass = ConsolaUI::GetLine();
			}
			else if (key == '3')
			{
				ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2 + 2, ConsolaUI::getConsoleHeight() / 2 + 4, "                         ", 15);
				ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2 + 2, ConsolaUI::getConsoleHeight() / 2 + 4);
				this->reNewPass = ConsolaUI::GetLine();
			}
			else if (key == 13)
			{
				this->changePassError = this->authService->changePassword(this->user, this->oldPass, this->newPass, this->reNewPass);
			}
		}

	}
	else if (this->menuChoice == 1)
	{
		if (this->choiceToAct == 2 || (this->isUpdate && this->choiceToAct == 1))
		{
			if (key == 13)
			{
				switch (this->currentIndex)
				{
				case 1:
				{
					ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 2);
					this->studentToAct.setFullName(ConsolaUI::GetLine());
					break;
				}
				case 2:
				{
					this->isDateEdit = !this->isDateEdit;
					break;
				}
				case 3:
				{
					this->studentToAct.setGender(this->studentToAct.getGender() ? false : true);
					break;
				}
				case 4:
				{
					ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 5);
					this->studentToAct.setStudentId(ConsolaUI::GetInt());
					break;
				}
				case 5:
				{
					ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 6);
					this->studentToAct.setClassName(ConsolaUI::GetLine());
					break;
				}
				case 6:
				{
					ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 7);
					this->studentToAct.setFaculty(ConsolaUI::GetLine());
					break;
				}
				case 7:
				{
					ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 8);
					this->studentToAct.setPhoneNumber(ConsolaUI::GetLine());
					break;
				}
				case 8:
				{
					ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 9);
					this->studentToAct.setEmail(ConsolaUI::GetLine());
					break;
				}
				}
			}
			if (this->choiceToAct == 2)
			{
				if (key == 'Y' || key == 'y')
					this->userService->createStudent(this->studentToAct);
				else if (key == 'X' || key == 'x')
					this->studentToAct = Student();
			}
		}
		if (this->choiceToAct == 1)
		{
			if (key == 'F' || key == 'f')
			{
				ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2 + 2, 9, "                  ", 15);
				ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2 + 2, 9);
				this->studentId = ConsolaUI::GetInt();
				this->isDelete = false;
				this->isUpdate = false;
			}
			else if (key == 'x' || key == 'X')
			{
				this->isDelete = true;
			}
			else if (key == 'U' || key == 'u')
			{
				this->isUpdate = true;
				this->preStudentId = this->studentToAct.getStudentId();
			}
			else if (key == 'y' || key == 'Y')
			{
				if (this->isDelete)
				{
					this->userService->deleteStudent(this->studentToAct.getStudentId());
				}
				else if (this->isUpdate)
				{
					this->userService->updateStudent(this->preStudentId, this->studentToAct);
				}
				this->isDelete = false;
				this->isUpdate = false;
			}
			else if (key == 'N' || key == 'n')
			{
				if (this->isDelete) this->isDelete = false;
				else if (this->isUpdate) this->isUpdate = false;
			}
		}
	}
	else if (this->menuChoice == 2)
	{
		if (this->choiceToAct == 1)
		{
			if (key == 'f' || key == 'F')
			{
				ConsolaUI::text(67, 9, "                ", 15);
				ConsolaUI::gotoXY(67, 9);
				this->roomId = ConsolaUI::GetInt();
			}
			else if (key == 'u' || key == 'U')
			{
				this->isUpdate = true;
			}
			if (this->isUpdate)
			{
				if (key == 13)
				{
					switch (this->currentIndex)
					{
					case 1:
					{
						ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 2);
						this->roomToAct.setRoomName(ConsolaUI::GetLine());
					}
					break;
					case 2:
					{
						if (this->roomToAct.getRoomType() == "Nam") this->roomToAct.setRoomType("Nu");
						else this->roomToAct.setRoomType("Nam");
					}
					break;
					case 3:
					{
						ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 4);
						this->roomToAct.setCapacity(ConsolaUI::GetInt());
					}
					break;
					case 4:
					{
						this->roomToAct.setIsActive(!this->roomToAct.getIsActive());
					}
					break;
					}
				}
				else if (key == 'n' || key == 'N')
				{
					this->isUpdate = false;
				}
				else if (key == 'y' || key == 'Y')
				{
					this->roomService->updateRoom(this->roomToAct);
					this->isUpdate = false;
				}
			}
		}
	}
	else if (this->menuChoice == 3)
	{
		if (this->choiceToAct == 1)
		{
			if (key == 'f' || key == 'F')
			{
				ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2 + 2, 9, "                ", 15);
				ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2 + 2, 9);
				this->roomId = ConsolaUI::GetInt();
			}
			else if (key == 13)
			{
				switch (this->currentIndex)
				{
				case 1:
				{
					ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 2);
					this->elecNum = ConsolaUI::GetInt();
				}
				break;
				case 2:
				{
					ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 3);
					this->waterNum = ConsolaUI::GetInt();
				}
				break;
				case 3:
				{
					ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 4);
					this->interNum = ConsolaUI::GetInt();
				}
				break;
				}
			}
			else if (key == 'Y' || key == 'y')
			{
				this->billingService->createInvoice(this->roomId, this->elecNum, this->waterNum, this->interNum);
				this->roomId = 0;
				this->elecNum = 0;
				this->waterNum = 0;
				this->interNum = 0;
			}
			else if (key == 'N' || key == 'n')
			{
				this->roomId = 0;
				this->elecNum = 0;
				this->waterNum = 0;
				this->interNum = 0;
			}
		}
		else if (this->choiceToAct == 2)
		{
			if (key == 'f' || key == 'F')
			{
				ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2 + 2, 9, "                ", 15);
				ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2 + 2, 9);
				this->studentId = ConsolaUI::GetInt();
			}
		}
		else if (this->choiceToAct == 3)
		{
			if (key == 'f' || key == 'F')
			{
				ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2 + 2, 9, "                ", 15);
				ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2 + 2, 9);
				this->invoiceId = ConsolaUI::GetInt();
			}
		}
	}
	else if (this->menuChoice == 4)
	{
		if (this->choiceToAct == 2)
		{
			if (key == 'f' || key == 'F')
			{
				ConsolaUI::text(ConsolaUI::getConsoleWidth() / 6 + 37, 9, "                ", 15);
				ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 6 + 37, 9);
				this->studentId = ConsolaUI::GetInt();
			}
		}
		else if (this->choiceToAct == 3)
		{
			if (key == 'f' || key == 'F')
			{
				ConsolaUI::text(ConsolaUI::getConsoleWidth() / 6 + 37, 9, "                ", 15);
				ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 6 + 37, 9);
				this->contractId = ConsolaUI::GetInt();
			}
		}
		else if (key == 13)
		{
			switch (this->currentIndex)
			{
			case 1:
			{
				ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 2, "                ", 15);
				ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 2);
				this->studentId = ConsolaUI::GetInt();
			}
			break;
			case 2:
			{
				ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 6, "                ", 15);
				ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 6);
				this->roomId = ConsolaUI::GetInt();
			}
			break;
			case 3:
			{
				ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 10, "                ", 15);
				ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 10);
				this->cycle = ConsolaUI::GetInt();
			}
			break;
			}
		}
	}
	if (this->isShow == false)
	{
		this->studentId = 0;
		this->roomId = 0;
		this->contractId = 0;
		this->invoiceId = 0;
		this->currentIndex = 1;
		this->isUpdate = false;
		this->isDelete = false;
		this->studentToAct = Student();
		this->preStudentId = 0;
	}
}

void EmployeeView::showHeader(const int& width, const int& height)
{
	ConsolaUI::text(12, 2, "HE THONG QUAN LY KI TUC XA", 13);
	ConsolaUI::drawBox(1, 3, width - 1, 2, 7);
	ConsolaUI::text((width - 2) / 10 - 5, 4, "THONG TIN", menuChoice == 0 ? 1 : 8);
	ConsolaUI::text(3 * (width - 2) / 10 - 6, 4, "QL SINH VIEN", menuChoice == 1 ? 1 : 8);
	ConsolaUI::text(5 * (width - 2) / 10 - 4, 4, "QL PHONG", menuChoice == 2 ? 1 : 8);
	ConsolaUI::text(7 * (width - 2) / 10 - 5, 4, "QL HOA DON", menuChoice == 3 ? 1 : 8);
	ConsolaUI::text(9 * (width - 2) / 10 - 6, 4, "QL HOP DONG", menuChoice == 4 ? 1 : 8);
}
void EmployeeView::showInfoMenu(const int& width, const int& height)
{
	ConsolaUI::drawBox(width / 2 - 19, height / 2 - 3, 39, 10, 15);
	ConsolaUI::text(width / 2 - 3, height / 2 - 3, " MENU ", 15);
	ConsolaUI::text(width / 2 - 9, height / 2, "THONG TIN CA NHAN", this->choiceToAct == 0 ? 3 : 15);
	ConsolaUI::text(width / 2 - 9, height / 2 + 1, "DOI MAT KHAU", this->choiceToAct == 1 ? 3 : 15);
	ConsolaUI::text(width / 2 - 9, height / 2 + 2, "DANG XUAT", this->choiceToAct == 2 ? 3 : 15);
	ConsolaUI::text(width / 2 - 13, height / 2 + this->choiceToAct, ">>", 3);
	ConsolaUI::text(width / 2 + 13, height / 2 + this->choiceToAct, "<<", 3);
}
void EmployeeView::showInfo(const int& width, const int& height)
{
	int xStart;
	Employee* temp = dynamic_cast<Employee*>(this->user->getUser());
	ConsolaUI::text(width / 2 - 18, 7, ">>   THONG TIN CA NHAN (NHAN VIEN)   <<", 14);
	ConsolaUI::drawBox(width / 2 - 30, 9, 60, 14, 8);
	ConsolaUI::text(width / 2 - 28, 10, "Thong tin dinh danh:", 11);
	ConsolaUI::text(width / 2 - 27, 12, "Ho Va Ten: ", 7);
	ConsolaUI::text(width / 2, 12, temp->getFullName(), 15);
	ConsolaUI::text(width / 2 - 27, 13, "Ma Nhan Vien: ", 7);
	ConsolaUI::text(width / 2, 13, to_string(temp->getEmployeeId()), 15);
	ConsolaUI::text(width / 2 - 27, 14, "Ngay Sinh: ", 7);
	ConsolaUI::gotoXY(width / 2, 14); ConsolaUI::setTextColor(15); cout << temp->getDateOfBirth();
	ConsolaUI::text(width / 2 - 27, 15, "Gioi Tinh: ", 7);
	ConsolaUI::text(width / 2, 15, temp->getGender() == true ? "Nam" : "Nu", 15);

	ConsolaUI::text(width / 2 - 28, 17, "---------------------------------------------", 8);
	ConsolaUI::text(width / 2 - 28, 18, "Thong tin lien he & Chuc vu:", 11);
	ConsolaUI::text(width / 2 - 27, 20, "Chuc Vu: ", 7);
	ConsolaUI::text(width / 2, 20, temp->getRole(), 15);
	ConsolaUI::text(width / 2 - 27, 21, "Email: ", 7);
	ConsolaUI::text(width / 2, 21, temp->getEmail(), 15);
	ConsolaUI::text(width / 2 - 27, 22, "So Dien Thoai: ", 7);
	ConsolaUI::text(width / 2, 22, temp->getPhoneNumber(), 15);
}
void EmployeeView::showChangePass(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 12, 7, ">>   DOI MAT KHAU:   <<", 14);
	ConsolaUI::text(width / 2 - 32, height / 2 - 2, "[1] Nhap Mat Khau Cu", 15);
	ConsolaUI::text(width / 2 - 32, height / 2 + 1, "[2] Nhap Mat Khau Moi", 15);
	ConsolaUI::text(width / 2 - 32, height / 2 + 4, "[3] Nhap Lai Mat Khau Moi", 15);
	ConsolaUI::text(width / 2 + 2, height / 2 - 2, ((this->oldPass == "") ? "" : this->oldPass), 15);
	ConsolaUI::text(width / 2 + 2, height / 2 + 1, ((this->newPass == "") ? "" : this->newPass), 15);
	ConsolaUI::text(width / 2 + 2, height / 2 + 4, ((this->reNewPass == "") ? "" : this->reNewPass), 15);
	ConsolaUI::text(width / 2, height / 2 + 7, "Nhan [       ] De Thay Doi Mat Khau", 15);
	ConsolaUI::text(width / 2 + 7, height / 2 + 7, "Enter", 2);
	ConsolaUI::drawBox(width / 2, height / 2 - 3, 30, 2, 15);
	ConsolaUI::drawBox(width / 2, height / 2, 30, 2, 15);
	ConsolaUI::drawBox(width / 2, height / 2 + 3, 30, 2, 15);
	if (this->changePassError == 1)
	{
		ConsolaUI::text(width / 2 - 17, height / 2 - 5, "Doi Mat Khau Thanh Cong          ", 2);
	}
	else if (this->changePassError == 2)
	{
		ConsolaUI::text(width / 2 - 17, height / 2 - 5, "Mat Khau Cu Khong Dung           ", 12);
	}
	else if (this->changePassError == 3)
	{
		ConsolaUI::text(width / 2 - 17, height / 2 - 5, "De trong mat khau                ", 12);
	}
	else if (this->changePassError == 4)
	{
		ConsolaUI::text(width / 2 - 17, height / 2 - 5, "Mat khau moi nhap lai khong khop ", 12);
	}
	else if (this->changePassError == 5)
	{
		ConsolaUI::text(width / 2 - 17, height / 2 - 5, "Mat khau cu giong mau khau moi   ", 12);
	}
}

void EmployeeView::showStudentMenu(const int& width, const int& height)
{
	ConsolaUI::drawBox(width / 2 - 25, height / 2 - 3, 55, 10, 15);
	ConsolaUI::text(width / 2 - 3, height / 2 - 3, " MENU ", 15);
	ConsolaUI::text(width / 2 - 17, height / 2, "DANH SACH SINH VIEN", this->choiceToAct == 0 ? 3 : 15);
	ConsolaUI::text(width / 2 - 17, height / 2 + 1, "TIM KIEM SINH VIEN THEO ID", this->choiceToAct == 1 ? 3 : 15);
	ConsolaUI::text(width / 2 - 17, height / 2 + 2, "THEM SINH VIEN", this->choiceToAct == 2 ? 3 : 15);
	ConsolaUI::text(width / 2 - 17, height / 2 + 3, "TIM SINH VIEN CHUA DANG KY HOP DONG", this->choiceToAct == 3 ? 3 : 15);
	ConsolaUI::text(width / 2 - 21, height / 2 + this->choiceToAct, ">>", 3);
	ConsolaUI::text(width / 2 + 21, height / 2 + this->choiceToAct, "<<", 3);
}
void EmployeeView::showAllStudents(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 17, 7, ">>   XEM DANH SACH SINH VIEN   <<", 14);
	LinkedList<Student*>* list = this->userService->getAllStudents();
	if (list->getSize() == 0)
		ConsolaUI::text(width / 2 - 19, 9, "Khong co sinh vien nao trong danh sach!", 12);
	else
	{
		int itemsPerPage = height - 13;
		int totalPages = (list->getSize() + itemsPerPage - 1) / itemsPerPage;
		this->maxPage = totalPages - 1;
		if (this->pageIndex > this->maxPage) this->pageIndex = this->maxPage;
		else if (this->pageIndex < 0) this->pageIndex = 0;
		ConsolaUI::text(width / 2 - 46, 8, "MSSV", 11);
		ConsolaUI::text(width / 2 - 31, 8, "Ho va Ten", 11);
		ConsolaUI::text(width / 2 + 4, 8, "Lop", 11);
		ConsolaUI::text(width / 2 + 19, 8, "Gioi Tinh", 11);
		ConsolaUI::text(width / 2 + 34, 8, "SDT", 11);
		ConsolaUI::text(width / 2 - 46, 9, "-------------------------------------------------------------------------------------------", 15);
		for (int i = 0; i < itemsPerPage; i++)
		{
			int yPos = 10 + i;
			if (i + this->pageIndex * itemsPerPage < list->getSize())
			{
				Student* student = *list->getAt(i + this->pageIndex * itemsPerPage);

				ConsolaUI::text(width / 2 - 46, yPos, to_string(student->getStudentId()), 15);
				ConsolaUI::text(width / 2 - 31, yPos, student->getFullName(), 15);
				ConsolaUI::text(width / 2 + 4, yPos, student->getClassName(), 15);
				ConsolaUI::text(width / 2 + 19, yPos, student->getGender() == true ? "Nam" : "Nu", 15);
				ConsolaUI::text(width / 2 + 34, yPos, student->getPhoneNumber(), 15);
			}
			else break;
		}
		ConsolaUI::text(width / 2 - 6, height - 1, "Trang " + to_string(this->pageIndex + 1) + "/" + to_string(totalPages), 7); // 15
		ConsolaUI::text(width / 2 - 31, height - 1, "[ Q ] Trang Truoc", 3);	// 20
		ConsolaUI::text(width / 2 + 11, height - 1, "[ P ] Trang Sau", 3);		// 20
	}
}
void EmployeeView::showFindStudent(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 18, 7, ">>   TIM KIEM THEO ID SINH VIEN   <<", 14);
	ConsolaUI::text(width / 2 - 25, 9, "[F] Nhap Ma Sinh Vien: ", 15);
	ConsolaUI::drawBox(width / 2, 8, 25, 2, 15);
	Student* student = this->userService->getStudentById(this->studentId);
	if (this->studentId != 0)
	{
		if (student == nullptr)
			ConsolaUI::text(width / 2 - 25, 11, ">> KHONG TIM THAY SINH VIEN: " + to_string(this->studentId) + " <<", 12);
		else
		{
			if (!this->isDelete && !this->isUpdate) this->studentToAct = *student;
			if (this->isDelete)
			{
				ConsolaUI::drawBox(width / 2 - 25, height / 2, 50, 7, 12);
				for (int i = 1; i < 7; i++)
					ConsolaUI::text(width / 2 - 24, height / 2 + i, "                                               ", 15);
				ConsolaUI::text(width / 2 - 9, height / 2 + 2, "** XAC NHAN XOA **", 12);
				ConsolaUI::text(width / 2 - 16, height / 2 + 2 + 3, "Ban co chac chan muon xoa khong?", 7);
				ConsolaUI::text(width / 2 - 15, height / 2 + 2 + 4, "[Y] Yes - Xoa    [N] No - Huy", 7);
				return;
			}
			else if (this->isUpdate)
			{
				ConsolaUI::drawBox(width / 2 - 30, height / 2, 60, 12, 8);
				for (int i = 1; i < 12; i++)
					ConsolaUI::text(width / 2 - 29, height / 2 + i, "                                                         ", 15);
				ConsolaUI::text(width / 2 - 12, height / 2 + 1, "** CAP NHAT THONG TIN **", 15);
				ConsolaUI::text(width / 2 - 25, height / 2 + 2, "Ho va ten       :", this->currentIndex == 1 ? 3 : 15);
				ConsolaUI::text(width / 2 - 25, height / 2 + 3, "Ngay sinh       :", this->currentIndex == 2 ? 3 : 15);
				ConsolaUI::text(width / 2 - 25, height / 2 + 4, "Gioi tinh       :", this->currentIndex == 3 ? 3 : 15);
				ConsolaUI::text(width / 2 - 25, height / 2 + 5, "Ma so sinh vien :", this->currentIndex == 4 ? 3 : 15);
				ConsolaUI::text(width / 2 - 25, height / 2 + 6, "Lop             :", this->currentIndex == 5 ? 3 : 15);
				ConsolaUI::text(width / 2 - 25, height / 2 + 7, "Khoa            :", this->currentIndex == 6 ? 3 : 15);
				ConsolaUI::text(width / 2 - 25, height / 2 + 8, "So dien thoai   :", this->currentIndex == 7 ? 3 : 15);
				ConsolaUI::text(width / 2 - 25, height / 2 + 9, "Email           :", this->currentIndex == 8 ? 3 : 15);

				ConsolaUI::text(width / 2, height / 2 + 2, this->studentToAct.getFullName() == "" ? "__________" : this->studentToAct.getFullName(), 15);
				ConsolaUI::text(width / 2, height / 2 + 3, (this->studentToAct.getDateOfBirth().getDay() < 10 ? "0" : "") + to_string(this->studentToAct.getDateOfBirth().getDay()) + "/", this->isDateEdit == true ? (this->dateIndex == 1 ? 10 : 15) : 15);
				ConsolaUI::text(width / 2 + 3, height / 2 + 3, (this->studentToAct.getDateOfBirth().getMonth() < 10 ? "0" : "") + to_string(this->studentToAct.getDateOfBirth().getMonth()) + "/", this->isDateEdit == true ? (this->dateIndex == 2 ? 10 : 15) : 15);
				ConsolaUI::text(width / 2 + 6, height / 2 + 3, to_string(this->studentToAct.getDateOfBirth().getYear()), this->isDateEdit == true ? (this->dateIndex == 3 ? 10 : 15) : 15);
				ConsolaUI::text(width / 2, height / 2 + 4, this->studentToAct.getGender() == true ? "Nam" : "Nu", 15);
				ConsolaUI::text(width / 2, height / 2 + 5, this->studentToAct.getStudentId() == 0 ? "__________" : to_string(this->studentToAct.getStudentId()), 15);
				ConsolaUI::text(width / 2, height / 2 + 6, this->studentToAct.getClassName() == "" ? "__________" : this->studentToAct.getClassName(), 15);
				ConsolaUI::text(width / 2, height / 2 + 7, this->studentToAct.getFaculty() == "" ? "__________" : this->studentToAct.getFaculty(), 15);
				ConsolaUI::text(width / 2, height / 2 + 8, this->studentToAct.getPhoneNumber() == "" ? "__________" : this->studentToAct.getPhoneNumber(), 15);
				ConsolaUI::text(width / 2, height / 2 + 9, this->studentToAct.getEmail() == "" ? "__________" : this->studentToAct.getEmail(), 15);
				ConsolaUI::text(width / 2 - 17, height / 2 + 11, "[Y] Yes - Cap Nhat    [N] No - Huy", 15);
				return;
			}
			// Show Thong Tin Sinh Vien Da Duoc Tim Kiem
			ConsolaUI::text(width / 2 - 25, 11, ">> SINH VIEN DA DUOC TIM THAY! (ID: " + to_string(this->studentId) + ") <<", 10);
			ConsolaUI::text(width / 2 - 25, 13, "Ho Va Ten:          " + student->getFullName(), 15);
			ConsolaUI::text(width / 2 - 25, 14, "Ma So Sinh Vien:    " + to_string(student->getStudentId()), 15);
			ConsolaUI::text(width / 2 - 25, 15, "Ngay Sinh:          " + student->getDateOfBirth().getDate(), 15);
			ConsolaUI::text(width / 2 - 25, 16, "Gioi Tinh:          ", 15);
			ConsolaUI::text(width / 2 - 5, 16, student->getGender() ? "Nam" : "Nu", 15);
			ConsolaUI::text(width / 2 - 25, 17, "Lop:                " + student->getClassName(), 15);
			ConsolaUI::text(width / 2 - 25, 18, "Khoa:               " + student->getFaculty(), 15);
			ConsolaUI::text(width / 2 - 25, 19, "SDT:                " + student->getPhoneNumber(), 15);
			ConsolaUI::text(width / 2 - 25, 20, "Email:              " + student->getEmail(), 15);
			// Nut Thao Tac Xoa Va Cap Nhat
			ConsolaUI::text(width / 2 - 25, 24, "[ X ] Xoa", 2);
			ConsolaUI::text(width / 2 - 25, 25, "[ U ] Cap Nhat", 2);

		}
	}
}
void EmployeeView::showAddStudent(const int& width, const int& height)
{
	ConsolaUI::drawBox(width / 2 - 30, height / 2, 60, 12, 8);
	ConsolaUI::text(width / 2 - 12, height / 2 + 1, "** THEM SINH VIEN MOI **", 15);
	ConsolaUI::text(width / 2 - 25, height / 2 + 2, "Ho va ten       :", this->currentIndex == 1 ? 3 : 15);
	ConsolaUI::text(width / 2 - 25, height / 2 + 3, "Ngay sinh       :", this->currentIndex == 2 ? 3 : 15);
	ConsolaUI::text(width / 2 - 25, height / 2 + 4, "Gioi tinh       :", this->currentIndex == 3 ? 3 : 15);
	ConsolaUI::text(width / 2 - 25, height / 2 + 5, "Ma so sinh vien :", this->currentIndex == 4 ? 3 : 15);
	ConsolaUI::text(width / 2 - 25, height / 2 + 6, "Lop             :", this->currentIndex == 5 ? 3 : 15);
	ConsolaUI::text(width / 2 - 25, height / 2 + 7, "Khoa            :", this->currentIndex == 6 ? 3 : 15);
	ConsolaUI::text(width / 2 - 25, height / 2 + 8, "So dien thoai   :", this->currentIndex == 7 ? 3 : 15);
	ConsolaUI::text(width / 2 - 25, height / 2 + 9, "Email           :", this->currentIndex == 8 ? 3 : 15);

	ConsolaUI::text(width / 2, height / 2 + 2, this->studentToAct.getFullName() == "" ? "__________" : this->studentToAct.getFullName(), 15);
	ConsolaUI::text(width / 2, height / 2 + 3, (this->studentToAct.getDateOfBirth().getDay() < 10 ? "0" : "") + to_string(this->studentToAct.getDateOfBirth().getDay()) + "/", this->isDateEdit == true ? (this->dateIndex == 1 ? 10 : 15) : 15);
	ConsolaUI::text(width / 2 + 3, height / 2 + 3, (this->studentToAct.getDateOfBirth().getMonth() < 10 ? "0" : "") + to_string(this->studentToAct.getDateOfBirth().getMonth()) + "/", this->isDateEdit == true ? (this->dateIndex == 2 ? 10 : 15) : 15);
	ConsolaUI::text(width / 2 + 6, height / 2 + 3, to_string(this->studentToAct.getDateOfBirth().getYear()), this->isDateEdit == true ? (this->dateIndex == 3 ? 10 : 15) : 15);
	ConsolaUI::text(width / 2, height / 2 + 4, this->studentToAct.getGender() == true ? "Nam" : "Nu", 15);
	ConsolaUI::text(width / 2, height / 2 + 5, this->studentToAct.getStudentId() == 0 ? "__________" : to_string(this->studentToAct.getStudentId()), 15);
	ConsolaUI::text(width / 2, height / 2 + 6, this->studentToAct.getClassName() == "" ? "__________" : this->studentToAct.getClassName(), 15);
	ConsolaUI::text(width / 2, height / 2 + 7, this->studentToAct.getFaculty() == "" ? "__________" : this->studentToAct.getFaculty(), 15);
	ConsolaUI::text(width / 2, height / 2 + 8, this->studentToAct.getPhoneNumber() == "" ? "__________" : this->studentToAct.getPhoneNumber(), 15);
	ConsolaUI::text(width / 2, height / 2 + 9, this->studentToAct.getEmail() == "" ? "__________" : this->studentToAct.getEmail(), 15);

	ConsolaUI::text(width / 2 - 20, height / 2 + 13, "[Y] Them Sinh Vien", 2);
	ConsolaUI::text(width / 2 - 20, height / 2 + 14, "[X] Xoa Thong Tin Sinh Vien Hien Tai", 12);
	ConsolaUI::text(width / 2 - 20, height / 2 + 15, "[ESC] Thoat", 12);
}
void EmployeeView::showStudentsNotRegister(const int& width, const int& height)
{
	LinkedList<Student*> students = this->userService->getStudentsWithoutRoom();
	if (students.getSize() == 0)
	{
		ConsolaUI::text(width / 2 - 20, 9, "Khong co sinh vien nao trong danh sach!", 12);
		return;
	}

	int itemsPerPage = height - 13;
	int totalPages = (students.getSize() + itemsPerPage - 1) / itemsPerPage;
	this->maxPage = totalPages - 1;
	if (this->pageIndex > this->maxPage) this->pageIndex = this->maxPage;
	else if (this->pageIndex < 0) this->pageIndex = 0;
	ConsolaUI::text(width / 2 - 44, 8, "MSSV", 11);					// 10
	ConsolaUI::text(width / 2 - 29, 8, "Ho va Ten", 11);			// 30 
	ConsolaUI::text(width / 2 + 6, 8, "Lop", 11);					// 10
	ConsolaUI::text(width / 2 + 21, 8, "Gioi Tinh", 11);			// 10
	ConsolaUI::text(width / 2 + 36, 8, "SDT", 11);					// 12
	ConsolaUI::text(width / 2 - 46, 9, "-------------------------------------------------------------------------------------------", 15);
	for (int i = 0; i < itemsPerPage; i++)
	{
		int yPos = 10 + i;
		if (i + this->pageIndex * itemsPerPage < students.getSize())
		{
			Student* student = *students.getAt(i + this->pageIndex * itemsPerPage);

			ConsolaUI::text(width / 2 - 44, yPos, to_string(student->getStudentId()), 15);
			ConsolaUI::text(width / 2 - 29, yPos, student->getFullName(), 15);
			ConsolaUI::text(width / 2 + 6, yPos, student->getClassName(), 15);
			ConsolaUI::text(width / 2 + 21, yPos, student->getGender() == true ? "Nam" : "Nu", 15);
			ConsolaUI::text(width / 2 + 36, yPos, student->getPhoneNumber(), 15);
		}
		else break;
	}
	ConsolaUI::text(width / 2 - 6, height - 1, "Trang " + to_string(this->pageIndex + 1) + "/" + to_string(totalPages), 7); // 15
	ConsolaUI::text(width / 2 - 31, height - 1, "[ Q ] Trang Truoc", 3);	// 20
	ConsolaUI::text(width / 2 + 11, height - 1, "[ P ] Trang Sau", 3);		// 20
}

void EmployeeView::showRoomMenu(const int& width, const int& height)
{
	ConsolaUI::drawBox(width / 2 - 30, height / 2 - 3, 61, 10, 15);
	ConsolaUI::text(width / 2 - 3, height / 2 - 3, " MENU ", 15);
	ConsolaUI::text(width / 2 - 20, height / 2, "DANH SACH PHONG", this->choiceToAct == 0 ? 3 : 15);
	ConsolaUI::text(width / 2 - 20, height / 2 + 1, "TIM KIEM PHONG THEO ID", this->choiceToAct == 1 ? 3 : 15);
	ConsolaUI::text(width / 2 - 20, height / 2 + 2, "TIM PHONG TRONG", this->choiceToAct == 2 ? 3 : 15);
	ConsolaUI::text(width / 2 - 20, height / 2 + 3, "TIM PHONG SAP XEP THEO SO LUONG CHO TRONG", this->choiceToAct == 3 ? 3 : 15);
	ConsolaUI::text(width / 2 - 24, height / 2 + this->choiceToAct, ">>", 3);
	ConsolaUI::text(width / 2 + 24, height / 2 + this->choiceToAct, "<<", 3);
}
void EmployeeView::showAllRooms(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 25, 7, ">>   XEM DANH SACH PHONG   <<", 14);
	LinkedList<Room*>* list = this->roomService->getAllRooms();

	if (list->getSize() == 0)
		ConsolaUI::text(width / 2 - 18, 9, "Khong co phong nao trong danh sach!", 12);
	else
	{
		int itemsPerPage = height - 13;
		int totalPages = (list->getSize() + itemsPerPage - 1) / itemsPerPage;
		this->maxPage = totalPages - 1;
		if (this->pageIndex > this->maxPage) this->pageIndex = this->maxPage;
		else if (this->pageIndex < 0) this->pageIndex = 0;
		ConsolaUI::text(width / 2 - 50, 8, "ID", 11);				// 10
		ConsolaUI::text(width / 2 - 35, 8, "Ten Phong", 11);		// 10
		ConsolaUI::text(width / 2 - 20, 8, "Loai", 11);				// 10
		ConsolaUI::text(width / 2 - 5, 8, "So Nguoi", 11);			// 10
		ConsolaUI::text(width / 2 + 10, 8, "Tang", 11);				// 10
		ConsolaUI::text(width / 2 + 25, 8, "Toa Nha", 11);			// 10
		ConsolaUI::text(width / 2 + 40, 8, "Trang Thai", 11);		// 10
		for (int i = 0; i < itemsPerPage; i++)
		{
			int yPos = 9 + i;
			if (i + this->pageIndex * itemsPerPage < list->getSize())
			{
				Room* room = *list->getAt(i + this->pageIndex * itemsPerPage);
				ConsolaUI::text(width / 2 - 50, yPos, to_string(room->getRoomId()), 15);
				ConsolaUI::text(width / 2 - 35, yPos, room->getRoomName(), 15);
				ConsolaUI::text(width / 2 - 20, yPos, room->getRoomType(), 15);
				ConsolaUI::text(width / 2 - 5, yPos, to_string(room->getCurrentOccupancy()) + "/" + to_string(room->getCapacity()), (room->getCurrentOccupancy() == room->getCapacity()) ? 6 : 10);
				ConsolaUI::text(width / 2 + 10, yPos, to_string(room->getFloor()), 15);
				ConsolaUI::text(width / 2 + 25, yPos, room->getBuilding(), 15);
				ConsolaUI::text(width / 2 + 40, yPos, room->getIsActive() ? "Hoat dong" : "Khong HD", room->getIsActive() ? 10 : 12);
			}
			else break;
		}
		ConsolaUI::text(width / 2 - 6, height - 1, "Trang " + to_string(this->pageIndex + 1) + "/" + to_string(totalPages), 7); // 15
		ConsolaUI::text(width / 2 - 31, height - 1, "[ Q ] Trang Truoc", 3);	// 20
		ConsolaUI::text(width / 2 + 11, height - 1, "[ P ] Trang Sau", 3);		// 20
	}
}
void EmployeeView::showFindRoomById(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 16, 7, ">>   TIM KIEM THEO ID PHONG   <<", 14);
	ConsolaUI::text(width / 2 - 25, 9, "[F] Nhap Ma Phong: ", 15);
	ConsolaUI::drawBox(width / 2, 8, 25, 2, 15);
	Room* roomToShow = this->roomService->getRoomById(this->roomId);
	if (this->roomId != 0)
	{
		if (roomToShow == nullptr)
			ConsolaUI::text(width / 2 - 15, 11, ">> KHONG TIM THAY PHONG: " + to_string(this->roomId) + " <<", 12);
		else
		{
			if (!this->isUpdate)
			{
				this->roomToAct = *roomToShow;
			}
			if (this->isUpdate)
			{
				if (this->currentIndex < 1) this->currentIndex = 4;
				else if (this->currentIndex > 4) this->currentIndex = 1;
				ConsolaUI::drawBox(width / 2 - 30, height / 2, 60, 12, 8);
				ConsolaUI::text(width / 2 - 25, height / 2 + 2, "Ten Phong: ", this->currentIndex == 1 ? 3 : 15);
				ConsolaUI::text(width / 2 - 25, height / 2 + 3, "Loai Phong: ", this->currentIndex == 2 ? 3 : 15);
				ConsolaUI::text(width / 2 - 25, height / 2 + 4, "Suc Chua: ", this->currentIndex == 3 ? 3 : 15);
				ConsolaUI::text(width / 2 - 25, height / 2 + 5, "Trang Thai: ", this->currentIndex == 4 ? 3 : 15);
				ConsolaUI::text(width / 2, height / 2 + 2, this->roomToAct.getRoomName(), 15);
				ConsolaUI::text(width / 2, height / 2 + 3, this->roomToAct.getRoomType(), 15);
				ConsolaUI::text(width / 2, height / 2 + 4, to_string(this->roomToAct.getCapacity()), 15);
				ConsolaUI::text(width / 2, height / 2 + 5, this->roomToAct.getIsActive() ? "Con Hoat Dong" : "Khong Hoat Dong", this->roomToAct.getIsActive() ? 10 : 12);
				ConsolaUI::text(width / 2 - 18, height / 2 + 9, "[Y] Yes - Cap Nhat     [N] No - Huy", 7);
				return;
			}
			ConsolaUI::text(35, 11, ">> TIM THAY PHONG <<", 10);
			int yPos = 13;
			int xLabel = width / 2 - 25;
			int xValue = width / 2;
			ConsolaUI::text(xLabel, yPos, "Ma Phong   : ", 15);
			ConsolaUI::text(xValue, yPos, to_string(roomToShow->getRoomId()), 15);
			ConsolaUI::text(xLabel, yPos + 1, "Ten Phong  : ", 15);
			ConsolaUI::text(xValue, yPos + 1, roomToShow->getRoomName(), 15);
			ConsolaUI::text(xLabel, yPos + 2, "Loai Phong : ", 15);
			ConsolaUI::text(xValue, yPos + 2, roomToShow->getRoomType(), 15);
			ConsolaUI::text(xLabel, yPos + 3, "So Nguoi   : ", 15);
			ConsolaUI::text(xValue, yPos + 3, to_string(roomToShow->getCurrentOccupancy()) + "/" + to_string(roomToShow->getCapacity()), (roomToShow->getCurrentOccupancy() == roomToShow->getCapacity()) ? 6 : 10);
			ConsolaUI::text(xLabel, yPos + 4, "Tang       : ", 15);
			ConsolaUI::text(xValue, yPos + 4, to_string(roomToShow->getFloor()), 15);
			ConsolaUI::text(xLabel, yPos + 5, "Toa Nha    : ", 15);
			ConsolaUI::text(xValue, yPos + 5, roomToShow->getBuilding(), 15);
			ConsolaUI::text(xLabel, yPos + 6, "Trang Thai : ", 15);
			bool isActive = roomToShow->getIsActive();
			ConsolaUI::text(xValue, yPos + 6, isActive ? "Hoat dong" : "Khong HD", isActive ? 10 : 12);
			ConsolaUI::text(xLabel, yPos + 9, "[U] Chinh Sua", 7);
		}
	}
}
void EmployeeView::showFindVacantRooms(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 17, 7, ">>  XEM DANH SACH PHONG TRONG   <<", 14);
	LinkedList<Room*> list = this->roomService->getVacantRooms();

	if (list.getSize() == 0)
		ConsolaUI::text(width / 2 - 18, 9, "Khong co phong nao trong danh sach!", 12);
	else
	{
		int itemsPerPage = height - 13;
		int totalPages = (list.getSize() + itemsPerPage - 1) / itemsPerPage;
		this->maxPage = totalPages - 1;
		if (this->pageIndex > this->maxPage) this->pageIndex = this->maxPage;
		else if (this->pageIndex < 0) this->pageIndex = 0;
		ConsolaUI::text(width / 2 - 50, 8, "ID", 11);				// 10
		ConsolaUI::text(width / 2 - 35, 8, "Ten Phong", 11);		// 10
		ConsolaUI::text(width / 2 - 20, 8, "Loai", 11);				// 10
		ConsolaUI::text(width / 2 - 5, 8, "So Nguoi", 11);			// 10
		ConsolaUI::text(width / 2 + 10, 8, "Tang", 11);				// 10
		ConsolaUI::text(width / 2 + 25, 8, "Toa Nha", 11);			// 10
		ConsolaUI::text(width / 2 + 40, 8, "Trang Thai", 11);		// 10
		for (int i = 0; i < itemsPerPage; i++)
		{
			int yPos = 9 + i;
			if (i + this->pageIndex * itemsPerPage < list.getSize())
			{
				Room* room = *list.getAt(i + this->pageIndex * itemsPerPage);
				ConsolaUI::text(width / 2 - 50, yPos, to_string(room->getRoomId()), 15);
				ConsolaUI::text(width / 2 - 35, yPos, room->getRoomName(), 15);
				ConsolaUI::text(width / 2 - 20, yPos, room->getRoomType(), 15);
				ConsolaUI::text(width / 2 - 5, yPos, to_string(room->getCurrentOccupancy()) + "/" + to_string(room->getCapacity()), (room->getCurrentOccupancy() == room->getCapacity()) ? 6 : 10);
				ConsolaUI::text(width / 2 + 10, yPos, to_string(room->getFloor()), 15);
				ConsolaUI::text(width / 2 + 25, yPos, room->getBuilding(), 15);
				ConsolaUI::text(width / 2 + 40, yPos, room->getIsActive() ? "Hoat dong" : "Khong HD", room->getIsActive() ? 10 : 12);
			}
			else break;
		}
		ConsolaUI::text(width / 2 - 6, height - 1, "Trang " + to_string(this->pageIndex + 1) + "/" + to_string(totalPages), 7); // 15
		ConsolaUI::text(width / 2 - 31, height - 1, "[ Q ] Trang Truoc", 3);	// 20
		ConsolaUI::text(width / 2 + 11, height - 1, "[ P ] Trang Sau", 3);		// 20
	}
}
void EmployeeView::showFindAvailableRooms(const int& width, const int& height)
{
	ConsolaUI::text(30, 7, "XEM DANH SACH PHONG:", 14);
	LinkedList<Room*> list = this->roomService->getAvailableRooms();

	if (list.getSize() == 0)
		ConsolaUI::text(33, 9, "Khong co phong nao trong danh sach!", 12);
	else
	{
		int itemsPerPage = height - 13;
		int totalPages = (list.getSize() + itemsPerPage - 1) / itemsPerPage;
		this->maxPage = totalPages - 1;
		if (this->pageIndex > this->maxPage) this->pageIndex = this->maxPage;
		else if (this->pageIndex < 0) this->pageIndex = 0;
		ConsolaUI::text(width / 2 - 50, 8, "ID", 11);				// 10
		ConsolaUI::text(width / 2 - 35, 8, "Ten Phong", 11);		// 10
		ConsolaUI::text(width / 2 - 20, 8, "Loai", 11);				// 10
		ConsolaUI::text(width / 2 - 5, 8, "So Nguoi", 11);			// 10
		ConsolaUI::text(width / 2 + 10, 8, "Tang", 11);				// 10
		ConsolaUI::text(width / 2 + 25, 8, "Toa Nha", 11);			// 10
		ConsolaUI::text(width / 2 + 40, 8, "Trang Thai", 11);		// 10
		for (int i = 0; i < itemsPerPage; i++)
		{
			int yPos = 9 + i;
			if (i + this->pageIndex * itemsPerPage < list.getSize())
			{
				Room* room = *list.getAt(i + this->pageIndex * itemsPerPage);
				ConsolaUI::text(width / 2 - 50, yPos, to_string(room->getRoomId()), 15);
				ConsolaUI::text(width / 2 - 35, yPos, room->getRoomName(), 15);
				ConsolaUI::text(width / 2 - 20, yPos, room->getRoomType(), 15);
				ConsolaUI::text(width / 2 - 5, yPos, to_string(room->getCurrentOccupancy()) + "/" + to_string(room->getCapacity()), (room->getCurrentOccupancy() == room->getCapacity()) ? 6 : 10);
				ConsolaUI::text(width / 2 + 10, yPos, to_string(room->getFloor()), 15);
				ConsolaUI::text(width / 2 + 25, yPos, room->getBuilding(), 15);
				ConsolaUI::text(width / 2 + 40, yPos, room->getIsActive() ? "Hoat dong" : "Khong HD", room->getIsActive() ? 10 : 12);
			}
			else break;
		}
		ConsolaUI::text(width / 2 - 6, height - 1, "Trang " + to_string(this->pageIndex + 1) + "/" + to_string(totalPages), 7); // 15
		ConsolaUI::text(width / 2 - 31, height - 1, "[ Q ] Trang Truoc", 3);	// 20
		ConsolaUI::text(width / 2 + 11, height - 1, "[ P ] Trang Sau", 3);		// 20
	}
}

void EmployeeView::showInvoiceMenu(const int& width, const int& height)
{
	ConsolaUI::drawBox(width / 2 - 27, height / 2 - 3, 55, 10, 15);
	ConsolaUI::text(width / 2 - 3, height / 2 - 3, " MENU ", 15);
	ConsolaUI::text(width / 2 - 17, height / 2, "DANH SACH HOA DON", this->choiceToAct == 0 ? 3 : 15);
	ConsolaUI::text(width / 2 - 17, height / 2 + 1, "TAO HOA DON CHO SINH VIEN", this->choiceToAct == 1 ? 3 : 15);
	ConsolaUI::text(width / 2 - 17, height / 2 + 2, "TIM KIEM HOA DON THEO MA SINH VIEN", this->choiceToAct == 2 ? 3 : 15);
	ConsolaUI::text(width / 2 - 17, height / 2 + 3, "TIM KIEM HOA DON THEO MA HOA DON", this->choiceToAct == 3 ? 3 : 15);
	ConsolaUI::text(width / 2 - 17, height / 2 + 4, "TIM KIEM HOA DON DA THANH TOAN", this->choiceToAct == 4 ? 3 : 15);
	ConsolaUI::text(width / 2 - 17, height / 2 + 5, "TIM KIEM HOA DON CHUA THANH TOAN", this->choiceToAct == 5 ? 3 : 15);
	ConsolaUI::text(width / 2 - 21, height / 2 + this->choiceToAct, ">>", 3);
	ConsolaUI::text(width / 2 + 21, height / 2 + this->choiceToAct, "<<", 3);
}
void EmployeeView::showAllInvoices(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 15, 7, ">>   XEM DANH SACH HOA DON   <<", 14);
	LinkedList<Invoice*>* list = this->billingService->getAllInvoices();
	if (list->getSize() == 0)
	{
		ConsolaUI::text(width / 2 - 19, 9, "Khong co hoa don nao trong danh sach!", 12);
		return;
	}
	int itemsPerPage = height - 13;
	int totalPages = (list->getSize() + itemsPerPage - 1) / itemsPerPage;
	this->maxPage = totalPages - 1;
	if (this->pageIndex > this->maxPage) this->pageIndex = this->maxPage;
	else if (this->pageIndex < 0) this->pageIndex = 0;
	ConsolaUI::text(width / 2 - 30, 8, "Ma Hoa Don", 11);			// 10
	ConsolaUI::text(width / 2 - 15, 8, "So Tien", 11);				// 10
	ConsolaUI::text(width / 2, 8, "Ngay Lap", 11);					// 10
	ConsolaUI::text(width / 2 + 15, 8, "Trang Thai", 11);			// 10
	ConsolaUI::text(width / 2 - 30, 9, "------------------------------------------------------", 15);
	for (int i = 0; i < itemsPerPage; i++)
	{
		int yPos = 10 + i;
		if (i + this->pageIndex * itemsPerPage < list->getSize())
		{
			Invoice* invoice = *list->getAt(i + this->pageIndex * itemsPerPage);
			ConsolaUI::text(width / 2 - 30, yPos, to_string(invoice->getInvoiceId()), 15);
			ConsolaUI::text(width / 2 - 15, yPos, to_string(invoice->getTotalAmount()), 15);
			ConsolaUI::text(width / 2, yPos, invoice->getCreatedDate().getDate(), 15);
			ConsolaUI::text(width / 2 + 15, yPos, invoice->getisPaid() ? "Da thanh toan" : "Chua thanh toan", invoice->getisPaid() ? 10 : 12);
		}
		else break;
	}
	ConsolaUI::text(width / 2 - 6, height - 1, "Trang " + to_string(this->pageIndex + 1) + "/" + to_string(totalPages), 7); // 15
	ConsolaUI::text(width / 2 - 31, height - 1, "[ Q ] Trang Truoc", 3);	// 20
	ConsolaUI::text(width / 2 + 11, height - 1, "[ P ] Trang Sau", 3);		// 20
}
void EmployeeView::showCreateNewInvoice(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 13, 7, ">>   Tao Hoa Don Moi   <<", 14);
	ConsolaUI::text(width / 2 - 25, 9, "[F] Nhap Ma Phong", 14);
	ConsolaUI::drawBox(width / 2, 8, 25, 2, 15);
	if (this->roomId == 0)
		return;
	Room* room = this->roomService->getRoomById(this->roomId);
	if (room == nullptr)
	{
		ConsolaUI::text(width / 2 - 10, 12, "Khong co phong nay!", 12);
		return;
	}
	if (this->currentIndex < 1) this->currentIndex = 3;
	else if (this->currentIndex > 3) this->currentIndex = 1;
	ConsolaUI::drawBox(width / 2 - 30, height / 2, 60, 12, 8);
	ConsolaUI::text(width / 2 - 25, height / 2 + 1, "Phong :" + room->getRoomName(), 15);
	ConsolaUI::text(width / 2 - 25, height / 2 + 2, "So Dien :", this->currentIndex == 1 ? 3 : 15);
	ConsolaUI::text(width / 2, height / 2 + 2, to_string(this->elecNum), this->currentIndex == 1 ? 3 : 15);
	ConsolaUI::text(width / 2 - 25, height / 2 + 3, "So Nuoc :", this->currentIndex == 2 ? 3 : 15);
	ConsolaUI::text(width / 2, height / 2 + 3, to_string(this->waterNum), this->currentIndex == 2 ? 3 : 15);
	ConsolaUI::text(width / 2 - 25, height / 2 + 4, "So Tien Internet :", this->currentIndex == 3 ? 3 : 15);
	ConsolaUI::text(width / 2, height / 2 + 4, to_string(this->interNum), this->currentIndex == 3 ? 3 : 15);
	ConsolaUI::text(width / 2 - 11, height / 2 + 8, "[Y] Xac Nhan   [N] Huy", 10);
}
void EmployeeView::showFindInvoicesByStudentId(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 18, 7, ">>   TIM KIEM THEO ID SINH VIEN   <<", 14);
	ConsolaUI::text(width / 2 - 25, 9, "[F] Nhap Ma Sinh Vien: ", 15);
	ConsolaUI::drawBox(width / 2, 8, 25, 2, 15);
	if (this->studentId == 0)
		return;
	LinkedList<Invoice*> invoices = this->billingService->getInvoicesByStudent(this->studentId);
	if (invoices.getSize() == 0)
	{
		ConsolaUI::text(width / 2 - 13, 11, "Sinh Vien Chua Co Hoa Don!", 12);
		return;
	}
	int itemsPerPage = height - 15;
	int totalPages = (invoices.getSize() + itemsPerPage - 1) / itemsPerPage;
	this->maxPage = totalPages - 1;
	if (this->pageIndex > this->maxPage) this->pageIndex = this->maxPage;
	else if (this->pageIndex < 0) this->pageIndex = 0;
	ConsolaUI::text(width / 2 - 30, 8, "Ma Hoa Don", 11);			// 10
	ConsolaUI::text(width / 2 - 15, 8, "So Tien", 11);				// 10
	ConsolaUI::text(width / 2, 8, "Ngay Lap", 11);					// 10
	ConsolaUI::text(width / 2 + 15, 8, "Trang Thai", 11);			// 10
	ConsolaUI::text(width / 2 - 30, 9, "------------------------------------------------------", 15);
	for (int i = 0; i < itemsPerPage; i++)
	{
		int yPos = 13 + i;
		if (i + this->pageIndex * itemsPerPage < invoices.getSize())
		{
			Invoice* invoice = *invoices.getAt(i + this->pageIndex * itemsPerPage);
			ConsolaUI::text(width / 2 - 30, yPos, to_string(invoice->getInvoiceId()), 15);
			ConsolaUI::text(width / 2 - 15, yPos, to_string(invoice->getTotalAmount()), 15);
			ConsolaUI::text(width / 2, yPos, invoice->getCreatedDate().getDate(), 15);
			ConsolaUI::text(width / 2 + 15, yPos, invoice->getisPaid() ? "Da thanh toan" : "Chua thanh toan", invoice->getisPaid() ? 10 : 12);
		}
		else break;
	}
	ConsolaUI::text(width / 2 - 6, height - 1, "Trang " + to_string(this->pageIndex + 1) + "/" + to_string(totalPages), 7); // 15
	ConsolaUI::text(width / 2 - 31, height - 1, "[ Q ] Trang Truoc", 3);	// 20
	ConsolaUI::text(width / 2 + 11, height - 1, "[ P ] Trang Sau", 3);		// 20
}
void EmployeeView::showFindInvoiceById(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 17, 7, ">>   TIM KIEM THEO ID HOA DON   <<", 14);
	ConsolaUI::text(width / 2 - 25, 9, "[F] Nhap Ma Hoa Don: ", 15);
	ConsolaUI::drawBox(width / 2, 8, 25, 2, 15);
	Invoice* invToShow = this->billingService->getInvoiceById(this->invoiceId);
	if (this->invoiceId == 0)
	{
		return;
	}
	if (invToShow == nullptr)
	{
		ConsolaUI::text(width / 2 - 15, 11, ">> KHONG TIM THAY HOA DON: " + to_string(this->invoiceId) + " <<", 12);
		return;
	}
	int yPos = height / 2;
	int xLabel = width / 2 - 25;
	int xValue = width / 2;
	ConsolaUI::drawBox(width / 2 - 30, height / 2, 60, 12, 8);
	ConsolaUI::text(xLabel, yPos + 2, "Ma Hoa Don : ", 15);
	ConsolaUI::text(xValue, yPos + 2, to_string(invToShow->getInvoiceId()), 15);
	ConsolaUI::text(xLabel, yPos + 3, "Phong   : ", 15);
	ConsolaUI::text(xValue, yPos + 3, (invToShow->getContract()->getRoom()->getRoomName()), 15);
	ConsolaUI::text(xLabel, yPos + 4, "Ma Sinh Vien: ", 15);
	ConsolaUI::text(xValue, yPos + 4, to_string(invToShow->getContract()->getStudentId()), 15);
	ConsolaUI::text(xLabel, yPos + 5, "So Tien    : ", 15);
	ConsolaUI::text(xValue, yPos + 5, to_string(invToShow->getTotalAmount()) + " VND", 10);
	ConsolaUI::text(xLabel, yPos + 6, "Ngay Phat Hanh: ", 15);
	ConsolaUI::text(xValue, yPos + 6, invToShow->getCreatedDate().getDate(), 15);
	ConsolaUI::text(xLabel, yPos + 7, "Trang Thai : ", 15);
	ConsolaUI::text(xValue, yPos + 7, invToShow->getisPaid() ? "Da Thanh Toan" : "Chua Thanh Toan", invToShow->getisPaid() ? 10 : 12);
}
void EmployeeView::showUnpaidInvoices(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 15, 7, ">>   XEM DANH SACH HOA DON   <<", 14);
	LinkedList<Invoice*> list = this->billingService->getUnpaidInvoices();
	if (list.getSize() == 0)
		ConsolaUI::text(width / 2 - 20, 9, "Khong co hoa don nao trong danh sach!", 12);
	else
	{
		int itemsPerPage = height - 13;
		int totalPages = (list.getSize() + itemsPerPage - 1) / itemsPerPage;
		this->maxPage = totalPages - 1;
		if (this->pageIndex > this->maxPage) this->pageIndex = this->maxPage;
		else if (this->pageIndex < 0) this->pageIndex = 0;
		ConsolaUI::text(width / 2 - 30, 8, "Ma Hoa Don", 11);			// 10
		ConsolaUI::text(width / 2 - 15, 8, "So Tien", 11);				// 10
		ConsolaUI::text(width / 2, 8, "Ngay Lap", 11);					// 10
		ConsolaUI::text(width / 2 + 15, 8, "Trang Thai", 11);			// 10
		ConsolaUI::text(width / 2 - 30, 9, "------------------------------------------------------", 15);

		for (int i = 0; i < itemsPerPage; i++)
		{
			int yPos = 9 + i;
			if (i + this->pageIndex * itemsPerPage < list.getSize())
			{
				Invoice* invoice = *list.getAt(i + this->pageIndex * itemsPerPage);
				ConsolaUI::text(width / 2 - 30, yPos, to_string(invoice->getInvoiceId()), 15);
				ConsolaUI::text(width / 2 - 15, yPos, to_string(invoice->getTotalAmount()), 15);
				ConsolaUI::text(width / 2, yPos, invoice->getCreatedDate().getDate(), 15);
				ConsolaUI::text(width / 2 + 15, yPos, invoice->getisPaid() ? "Da thanh toan" : "Chua thanh toan", invoice->getisPaid() ? 10 : 12);
			}
			else break;
		}
		ConsolaUI::text(width / 2 - 6, height - 1, "Trang " + to_string(this->pageIndex + 1) + "/" + to_string(totalPages), 7); // 15
		ConsolaUI::text(width / 2 - 31, height - 1, "[ Q ] Trang Truoc", 3);	// 20
		ConsolaUI::text(width / 2 + 11, height - 1, "[ P ] Trang Sau", 3);		// 20
	}
}
void EmployeeView::showPaidInvoices(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 15, 7, ">>   XEM DANH SACH HOA DON   <<", 14);
	LinkedList<Invoice*> list = this->billingService->getPaidInvoices();

	if (list.getSize() == 0)
		ConsolaUI::text(width / 2 - 20, 9, "Khong co hoa don nao trong danh sach!", 12);
	else
	{
		int itemsPerPage = height - 13;
		int totalPages = (list.getSize() + itemsPerPage - 1) / itemsPerPage;
		this->maxPage = totalPages - 1;
		if (this->pageIndex > this->maxPage) this->pageIndex = this->maxPage;
		else if (this->pageIndex < 0) this->pageIndex = 0;
		ConsolaUI::text(width / 2 - 30, 8, "Ma Hoa Don", 11);			// 10
		ConsolaUI::text(width / 2 - 15, 8, "So Tien", 11);				// 10
		ConsolaUI::text(width / 2, 8, "Ngay Lap", 11);					// 10
		ConsolaUI::text(width / 2 + 15, 8, "Trang Thai", 11);			// 10
		ConsolaUI::text(width / 2 - 30, 9, "------------------------------------------------------", 15);
		for (int i = 0; i < itemsPerPage; i++)
		{
			int yPos = 9 + i;
			if (i + this->pageIndex * itemsPerPage < list.getSize())
			{
				Invoice* invoice = *list.getAt(i + this->pageIndex * itemsPerPage);
				ConsolaUI::text(width / 2 - 30, yPos, to_string(invoice->getInvoiceId()), 15);
				ConsolaUI::text(width / 2 - 15, yPos, to_string(invoice->getTotalAmount()), 15);
				ConsolaUI::text(width / 2, yPos, invoice->getCreatedDate().getDate(), 15);
				ConsolaUI::text(width / 2 + 15, yPos, invoice->getisPaid() ? "Da thanh toan" : "Chua thanh toan", invoice->getisPaid() ? 10 : 12);
			}
			else break;
		}
		ConsolaUI::text(width / 2 - 6, height - 1, "Trang " + to_string(this->pageIndex + 1) + "/" + to_string(totalPages), 7); // 15
		ConsolaUI::text(width / 2 - 31, height - 1, "[ Q ] Trang Truoc", 3);	// 20
		ConsolaUI::text(width / 2 + 11, height - 1, "[ P ] Trang Sau", 3);		// 20
	}
}

void EmployeeView::showContractMenu(const int& width, const int& height)
{
	ConsolaUI::drawBox(width / 2 - 25, height / 2 - 3, 51, 10, 15);
	ConsolaUI::text(width / 2 - 3, height / 2 - 3, " MENU ", 15);
	ConsolaUI::text(width / 2 - 15, height / 2, "DANH SACH HOP DONG", this->choiceToAct == 0 ? 3 : 15);
	ConsolaUI::text(width / 2 - 15, height / 2 + 1, "TAO HOP DONG CHO SINH VIEN", this->choiceToAct == 1 ? 3 : 15);
	ConsolaUI::text(width / 2 - 15, height / 2 + 2, "TIM HOP DONG THEO SINH VIEN", this->choiceToAct == 2 ? 3 : 15);
	ConsolaUI::text(width / 2 - 15, height / 2 + 3, "TIM HOP DONG THEO MA HOP DONG", this->choiceToAct == 3 ? 3 : 15);
	ConsolaUI::text(width / 2 - 15, height / 2 + 4, "TIM HOP DONG HET HAN", this->choiceToAct == 4 ? 3 : 15);
	ConsolaUI::text(width / 2 - 15, height / 2 + 5, "TIM HOP DONG CON HAN", this->choiceToAct == 5 ? 3 : 15);
	ConsolaUI::text(width / 2 - 19, height / 2 + this->choiceToAct, ">>", 3);
	ConsolaUI::text(width / 2 + 19, height / 2 + this->choiceToAct, "<<", 3);
}
void EmployeeView::showAllContracts(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 16, 7, ">>   XEM DANH SACH HOP DONG   <<", 14);
	LinkedList<Contract*>* list = this->contractService->getAllContracts();
	if (list->getSize() > 0)
	{
		int itemsPerPage = height - 14;
		int totalPages = (list->getSize() + itemsPerPage - 1) / itemsPerPage;
		this->maxPage = totalPages - 1;
		if (this->pageIndex > this->maxPage) this->pageIndex = this->maxPage;
		else if (this->pageIndex < 0) this->pageIndex = 0;
		ConsolaUI::text(width / 2 - 10, 8, "TIM THAY " + to_string(list->getSize()) + " HOP DONG:", 10);
		ConsolaUI::text(width / 2 - 38, 9, "Ma HD", 7);			// 10
		ConsolaUI::text(width / 2 - 23, 9, "Ngay Bat Dau", 7);	// 10
		ConsolaUI::text(width / 2 - 8, 9, "Ngay Ket Thuc", 7);	// 10
		ConsolaUI::text(width / 2 + 7, 9, "Trang Thai", 7);	// 15
		ConsolaUI::text(width / 2 + 27, 9, "Phong", 7);		// 10
		ConsolaUI::text(width / 2 - 38, 10, "------------------------------------------------------------------------", 8);
		for (int i = 0; i < itemsPerPage; i++)
		{
			int yPos = 11 + i;
			if (i + this->pageIndex * itemsPerPage < list->getSize())
			{
				Contract* contract = *list->getAt(i + this->pageIndex * itemsPerPage);
				ConsolaUI::text(width / 2 - 38, yPos, to_string(contract->getContractId()), 15);
				ConsolaUI::text(width / 2 - 23, yPos, contract->getStartDate().getDate(), 15);
				ConsolaUI::text(width / 2 - 8, yPos, contract->getEndDate().getDate(), 15);
				ConsolaUI::text(width / 2 + 7, yPos, contract->isActive() ? "Con hieu luc" : "Da het han", contract->isActive() ? 10 : 12);
				ConsolaUI::text(width / 2 + 27, yPos, contract->getRoom()->getRoomName(), 15);
			}
			else break;
		}
		ConsolaUI::text(width / 2 - 6, height - 1, "Trang " + to_string(this->pageIndex + 1) + "/" + to_string(totalPages), 7); // 15
		ConsolaUI::text(width / 2 - 31, height - 1, "[ Q ] Trang Truoc", 3);	// 20
		ConsolaUI::text(width / 2 + 11, height - 1, "[ P ] Trang Sau", 3);		// 20
	}
}
void EmployeeView::showCreateContract(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 14, 7, ">>    TAO HOP DONG MOI    <<", 14);
	bool canSave = true, isValid = false;
	ConsolaUI::drawBox(width / 2 - 30, height / 2, 60, 12, 8);
	ConsolaUI::text(width / 2 - 25, height / 2 + 2, "[*] Ma Sinh Vien:", this->currentIndex == 1 ? 9 : 15);
	ConsolaUI::text(width / 2 - 25 + 4, height / 2 + 3, "Ten Sinh Vien:", 15);
	ConsolaUI::text(width / 2 - 25 + 4, height / 2 + 4, "Ngay Sinh:", 15);
	ConsolaUI::text(width / 2 - 25 + 4, height / 2 + 5, "Gioi Tinh:", 15);
	ConsolaUI::text(width / 2 - 25, height / 2 + 6, "[*] Ma Phong:", this->currentIndex == 2 ? 9 : 15);
	ConsolaUI::text(width / 2 - 25 + 4, height / 2 + 7, "Ten Phong:", 15);
	ConsolaUI::text(width / 2 - 25 + 4, height / 2 + 8, "So Nguoi Hien Tai:", 15);
	ConsolaUI::text(width / 2 - 25, height / 2 + 9, "Loai Phong", 15);
	ConsolaUI::text(width / 2 - 25, height / 2 + 10, "[*] Thoi Han (So Thang):", this->currentIndex == 3 ? 9 : 15);

	Student* student = this->userService->getStudentById(this->studentId);
	ConsolaUI::text(width / 2, height / 2 + 2, to_string(this->studentId), 15);
	if (student == nullptr)
	{
		isValid = false;
		ConsolaUI::text(width / 2, height / 2 + 3, "N/A", 15);
		ConsolaUI::text(width / 2, height / 2 + 4, "N/A", 15);
		ConsolaUI::text(width / 2, height / 2 + 5, "N/A", 15);
		canSave = false;
	}
	else
	{
		ConsolaUI::text(width / 2, height / 2 + 3, student->getFullName(), 15);
		ConsolaUI::text(width / 2, height / 2 + 4, student->getDateOfBirth().getDate(), 15);
		ConsolaUI::text(width / 2, height / 2 + 5, student->getGender() ? "Nam" : "Nu", 15);
		canSave = true;
	}

	Room* room = this->roomService->getRoomById(this->roomId);
	if (room == nullptr)
	{
		isValid = false;
		ConsolaUI::text(width / 2, height / 2 + 7, "N/A", 15);
		ConsolaUI::text(width / 2, height / 2 + 8, "N/A", 15);
		ConsolaUI::text(width / 2, height / 2 + 9, "N/A", 15);
		canSave = false;
	}
	else
	{
		ConsolaUI::text(width / 2, height / 2 + 7, room->getRoomName(), 15);
		ConsolaUI::text(width / 2, height / 2 + 8, to_string(room->getCurrentOccupancy()) + "/" + to_string(room->getCapacity()), 15);
		ConsolaUI::text(width / 2, height / 2 + 9, room->getRoomType(), 15);
		canSave = true;
	}
	// check Nam Nu
	ConsolaUI::text(width / 2, height / 2 + 6, to_string(this->roomId), isValid ? 10 : 15);
	ConsolaUI::text(width / 2, height / 2 + 10, to_string(this->cycle), 15);
	if (this->cycle < 0) canSave = false;
	ConsolaUI::text(width / 2 - 25, height / 2 + 11, "[Y] Luu Hop Dong", canSave ? 10 : 8);
	ConsolaUI::text(width / 2, height / 2 + 11, "[ESC] Huy Bo", 12);
}
void EmployeeView::showFindContractsByStudentId(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 18, 7, ">>   TIM KIEM THEO ID SINH VIEN   <<", 14);
	ConsolaUI::text(width / 2 - 25, 9, "[F] Nhap Ma Sinh Vien:", 15);
	ConsolaUI::drawBox(width / 2, 8, 25, 2, 15);
	if (this->studentId == 0)
		return;
	LinkedList<Contract*>* contracts = this->contractService->getContractsByStudent(this->studentId);
	if (contracts->getSize() == 0)
	{
		ConsolaUI::text(35, 11, ">> Sinh Vien Chua Co Hop Dong <<", 12);
		return;
	}
	int itemsPerPage = height - 13;
	if (itemsPerPage <= 0) itemsPerPage = 1;
	int totalPages = (contracts->getSize() + itemsPerPage - 1) / itemsPerPage;
	this->maxPage = totalPages - 1;
	if (this->pageIndex > this->maxPage) this->pageIndex = this->maxPage;
	else if (this->pageIndex < 0) this->pageIndex = 0;
	ConsolaUI::text(width / 2 - 38, 9, "Ma HD", 7);			// 10
	ConsolaUI::text(width / 2 - 23, 9, "Ngay Bat Dau", 7);	// 10
	ConsolaUI::text(width / 2 - 8, 9, "Ngay Ket Thuc", 7);	// 10
	ConsolaUI::text(width / 2 + 7, 9, "Trang Thai", 7);	// 15
	ConsolaUI::text(width / 2 + 27, 9, "Phong", 7);		// 10
	ConsolaUI::text(width / 2 - 38, 10, "------------------------------------------------------------------------", 8);
	for (int i = 0; i < itemsPerPage; i++)
	{
		int yPos = 14 + i;
		int currentIndex = i + this->pageIndex * itemsPerPage;
		if (currentIndex < contracts->getSize())
		{
			Contract* contract = *contracts->getAt(currentIndex);
			if (contract != nullptr)
			{
				ConsolaUI::text(width / 2 - 38, yPos, to_string(contract->getContractId()), 15);
				ConsolaUI::text(width / 2 - 23, yPos, contract->getStartDate().getDate(), 15);
				ConsolaUI::text(width / 2 - 8, yPos, contract->getEndDate().getDate(), 15);
				ConsolaUI::text(width / 2 + 7, yPos, contract->isActive() ? "Con hieu luc" : "Da het han", contract->isActive() ? 10 : 12);
				ConsolaUI::text(width / 2 + 27, yPos, contract->getRoom()->getRoomName(), 15);
			}
		}
		else break;
	}
	ConsolaUI::text(width / 2 - 6, height - 1, "Trang " + to_string(this->pageIndex + 1) + "/" + to_string(totalPages), 7); // 15
	ConsolaUI::text(width / 2 - 31, height - 1, "[ Q ] Trang Truoc", 3);	// 20
	ConsolaUI::text(width / 2 + 11, height - 1, "[ P ] Trang Sau", 3);		// 20
}
void EmployeeView::showFindContractById(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 18, 7, ">>   TIM KIEM THEO ID HOP DONG   <<", 14);
	ConsolaUI::text(width / 2 - 25, 9, "[F] Nhap Ma Hop Dong:", 15);
	ConsolaUI::drawBox(width / 2, 8, 25, 2, 15);
	if (this->contractId == 0)
		return;
	Contract* contract = this->contractService->getContractById(this->contractId);
	if (contract == nullptr)
	{
		ConsolaUI::text(width / 2 - 19, 11, ">> Khong Tim Thay Hop Dong Voi Ma ID Nay <<", 12);
		return;
	}
	ConsolaUI::text(width / 2 - 25, 11, "THONG TIN CHI TIET HOP DONG:", 11);
	ConsolaUI::text(width / 2 - 25, 12, "Ma Hop Dong  : ", 15);
	ConsolaUI::text(width / 2, 12, to_string(contract->getContractId()), 14);
	ConsolaUI::text(width / 2 - 25, 13, "Ma Sinh Vien : ", 15);
	ConsolaUI::text(width / 2, 13, to_string(contract->getStudentId()), 14);
	ConsolaUI::text(width / 2 - 25, 14, "Ma Phong     : ", 15);
	ConsolaUI::text(width / 2, 14, to_string(contract->getRoomId()), 14);
	ConsolaUI::text(width / 2 - 25, 15, "Ten Phong    : ", 15);
	ConsolaUI::text(width / 2, 15, contract->getRoom()->getRoomName(), 14);
	ConsolaUI::text(width / 2 - 25, 16, "Ngay Bat Dau : ", 15);
	ConsolaUI::text(width / 2, 16, contract->getStartDate().getDate(), 14);
	ConsolaUI::text(width / 2 - 25, 17, "Ngay Ket Thuc: ", 15);
	ConsolaUI::text(width / 2, 17, contract->getEndDate().getDate(), 14);
	ConsolaUI::text(width / 2 - 25, 18, "Trang Thai   : ", 15);
	ConsolaUI::text(width / 2, 18, contract->isActive() ? "Da thanh toan" : "Chua thanh toan", contract->isActive() ? 10 : 12);
}
void EmployeeView::showInvalidContracts(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 16, 7, ">>   XEM DANH SACH HOP DONG   <<", 14);
	LinkedList<Contract*> list = this->contractService->getExpiredContracts();
	if (list.getSize() > 0)
	{
		int itemsPerPage = height - 13;
		int totalPages = (list.getSize() + itemsPerPage - 1) / itemsPerPage;
		this->maxPage = totalPages - 1;
		if (this->pageIndex > this->maxPage) this->pageIndex = this->maxPage;
		else if (this->pageIndex < 0) this->pageIndex = 0;
		ConsolaUI::text(width / 2 - 10, 8, "TIM THAY " + to_string(list.getSize()) + " HOP DONG:", 10);
		ConsolaUI::text(width / 2 - 38, 9, "Ma HD", 7);			// 10
		ConsolaUI::text(width / 2 - 23, 9, "Ngay Bat Dau", 7);	// 10
		ConsolaUI::text(width / 2 - 8, 9, "Ngay Ket Thuc", 7);	// 10
		ConsolaUI::text(width / 2 + 7, 9, "Trang Thai", 7);	// 15
		ConsolaUI::text(width / 2 + 27, 9, "Phong", 7);		// 10
		ConsolaUI::text(width / 2 - 38, 10, "------------------------------------------------------------------------", 8);
		for (int i = 0; i < itemsPerPage; i++)
		{
			int yPos = 12 + i;
			if (i + this->pageIndex * itemsPerPage < list.getSize())
			{
				Contract* contract = *list.getAt(i + this->pageIndex * itemsPerPage);
				ConsolaUI::text(width / 2 - 38, yPos, to_string(contract->getContractId()), 15);
				ConsolaUI::text(width / 2 - 23, yPos, contract->getStartDate().getDate(), 15);
				ConsolaUI::text(width / 2 - 8, yPos, contract->getEndDate().getDate(), 15);
				ConsolaUI::text(width / 2 + 7, yPos, contract->isActive() ? "Con hieu luc" : "Da het han", contract->isActive() ? 10 : 12);
				ConsolaUI::text(width / 2 + 27, yPos, contract->getRoom()->getRoomName(), 15);
			}
			else break;
		}
		ConsolaUI::text(width / 2 - 6, height - 1, "Trang " + to_string(this->pageIndex + 1) + "/" + to_string(totalPages), 7); // 15
		ConsolaUI::text(width / 2 - 31, height - 1, "[ Q ] Trang Truoc", 3);	// 20
		ConsolaUI::text(width / 2 + 11, height - 1, "[ P ] Trang Sau", 3);		// 20
	}
}
void EmployeeView::showValidContracts(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 16, 7, ">>   XEM DANH SACH HOP DONG   <<", 14);
	LinkedList<Contract*> list = this->contractService->getActiveContracts();
	if (list.getSize() > 0)
	{
		int itemsPerPage = height - 13;
		int totalPages = (list.getSize() + itemsPerPage - 1) / itemsPerPage;
		this->maxPage = totalPages - 1;
		if (this->pageIndex > this->maxPage) this->pageIndex = this->maxPage;
		else if (this->pageIndex < 0) this->pageIndex = 0;
		ConsolaUI::text(width / 2 - 10, 8, "TIM THAY " + to_string(list.getSize()) + " HOP DONG:", 10);
		ConsolaUI::text(width / 2 - 38, 9, "Ma HD", 7);			// 10
		ConsolaUI::text(width / 2 - 23, 9, "Ngay Bat Dau", 7);	// 10
		ConsolaUI::text(width / 2 - 8, 9, "Ngay Ket Thuc", 7);	// 10
		ConsolaUI::text(width / 2 + 7, 9, "Trang Thai", 7);	// 15
		ConsolaUI::text(width / 2 + 27, 9, "Phong", 7);		// 10
		ConsolaUI::text(width / 2 - 38, 10, "------------------------------------------------------------------------", 8);
		for (int i = 0; i < itemsPerPage; i++)
		{
			int yPos = 11 + i;
			if (i + this->pageIndex * itemsPerPage < list.getSize())
			{
				Contract* contract = *list.getAt(i + this->pageIndex * itemsPerPage);
				ConsolaUI::text(width / 2 - 38, yPos, to_string(contract->getContractId()), 15);
				ConsolaUI::text(width / 2 - 23, yPos, contract->getStartDate().getDate(), 15);
				ConsolaUI::text(width / 2 - 8, yPos, contract->getEndDate().getDate(), 15);
				ConsolaUI::text(width / 2 + 7, yPos, contract->isActive() ? "Con hieu luc" : "Da het han", contract->isActive() ? 10 : 12);
				ConsolaUI::text(width / 2 + 27, yPos, contract->getRoom()->getRoomName(), 15);
			}
			else break;
		}
		ConsolaUI::text(width / 2 - 6, height - 1, "Trang " + to_string(this->pageIndex + 1) + "/" + to_string(totalPages), 7); // 15
		ConsolaUI::text(width / 2 - 31, height - 1, "[ Q ] Trang Truoc", 3);	// 20
		ConsolaUI::text(width / 2 + 11, height - 1, "[ P ] Trang Sau", 3);		// 20
	}
}