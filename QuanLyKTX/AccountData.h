#pragma once
#include "Account.h"
#include "LinkedList.h"
#include "HashTable.h"


class AccountData 
{
private:
    string fileName;
    LinkedList<Account*> list;
    HashTable<int, Account*> mapUserId;

public:
    AccountData(const string&);
	~AccountData();

    void loadData();
    void saveData();
    LinkedList<Account*>* getList();

    void Add(const Account&);
    void Update(const Account&);
    void Delete(const Account&);
    Account* GetByUserId(const int&);
    Account* GetByUsername(const string&);

    int GetSize();
};