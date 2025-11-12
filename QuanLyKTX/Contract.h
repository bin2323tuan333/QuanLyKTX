#pragma once
#include "IContract.h"
#include "Date.h"
#include "IStudent.h"
#include "IRoom.h"
#include "IInvoice.h"
#include "LinkedList.h"



class Contract : public IContract
{
private:
	int contractId;
	int studentId;
	int roomId;
	Date startDate;
	Date endDate;
	IStudent* student;
	IRoom* room;
	LinkedList<IInvoice*> invoices;
public:
	Contract(const int& = 0, const int& = 0, const int& = 0, const Date & = Date(), const Date & = Date(), IStudent* = nullptr, IRoom* = nullptr);
	Contract(const Contract&);
	~Contract();

	void AddStudent(IStudent*) override;
	void AddRoom(IRoom*) override;
	void AddInvoice(IInvoice*) override;
	IStudent* getStudent() override;
	IRoom* getRoom() override;
	LinkedList<IInvoice*>* getInvoices() override;

	int getContractId() const override;
	void setContractId(const int&) override;
	int getStudentId() const override;
	void setStudentId(const int&) override;
	int getRoomId() const override;
	void setRoomId(const int&) override;
	Date getStartDate() const override;
	void setStartDate(const Date&) override;
	Date getEndDate() const override;
	void setEndDate(const Date&) override;
	bool isActive() const override;

	Contract& operator=(const Contract&);
	bool operator==(const Contract&);
	bool operator!=(const Contract&);
};
