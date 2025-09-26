#include "Service.h"
#include <iostream>

// Constructor
Service::Service(const int& serviceID, const string& serviceName, const int& unitPrice, const string& description)
    : serviceID(serviceID), serviceName(serviceName), unitPrice(unitPrice), description(description) 
{
}
Service::Service(const Service& s)
    : serviceID(s.serviceID), serviceName(s.serviceName), unitPrice(s.unitPrice), description(s.description) 
{
}
Service::~Service() 
{
}



// Getter & Setter
int Service::getServiceID() 
{
    return this->serviceID;
}
void Service::setServiceID(const int& serviceID) 
{
    this->serviceID = serviceID;
}
string Service::getServiceName() 
{
    return this->serviceName;
}
void Service::setServiceName(const string& serviceName) 
{
    this->serviceName = serviceName;
}
int Service::getUnitPrice() 
{
    return this->unitPrice;
}
void Service::setUnitPrice(const int& unitPrice) 
{
    this->unitPrice = unitPrice;
}
string Service::getDescription() 
{
    return this->description;
}
void Service::setDescription(const string& description) 
{
    this->description = description;
}






void Service::show() 
{
    cout << this->serviceID << " "
        << this->serviceName << " "
        << this->unitPrice << " "
        << this->description;
}
