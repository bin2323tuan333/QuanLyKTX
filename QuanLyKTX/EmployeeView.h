#pragma once
#include "BaseView.h"


class IAccount;
class IStudent;
class IRoom;
class IInvoice;
class IAuthService;
class IUserService;
class IRoomService;
class IBillingService;
class IContractService;
class EmployeeView : public BaseView
{
private:
	IAccount* user;
	IAuthService* authService;
	IUserService* userService;
	IRoomService* roomService;
	IBillingService* billingService;
	IContractService* contractService;


	int menuChoice, choiceToAct, error, changePassError, maxPage, pageIndex, currentIndex, dateIndex;
	int invoiceId, studentId, preStudentId, roomId;
	int cycle, elecNum, waterNum, interNum;
	int contractId;
	bool isShow, isLogout, isDelete, isUpdate, isDateEdit, isPaid;
	string oldPass, newPass, reNewPass;
	IStudent* studentToAct;
	IInvoice* invToPay;
	IRoom* roomToAct;


	void handleInput() override;
	void showHeader(const int&, const int&);
	void showInfoMenu(const int&, const int&);
	void showInfo(const int&, const int&);
	void showChangePass(const int&, const int&);
	void showStudentMenu(const int&, const int&);
	void showAllStudents(const int&, const int&);
	void showFindStudent(const int&, const int&);
	void showAddStudent(const int&, const int&);
	void showStudentsNotRegister(const int&, const int&);
	void showRoomMenu(const int&, const int&);
	void showAllRooms(const int&, const int&);
	void showFindRoomById(const int&, const int&);
	void showFindVacantRooms(const int&, const int&);
	void showFindAvailableRooms(const int&, const int&);
	void showInvoiceMenu(const int&, const int&);
	void showAllInvoices(const int&, const int&);
	void showCreateNewInvoice(const int&, const int&);
	void showFindInvoicesByStudentId(const int&, const int&);
	void showFindInvoiceById(const int&, const int&);
	void showUnpaidInvoices(const int&, const int&);
	void showPaidInvoices(const int&, const int&);
	void showContractMenu(const int&, const int&);
	void showAllContracts(const int&, const int&);
	void showCreateContract(const int&, const int&);
	void showFindContractsByStudentId(const int&, const int&);
	void showFindContractById(const int&, const int&);
	void showInvalidContracts(const int&, const int&);
	void showValidContracts(const int&, const int&);

public:
	EmployeeView(IAccount*, IAuthService*, IUserService*, IRoomService*, IBillingService*, IContractService*);
	virtual ~EmployeeView();

	int show() override;
};

