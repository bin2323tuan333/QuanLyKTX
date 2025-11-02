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
		this->map.insert(acc->getUsername(), acc);
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



//void AccountData::Add(const Account& account)
//{
//
//}
//void AccountData::Delete(const Account& account)
//{
//	
//}
//void AccountData::Update(const Account& account)
//{
//
//}
//LinkedList<Account> AccountData::GetAll()
//{
//
//}
//Account* AccountData::GetById(const int& accountID)
//{
//
//}
//Account* AccountData::GetByUsername(const string& username)
//{
//
//}
//
//int AccountData::GetSize()
//{
//	return this->list.getSize();
//}