#pragma once
#include "Date.h"




class ServiceRegistration {
private:
    int studentID;
    int serviceID;
    Date registrationDate;

public:
    // Constructor, Copy constructor, Destructor
    ServiceRegistration(const int& = 0, const int& = 0, const Date & = Date());
    ServiceRegistration(const ServiceRegistration&);
    ~ServiceRegistration();

    // Getter & Setter
    int getStudentID();
    void setStudentID(const int&);

    int getServiceID();
    void setServiceID(const int&);

    Date getRegistrationDate();
    void setRegistrationDate(const Date&);

    void show();
};
