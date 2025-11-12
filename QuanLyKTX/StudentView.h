#pragma once
#include "BaseView.h"
#include "AuthService.h"
#include "UserService.h"
#include "RoomService.h"
#include "BillingService.h"
#include "ContractService.h"

class StudentView : public BaseView
{
private:
	Account*& user;
	AuthService* authService;
	UserService* userService;
	RoomService* roomService;
	BillingService* billingService;
	ContractService* contractService;


	int menuChoice, choiceToAct, changePassError, pageIndex, currentIndex, dateIndex, preId, error, maxPage, roomId, cycle;
	bool isDateEdit, isShow, isLogout, isPaid, isUpdate, isCreate;
	Student studentToAct;
	Invoice invToPay;
	void showHeader(const int&, const int&);
	void showInfoMenu(const int&, const int&);
	void showInfo(const int&, const int&);
	void showChangePass(const int&, const int&);
	string oldPass, newPass, reNewPass;
	void showRoomInfo(const int&, const int&);
	void showInvoiceList(const int&, const int&);
	void showContractList(const int&, const int&);
public:
	StudentView(Account*&, AuthService*, UserService*, RoomService*, BillingService*, ContractService*);
	~StudentView();

	int show() override;
	void handleInput() override;
};



