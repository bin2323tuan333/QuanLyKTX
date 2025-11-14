#include "StudentView.h"
#include "IAuthService.h"
#include "IUserService.h"
#include "IBillingService.h"
#include "IRoomService.h"
#include "IContractService.h"
#include "Account.h" 
#include "Student.h"
#include "Employee.h"
#include "Invoice.h"
#include "Contract.h"
#include "DB.h"

StudentView::StudentView(IAccount* user, IAuthService* auth, IUserService* userService, IRoomService* roomService, IBillingService* billing, IContractService* con)
	:user(user), authService(auth), userService(userService), roomService(roomService), billingService(billing), contractService(con)
{
	this->menuChoice = 0;
	this->choiceToAct = 0;
	this->isShow = false;
	this->isLogout = false;
	this->isUpdate = false;
	this->error = -1;
	this->currentIndex = 1;
	this->isDateEdit = false;
	this->dateIndex = 1;
	this->preId = 0;
	this->isPaid = false;
	this->isCreate = false;
}
StudentView::~StudentView()
{
}
int StudentView::show()
{
	if (this->menuChoice < 0) this->menuChoice = 3;
	else if (this->menuChoice > 3) this->menuChoice = 0;
	this->showHeader(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
	switch (this->menuChoice)
	{
	case 0:
	{
		if (this->isShow == false)
		{
			showInfoMenu(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
		}
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
		showRoomInfo(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
	}
	break;
	case 2:
	{
		showInvoiceList(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
	}
	break;
	case 3:
	{
		showContractList(ConsolaUI::getConsoleWidth(), ConsolaUI::getConsoleHeight());
	}
	break;
	}
	handleInput();
	if (this->isLogout) return 2;
	return 1;
}
void StudentView::handleInput()
{
	if (menuChoice != 0) this->isShow = true;
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
				this->preId = 0;
			}
			else if (tempKey == 77)						// Nut Sang Phai
			{
				this->menuChoice++;
				this->isShow = false;
				this->choiceToAct = 0;
				this->preId = 0;
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
			Date tempDate = this->studentToAct->getDateOfBirth();
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
			this->studentToAct->setDateOfBirth(tempDate);
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
		if (choiceToAct == 0)
		{
			if (key == 13)
			{
				switch (this->currentIndex)
				{
				case 1:
				{
					ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 2, "                        ", 15);
					ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 2);
					this->studentToAct->setFullName(ConsolaUI::GetLine());
					break;
				}
				case 2:
				{
					this->isDateEdit = !this->isDateEdit;
					break;
				}
				case 3:
				{
					this->studentToAct->setGender(!this->studentToAct->getGender());
					break;
				}
				case 4:
				{
					ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 5, "                        ", 15);
					ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 5);
					this->studentToAct->setStudentId(ConsolaUI::GetInt());
					break;
				}
				case 5:
				{
					ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 6, "                        ", 15);
					ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 6);
					this->studentToAct->setClassName(ConsolaUI::GetLine());
					break;
				}
				case 6:
				{
					ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 7, "                        ", 15);
					ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 7);
					this->studentToAct->setFaculty(ConsolaUI::GetLine());
					break;
				}
				case 7:
				{
					ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 8, "                        ", 15);
					ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 8);
					this->studentToAct->setPhoneNumber(ConsolaUI::GetLine());
					break;
				}
				case 8:
				{
					ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 9, "                        ", 15);
					ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 9);
					this->studentToAct->setEmail(ConsolaUI::GetLine());
					break;
				}
				}
			}
			else if (key == 'x' || key == 'X')
			{
				this->isUpdate = true;
				this->preId = this->studentToAct->getStudentId();
			}
			else if (key == 'y' || key == 'Y')
			{
				this->error = this->userService->updateStudent(this->preId, *this->studentToAct);
				this->isUpdate = false;
			}
			else if (key == 'N' || key == 'n')
			{
				this->isUpdate = false;
			}
		}
		else if (choiceToAct == 1 && this->isShow == true)
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
	else if (this->menuChoice == 2)

	{
		if (key == 'f' || key == 'F')
		{
			ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2 + 2, 9, "                     ", 15);
			ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2 + 2, 9);
			this->preId = ConsolaUI::GetInt();
		}
		else if (this->isPaid == false && (key == 'y' || key == 'Y'))
		{
			this->isPaid = true;
		}
		else if (key == 't' || key == 'T')
		{
			this->billingService->printInvoice(*this->invToPay);
		}
		else if (this->isPaid == true && (key == 'y' || key == 'Y'))
		{
			this->isPaid = false;
			this->billingService->paidInvoice(*this->invToPay);
		}
	}
	else if (this->menuChoice == 3)
	{
		if (key == 'd' || key == 'D')
		{
			this->isCreate = true;
		}
		else if (key == 'y' || key == 'Y')
		{
			IStudent* temp = dynamic_cast<IStudent*>(this->user->getUser());
			this->error = this->contractService->createContract(temp->getStudentId(), this->roomId, this->cycle);
			if (this->error == 1) this->isCreate = false;
		}
		else if (key == 'n' || key == 'N')
		{
			this->isCreate = false;
		}
		if (key == 13 && this->isCreate)
		{
			switch (this->currentIndex)
			{
			case 2:
			{
				ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 6, "               ", 15);
				ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 6);
				this->roomId = ConsolaUI::GetInt();
			}
			break;
			case 3:
			{
				ConsolaUI::text(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 10, "               ", 15);
				ConsolaUI::gotoXY(ConsolaUI::getConsoleWidth() / 2, ConsolaUI::getConsoleHeight() / 2 + 10);
				this->cycle = ConsolaUI::GetInt();
			}
			break;
			}
		}
	}
	if (this->isShow == false)
	{
		this->studentToAct = nullptr;
	}
}

