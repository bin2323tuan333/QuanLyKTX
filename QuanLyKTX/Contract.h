#pragma once
#include "Date.h"




class Contract 
{
private:
    int contractID, studentID, roomID;
    Date startDate, endDate;
    int duration;

public:
    // Constructor, Copy constructor, Destructor
    Contract(const int& = 0, const int& = 0, const int& = 0, const Date & = Date(), const Date & = Date(), const int& = 0);
    Contract(const Contract&);
    ~Contract();

    // Getter & Setter
    int getContractID();
    void setContractID(const int&);

    Date getStartDate();
    void setStartDate(const Date&);

    Date getEndDate();
    void setEndDate(const Date&);

    int getDuration();
    void setDuration(const int&);

    int getStudentID();
    void setStudentID(const int&);

    int getRoomID();
    void setRoomID(const int&);


    Contract& operator=(const Contract&);
    bool operator==(const Contract&);
};
