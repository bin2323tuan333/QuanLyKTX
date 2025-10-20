#include "ServiceManager.h"


void ServiceManager::initialize()
{
	this->accountRepo = new AccountRepository();
	this->contractRepo = new ContractRepository();
	this->employeeRepo = new EmployeeRepository();
	this->invoiceRepo = new InvoiceRepository();
	this->roomRepo = new RoomRepository();
	this->studentRepo = new StudentRepository();

	this->accountService = new AccountService(*accountRepo);
	this->contractService = new ContractService(
		*contractRepo, 
		*studentRepo
	);
	this->employeeService = new EmployeeService(*employeeRepo);
	this->invoiceService = new InvoiceService(*invoiceRepo);
	this->roomService = new RoomService(
		*roomRepo,
		*studentRepo,
		*contractRepo
	);
	this->studentService = new StudentService(*studentRepo);
}

void ServiceManager::shutdown()
{
	delete accountService; 
	delete contractService; 
	delete employeeService; 
	delete invoiceService; 
	delete roomService;
	delete studentService;

	delete accountRepo; 
	delete contractRepo; 
	delete employeeRepo; 
	delete invoiceRepo; 
	delete roomRepo; 
	delete studentRepo; 
}

AccountService* ServiceManager::getAccountService()
{
	return accountService;
}

ContractService* ServiceManager::getContractService()
{
	return contractService;
}

InvoiceService* ServiceManager::getInvoiceService()
{
	return invoiceService;
}

EmployeeService* ServiceManager::getEmployeeService()
{
	return employeeService;
}

RoomService* ServiceManager::getRoomService()
{
	return roomService;
}

StudentService* ServiceManager::getStudentService()
{
	return studentService;
}
