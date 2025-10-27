#pragma once
#include "StudentService.h"
#include "RoomService.h"
#include "InvoiceService.h"

class StudentPage {
private:
    StudentService* studentService;
    RoomService* roomService;
    InvoiceService* invoiceService;
    string currentStudentId;

public:
    StudentPage();
    ~StudentPage();

    void setServices(StudentService*, RoomService*, InvoiceService*);
    void setCurrentStudent(const string&);
    void show();

private:
    void RoomView();
    void StudentInformation();
    void PaymentView();
    void ContractView();
};