#include "ServiceManager.h"


ServiceManager::ServiceManager()
{
	this->initialize();
}
ServiceManager::~ServiceManager()
{
	this->shutdown();
}


void ServiceManager::linking()
{
	LinkedList<Student*>* listStudents = this->studentData->getList();
	for (ListNode<Student*>* p = listStudents->getHead(); p != nullptr; p = p->next)
	{
		int key = p->value->getUserId();
		p->value->AddAccount(this->accountData->GetByUserId(key));
	}
	LinkedList<Employee*>* listEmployees = this->employeeData->getList();
	for (ListNode<Employee*>* p = listEmployees->getHead(); p != nullptr; p = p->next)
	{
		int key = p->value->getUserId();
		p->value->AddAccount(this->accountData->GetByUserId(key));
	}
	LinkedList<Contract*>* listContracts = this->contractData->getList();
	for (ListNode<Contract*>* p = listContracts->getHead(); p != nullptr; p = p->next)
	{
		int key = p->value->getStudentId();
		p->value->AddStudent(this->studentData->GetByStudentId(key));
		key = p->value->getRoomId();
		p->value->AddRoom(this->roomData->GetByRoomId(key));
	}
	LinkedList<Invoice*>* listInvoices = this->invoiceData->getList();
	for (ListNode<Invoice*>* p = listInvoices->getHead(); p != nullptr; p = p->next)
	{
		int key = p->value->getEmployeeId();
		p->value->AddEmployee(this->employeeData->GetByEmployeeId(key));
		key = p->value->getContractId();
		p->value->AddContract(this->contractData->GetByContractId(key));
	}
}
void ServiceManager::initialize()
{
	this->accountData = new AccountData("Account.txt");
	this->contractData = new ContractData("Contract.txt");
	this->employeeData = new EmployeeData("Employee.txt");
	this->invoiceData = new InvoiceData("Invoice.txt");
	this->roomData = new RoomData("Room.txt");
	this->studentData = new StudentData("Student.txt");

	this->linking();

	this->accountService = new AccountService(*accountData);
	this->contractService = new ContractService(
		*contractData,
		*studentData
	);
	this->employeeService = new EmployeeService(*employeeData);
	this->invoiceService = new InvoiceService(*invoiceData);
	this->roomService = new RoomService(
		*roomData,
		*studentData,
		*contractData
	);
	this->studentService = new StudentService(*studentData);
}

void ServiceManager::shutdown()
{
	delete accountService; 
	delete contractService; 
	delete employeeService; 
	delete invoiceService; 
	delete roomService;
	delete studentService;

	delete accountData;
	delete contractData;
	delete employeeData;
	delete invoiceData;
	delete roomData;
	delete studentData;
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
