#pragma once
#include "AccountService.h"
#include "ContractService.h"
#include "EmployeeService.h"
#include "InvoiceService.h"
#include "RoomService.h"
#include "StudentService.h"


class ServiceManager {
private:
	AccountRepository* accountRepo;
	ContractRepository* contractRepo;
	EmployeeRepository* employeeRepo;
	InvoiceRepository* invoiceRepo;
	RoomRepository* roomRepo;
	StudentRepository* studentRepo;

	AccountService* accountService;
	ContractService* contractService;
	EmployeeService* employeeService;
	InvoiceService* invoiceService;
	RoomService* roomService;
	StudentService* studentService;

public:
	ServiceManager();
	~ServiceManager();


	void initialize();
	void shutdown();

	AccountService* getAccountService();
	ContractService* getContractService();
	EmployeeService* getEmployeeService();
	InvoiceService* getInvoiceService();
	RoomService* getRoomService();
	StudentService* getStudentService();
};