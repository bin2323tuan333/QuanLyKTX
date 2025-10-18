#pragma once
#include "AccountService.h"
#include "EmployeeService.h"

class InfoManageView {
private:
    AccountService* accountService;
    EmployeeService* employeeService;

    string* sidebarInfoList;
    int sidebarInfoSize;
    int sidebarInfoSelected;

    int changePasswordSelected;
    string oldPass, newPass, reEnterNewPass;
    int isError;

public:
    InfoManageView(AccountService*, EmployeeService*);
    ~InfoManageView();

    void show();
    void handleInput(int);

private:
    void draw();
    void drawInfomationContent(const int&, const int&);
    void drawSidebarInfomation(const int&, const int&);
    string GetLine();
};