#pragma once


#include <string>
#include "Date.h"

using namespace std;

class Person {
protected:
    string fullName;
    Date dateOfBirth;
    string gender;
    string phoneNumber;
    string email;

public:
    // Constructor
    Person(const string& = "", const Date& datfBirth = Date(), const string& = "", const string& = "", const string& = "");
    Person(const Person& p);
    ~Person();

    string getFullName();
    void setFullName(const string&);

    Date getDateOfBirth();
    void setDateOfBirth(const Date&);

    string getGender();
    void setGender(const string&);

    string getPhoneNumber();
    void setPhoneNumber(const string&);

    string getEmail();
    void setEmail(const string&);

    virtual void show();
};
