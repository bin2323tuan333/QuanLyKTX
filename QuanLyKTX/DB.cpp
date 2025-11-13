#include "DB.h"
#include "Account.h"
#include "Student.h"
#include "Employee.h"
#include "Room.h"
#include "Contract.h"
#include "Invoice.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

DB* DB::_Instance = nullptr;
DB::DB()
{
	loadData();
	connect();
}
DB::~DB()
{
	saveData();
	freeMem();
}

DB* DB::Instance()
{
	if (_Instance == nullptr)
		_Instance = new DB();
	return _Instance;
}
void DB::Destroy()
{
	if (_Instance != nullptr)
	{
		delete _Instance;
		_Instance = nullptr;
	}
}

void DB::loadData()
{
	// Account data
	ifstream accFile("Account.txt");
	if (!accFile.is_open()) return;
	string line;
	while (getline(accFile, line))
	{
		if (line == "") continue;
		stringstream ss(line);
		IAccount* acc = new Account();
		string token;
		getline(ss, token, ';'); acc->setUserId(stoi(token));
		getline(ss, token, ';'); acc->setUsername(token);
		getline(ss, token, ';'); acc->setPassword(token);
		this->listAccounts.add(acc);
	}
	accFile.close();

	// Student Data
	ifstream stuFile("Student.txt");
	if (!stuFile.is_open()) return;
	while (getline(stuFile, line)) {
		if (line == "") continue;
		stringstream ss(line);
		string token;
		IStudent* student = new Student();
		getline(ss, token, ';'); student->setStudentId(stoi(token));
		getline(ss, token, ';'); student->setUserId(stoi(token));
		getline(ss, token, ';'); student->setFullName(token);
		getline(ss, token, ';'); student->setGender(token == "1");
		getline(ss, token, ';'); student->setDateOfBirth(Date::stringToDate(token));
		getline(ss, token, ';'); student->setPhoneNumber(token);
		getline(ss, token, ';'); student->setEmail(token);
		getline(ss, token, ';'); student->setClassName(token);
		getline(ss, token, ';'); student->setFaculty(token);
		this->listStudents.add(student);
	}
	stuFile.close();

	// Employee Data
	ifstream empFile("Employee.txt");
	if (!empFile.is_open())
		return;
	while (getline(empFile, line)) {
		if (line == "") continue;
		stringstream ss(line);
		string token;
		IEmployee* employee = new Employee();
		getline(ss, token, ';'); employee->setEmployeeId(stoi(token));
		getline(ss, token, ';'); employee->setUserId(stoi(token));
		getline(ss, token, ';'); employee->setFullName(token);
		getline(ss, token, ';'); employee->setGender(token == "1" ? true : false);
		getline(ss, token, ';'); employee->setDateOfBirth(Date::stringToDate(token));
		getline(ss, token, ';'); employee->setPhoneNumber(token);
		getline(ss, token, ';'); employee->setEmail(token);
		getline(ss, token, ';'); employee->setSalary(stoi(token));
		this->listEmployees.add(employee);
	}
	empFile.close();

	// Room Data
	ifstream roomFile("Room.txt");
	if (!roomFile.is_open()) return;
	while (getline(roomFile, line)) {
		if (line == "") continue;
		stringstream ss(line);
		string token;
		IRoom* room = new Room();
		getline(ss, token, ';'); room->setRoomId(stoi(token));
		getline(ss, token, ';'); room->setRoomName(token);
		getline(ss, token, ';'); room->setRoomType(token);
		getline(ss, token, ';'); room->setCapacity(stoi(token));
		getline(ss, token, ';'); room->setFloor(stoi(token));
		getline(ss, token, ';'); room->setBuilding(token);
		getline(ss, token, ';'); room->setIsActive(token == "1" ? true : false);
		this->listRooms.add(room);
	}
	roomFile.close();

	// Invoice Data
	ifstream invFile("Invoice.txt");
	if (!invFile.is_open()) return;
	while (getline(invFile, line)) {
		if (line == "") continue;
		stringstream ss(line);
		string token;
		IInvoice* invoice = new Invoice();
		getline(ss, token, ';'); invoice->setInvoiceId(stoi(token));
		getline(ss, token, ';'); invoice->setContractId(stoi(token));
		getline(ss, token, ';'); invoice->setRoomFee(stoi(token));
		getline(ss, token, ';'); invoice->setInternetFee(stoi(token));
		getline(ss, token, ';'); invoice->setElectricFee(stoi(token));
		getline(ss, token, ';'); invoice->setWaterFee(stoi(token));
		getline(ss, token, ';'); invoice->setCreatedDate(Date::stringToDate(token));
		getline(ss, token, ';'); invoice->setIsPaid(token == "1" ? true : false);
		this->listInvoices.add(invoice);
	}
	invFile.close();

	// Contract Data
	ifstream conFile("Contract.txt");
	if (!conFile.is_open())
		return;
	while (getline(conFile, line))
	{
		if (line == "") continue;
		stringstream ss(line);
		string token;
		IContract* contract = new Contract();
		getline(ss, token, ';'); contract->setContractId(stoi(token));
		getline(ss, token, ';'); contract->setStudentId(stoi(token));
		getline(ss, token, ';'); contract->setRoomId(stoi(token));
		getline(ss, token, ';'); contract->setStartDate(Date::stringToDate(token));
		getline(ss, token, ';'); contract->setEndDate(Date::stringToDate(token));
		this->listContracts.add(contract);
	}
	conFile.close();
}
void DB::connect()
{
	for (ListNode<IStudent*>* p = this->listStudents.getHead(); p != nullptr; p = p->next)
	{
		if (p->value == nullptr) continue;
		int key = p->value->getUserId();
		IAccount* temp = this->getAccountByUserId(key);
		if (temp != nullptr)
			p->value->AddAccount(temp);
	}
	for (ListNode<IEmployee*>* p = this->listEmployees.getHead(); p != nullptr; p = p->next)
	{
		if (p->value == nullptr) continue;
		int key = p->value->getUserId();
		IAccount* temp = this->getAccountByUserId(key);
		if (temp != nullptr)
			p->value->AddAccount(temp);
	}
	for (ListNode<IContract*>* p = this->listContracts.getHead(); p != nullptr; p = p->next)
	{
		if (p->value == nullptr) continue;
		int key = p->value->getStudentId();
		IStudent* student = this->getStudentByStudentId(key);
		if (student != nullptr)
			p->value->AddStudent(student);
		if (!p->value->isActive()) continue;
		key = p->value->getRoomId();
		IRoom* room = this->getRoomByRoomId(key);
		if (room != nullptr)
			p->value->AddRoom(room);
	}
	for (ListNode<IInvoice*>* p = this->listInvoices.getHead(); p != nullptr; p = p->next)
	{
		if (p->value == nullptr) continue;
		int key = p->value->getContractId();
		IContract* contract = this->getContractByContractId(key);
		if (contract != nullptr)
			p->value->AddContract(contract);
	}
}
void DB::saveData()
{
	// Account
	ofstream accFile("Account.txt");
	if (!accFile.is_open())
		return;
	for (ListNode<IAccount*>* p = this->listAccounts.getHead(); p != nullptr; p = p->next)
	{
		if (p->value == nullptr) continue;
		accFile << (p->value)->getUserId() << ";";
		accFile << (p->value)->getUsername() << ";";
		accFile << (p->value)->getPassword() << endl;
	}
	accFile.close();

	// Student
	ofstream stuFile("Student.txt");
	if (!stuFile.is_open()) return;
	for (ListNode<IStudent*>* p = this->listStudents.getHead(); p != nullptr; p = p->next)
	{
		if (p->value == nullptr) continue;
		stuFile << p->value->getStudentId() << ";";
		stuFile << p->value->getUserId() << ";";
		stuFile << p->value->getFullName() << ";";
		stuFile << (p->value->getGender() == true ? "1" : "0") << ";";
		stuFile << p->value->getDateOfBirth() << ";";
		stuFile << p->value->getPhoneNumber() << ";";
		stuFile << p->value->getEmail() << ";";
		stuFile << p->value->getClassName() << ";";
		stuFile << p->value->getFaculty() << endl;
	}
	stuFile.close();

	// Employee
	ofstream empFile("Employee.txt");
	if (!empFile.is_open()) return;
	for (ListNode<IEmployee*>* p = this->listEmployees.getHead(); p != nullptr; p = p->next)
	{
		if (p->value == nullptr) continue;
		empFile << p->value->getEmployeeId() << ";";
		empFile << p->value->getUserId() << ";";
		empFile << p->value->getFullName() << ";";
		empFile << (p->value->getGender() == true ? "1" : "0") << ";";
		empFile << p->value->getDateOfBirth() << ";";
		empFile << p->value->getPhoneNumber() << ";";
		empFile << p->value->getEmail() << ";";
		empFile << p->value->getSalary() << endl;
	}
	empFile.close();

	// Contract
	ofstream conFile("Contract.txt");
	if (!conFile.is_open()) return;
	for (ListNode<IContract*>* p = this->listContracts.getHead(); p != nullptr; p = p->next)
	{
		if (p->value == nullptr) continue;
		conFile << p->value->getContractId() << ";";
		conFile << p->value->getStudentId() << ";";
		conFile << p->value->getRoomId() << ";";
		conFile << p->value->getStartDate() << ";";
		conFile << p->value->getEndDate() << endl;
	}
	conFile.close();

	// Invoice
	ofstream invFile("Invoice.txt");
	if (!invFile.is_open()) return;
	for (ListNode<IInvoice*>* p = this->listInvoices.getHead(); p != nullptr; p = p->next)
	{
		if (p->value == nullptr) continue;
		invFile << p->value->getInvoiceId() << ";";
		invFile << p->value->getContractId() << ";";
		invFile << p->value->getRoomFee() << ";";
		invFile << p->value->getInternetFee() << ";";
		invFile << p->value->getElectricFee() << ";";
		invFile << p->value->getWaterFee() << ";";
		invFile << p->value->getCreatedDate() << ";";
		invFile << (p->value->getIsPaid() ? "1" : "0") << endl;
	}
	invFile.close();

	// Room
	ofstream roomFile("Room.txt");
	if (!roomFile.is_open()) return;
	for (ListNode<IRoom*>* p = this->listRooms.getHead(); p != nullptr; p = p->next)
	{
		if (p->value == nullptr) continue;
		roomFile << p->value->getRoomId() << ";";
		roomFile << p->value->getRoomName() << ";";
		roomFile << p->value->getRoomType() << ";";
		roomFile << p->value->getCapacity() << ";";
		roomFile << p->value->getFloor() << ";";
		roomFile << p->value->getBuilding() << ";";
		roomFile << (p->value->getIsActive() == true ? "1" : "0") << "\n";
	}
	roomFile.close();
}
void DB::freeMem()
{
	for (ListNode<IStudent*>* p = this->listStudents.getHead(); p != nullptr; p = p->next) delete p->value;
	this->listStudents.clear();
	for (ListNode<IEmployee*>* p = this->listEmployees.getHead(); p != nullptr; p = p->next) delete p->value;
	this->listEmployees.clear();
	for (ListNode<IAccount*>* p = this->listAccounts.getHead(); p != nullptr; p = p->next) delete p->value;
	this->listAccounts.clear();
	for (ListNode<IContract*>* p = this->listContracts.getHead(); p != nullptr; p = p->next) delete p->value;
	this->listContracts.clear();
	for (ListNode<IInvoice*>* p = this->listInvoices.getHead(); p != nullptr; p = p->next) delete p->value;
	this->listInvoices.clear();
	for (ListNode<IRoom*>* p = this->listRooms.getHead(); p != nullptr; p = p->next) delete p->value;
	this->listRooms.clear();
}


