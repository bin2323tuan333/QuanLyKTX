#pragma once
#include "Account.h"
#include "LinkedList.h"


class AccountRepository
{
private:
	LinkedList<Account> list;

public:
	AccountRepository();
	~AccountRepository();

    void Add(const Account&);
    bool Delete(const int&);
    bool Update(Account&);
    LinkedList<Account> GetAll();
    Account* GetById(const int&);
    Account* GetByUsername(const string&);

    int GetSize();

    void LoadDataFromFile();
    void SaveDataToFile();
};