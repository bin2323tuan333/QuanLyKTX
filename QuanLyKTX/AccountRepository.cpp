#include "AccountRepository.h"
#include <fstream>
#include <sstream>

AccountRepository::AccountRepository(const string& fileName)
	:fileName(fileName)
{
	this->loadData();
	
}
AccountRepository::~AccountRepository()
{
	this->saveData();
}

void AccountRepository::loadData()
{
	ifstream file(this->fileName);
	if (!file.is_open())
		return;
	string line;

	while (getline(file, line)) {
		if (line.empty()) continue;
		stringstream ss(line);
		string token;
		Account temp;

		getline(ss, token, ';'); temp.setAccountID(stoi(token));
		getline(ss, token, ';'); temp.setUsername(token);
		getline(ss, token, ';'); temp.setPassword(token);
		getline(ss, token, ';'); temp.setRole(token);
		getline(ss, token, ';'); temp.setStudentID(stoi(token));
		getline(ss, token, ';'); temp.setEmployeeID(stoi(token));
		this->list.add(temp);
	}
	file.close();
}
void AccountRepository::saveData()
{
	ofstream file(this->fileName);
	if (!file.is_open())
		return;

	for (ListNode<Account>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		file << p->value.getAccountID() << ";";
		file << p->value.getUsername() << ";";
		file << p->value.getPassword() << ";";
		file << p->value.getRole() << ";";
		file << p->value.getStudentID() << ";";
		file << p->value.getEmployeeID() << "\n";
	}
	file.close();
}



void AccountRepository::Add(const Account& account)
{
	this->list.add(account);
}
void AccountRepository::Delete(const Account& account)
{
	Account* temp = this->GetById(account.getAccountID());
	if (temp == nullptr) return;
	this->list.remove(*temp);
}
void AccountRepository::Update(const Account& account)
{
	Account* temp = this->GetById(account.getAccountID());
	*temp = account;
}
LinkedList<Account> AccountRepository::GetAll()
{
	return this->list;
}
Account* AccountRepository::GetById(const int& accountID)
{
	for (ListNode<Account>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		if (p->value.getAccountID() == accountID)
			return &(p->value);
	}
	return nullptr;
}
Account* AccountRepository::GetByUsername(const string& username)
{
	for (ListNode<Account>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		if (p->value.getUsername() == username)
			return &(p->value);
	}
	return nullptr;
}

int AccountRepository::GetSize()
{
	return this->list.getSize();
}