#pragma once
#include "IRoom.h"
#include "LinkedList.h"
#include "IContact.h"

class IContract;
class Room : public virtual IRoom
{
private:
    int roomId;
    string roomName;
    string roomType;
    int capacity;
    int floor;
    string building;
    bool isActive;
    LinkedList<IContract*> contracts;
public:
    Room(const int& = 0, const string & = "", const string & = "", const int& = 0, const int& = 0, const string& = "", const bool& = true);
    Room(const Room&);
    ~Room();

    void AddContract(IContract*) override;
    LinkedList<IContract*>* getContracts() override;
    bool isAvailable() override;
    bool isVacant() override;

    int getRoomId() const override;
    void setRoomId(const int&) override;
    string getRoomName() const override;
    void setRoomName(const string&) override;
    string getRoomType() const override;
    void setRoomType(const string&) override;
    int getCapacity() const override;
    void setCapacity(const int&) override;
    int getCurrentOccupancy() override;
    int getFloor() const override;
    void setFloor(const int&) override;
    string getBuilding() const override;
    void setBuilding(const string&) override;
    bool getIsActive() const override;
    void setIsActive(const bool&) override;

    IRoom* clone() const override;

    Room& operator=(const Room&);
    bool operator==(const Room&);
    bool operator!=(const Room&);
};
