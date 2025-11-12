#pragma once
#include "Date.h"
#include "IStudent.h"
#include "IRoom.h"
#include "IInvoice.h"
#include "LinkedList.h"

class IContract {
public:
	virtual ~IContract() = default;

	virtual IStudent* getStudent() = 0;
	virtual IRoom* getRoom() = 0;
	virtual LinkedList<IInvoice*>* getInvoices() = 0;
	virtual void AddStudent(IStudent* student) = 0;
	virtual void AddRoom(IRoom* room) = 0;
	virtual void AddInvoice(IInvoice* invoice) = 0;

	virtual int getContractId() const = 0;
	virtual void setContractId(const int&) = 0;
	virtual int getStudentId() const = 0;
	virtual void setStudentId(const int&) = 0;
	virtual int getRoomId() const = 0;
	virtual void setRoomId(const int&) = 0;
	virtual Date getStartDate() const = 0;
	virtual void setStartDate(const Date&) = 0;
	virtual Date getEndDate() const = 0;
	virtual void setEndDate(const Date&) = 0;
	
	virtual bool isActive() const = 0;
};