#include "DB.h"
#include <fstream>
#include <sstream>

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
		Account* acc = new Account();
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
		Student* student = new Student();
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
		Employee* employee = new Employee();
		getline(ss, token, ';'); employee->setEmployeeId(stoi(token));
		getline(ss, token, ';'); employee->setUserId(stoi(token));
		getline(ss, token, ';'); employee->setFullName(token);
		getline(ss, token, ';'); employee->setGender(token == "1" ? true : false);
		getline(ss, token, ';'); employee->setDateOfBirth(Date::stringToDate(token));
		getline(ss, token, ';'); employee->setPhoneNumber(token);
		getline(ss, token, ';'); employee->setEmail(token);
		getline(ss, token, ';'); employee->setRole(token);
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
		Room* room = new Room();
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
		Invoice* invoice = new Invoice();
		getline(ss, token, ';'); invoice->setInvoiceId(stoi(token));
		getline(ss, token, ';'); invoice->setContractId(stoi(token));
		getline(ss, token, ';'); invoice->setRoomFee(stoi(token));
		getline(ss, token, ';'); invoice->setInternetFee(stoi(token));
		getline(ss, token, ';'); invoice->setElectricFee(stoi(token));
		getline(ss, token, ';'); invoice->setWaterFee(stoi(token));
		getline(ss, token, ';'); invoice->setCreatedDate(Date::stringToDate(token));
		getline(ss, token, ';'); invoice->setisPaid(token == "1" ? true : false);
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
		Contract* contract = new Contract();
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
	for (ListNode<Student*>* p = this->listStudents.getHead(); p != nullptr; p = p->next)
	{
		if (p->value == nullptr) continue;
		int key = p->value->getUserId();
		Account* temp = this->getAccountByUserId(key);
		if (temp != nullptr)
			p->value->AddAccount(temp);
	}
	for (ListNode<Employee*>* p = this->listEmployees.getHead(); p != nullptr; p = p->next)
	{
		if (p->value == nullptr) continue;
		int key = p->value->getUserId();
		Account* temp = this->getAccountByUserId(key);
		if (temp != nullptr)
			p->value->AddAccount(temp);
	}
	for (ListNode<Contract*>* p = this->listContracts.getHead(); p != nullptr; p = p->next)
	{
		if (p->value == nullptr) continue;
		int key = p->value->getStudentId();
		Student* student = this->getStudentByStudentId(key);
		if (student != nullptr)
			p->value->AddStudent(student);
		if (!p->value->isActive()) continue;
		key = p->value->getRoomId();
		Room* room = this->getRoomByRoomId(key);
		if (room != nullptr)
			p->value->AddRoom(room);
	}
	for (ListNode<Invoice*>* p = this->listInvoices.getHead(); p != nullptr; p = p->next)
	{
		if (p->value == nullptr) continue;
		int key = p->value->getContractId();
		Contract* contract = this->getContractByContractId(key);
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
	for (ListNode<Account*>* p = this->listAccounts.getHead(); p != nullptr; p = p->next)
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
	for (ListNode<Student*>* p = this->listStudents.getHead(); p != nullptr; p = p->next)
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
	for (ListNode<Employee*>* p = this->listEmployees.getHead(); p != nullptr; p = p->next)
	{
		if (p->value == nullptr) continue;
		empFile << p->value->getEmployeeId() << ";";
		empFile << p->value->getUserId() << ";";
		empFile << p->value->getFullName() << ";";
		empFile << (p->value->getGender() == true ? "1" : "0") << ";";
		empFile << p->value->getDateOfBirth() << ";";
		empFile << p->value->getPhoneNumber() << ";";
		empFile << p->value->getEmail() << ";";
		empFile << p->value->getRole() << ";";
		empFile << p->value->getSalary() << endl;
	}
	empFile.close();

	// Contract
	ofstream conFile("Contract.txt");
	if (!conFile.is_open()) return;
	for (ListNode<Contract*>* p = this->listContracts.getHead(); p != nullptr; p = p->next)
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
	for (ListNode<Invoice*>* p = this->listInvoices.getHead(); p != nullptr; p = p->next)
	{
		if (p->value == nullptr) continue;
		invFile << p->value->getInvoiceId() << ";";
		invFile << p->value->getContractId() << ";";
		invFile << p->value->getRoomFee() << ";";
		invFile << p->value->getInternetFee() << ";";
		invFile << p->value->getElectricFee() << ";";
		invFile << p->value->getWaterFee() << ";";
		invFile << p->value->getCreatedDate() << ";";
		invFile << (p->value->getisPaid() ? "1" : "0") << endl;
	}
	invFile.close();

	// Room
	ofstream roomFile("Room.txt");
	if (!roomFile.is_open()) return;
	for (ListNode<Room*>* p = this->listRooms.getHead(); p != nullptr; p = p->next)
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
	for (ListNode<Student*>* p = this->listStudents.getHead(); p != nullptr; p = p->next) delete p->value;
	this->listStudents.clear();
	for (ListNode<Employee*>* p = this->listEmployees.getHead(); p != nullptr; p = p->next) delete p->value;
	this->listEmployees.clear();
	for (ListNode<Account*>* p = this->listAccounts.getHead(); p != nullptr; p = p->next) delete p->value;
	this->listAccounts.clear();
	for (ListNode<Contract*>* p = this->listContracts.getHead(); p != nullptr; p = p->next) delete p->value;
	this->listContracts.clear();
	for (ListNode<Invoice*>* p = this->listInvoices.getHead(); p != nullptr; p = p->next) delete p->value;
	this->listInvoices.clear();
	for (ListNode<Room*>* p = this->listRooms.getHead(); p != nullptr; p = p->next) delete p->value;
	this->listRooms.clear();
}


