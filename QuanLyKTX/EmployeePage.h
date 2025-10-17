#pragma once
#include "EmployeeService.h"
#include "AccountService.h"
#include "StudentService.h"

class EmployeePage {
private:
	AccountService* accountService;
	EmployeeService* employeeService;
	StudentService* studentService;

	bool isRunning;

	string* menuList;
	int menuSize;
	int menuSelected;

	string* sidebarInfoList;
	int sidebarInfoSize;
	int sidebarInfoSelected;
	

	string* sidebarStudentList;
	int sidebarStudentSize;
	int sidebarStudentSelected;

	string* sidebarRoomList;
	int sidebarRoomSize;
	int sidebarRoomSelected;

	string* sidebarContractList;
	int sidebarContractSize;
	int sidebarContractSelected;

	string* sidebarInvoiceList;
	int sidebarInvoiceSize;
	int sidebarInvoiceSelected;

	int changePasswordSelected;
	string oldPass, newPass, reEnterNewPass;
	bool isChangePass;

	Student* studentToAct;
	int studentIDToSearch;
	int keyToSearchStudent;
	int keyToActStudent;
	bool isShowBoxDeleteStudent;
	bool isShowBoxUpdateStudent;
	bool isDeleteComplete;
	bool isUpdateComplete;

	Student* studentToAdd;
	int tempDay, tempMonth, tempYear;
	bool isAddStudentSucessfull;

public:
	EmployeePage(AccountService* ,EmployeeService*, StudentService*);
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

	void drawContractServiceContent(const int&, const int&);
	void drawSidebarContract(const int&, const int&);

	void drawInvoiceServiceContent(const int&, const int&);
	void drawSidebarInvoice(const int&, const int&);

	

	void handleArrowLR(int, int&, const int&);
	void handleArrowUD(int, int&, const int&);
	void handleNormalKeys(int, int&);
	string GetLine();
	int GetInt();
};