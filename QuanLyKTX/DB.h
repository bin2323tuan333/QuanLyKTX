#pragma once
#include <string>
#include "LinkedList.h"
using namespace std;

class Account;
class Student;
class Employee;
class Contract;
class Invoice;
class Room;
class DB
{
private:
	static DB* _Instance;
	LinkedList<Account*> listAccounts;
	LinkedList<Student*> listStudents;
	LinkedList<Employee*> listEmployees;
	LinkedList<Contract*> listContracts;
	LinkedList<Invoice*> listInvoices;
	LinkedList<Room*> listRooms;
	DB();
	DB(const DB&) = delete;
	const DB& operator=(const DB&) = delete;

	void loadData();
	void connect();
	void freeMem();
public:
	~DB();
	static DB* Instance();
	static void Destroy();
    void saveData();
	// ====  ====
	LinkedList<Student*>* getStudentInRoom(const int&);
	LinkedList<Contract*>* getContractInStudent(const int&);
	LinkedList<Invoice*>* getInvoiceInContract(const int&);



	// ==== CRUD BASIC ====
	// ===Account===
	void deleteAccount(const Account&);
	void addAccount(Account*);
	Account* getAccountByUsername(const string&);
	Account* getAccountByUserId(const int&);
	LinkedList<Account*>* getAllAccounts();

	// ===Student===
	void deleteStudent(const Student&);
	void addStudent(const Student&);
	Student* getStudentByStudentId(const int&);
	LinkedList<Student*>* getAllStudents();

	// ===Employee===
	void deleteEmployee(const Employee&);
	void addEmployee(const Employee&);
	Employee* getEmployeeByEmployeeId(const int&);
	LinkedList<Employee*>* getAllEmployees();

	// ===Contract===
	void deleteContract(const Contract&);
	void addContract(const Contract&);
	Contract* getContractByContractId(const int&);
	LinkedList<Contract*>* getAllContracts();

	// ===Invoice===
	void deleteInvoice(const Invoice&);
	void addInvoice(const Invoice&);
	Invoice* getInvoiceByInvoiceId(const int&);
	LinkedList<Invoice*>* getAllInvoices();

	// ===Room===
	void deleteRoom(const Room&);
	void addRoom(const Room&);
	Room* getRoomByRoomId(const int&);
	LinkedList<Room*>* getAllRooms();
};

