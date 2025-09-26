#include "ServiceRegistration.h"
#include <iostream>

// Constructor
ServiceRegistration::ServiceRegistration(const int& studentID, const int& serviceID, const Date& registrationDate)
    : studentID(studentID), serviceID(serviceID), registrationDate(registrationDate) 
{
}
ServiceRegistration::ServiceRegistration(const ServiceRegistration& sr)
    : studentID(sr.studentID), serviceID(sr.serviceID), registrationDate(sr.registrationDate) 
{
}
ServiceRegistration::~ServiceRegistration() 
{
}
int ServiceRegistration::getStudentID() 
{
    return this->studentID;
}
void ServiceRegistration::setStudentID(const int& studentID) 
{
    this->studentID = studentID;
}
int ServiceRegistration::getServiceID() 
{
    return this->serviceID;
}
void ServiceRegistration::setServiceID(const int& serviceID) 
{
    this->serviceID = serviceID;
}
Date ServiceRegistration::getRegistrationDate() 
{
    return this->registrationDate;
}
void ServiceRegistration::setRegistrationDate(const Date& registrationDate) 
{
    this->registrationDate = registrationDate;
}







void ServiceRegistration::show() 
{
    cout << this->studentID << " "
        << this->serviceID << " "
        << this->registrationDate;
}
