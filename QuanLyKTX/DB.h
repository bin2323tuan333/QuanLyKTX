#pragma once
#include <string>
#include "LinkedList.h"
using namespace std;


class IAccount;
class IStudent;
class IEmployee;
class IContract;
class IInvoice;
class IRoom;
class DB
{
private:
	static DB* _Instance;
	LinkedList<IAccount*> listAccounts;
	LinkedList<IStudent*> listStudents;
	LinkedList<IEmployee*> listEmployees;
	LinkedList<IContract*> listContracts;
	LinkedList<IInvoice*> listInvoices;
	LinkedList<IRoom*> listRooms;
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
	LinkedList<IStudent*>* getStudentInRoom(const int&);
	LinkedList<IContract*>* getContractInStudent(const int&);
	LinkedList<IInvoice*>* getInvoiceInContract(const int&);



	// ==== CRUD BASIC ====
	// ===Account===
	void updateAccount(const IAccount&);
	void deleteAccount(const IAccount&);
	void addAccount(IAccount*);
	IAccount* getAccountByUsername(const string&);
	IAccount* getAccountByUserId(const int&);
	LinkedList<IAccount*>* getAllAccounts();

	// ===Student===
	void updateStudent(const int& id, const IStudent&);
	void deleteStudent(const IStudent&);
	void addStudent(const IStudent&);
	IStudent* getStudentByStudentId(const int&);
	LinkedList<IStudent*>* getAllStudents();

	// ===Employee===
	void updateEmployee(const IEmployee&);
	void deleteEmployee(const IEmployee&);
	void addEmployee(const IEmployee&);
	IEmployee* getEmployeeByEmployeeId(const int&);
	LinkedList<IEmployee*>* getAllEmployees();

	// ===Contract===
	void updateContract(const IContract&);
	void deleteContract(const IContract&);
	void addContract(const IContract&);
	IContract* getContractByContractId(const int&);
	LinkedList<IContract*>* getAllContracts();

	// ===Invoice===
	void updateInvoice(const IInvoice&);
	void deleteInvoice(const IInvoice&);
	void addInvoice(const IInvoice&);
	IInvoice* getInvoiceByInvoiceId(const int&);
	LinkedList<IInvoice*>* getAllInvoices();

	// ===Room===
	void updateRoom(const IRoom&);
	void deleteRoom(const IRoom&);
	void addRoom(const IRoom&);
	IRoom* getRoomByRoomId(const int&);
	LinkedList<IRoom*>* getAllRooms();
};

