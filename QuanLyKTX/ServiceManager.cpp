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
	this->contractService = new ContractService(*contractRepo, *studentRepo);
	this->employeeService = new EmployeeService(*employeeRepo);
	this->paymentService = new PaymentService(*invoiceRepo);
	this->roomService = new RoomService(*roomRepo, *studentRepo);
	this->studentService = new StudentService(*studentRepo);
}

void ServiceManager::shutdown()
{
	delete accountService; accountService = nullptr;
	delete contractService; contractService = nullptr;
	delete employeeService; employeeService = nullptr;
	delete paymentService; paymentService = nullptr;
	delete roomService; roomService = nullptr;
	delete studentService; studentService = nullptr;

	delete accountRepo; accountRepo = nullptr;
	delete contractRepo; contractRepo = nullptr;
	delete employeeRepo; employeeRepo = nullptr;
	delete invoiceRepo; invoiceRepo = nullptr;
	delete roomRepo; roomRepo = nullptr;
	delete studentRepo; studentRepo = nullptr;
}

AccountService* ServiceManager::getAccountService()
{
	return accountService;
}

ContractService* ServiceManager::getContractService()
{
	return contractService;
}

PaymentService* ServiceManager::getPaymentService()
{
	return paymentService;
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