void StudentView::showHeader(const int& width, const int& height)
{
	ConsolaUI::text(12, 2, "HE THONG QUAN LY KI TUC XA", 13);
	ConsolaUI::drawBox(1, 3, width - 1, 2, 7);
	ConsolaUI::text((width - 2) / 8 - 5, 4, "THONG TIN", menuChoice == 0 ? 1 : 8);
	ConsolaUI::text(3 * (width - 2) / 8 - 3, 4, "PHONG", menuChoice == 1 ? 1 : 8);
	ConsolaUI::text(5 * (width - 2) / 8 - 3, 4, "HOA DON", menuChoice == 2 ? 1 : 8);
	ConsolaUI::text(7 * (width - 2) / 8 - 4, 4, "HOP DONG", menuChoice == 3 ? 1 : 8);
}
void StudentView::showInfoMenu(const int& width, const int& height)
{
	ConsolaUI::drawBox(width / 2 - 19, height / 2 - 3, 39, 10, 15);
	ConsolaUI::text(width / 2 - 3, height / 2 - 3, " MENU ", 15);
	ConsolaUI::text(width / 2 - 9, height / 2, "THONG TIN CA NHAN", this->choiceToAct == 0 ? 3 : 15);
	ConsolaUI::text(width / 2 - 9, height / 2 + 1, "DOI MAT KHAU", this->choiceToAct == 1 ? 3 : 15);
	ConsolaUI::text(width / 2 - 9, height / 2 + 2, "DANG XUAT", this->choiceToAct == 2 ? 3 : 15);
	ConsolaUI::text(width / 2 - 13, height / 2 + this->choiceToAct, ">>", 3);
	ConsolaUI::text(width / 2 + 13, height / 2 + this->choiceToAct, "<<", 3);
}
void StudentView::showInfo(const int& width, const int& height)
{

	IStudent* temp = dynamic_cast<IStudent*>(this->user->getUser());
	if (!this->isUpdate)
		this->studentToAct = temp;
	if (this->isUpdate)
	{
		if (this->currentIndex > 8) this->currentIndex = 1;
		else if (this->currentIndex < 1) this->currentIndex = 8;
		ConsolaUI::drawBox(width / 2 - 30, height / 2, 60, 12, 8);
		for (int i = 1; i < 12; i++)
			ConsolaUI::text(width / 2 - 29, height / 2 + i, "                                                         ", 15);
		if (this->error == 4)
			ConsolaUI::text(width / 2 - 12, height / 2 - 1, "Du lieu khong hop le!", 15);
		else if (this->error == 5)
			ConsolaUI::text(width / 2 - 12, height / 2 - 1, "Id moi da ton tai trong he thong!", 15);
		ConsolaUI::text(width / 2 - 12, height / 2 + 1, "** CAP NHAT THONG TIN **", 15);
		ConsolaUI::text(width / 2 - 25, height / 2 + 2, "Ho va ten       :", this->currentIndex == 1 ? 3 : 15);
		ConsolaUI::text(width / 2 - 25, height / 2 + 3, "Ngay sinh       :", this->currentIndex == 2 ? 3 : 15);
		ConsolaUI::text(width / 2 - 25, height / 2 + 4, "Gioi tinh       :", this->currentIndex == 3 ? 3 : 15);
		ConsolaUI::text(width / 2 - 25, height / 2 + 5, "Ma so sinh vien :", this->currentIndex == 4 ? 3 : 15);
		ConsolaUI::text(width / 2 - 25, height / 2 + 6, "Lop             :", this->currentIndex == 5 ? 3 : 15);
		ConsolaUI::text(width / 2 - 25, height / 2 + 7, "Khoa            :", this->currentIndex == 6 ? 3 : 15);
		ConsolaUI::text(width / 2 - 25, height / 2 + 8, "So dien thoai   :", this->currentIndex == 7 ? 3 : 15);
		ConsolaUI::text(width / 2 - 25, height / 2 + 9, "Email           :", this->currentIndex == 8 ? 3 : 15);

		ConsolaUI::text(width / 2, height / 2 + 2, this->studentToAct->getFullName() == "" ? "__________" : this->studentToAct->getFullName(), 15);
		ConsolaUI::text(width / 2, height / 2 + 3, (this->studentToAct->getDateOfBirth().getDay() < 10 ? "0" : "") + to_string(this->studentToAct->getDateOfBirth().getDay()) + "/", this->isDateEdit == true ? (this->dateIndex == 1 ? 10 : 15) : 15);
		ConsolaUI::text(width / 2 + 3, height / 2 + 3, (this->studentToAct->getDateOfBirth().getMonth() < 10 ? "0" : "") + to_string(this->studentToAct->getDateOfBirth().getMonth()) + "/", this->isDateEdit == true ? (this->dateIndex == 2 ? 10 : 15) : 15);
		ConsolaUI::text(width / 2 + 6, height / 2 + 3, to_string(this->studentToAct->getDateOfBirth().getYear()), this->isDateEdit == true ? (this->dateIndex == 3 ? 10 : 15) : 15);
		ConsolaUI::text(width / 2, height / 2 + 4, this->studentToAct->getGender() == true ? "Nam" : "Nu", 15);
		ConsolaUI::text(width / 2, height / 2 + 5, this->studentToAct->getStudentId() == 0 ? "__________" : to_string(this->studentToAct->getStudentId()), 15);
		ConsolaUI::text(width / 2, height / 2 + 6, this->studentToAct->getClassName() == "" ? "__________" : this->studentToAct->getClassName(), 15);
		ConsolaUI::text(width / 2, height / 2 + 7, this->studentToAct->getFaculty() == "" ? "__________" : this->studentToAct->getFaculty(), 15);
		ConsolaUI::text(width / 2, height / 2 + 8, this->studentToAct->getPhoneNumber() == "" ? "__________" : this->studentToAct->getPhoneNumber(), 15);
		ConsolaUI::text(width / 2, height / 2 + 9, this->studentToAct->getEmail() == "" ? "__________" : this->studentToAct->getEmail(), 15);
		ConsolaUI::text(width / 2 - 17, height / 2 + 11, "[Y] Yes - Cap Nhat    [N] No - Huy", 15);
		return;
	}
	ConsolaUI::text(width / 2 - 18, 7, ">>   THONG TIN CA NHAN (NHAN VIEN)   <<", 14);
	ConsolaUI::drawBox(width / 2 - 30, 9, 60, 14, 8);
	ConsolaUI::text(width / 2 - 28, 10, "Thong tin dinh danh:", 11);
	ConsolaUI::text(width / 2 - 27, 12, "Ho Va Ten: ", 7);
	ConsolaUI::text(width / 2, 12, temp->getFullName(), 15);
	ConsolaUI::text(width / 2 - 27, 13, "Ma Sinh Vien: ", 7);
	ConsolaUI::text(width / 2, 13, to_string(temp->getStudentId()), 15);
	ConsolaUI::text(width / 2 - 27, 14, "Ngay Sinh: ", 7);
	ConsolaUI::gotoXY(width / 2, 14); ConsolaUI::setTextColor(15); cout << temp->getDateOfBirth();
	ConsolaUI::text(width / 2 - 27, 15, "Gioi Tinh: ", 7);
	ConsolaUI::text(width / 2, 15, temp->getGender() == true ? "Nam" : "Nu", 15);
	ConsolaUI::text(width / 2 - 28, 17, "---------------------------------------------", 8);
	ConsolaUI::text(width / 2 - 28, 18, "Thong tin lien he:", 11);
	ConsolaUI::text(width / 2 - 27, 19, "Lop: ", 7);
	ConsolaUI::text(width / 2, 19, temp->getClassName(), 15);
	ConsolaUI::text(width / 2 - 27, 20, "Khoa: ", 7);
	ConsolaUI::text(width / 2, 20, temp->getFaculty(), 15);
	ConsolaUI::text(width / 2 - 27, 21, "Email: ", 7);
	ConsolaUI::text(width / 2, 21, temp->getEmail(), 15);
	ConsolaUI::text(width / 2 - 27, 22, "So Dien Thoai: ", 7);
	ConsolaUI::text(width / 2, 22, temp->getPhoneNumber(), 15);
	ConsolaUI::text(width / 2, 25, "[X] Chinh sua thong tin", 15);
}
void StudentView::showChangePass(const int& width, const int& height)
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

