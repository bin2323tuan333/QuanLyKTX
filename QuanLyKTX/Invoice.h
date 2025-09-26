#pragma once

#include "Date.h"
#include <string>
using namespace std;

class Invoice {
private:
    int invoiceID;
    int totalAmount;
    Date createdDate;
    string paymentPeriod;
    int employeeID;

public:
    // Constructor, Copy constructor, Destructor
    Invoice(const int& = 0, const int& = 0, const Date & = Date(), const string & = "", const int& = 0);
    Invoice(const Invoice&);
    ~Invoice();

    // Getter & Setter
    int getInvoiceID();
    void setInvoiceID(const int&);

    int getTotalAmount();
    void setTotalAmount(const int&);

    Date getCreatedDate();
    void setCreatedDate(const Date&);

    string getPaymentPeriod();
    void setPaymentPeriod(const string&);

    int getEmployeeID();
    void setEmployeeID(const int&);

    void show();
};
