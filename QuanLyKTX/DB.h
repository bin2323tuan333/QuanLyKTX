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
	void deleteAccount(const IAccount&);
	void addAccount(IAccount*);
	IAccount* getAccountByUsername(const string&);
	IAccount* getAccountByUserId(const int&);
	LinkedList<IAccount*>* getAllAccounts();

	// ===Student===
	void deleteStudent(const IStudent&);
	void addStudent(const IStudent&);
	IStudent* getStudentByStudentId(const int&);
	LinkedList<IStudent*>* getAllStudents();

	// ===Employee===
	void deleteEmployee(const IEmployee&);
	void addEmployee(const IEmployee&);
	IEmployee* getEmployeeByEmployeeId(const int&);
	LinkedList<IEmployee*>* getAllEmployees();

	// ===Contract===
	void deleteContract(const IContract&);
	void addContract(const IContract&);
	IContract* getContractByContractId(const int&);
	LinkedList<IContract*>* getAllContracts();

	// ===Invoice===
	void deleteInvoice(const IInvoice&);
	void addInvoice(const IInvoice&);
	IInvoice* getInvoiceByInvoiceId(const int&);
	LinkedList<IInvoice*>* getAllInvoices();

	// ===Room===
	void deleteRoom(const IRoom&);
	void addRoom(const IRoom&);
	IRoom* getRoomByRoomId(const int&);
	LinkedList<IRoom*>* getAllRooms();
};

