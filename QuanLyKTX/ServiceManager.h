#pragma once
#include "AccountService.h"
#include "ContractService.h"
#include "EmployeeService.h"
#include "PaymentService.h"
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
	PaymentService* paymentService;
	RoomService* roomService;
	StudentService* studentService;

public:
	void initialize();
	void shutdown();

	AccountService* getAccountService();
	ContractService* getContractService();
	EmployeeService* getEmployeeService();
	PaymentService* getPaymentService();
	RoomService* getRoomService();
	StudentService* getStudentService();
};