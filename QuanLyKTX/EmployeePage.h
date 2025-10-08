#pragma once
#include "EmployeeService.h"
#include "AccountService.h"

class EmployeePage {
private:
	AccountService* accountService;
	EmployeeService* employeeService;

	bool isRunning;

	string* menuList;
	int menuSize;
	int menuSelected;

	string* sidebarInfoList;
	int sidebarInfoSize;
	int sidebarInfoSelected;

public:
	EmployeePage(AccountService* ,EmployeeService*);
	~EmployeePage();

	void show();

private:
	void drawEmployeePage();
	void drawHeader(const int&, const int&);
	void drawMenuItems(const int&, const int&);
	void drawFooter(const int&, const int&);


	void drawInfomationContent(const int&, const int&);
	void drawSidebarInfomation(const int&, const int&);

	void drawStudentServiceContent(const int&, const int&);
	void drawSidebarStudent(const int&, const int&);

	void drawRoomServiceContent(const int&, const int&);
	void drawSidebarRoom(const int&, const int&);

	void drawInvoiceServiceContent(const int&, const int&);
	void drawSidebarInvoice(const int&, const int&);

	void drawRegisterServiceContent(const int&, const int&);
	void drawSidebarRegister(const int&, const int&);

	void handleArrowLR(int, int&, const int&);
	void handleArrowUD(int, int&, const int&);
	void handleNormalKeys(int, int&, const int&);
};