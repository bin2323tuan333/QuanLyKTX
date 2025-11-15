#pragma once
#include "BaseView.h"

class Account;
class Student;
class Invoice;
class IAuthService;
class IUserService;
class IRoomService;
class IBillingService;
class IContractService;
class StudentView : public BaseView
{
private:
	Account* user;
	IAuthService* authService;
	IUserService* userService;
	IRoomService* roomService;
	IBillingService* billingService;
	IContractService* contractService;


	int menuChoice, choiceToAct, changePassError, pageIndex, currentIndex, dateIndex, preId, error, maxPage, roomId, cycle;
	bool isDateEdit, isShow, isLogout, isPaid, isUpdate, isCreate;
	string oldPass, newPass, reNewPass;
	Student* studentToAct;
	Invoice* invToPay;


	void showHeader(const int&, const int&);
	void showInfoMenu(const int&, const int&);
	void showInfo(const int&, const int&);
	void showChangePass(const int&, const int&);
	void showRoomInfo(const int&, const int&);
	void showInvoiceList(const int&, const int&);
	void showContractList(const int&, const int&);
public:
	StudentView(Account*, IAuthService*, IUserService*, IRoomService*, IBillingService*, IContractService*);
	~StudentView();

	int show() override;
	void handleInput() override;
};



