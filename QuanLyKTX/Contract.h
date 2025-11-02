#pragma once
#include "Date.h"
#include "Room.h"
#include "Student.h"
#include "Invoice.h"


class Contract
{
private:
	int contractId;
	Date startDate;
	Date endDate;
	int duration;

	Student* student;
	Room* room;
	LinkedList<Invoice*> invoices;
public:
	// Constructor, Copy constructor, Destructor
	Contract(
		const int& = 0,
		const Date & = Date(),
		const Date & = Date(),
		const int& = 0,
		Student* = nullptr,
		Room* = nullptr
	);
	Contract(const Contract&);
	~Contract();

	void AddStudent(Student*);
	void AddRoom(Room*);
	void AddInvoice(Invoice*);

	// Getter & Setter
	int getContractId() const;
	void setContractId(const int&);
	Date getStartDate();
	void setStartDate(const Date&);
	Date getEndDate();
	void setEndDate(const Date&);
	int getDuration();
	void setDuration(const int&);

	bool isActive();

	Contract& operator=(const Contract&);
	bool operator==(const Contract&);
	bool operator!=(const Contract&);
};
