#pragma once
#include "Account.h"
#include "LinkedList.h"


class AccountRepository 
{
private:
    string fileName;
    LinkedList<Account> list;

public:
	AccountRepository(const string&);
	~AccountRepository();

    void loadData();
    void saveData();

    void Add(const Account&);
    void Update(const Account&);
    void Delete(const Account&);
    Account* GetById(const int&);
    Account* GetByUsername(const string&);
    LinkedList<Account> GetAll();

    int GetSize();
};