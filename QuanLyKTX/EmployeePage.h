#pragma once
#include "StudentService.h"
#include "RoomService.h"
#include "ContractService.h"
#include "PaymentService.h"

class EmployeePage {
private:
    StudentService* studentService;
    RoomService* roomService;
    ContractService* contractService;
    PaymentService* paymentService;

public:
    EmployeePage();
    ~EmployeePage();

    void setServices(StudentService*, RoomService*, ContractService*, PaymentService*);
    void show();

private:
    void AddStudent();
    void RemoveStudent();
    void CreateInvoice();
    void ManageRooms();
    void ManageContracts();
    void ViewReports();
};