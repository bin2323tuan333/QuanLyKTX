#pragma once
#include "Date.h"
#include "Room.h"
#include "Student.h"
#include "Invoice.h"

class Invoice;
class Student;
class Room;
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
	// Constructor, Copy constructor, Destructor
	Contract(
		const int& = 0,
		const int& = 0,
		const int& = 0,
		const Date & = Date(),
		const Date & = Date(),
		Student* = nullptr,
		Room* = nullptr
	);
	Contract(const Contract&);
	~Contract();

	void AddStudent(Student*);
	void AddRoom(Room*);
	void AddInvoice(Invoice*);
	Student* getStudent();
	Room* getRoom();
	LinkedList<Invoice*>* getInvoices();

	// Getter & Setter
	int getContractId() const;
	void setContractId(const int&);
	int getStudentId() const;
	void setStudentId(const int&);
	int getRoomId() const;
	void setRoomId(const int&);
	Date getStartDate();
	void setStartDate(const Date&);
	Date getEndDate();
	void setEndDate(const Date&);

	bool isActive();

	Contract& operator=(const Contract&);
	bool operator==(const Contract&);
	bool operator!=(const Contract&);
};
