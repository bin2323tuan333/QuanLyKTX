#include "ServiceManager.h"


ServiceManager::ServiceManager()
{
	this->initialize();
}
ServiceManager::~ServiceManager()
{
	this->shutdown();
}


void ServiceManager::initialize()
{
	this->accountRepo = new AccountRepository("Account.txt");
	this->contractRepo = new ContractRepository("Contract.txt");
	this->employeeRepo = new EmployeeRepository("Employee.txt");
	this->invoiceRepo = new InvoiceRepository("Invoice.txt");
	this->roomRepo = new RoomRepository("Room.txt");
	this->studentRepo = new StudentRepository("Student.txt");

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