// ===== CRUD BASIC =====
// === Account ===
void DB::updateAccount(const Account& acc)
{
	Account* current = this->getAccountByUserId(acc.getUserId());
	if (current == nullptr) return;
	*current = acc;
}
void DB::deleteAccount(const Account& acc)
{
	Account* temp = this->getAccountByUserId(acc.getUserId());
	this->listAccounts.remove(temp);
	delete temp;
}
void DB::addAccount(Account* newAccount)
{
	this->listAccounts.add(newAccount);

}
Account* DB::getAccountByUsername(const string& username)
{
	for (ListNode<Account*>* p = this->listAccounts.getHead(); p != nullptr; p = p->next)
		if (username == p->value->getUsername()) return p->value;
	return nullptr;
}
Account* DB::getAccountByUserId(const int& userId)
{
	for (ListNode<Account*>* p = this->listAccounts.getHead(); p != nullptr; p = p->next)
		if (userId == p->value->getUserId()) return p->value;
	return nullptr;
}
LinkedList<Account*>* DB::getAllAccounts()
{
	return &this->listAccounts;
}

// === Student === 
void DB::updateStudent(const int& id, const Student& stu)
{
	Student* current = this->getStudentByStudentId(id);
	if (current == nullptr) return;
	*current = stu;
	current->getAccount()->setUsername(to_string(current->getStudentId()));
}
void DB::deleteStudent(const Student& stu)
{
	Student* temp = this->getStudentByStudentId(stu.getStudentId());
	this->listStudents.remove(temp);
	delete temp;
}
void DB::addStudent(const Student& stu)
{
	Student* newStudent = new Student(stu);
	this->listStudents.add(newStudent);
}
Student* DB::getStudentByStudentId(const int& studentId)
{
	for (ListNode<Student*>* p = this->listStudents.getHead(); p != nullptr; p = p->next)
		if ( studentId == p->value->getStudentId()) return p->value;
	return nullptr;
}
LinkedList<Student*>* DB::getAllStudents()
{
	return &this->listStudents;
}

