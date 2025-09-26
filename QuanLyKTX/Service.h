#pragma once
#include <string>
using namespace std;


class Service {
private:
    int serviceID;
    string serviceName;
    int unitPrice;
    string description;

public:
    // Constructor, Copy constructor, Destructor
    Service(const int& = 0, const string & = "", const int& = 0, const string & = "");
    Service(const Service&);
    ~Service();

    // Getter & Setter
    int getServiceID();
    void setServiceID(const int&);

    string getServiceName();
    void setServiceName(const string&);

    int getUnitPrice();
    void setUnitPrice(const int&);

    string getDescription();
    void setDescription(const string&);

    void show();
};
