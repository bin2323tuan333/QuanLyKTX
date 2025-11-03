#include "AccountData.h"
#include <fstream>
#include <sstream>

AccountData::AccountData(const string& fileName)
	:fileName(fileName)
{
	this->loadData();
}
AccountData::~AccountData()
{
	this->saveData();
}

void AccountData::loadData()
{
	ifstream file(this->fileName);
	if (!file.is_open())
		return;

	string line;
	while (getline(file, line))
	{
		if (line == "")
			continue;
		stringstream ss(line);
		Account* acc = new Account();
		string token;
		getline(ss, token, ';'); acc->setUserId(stoi(token));
		getline(ss, token, ';'); acc->setUsername(token);
		getline(ss, token, ';'); acc->setPassword(token);
		this->list.add(acc);
		this->mapUserId.insert(acc->getUserId(), acc);
	}
	file.close();
}
void AccountData::saveData()
{
	ofstream file(this->fileName);
	if (!file.is_open())
		return;
	for (ListNode<Account*>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		file << (p->value)->getUserId() << ";";
		file << (p->value)->getUsername() << ";";
		file << (p->value)->getPassword() << endl;
	}
	file.close();
}

LinkedList<Account*>* AccountData::getList()
{
	return &(this->list);
}

void AccountData::Add(const Account& account)
{
	Account* acc = new Account(account);
	this->list.add(acc);
	this->mapUserId.insert(acc->getUserId(), acc);
}
void AccountData::Delete(const Account& account)
{
	Account* accToDelete = GetByUserId(account.getUserId());
	if (accToDelete == nullptr)
		return;
	this->list.remove(accToDelete);
	this->mapUserId.remove(accToDelete->getUserId());
	delete accToDelete;
}
void AccountData::Update(const Account& account)
{
	Account* accToUpdate = GetByUserId(account.getUserId());
	if (accToUpdate == nullptr)
		return;
	*accToUpdate = account;
}
Account* AccountData::GetByUserId(const int& userId)
{
	Account** acc = this->mapUserId.search(userId);
	if (acc == nullptr) return nullptr;
	return *acc;
}
Account* AccountData::GetByUsername(const string& username)
{
	for (ListNode<Account*>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		if (username == p->value->getUsername())
			return p->value;
	}
	return nullptr;
}
int AccountData::GetSize()
{
	return this->list.getSize();
}