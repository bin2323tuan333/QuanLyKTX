#include <iostream>
#include "Invoice.h"

// Constructor
Invoice::Invoice(const int& invoiceID, const int& totalAmount, const Date& createdDate, const string& paymentPeriod, const int& employeeID)
    : invoiceID(invoiceID), totalAmount(totalAmount), createdDate(createdDate), paymentPeriod(paymentPeriod), employeeID(employeeID) 
{
}
Invoice::Invoice(const Invoice& inv)
    : invoiceID(inv.invoiceID), totalAmount(inv.totalAmount), createdDate(inv.createdDate), paymentPeriod(inv.paymentPeriod), employeeID(inv.employeeID) {
}
Invoice::~Invoice() 
{
}




// Getter & Setter
int Invoice::getInvoiceID() 
{
    return this->invoiceID;
}
void Invoice::setInvoiceID(const int& invoiceID)
{
    this->invoiceID = invoiceID;
}
int Invoice::getTotalAmount() 
{
    return this->totalAmount;
}
void Invoice::setTotalAmount(const int& totalAmount) 
{
    this->totalAmount = totalAmount;
}
Date Invoice::getCreatedDate() 
{
    return this->createdDate;
}
void Invoice::setCreatedDate(const Date& createdDate) 
{
    this->createdDate = createdDate;
}
string Invoice::getPaymentPeriod() 
{
    return this->paymentPeriod;
}
void Invoice::setPaymentPeriod(const string& paymentPeriod) 
{
    this->paymentPeriod = paymentPeriod;
}
int Invoice::getEmployeeID() 
{
    return this->employeeID;
}
void Invoice::setEmployeeID(const int& employeeID) 
{
    this->employeeID = employeeID;
}





void Invoice::show() 
{
    cout << this->invoiceID << " "
        << this->totalAmount << " "
        << this->createdDate << " "
        << this->paymentPeriod << " "
        << this->employeeID;
}
