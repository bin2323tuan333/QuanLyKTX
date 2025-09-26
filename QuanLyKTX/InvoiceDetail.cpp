#include "InvoiceDetail.h"
#include <iostream>
using namespace std;

// Constructor
InvoiceDetail::InvoiceDetail(const int& invoiceDetailID, const int& quantity, const int& totalAmount, const int& serviceID)
    : invoiceDetailID(invoiceDetailID), quantity(quantity), totalAmount(totalAmount), serviceID(serviceID)
{
}
InvoiceDetail::InvoiceDetail(const InvoiceDetail& id)
    : invoiceDetailID(id.invoiceDetailID), quantity(id.quantity), totalAmount(id.totalAmount), serviceID(id.serviceID) 
{
}
InvoiceDetail::~InvoiceDetail() 
{
}

// Getter & Setter
int InvoiceDetail::getInvoiceDetailID() 
{
    return this->invoiceDetailID;
}
void InvoiceDetail::setInvoiceDetailID(const int& invoiceDetailID) 
{
    this->invoiceDetailID = invoiceDetailID;
}
int InvoiceDetail::getQuantity() 
{
    return this->quantity;
}
void InvoiceDetail::setQuantity(const int& quantity) 
{
    this->quantity = quantity;
}
int InvoiceDetail::getTotalAmount() 
{
    return this->totalAmount;
}
void InvoiceDetail::setTotalAmount(const int& totalAmount) 
{
    this->totalAmount = totalAmount;
}
int InvoiceDetail::getServiceID() 
{
    return this->serviceID;
}
void InvoiceDetail::setServiceID(const int& serviceID) 
{
    this->serviceID = serviceID;
}







void InvoiceDetail::show() 
{
    cout << this->invoiceDetailID << " "
        << this->serviceID << " "
        << this->quantity << " "
        << this->totalAmount;
}
