#pragma once
#include "Account.h"
#include "LinkedList.h"
#include "HashTable.h"


class AccountData 
{
private:
    string fileName;
    LinkedList<Account*> list;
    HashTable<string, Account*> map;


public:
    AccountData(const string&);
	~AccountData();

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