#include "AccountRepository.h"
#include <fstream>
#include <sstream>

AccountRepository::AccountRepository()
{
	LoadDataFromFile();
}
AccountRepository::~AccountRepository()
{
	SaveDataToFile();
}

void AccountRepository::Add(const Account& account)
{
	this->list.add(account);
}

bool AccountRepository::Delete(const int& id)
{
	Account* temp = this->GetById(id);
	if (temp == nullptr) return false;
	this->list.remove(*temp);
	return true;
}
bool AccountRepository::Update(Account& acc)
{
	bool temp = this->Delete(acc.getAccountID());
	if (temp == false) return false;
	this->Add(acc);
	return true;
}
LinkedList<Account> AccountRepository::GetAll()
{
	return this->list;
}
Account* AccountRepository::GetById(const int& accountID)
{
	for (int i = 0; i < this->list.getSize(); i++)
	{
		Account* temp = this->list.getAt(i);
		if (temp->getAccountID() == accountID)
			return temp;
	}
	return nullptr;
}
Account* AccountRepository::GetByUsername(const string& username)
{
	for (int i = 0; i < this->list.getSize(); i++)
	{
		Account* temp = this->list.getAt(i);
		if (temp->getUsername() == username)
			return temp;
	}
	return nullptr;
}

int AccountRepository::GetSize()
{
	return this->list.getSize();
}

void AccountRepository::LoadDataFromFile()
{
	string filename = "Account.txt";
	ifstream file(filename);
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

		this->Add(temp);
	}
	file.close();
}
void AccountRepository::SaveDataToFile()
{
	string filename = "Account.txt";
	ofstream file(filename);
	if (!file.is_open())
		return;

	for (int i = 0; i < this->list.getSize(); i++)
	{
		Account* acc = this->list.getAt(i);

		if (acc != nullptr)
		{
			file << acc->getAccountID() << ";";
			file << acc->getUsername() << ";";
			file << acc->getPassword() << ";";
			file << acc->getRole() << ";";
			file << acc->getStudentID() << ";";
			file << acc->getEmployeeID() << "\n";
		}
	}
	file.close();
}