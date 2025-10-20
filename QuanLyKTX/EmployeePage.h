#pragma once
#include "ManageViewBase.h"
#include "EmployeeService.h"
#include "AccountService.h"
#include "StudentService.h"
#include "RoomService.h"
#include "InfoManageView.h"
#include "StudentManageView.h"
#include "RoomManageView.h"
#include "InvoiceManageView.h"
#include "ContractManageView.h"

class EmployeePage {
private:
	AccountService* accountService;
	EmployeeService* employeeService;
	StudentService* studentService;
	RoomService* roomService;
	InvoiceService* invoiceService;
	ContractService* contractService;

	ManageViewBase* currentView;

	bool isRunning;
	string* menuList;
	int menuSize;
	int menuSelected;
public:
	EmployeePage(
		AccountService*,
		EmployeeService*,
		StudentService*,
		RoomService*,
		InvoiceService*,
		ContractService*
		);
	~EmployeePage();

	void show();

private:
	void drawEmployeePage();
	void drawHeader(const int&, const int&);
	void drawMenuItems(const int&, const int&);
	void drawFooter(const int&, const int&);

	void handleArrowLR(int, int&, const int&);
	string GetLine();
	int GetInt();
};