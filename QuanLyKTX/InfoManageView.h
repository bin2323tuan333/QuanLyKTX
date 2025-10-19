#pragma once
#include "ManageViewBase.h"
#include "AccountService.h"
#include "EmployeeService.h"

class InfoManageView : public ManageViewBase
{
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

    void show() override;
    void handleInput(int) override;

private:
    void drawInfomationContent(const int&, const int&);
    void drawSidebarInfomation(const int&, const int&);
    string GetLine();
};