// ===== CRUD BASIC =====
// === Account ===
void DB::updateAccount(const IAccount& acc)
{
	IAccount* current = this->getAccountByUserId(acc.getUserId());
	if (current == nullptr) return;
	*current = acc;
}
void DB::deleteAccount(const IAccount& acc)
{
	IAccount* temp = this->getAccountByUserId(acc.getUserId());
	this->listAccounts.remove(temp);
	delete temp;
}
void DB::addAccount(IAccount* newAccount)
{
	this->listAccounts.add(newAccount);

}
IAccount* DB::getAccountByUsername(const string& username)
{
	for (ListNode<IAccount*>* p = this->listAccounts.getHead(); p != nullptr; p = p->next)
		if (username == p->value->getUsername()) return p->value;
	return nullptr;
}
IAccount* DB::getAccountByUserId(const int& userId)
{
	for (ListNode<IAccount*>* p = this->listAccounts.getHead(); p != nullptr; p = p->next)
		if (userId == p->value->getUserId()) return p->value;
	return nullptr;
}
LinkedList<IAccount*>* DB::getAllAccounts()
{
	return &this->listAccounts;
}

// === Student === 
void DB::updateStudent(const int& id, const IStudent& stu)
{
	IStudent* current = this->getStudentByStudentId(id);
	if (current == nullptr) return;
	*current = stu;
	current->getAccount()->setUsername(to_string(current->getStudentId()));
}
void DB::deleteStudent(const IStudent& stu)
{
	IStudent* temp = this->getStudentByStudentId(stu.getStudentId());
	this->listStudents.remove(temp);
	delete temp;
}
void DB::addStudent(const IStudent& stu)
{
	IStudent* newStudent = new Student();
	*newStudent = stu;
	this->listStudents.add(newStudent);
}
IStudent* DB::getStudentByStudentId(const int& studentId)
{
	for (ListNode<IStudent*>* p = this->listStudents.getHead(); p != nullptr; p = p->next)
		if ( studentId == p->value->getStudentId()) return p->value;
	return nullptr;
}
LinkedList<IStudent*>* DB::getAllStudents()
{
	return &this->listStudents;
}

