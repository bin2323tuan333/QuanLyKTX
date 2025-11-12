#pragma once
#include "IPerson.h"
#include "IContract.h"
#include "LinkedList.h"

class IStudent : public IPerson {
public:
	virtual ~IStudent();

	virtual string getRole() override = 0;
	virtual void AddContract(IContract* contract) = 0;
	virtual LinkedList<IContract*>* getContracts() = 0;

	virtual int getStudentId() const = 0;
	virtual string getClassName() const = 0;
	virtual string getFaculty() const = 0;
	virtual void setStudentId(const int&) = 0;
	virtual void setClassName(const string&) = 0;
	virtual void setFaculty(const string&) = 0;
};

IStudent::~IStudent()
{
}