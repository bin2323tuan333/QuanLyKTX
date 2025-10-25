#pragma once
#include "Date.h"
#include <string>
using namespace std;

class Invoice {
private:
    int invoiceID, studentID, employeeID;
    int month, year;
    int roomFee, internetFee, electricFee, waterFee;
    int totalAmount;
    Date createdDate;
    

public:
    // Constructor, Copy constructor, Destructor
    Invoice(const int& = 0, const int& = 0, const int& = 0, const int& = 0, const int& = 0, const int& = 0,
        const int& = 0, const int& = 0, const int& = 0, const int& = 0, const Date & = Date());
    Invoice(const Invoice&);
    ~Invoice();

    // Getter & Setter
    int getInvoiceID() const;
    void setInvoiceID(const int&);

    int getStudentID();
    void setStudentID(const int&);

    int getEmployeeID();
    void setEmployeeID(const int&);

    int getMonth();
    void setMonth(const int&);

    int getYear();
    void setYear(const int&);

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
};