void StudentView::showRoomInfo(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 13, 7, ">>   THONG TIN PHONG   <<", 14);
	IStudent* temp = dynamic_cast<IStudent*>(this->user->getUser());
	IRoom* roomToShow = this->roomService->getRoomByStudentId(temp->getStudentId());
	if (roomToShow == nullptr)
	{
		ConsolaUI::text(width / 2 - 20, 8, "Sinh vien can dang ky hop dong de vao o!", 15);
		return;
	}
	ConsolaUI::drawBox(width / 2 - 30, height / 2 - 4, 50, 8, 7);
	int yPos = height / 2 - 2;
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
}
void StudentView::showInvoiceList(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 14, 7, ">>   DANH SACH HOA DON   <<", 14);
	ConsolaUI::text(width / 2 - 25, 9, "[F] Nhap Ma Hoa Don:", 15);
	ConsolaUI::drawBox(width / 2, 8, 25, 2, 15);
	if (this->preId != 0)
	{
		IInvoice* invToShow = this->billingService->getInvoiceById(this->preId);
		if (invToShow == nullptr && this->preId != 0)
		{
			ConsolaUI::text(width / 2 - 15, 11, "Ban Khong Co Quyen Truy Cap!", 12);
		}
		else
		{
			this->invToPay = invToShow;
			if (this->isPaid)
			{
				ConsolaUI::drawBox(width / 2 - 16, height / 2, 32, 12, 15);
				ConsolaUI::text(width / 2 - 6, height / 2 + 1, "QR to Scan", 15);
				ConsolaUI::text(width / 2 - 13, height / 2 + 2, "*************************", 15);
				ConsolaUI::text(width / 2 - 13, height / 2 + 3, "* ** * * ** * **** * ** *", 15);
				ConsolaUI::text(width / 2 - 13, height / 2 + 4, "* ** * *****  * *  * ** *", 15);
				ConsolaUI::text(width / 2 - 13, height / 2 + 5, "****** **  **** ** ******", 15);
				ConsolaUI::text(width / 2 - 13, height / 2 + 6, "**  **** *** **  ** **** ", 15);
				ConsolaUI::text(width / 2 - 13, height / 2 + 7, "******  **** *   ****  **", 15);
				ConsolaUI::text(width / 2 - 13, height / 2 + 8, "* ** ** * * * * * * * * *", 15);
				ConsolaUI::text(width / 2 - 13, height / 2 + 9, "* ** **   ****  **     **", 15);
				ConsolaUI::text(width / 2 - 13, height / 2 + 10, "*************************", 15);
				ConsolaUI::text(width / 2 - 13, height / 2 + 14, "[Y] - Xac Nhan.", 15);
				return;

			}
			int yPos = height / 2;
			int xLabel = width / 2 - 25;
			int xValue = width / 2;
			ConsolaUI::drawBox(width / 2 - 30, height / 2, 60, 13, 8);
			ConsolaUI::text(xLabel, yPos + 1, "Ma Hoa Don:", 15);
			ConsolaUI::text(xValue, yPos + 1, to_string(invToShow->getInvoiceId()), 15);
			ConsolaUI::text(xLabel, yPos + 2, "Phong:", 15);
			ConsolaUI::text(xValue, yPos + 2, to_string(invToShow->getContract()->getRoomId()), 15);
			ConsolaUI::text(xLabel, yPos + 3, "Ma Sinh Vien:", 15);
			ConsolaUI::text(xValue, yPos + 3, to_string(invToShow->getContract()->getStudentId()), 15);
			ConsolaUI::text(xLabel, yPos + 4, "-------------------------------------------------", 15);
			ConsolaUI::text(xLabel, yPos + 5, "Tien Phong:", 15);
			ConsolaUI::text(xValue, yPos + 5, to_string(invToShow->getRoomFee()) + " VND", 15);
			ConsolaUI::text(xLabel, yPos + 6, "Tien Dien:", 15);
			ConsolaUI::text(xValue, yPos + 6, to_string(invToShow->getElectricFee()) + " VND", 15);
			ConsolaUI::text(xLabel, yPos + 7, "Tien Nuoc", 15);
			ConsolaUI::text(xValue, yPos + 7, to_string(invToShow->getWaterFee()) + " VND", 15);
			ConsolaUI::text(xLabel, yPos + 8, "Tien Internet:", 15);
			ConsolaUI::text(xValue, yPos + 8, to_string(invToShow->getInternetFee()) + " VND", 15);
			ConsolaUI::text(xLabel, yPos + 9, "-------------------------------------------------", 15);
			ConsolaUI::text(xLabel, yPos + 10, "Tong Tien:", 15);
			ConsolaUI::text(xValue, yPos + 10, to_string(invToShow->getTotalAmount()) + " VND", 15);
			ConsolaUI::text(xLabel, yPos + 11, "Ngay Lap Hoa Don:", 15);
			ConsolaUI::text(xValue, yPos + 11, invToShow->getCreatedDate().getDate(), 15);
			ConsolaUI::text(xLabel, yPos + 12, "Trang Thai:", 15);
			ConsolaUI::text(xValue, yPos + 12, invToShow->getIsPaid() ? "Da Thanh Toan" : "Chua Thanh Toan", invToShow->getIsPaid() ? 10 : 7);
			ConsolaUI::text(width / 2 - 20, height / 2 + 14, "[T] - In Hoa Don       [Y] - Thanh Toan", 7);
			return;
		}
	}
	IStudent* temp = dynamic_cast<IStudent*>(this->user->getUser());
	LinkedList<IInvoice*> invoices = this->billingService->getInvoicesByStudent(temp->getStudentId());
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
	ConsolaUI::text(width / 2 - 30, 12, "Ma Hoa Don", 11);			// 10
	ConsolaUI::text(width / 2 - 15, 12, "So Tien", 11);				// 10
	ConsolaUI::text(width / 2, 12, "Ngay Lap", 11);					// 10
	ConsolaUI::text(width / 2 + 15, 12, "Trang Thai", 11);			// 10
	ConsolaUI::text(width / 2 - 30, 13, "-----------------------------------------------------------", 15);
	for (int i = 0; i < itemsPerPage; i++)
	{
		int yPos = 14 + i;
		if (i + this->pageIndex * itemsPerPage < invoices.getSize())
		{
			IInvoice* invoice = *invoices.getAt(i + this->pageIndex * itemsPerPage);
			ConsolaUI::text(width / 2 - 30, yPos, to_string(invoice->getInvoiceId()), 15);
			ConsolaUI::text(width / 2 - 15, yPos, to_string(invoice->getTotalAmount()), 15);
			ConsolaUI::text(width / 2, yPos, invoice->getCreatedDate().getDate(), 15);
			ConsolaUI::text(width / 2 + 15, yPos, invoice->getIsPaid() ? "Da thanh toan" : "Chua thanh toan", invoice->getIsPaid() ? 10 : 12);
		}
		else break;
	}
	ConsolaUI::text(width / 2 - 6, height - 1, "Trang " + to_string(this->pageIndex + 1) + "/" + to_string(totalPages), 7); // 15
	ConsolaUI::text(width / 2 - 31, height - 1, "[ Q ] Trang Truoc", 3);	// 20
	ConsolaUI::text(width / 2 + 11, height - 1, "[ P ] Trang Sau", 3);		// 20

}
void StudentView::showContractList(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 15, 7, ">>   DANH SACH HOP DONG   <<", 14);
	Student* temp = dynamic_cast<Student*>(this->user->getUser());
	LinkedList<IContract*>* contracts = this->contractService->getContractsByStudent(temp->getStudentId());
	if (contracts->getSize() == 0)
	{
		ConsolaUI::text(35, 9, ">> Sinh Vien Chua Co Hop Dong <<", 12);
		return;
	}
	if (this->isCreate)
	{
		if (this->currentIndex < 2) this->currentIndex = 3;
		else if (this->currentIndex > 3) this->currentIndex = 2;
		bool canSave = true, isValid = false;
		if (this->error == 2)
			ConsolaUI::text(width / 2 - 10, height / 2 - 1, "Phong Day Sinh Vien", 12);
		ConsolaUI::drawBox(width / 2 - 30, height / 2, 60, 12, 8);
		ConsolaUI::text(width / 2 - 25, height / 2 + 2, "[*] Ma Sinh Vien:", 15);
		ConsolaUI::text(width / 2 - 25 + 4, height / 2 + 3, "Ten Sinh Vien:", 15);
		ConsolaUI::text(width / 2 - 25 + 4, height / 2 + 4, "Ngay Sinh:", 15);
		ConsolaUI::text(width / 2 - 25 + 4, height / 2 + 5, "Gioi Tinh:", 15);
		ConsolaUI::text(width / 2 - 25, height / 2 + 6, "[*] Ma Phong:", this->currentIndex == 2 ? 9 : 15);
		ConsolaUI::text(width / 2 - 25 + 4, height / 2 + 7, "Ten Phong:", 15);
		ConsolaUI::text(width / 2 - 25 + 4, height / 2 + 8, "So Nguoi Hien Tai:", 15);
		ConsolaUI::text(width / 2 - 25, height / 2 + 9, "Loai Phong", 15);
		ConsolaUI::text(width / 2 - 25, height / 2 + 10, "[*] Thoi Han (So Thang):", this->currentIndex == 3 ? 9 : 15);
		ConsolaUI::text(width / 2, height / 2 + 2, to_string(temp->getStudentId()), 15);
		ConsolaUI::text(width / 2, height / 2 + 3, temp->getFullName(), 15);
		ConsolaUI::text(width / 2, height / 2 + 4, temp->getDateOfBirth().getDate(), 15);
		ConsolaUI::text(width / 2, height / 2 + 5, temp->getGender() ? "Nam" : "Nu", 15);
		IRoom* room = this->roomService->getRoomById(this->roomId);
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
		ConsolaUI::text(width / 2, height / 2 + 6, to_string(this->roomId), isValid ? 10 : 15);
		ConsolaUI::text(width / 2, height / 2 + 10, to_string(this->cycle), 15);
		if (this->cycle <= 0) canSave = false;
		ConsolaUI::text(width / 2 - 25, height / 2 + 11, "[Y] Luu Hop Dong", canSave ? 10 : 8);
		ConsolaUI::text(width / 2, height / 2 + 11, "[N] Huy Bo", 12);
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
	ConsolaUI::text(width / 2 - 38, 10, "------------------------------------------------------------------------", 15);
	for (int i = 0; i < itemsPerPage; i++)
	{
		int yPos = 11 + i;
		int currentIndex = i + this->pageIndex * itemsPerPage;
		if (currentIndex < contracts->getSize())
		{
			IContract* contract = *contracts->getAt(currentIndex);
			if (contract != nullptr)
			{
				ConsolaUI::text(width / 2 - 38, yPos, to_string(contract->getContractId()), 15);
				ConsolaUI::text(width / 2 - 23, yPos, contract->getStartDate().getDate(), 15);
				ConsolaUI::text(width / 2 - 8, yPos, contract->getEndDate().getDate(), 15);
				ConsolaUI::text(width / 2 + 7, yPos, contract->isActive() ? "Con hieu luc" : "Da het han", contract->isActive() ? 10 : 12);
				ConsolaUI::text(width / 2 + 27, yPos, to_string(contract->getRoomId()), 15);
			}
		}
		else break;
	}
	ConsolaUI::text(width / 2 - 25, height - 2, "[D] Dang ky / Gia han hop dong", 15);
	ConsolaUI::text(width / 2 - 6, height - 1, "Trang " + to_string(this->pageIndex + 1) + "/" + to_string(totalPages), 7); // 15
	ConsolaUI::text(width / 2 - 31, height - 1, "[ Q ] Trang Truoc", 3);	// 20
	ConsolaUI::text(width / 2 + 11, height - 1, "[ P ] Trang Sau", 3);		// 20
}