// === Employee === 
void DB::updateEmployee(const IEmployee& emp)
{
	IEmployee* current = this->getEmployeeByEmployeeId(emp.getEmployeeId());
	if (current == nullptr) return;
	*current = emp;
}
void DB::deleteEmployee(const IEmployee& emp)
{
	IEmployee* temp = this->getEmployeeByEmployeeId(emp.getEmployeeId());
	this->listEmployees.remove(temp);
	delete temp;
}
void DB::addEmployee(const IEmployee& emp)
{
	IEmployee* newEmployee = new Employee();
	*newEmployee = emp;
	this->listEmployees.add(newEmployee);
}
IEmployee* DB::getEmployeeByEmployeeId(const int& employeeId)
{
	for (ListNode<IEmployee*>* p = this->listEmployees.getHead(); p != nullptr; p = p->next)
		if (employeeId == p->value->getEmployeeId()) return p->value;
	return nullptr;
}
LinkedList<IEmployee*>* DB::getAllEmployees()
{
	return &this->listEmployees;
}

// === Room === 
void DB::updateRoom(const IRoom& room)
{
	IRoom* current = this->getRoomByRoomId(room.getRoomId());
	if (current == nullptr) return;
	*current = room;
}
void DB::deleteRoom(const IRoom& room)
{
	IRoom* temp = this->getRoomByRoomId(room.getRoomId());
	this->listRooms.remove(temp);
	delete temp;
}
void DB::addRoom(const IRoom& room)
{
	IRoom* newRoom = new Room();
	*newRoom = room;
	this->listRooms.add(newRoom);
}
IRoom* DB::getRoomByRoomId(const int& roomId)
{
	for (ListNode<IRoom*>* p = this->listRooms.getHead(); p != nullptr; p = p->next)
		if (roomId == p->value->getRoomId()) return p->value;
	return nullptr;
}
LinkedList<IRoom*>* DB::getAllRooms()
{
	return &this->listRooms;
}

