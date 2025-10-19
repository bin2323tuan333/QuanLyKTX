#pragma once
#include "StudentService.h"
#include "ManageViewBase.h"

class StudentManageView : public ManageViewBase
{
private:
    StudentService* studentService;

    string* sidebarStudentList;
    int sidebarStudentSize;
    int sidebarStudentSelected;

    Student* studentToAct;
    int studentIDToSearch;
    bool isShowBoxDeleteStudent;
    bool isShowBoxUpdateStudent;
    bool isDeleteComplete;
    bool isUpdateComplete;

    Student* studentToAdd;
    int tempDay, tempMonth, tempYear;
    bool isAddStudentSucessfull;
    Student studentToUpdate;

public:
    StudentManageView(StudentService*);
    ~StudentManageView();

    void show() override;
    void handleInput(int) override;

private:
    void drawStudentServiceContent(const int&, const int&);
    void drawSidebarStudent(const int&, const int&);
    string GetLine();
    int GetInt();
};