#pragma once
#include "AccountService.h"
#include "ContractService.h"
#include "EmployeeService.h"
#include "InvoiceService.h"
#include "RoomService.h"
#include "StudentService.h"


class ServiceManager {
private:
	AccountData* accountData;
	ContractData* contractData;
	EmployeeData* employeeData;
	InvoiceData* invoiceData;
	RoomData* roomData;
	StudentData* studentData;

	AccountService* accountService;
	ContractService* contractService;
	EmployeeService* employeeService;
	InvoiceService* invoiceService;
	RoomService* roomService;
	StudentService* studentService;

public:
	ServiceManager();
	~ServiceManager();

	void linking();
	void initialize();
	void shutdown();

	AccountService* getAccountService();
	ContractService* getContractService();
	EmployeeService* getEmployeeService();
	InvoiceService* getInvoiceService();
	RoomService* getRoomService();
	StudentService* getStudentService();
};