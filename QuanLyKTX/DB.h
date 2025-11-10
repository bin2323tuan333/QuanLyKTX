#pragma once
#include "Account.h"
#include "Employee.h"
#include "Student.h"
#include "Contract.h"
#include "Room.h"
#include "Invoice.h"
#include "LinkedList.h"



class DB
{
private:
	static DB* _Instance;


	// Data
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
	void updateAccount(const Account&);
	void deleteAccount(const Account&);
	void addAccount(Account*);
	Account* getAccountByUsername(const string&);
	Account* getAccountByUserId(const int&);
	LinkedList<Account*>* getAllAccounts();

	// ===Student===
	void updateStudent(const Student&);
	void deleteStudent(const Student&);
	void addStudent(const Student&);
	Student* getStudentByStudentId(const int&);
	LinkedList<Student*>* getAllStudents();

	// ===Employee===
	void updateEmployee(const Employee&);
	void deleteEmployee(const Employee&);
	void addEmployee(const Employee&);
	Employee* getEmployeeByEmployeeId(const int&);
	LinkedList<Employee*>* getAllEmployees();

	// ===Contract===
	void updateContract(const Contract&);
	void deleteContract(const Contract&);
	void addContract(const Contract&);
	Contract* getContractByContractId(const int&);
	LinkedList<Contract*>* getAllContracts();

	// ===Invoice===
	void updateInvoice(const Invoice&);
	void deleteInvoice(const Invoice&);
	void addInvoice(const Invoice&);
	Invoice* getInvoiceByInvoiceId(const int&);
	LinkedList<Invoice*>* getAllInvoices();

	// ===Room===
	void updateRoom(const Room&);
	void deleteRoom(const Room&);
	void addRoom(const Room&);
	Room* getRoomByRoomId(const int&);
	LinkedList<Room*>* getAllRooms();



    // ==================== RELATIONSHIP QUERIES ====================
    // Student -> Room
    LinkedList<Student*>* getStudentsInRoom(int roomId);
    Room* getRoomOfStudent(int studentId);

    // Student -> Contracts
    LinkedList<Contract*>* getContractsByStudent(int studentId);
    Contract* getActiveContractByStudent(int studentId);

    // Contract -> Invoices
    LinkedList<Invoice*>* getInvoicesByContract(int contractId);
    LinkedList<Invoice*> getUnpaidInvoicesByContract(int contractId);

    // Student -> Invoices (through contracts)
    LinkedList<Invoice*>* getAllInvoicesByStudent(int studentId);
    LinkedList<Invoice*> getUnpaidInvoicesByStudent(int studentId);

    // Room -> Contracts
    LinkedList<Contract*>* getContractsByRoom(int roomId);

    /*// ==================== ACCOUNT MANAGEMENT ====================
    void addAccount(Account* account);
    void updateAccount(const Account& account);
    void deleteAccount(const Account& account);
    void deleteAccountById(int accountId);

    Account* getAccountById(int accountId);
    Account* getAccountByUsername(const string& username);
    LinkedList<Account*>* getAllAccounts();
    int generateAccountId() { return ++nextAccountId; }

    // ==================== STUDENT MANAGEMENT ====================
    void addStudent(Student* student);
    void updateStudent(const Student& student);
    void deleteStudent(const Student& student);
    void deleteStudentById(int studentId);

    Student* getStudentById(int studentId);
    Student* getStudentByEmail(const string& email);
    LinkedList<Student*>* getAllStudents();
    LinkedList<Student*>* getStudentsWithoutRoom();

    int generateStudentId() { return ++nextStudentId; }

    // ==================== EMPLOYEE MANAGEMENT ====================
    void addEmployee(Employee* employee);
    void updateEmployee(const Employee& employee);
    void deleteEmployee(const Employee& employee);
    void deleteEmployeeById(int employeeId);

    Employee* getEmployeeById(int employeeId);
    LinkedList<Employee*>* getAllEmployees();
    int generateEmployeeId() { return ++nextEmployeeId; }

    // ==================== ROOM MANAGEMENT ====================
    void addRoom(Room* room);
    void updateRoom(const Room& room);
    void deleteRoom(const Room& room);
    void deleteRoomById(int roomId);

    Room* getRoomById(int roomId);
    LinkedList<Room*>* getAllRooms();
    LinkedList<Room*>* getRoomsByBuilding(const string& building);
    LinkedList<Room*>* getRoomsByFloor(const int& floor);
    LinkedList<Room*>* getRoomsByType(const string& type);
    LinkedList<Room*>* getAvailableRooms();
    LinkedList<Room*>* getAvailableRoomsByType(const string& type);

    int generateRoomId() { return ++nextRoomId; }
    int getRoomOccupancy(int roomId);
    bool isRoomAvailable(int roomId);

    // ==================== CONTRACT MANAGEMENT ====================
    void addContract(Contract* contract);
    void updateContract(const Contract& contract);
    void deleteContract(const Contract& contract);
    void deleteContractById(int contractId);

    Contract* getContractById(int contractId);
    LinkedList<Contract*>* getAllContracts();
    LinkedList<Contract*>* getActiveContracts();
    LinkedList<Contract*>* getPendingContracts();
    LinkedList<Contract*>* getExpiredContracts();
    LinkedList<Contract*>* getExpiringContracts(int daysAhead);
    LinkedList<Contract*>* getContractsByStatus(const string& status);

    int generateContractId() { return ++nextContractId; }
    bool hasActiveContract(int studentId);

    // ==================== INVOICE MANAGEMENT ====================
    void addInvoice(Invoice* invoice);
    void updateInvoice(const Invoice& invoice);
    void deleteInvoice(const Invoice& invoice);
    void deleteInvoiceById(int invoiceId);

    Invoice* getInvoiceById(int invoiceId);
    LinkedList<Invoice*>* getAllInvoices();
    LinkedList<Invoice*>* getUnpaidInvoices();
    LinkedList<Invoice*>* getPaidInvoices();
    LinkedList<Invoice*>* getOverdueInvoices();
    LinkedList<Invoice*>* getInvoicesByMonth(int month, int year);
    LinkedList<Invoice*>* getInvoicesByDateRange(const string& startDate, const string& endDate);
    LinkedList<Invoice*>* getInvoicesByType(const string& type);
    int generateInvoiceId() { return ++nextInvoiceId; }

    // ==================== STATISTICS ====================
    int getTotalStudents();
    int getTotalEmployees();
    int getTotalRooms();
    int getOccupiedRooms();
    int getAvailableRoomCount();
    double getOccupancyRate();

    int getTotalContracts();
    int getActiveContractCount();
    int getExpiredContractCount();

    int getTotalInvoices();
    int getUnpaidInvoiceCount();
    double getTotalRevenue();
    double getTotalUnpaidAmount();
    double getTotalDebtByStudent(int studentId);

    // ==================== VALIDATION ====================
    bool isEmailExists(const string& email);
    bool isPhoneExists(const string& phone);
    bool canDeleteStudent(int studentId);  // Check if has active contracts
    bool canDeleteRoom(int roomId);        // Check if has active contracts
    bool canDeleteContract(int contractId); // Check if has unpaid invoices*/
};

