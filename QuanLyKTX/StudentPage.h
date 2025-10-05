#pragma once
#include "StudentService.h"
#include "RoomService.h"
#include "PaymentService.h"

class StudentPage {
private:
    StudentService* studentService;
    RoomService* roomService;
    PaymentService* paymentService;
    string currentStudentId;

public:
    StudentPage();

    void setServices(StudentService*, RoomService*, PaymentService*);
    void setCurrentStudent(const string&);
    void show();

private:
    void RoomView();
    void StudentInformation();
    void PaymentView();
    void ContractView();
};