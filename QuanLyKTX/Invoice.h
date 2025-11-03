#pragma once
#include "Date.h"
#include "Student.h"
#include "Employee.h"
#include <string>
using namespace std;

class Invoice {
private:
    int invoiceId;
    int roomFee, internetFee, electricFee, waterFee;
    int totalAmount;
    Date createdDate;
    
    int employeeId;
    int contractId;
    Contract* contract;
    Employee* employee;

public:
    // Constructor, Copy constructor, Destructor
    Invoice(
        const int& = 0, 
        const int& = 0, 
        const int& = 0, 
        const int& = 0, 
        const int& = 0, 
        const int& = 0,
        const Date & = Date(),
        Contract* = nullptr,
        Employee* = nullptr
    );
    Invoice(const Invoice&);
    ~Invoice();

    void AddContract(Contract*);
    void AddEmployee(Employee*);
    Contract* getContract();
    Employee* getEmployee();

    // Getter & Setter
    int getInvoiceId() const;
    void setInvoiceId(const int&);

    int getContractId() const;
    void setContractId(const int&);

    int getEmployeeId() const;
    void setEmployeeId(const int&);

    int getRoomFee();
    void setRoomFee(const int&);

    int getInternetFee();
    void setInternetFee(const int&);

    int getElectricFee();
    void setElectricFee(const int&);

    int getWaterFee();
    void setWaterFee(const int&);

    int getTotalAmount();
    void setTotalAmount(const int&);

    Date getCreatedDate();
    void setCreatedDate(const Date&);


    Invoice& operator=(const Invoice&);
    bool operator==(const Invoice&);
    bool operator!=(const Invoice&);
};