// === Employee === 
void DB::updateEmployee(const Employee& emp)
{
	Employee* current = this->getEmployeeByEmployeeId(emp.getEmployeeId());
	if (current == nullptr) return;
	*current = emp;
}
void DB::deleteEmployee(const Employee& emp)
{
	Employee* temp = this->getEmployeeByEmployeeId(emp.getEmployeeId());
	this->listEmployees.remove(temp);
	delete temp;
}
void DB::addEmployee(const Employee& emp)
{
	Employee* newEmployee = new Employee(emp);
	this->listEmployees.add(newEmployee);
}
Employee* DB::getEmployeeByEmployeeId(const int& employeeId)
{
	for (ListNode<Employee*>* p = this->listEmployees.getHead(); p != nullptr; p = p->next)
		if (employeeId == p->value->getEmployeeId()) return p->value;
	return nullptr;
}
LinkedList<Employee*>* DB::getAllEmployees()
{
	return &this->listEmployees;
}

// === Room === 
void DB::updateRoom(const Room& room)
{
	Room* current = this->getRoomByRoomId(room.getRoomId());
	if (current == nullptr) return;
	*current = room;
}
void DB::deleteRoom(const Room& room)
{
	Room* temp = this->getRoomByRoomId(room.getRoomId());
	this->listRooms.remove(temp);
	delete temp;
}
void DB::addRoom(const Room& room)
{
	Room* newRoom = new Room(room);
	this->listRooms.add(newRoom);
}
Room* DB::getRoomByRoomId(const int& roomId)
{
	for (ListNode<Room*>* p = this->listRooms.getHead(); p != nullptr; p = p->next)
		if (roomId == p->value->getRoomId()) return p->value;
	return nullptr;
}
LinkedList<Room*>* DB::getAllRooms()
{
	return &this->listRooms;
}

// === Contract === 
void DB::updateContract(const Contract& con)
{
	Contract* current = this->getContractByContractId(con.getContractId());
	if (current == nullptr) return;
	*current = con;
}
void DB::deleteContract(const Contract& con)
{
	Contract* temp = this->getContractByContractId(con.getContractId());
	this->listContracts.remove(temp);
	delete temp;
}
void DB::addContract(const Contract& con)
{
	Contract* newContract = new Contract(con);
	this->listContracts.add(newContract);
	newContract->AddRoom(this->getRoomByRoomId(newContract->getRoomId()));
	newContract->AddStudent(this->getStudentByStudentId(newContract->getStudentId()));
}
Contract* DB::getContractByContractId(const int& contractId)
{
	for (ListNode<Contract*>* p = this->listContracts.getHead(); p != nullptr; p = p->next)
		if (p->value->getContractId() == contractId) return p->value;
	return nullptr;
}
LinkedList<Contract*>* DB::getAllContracts()
{
	return &this->listContracts;
}

// === Invoice ===
void DB::updateInvoice(const Invoice& inv)
{
	Invoice* current = this->getInvoiceByInvoiceId(inv.getInvoiceId());
	if (current == nullptr) return;
	*current = inv;
}
void DB::deleteInvoice(const Invoice& inv)
{
	Invoice* temp = this->getInvoiceByInvoiceId(inv.getInvoiceId());
	this->listInvoices.remove(temp);
	delete temp;
}
void DB::addInvoice(const Invoice& inv)
{
	Invoice* newInvoice = new Invoice(inv);
	this->listInvoices.add(newInvoice);
	Contract* contract = this->getContractByContractId(newInvoice->getContractId());
	newInvoice->AddContract(contract);
}
LinkedList<Invoice*>* DB::getAllInvoices()
{
	return &this->listInvoices;
}
Invoice* DB::getInvoiceByInvoiceId(const int& invoiceId)
{
	for (ListNode<Invoice*>* p = this->listInvoices.getHead(); p != nullptr; p = p->next)
		if (p->value->getInvoiceId() == invoiceId) return p->value;
	return nullptr;
}