// === Contract === 
void DB::updateContract(const IContract& con)
{
	IContract* current = this->getContractByContractId(con.getContractId());
	if (current == nullptr) return;
	*current = con;
}
void DB::deleteContract(const IContract& con)
{
	IContract* temp = this->getContractByContractId(con.getContractId());
	this->listContracts.remove(temp);
	delete temp;
}
void DB::addContract(const IContract& con)
{
	IContract* newContract = new Contract();
	*newContract = con;
	this->listContracts.add(newContract);
	newContract->AddRoom(this->getRoomByRoomId(newContract->getRoomId()));
	newContract->AddStudent(this->getStudentByStudentId(newContract->getStudentId()));
}
IContract* DB::getContractByContractId(const int& contractId)
{
	for (ListNode<IContract*>* p = this->listContracts.getHead(); p != nullptr; p = p->next)
		if (p->value->getContractId() == contractId) return p->value;
	return nullptr;
}
LinkedList<IContract*>* DB::getAllContracts()
{
	return &this->listContracts;
}

// === Invoice ===
void DB::updateInvoice(const IInvoice& inv)
{
	IInvoice* current = this->getInvoiceByInvoiceId(inv.getInvoiceId());
	if (current == nullptr) return;
	*current = inv;
}
void DB::deleteInvoice(const IInvoice& inv)
{
	IInvoice* temp = this->getInvoiceByInvoiceId(inv.getInvoiceId());
	this->listInvoices.remove(temp);
	delete temp;
}
void DB::addInvoice(const IInvoice& inv)
{
	IInvoice* newInvoice = new Invoice();
	*newInvoice = inv;
	this->listInvoices.add(newInvoice);
	IContract* contract = this->getContractByContractId(newInvoice->getContractId());
	newInvoice->AddContract(contract);
}
LinkedList<IInvoice*>* DB::getAllInvoices()
{
	return &this->listInvoices;
}
IInvoice* DB::getInvoiceByInvoiceId(const int& invoiceId)
{
	for (ListNode<IInvoice*>* p = this->listInvoices.getHead(); p != nullptr; p = p->next)
		if (p->value->getInvoiceId() == invoiceId) return p->value;
	return nullptr;
}