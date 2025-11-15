#pragma once
#include "Date.h"
#include "LinkedList.h"

class Invoice;
class Room;
class Student;
class Contract
{
private:
	int contractId;
	int studentId;
	int roomId;
	Date startDate;
	Date endDate;
	Student* student;
	Room* room;
	LinkedList<Invoice*> invoices;
public:
	Contract(const int& = 0, const int& = 0, const int& = 0, const Date & = Date(), const Date & = Date(), Student* = nullptr, Room* = nullptr);
	Contract(const Contract&);
	~Contract();

	void AddStudent(Student*);
	void AddRoom(Room*);
	void AddInvoice(Invoice*);
	Student* getStudent();
	Room* getRoom();
	LinkedList<Invoice*>* getInvoices();

	int getContractId() const;
	void setContractId(const int&);
	int getStudentId() const;
	void setStudentId(const int&);
	int getRoomId() const;
	void setRoomId(const int&);
	Date getStartDate() const;
	void setStartDate(const Date&);
	Date getEndDate() const;
	void setEndDate(const Date&);
	bool isActive() const;

	Contract& operator=(const Contract&);
	bool operator==(const Contract&);
	bool operator!=(const Contract&);
};
