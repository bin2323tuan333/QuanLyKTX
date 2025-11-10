#pragma once
#include "BaseView.h"
#include "AuthService.h"
#include "UserService.h"
#include "RoomService.h"
#include "BillingService.h"
#include "ContractService.h"

class EmployeeView : public BaseView
{
private:
	Account*& user;
	AuthService* authService;
	UserService* userService;
	RoomService* roomService;
	BillingService* billingService;
	ContractService* contractService;
	int menuChoice;
	void handleInput() override;
	void showHeader(const int&, const int&);

	// Menu
	int choiceToAct;
	bool isShow;
	bool isLogout;

	// Info
	void showInfoMenu(const int&, const int&);
	void showInfo(const int&, const int&);
	void showChangePass(const int&, const int&);
	string oldPass, newPass, reNewPass;
	int changePassError;

	// Student
	void showStudentMenu(const int&, const int&);
	int maxPage, pageIndex;
	void showAllStudents(const int&, const int&);
	int studentId, preStudentId;
	bool isDelete;
	bool isUpdate;
	void showFindStudent(const int&, const int&);
	int currentIndex;
	Student studentToAct;
	bool isDateEdit;
	int dateIndex;
	void showAddStudent(const int&, const int&);
	void showStudentsNotRegister(const int&, const int&);

	// Room
	void showRoomMenu(const int&, const int&);
	void showAllRooms(const int&, const int&);
	int roomId;
	Room roomToAct;
	void showFindRoomById(const int&, const int&);
	void showFindVacantRooms(const int&, const int&);
	void showFindAvailableRooms(const int&, const int&);

	// Invoice
	void showInvoiceMenu(const int&, const int&);
	void showAllInvoices(const int&, const int&);
	int elecNum, waterNum, interNum;
	void showCreateNewInvoice(const int&, const int&);
	void showFindInvoicesByStudentId(const int&, const int&);
	int invoiceId;
	void showFindInvoiceById(const int&, const int&);
	void showUnpaidInvoices(const int&, const int&);
	void showPaidInvoices(const int&, const int&);

	// Contract
	void showContractMenu(const int&, const int&);
	void showAllContracts(const int&, const int&);
	int cycle;
	void showCreateContract(const int&, const int&);
	void showFindContractsByStudentId(const int&, const int&);
	int contractId;
	void showFindContractById(const int&, const int&);
	void showInvalidContracts(const int&, const int&);
	void showValidContracts(const int&, const int&);

public:
	EmployeeView(Account*&, AuthService*, UserService*, RoomService*, BillingService*, ContractService*);
	virtual ~EmployeeView();

	int show() override;
};

