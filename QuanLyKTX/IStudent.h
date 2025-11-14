#pragma once
#include "IPerson.h"
#include "LinkedList.h"

class IContract;
class IStudent : public virtual IPerson 
{
public:
	virtual ~IStudent();

	virtual string getRole() = 0;
	virtual void AddContract(IContract*) = 0;
	virtual LinkedList<IContract*>* getContracts() = 0;
	virtual bool hasActiveContract() = 0;

	virtual int getStudentId() const = 0;
	virtual string getClassName() const = 0;
	virtual string getFaculty() const = 0;
	virtual void setStudentId(const int&) = 0;
	virtual void setClassName(const string&) = 0;
	virtual void setFaculty(const string&) = 0;

	virtual IStudent* clone() const = 0;
};