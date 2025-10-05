#include "AccountRepository.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

AccountRepository::AccountRepository()
{
	this->p = nullptr;
	this->n = 0;
	LoadDataFromFile();
}
AccountRepository::~AccountRepository()
{
	delete[] this->p;
}

// Create
void AccountRepository::Add(const Account& account)
{
	if (this->n == 0)
	{
		this->p = new Account[this->n + 1];
		*(this->p + this->n) = account;
	}
	else
	{
		Account* temp = new Account[this->n];
		for (int i = 0; i < this->n; i++)
		{
			*(temp + i) = *(this->p + i);
		}
		delete[] this->p;
		this->p = new Account[this->n + 1];
		for (int i = 0; i < this->n; i++)
		{
			*(this->p + i) = *(temp + i);
		}
		delete[] temp;
		*(this->p + this->n) = account;
	}
	(this->n)++;
}
void AccountRepository::Insert(const Account& account, const int& index)
{
	if (index < 0 || index > this->n) return;

	Account* temp = new Account[this->n + 1];
	for (int i = 0; i < index; i++)
	{
		*(temp + i) = *(this->p + i);
	}
	*(temp + index) = account;
	for (int i = index; i < this->n; i++)
	{
		*(temp + i + 1) = *(this->p + i);
	}
	delete[] this->p;
	p = temp;
	this->n++;
}

// Read
int AccountRepository::IndexOf(const int& accountID)
{
	int index = -1;
	for (int i = 0; i < this->n; i++)
	{
		if ((this->p + i)->getAccountID() == accountID)
		{
			index = i;
			break;
		}
	}
	return index;
}
Account AccountRepository::SearchByID(const int& accountID)
{
	int index = IndexOf(accountID);
	if (index != -1)
	{
		return *(this->p + index);
	}
	return Account();
}
Account AccountRepository::SearchByUsername(const string& username)
{
	for (int i = 0; i < this->n; i++)
	{
		if ((this->p + i)->getUsername() == username)
		{
			return *(this->p + i);
		}
	}
	return Account();
}


// Update
void AccountRepository::Update(Account& account)
{
	int index = IndexOf(account.getAccountID());
	if (index == -1)
	{
		return;
	}
	
	(this->p + index)->setAccountID(account.getAccountID());
	(this->p + index)->setUsername(account.getUsername());
	(this->p + index)->setPassword(account.getPassword());
	(this->p + index)->setEmployeeID(account.getEmployeeID());
	(this->p + index)->setStudentID(account.getStudentID());
	(this->p + index)->setRole(account.getRole());
}

//Delete
void AccountRepository::Delete(const int& accountID)
{
	int index = IndexOf(accountID);
	if (index == -1) return;

	Account* temp = new Account[this->n - 1];
	int j = 0;
	for (int i = 0; i < this->n; i++)
	{
		{
		if (i != index)
			*(temp + j) = *(this->p + i);
			j++;
		}
	}
	delete[] this->p;
	p = temp;
	this->n--;
}


void AccountRepository::LoadDataFromFile()
{
	string filename = "Account.txt";
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Khong the mo file " << filename << "!";
		return;
	}
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
void AccountRepository::SaveDateToFile()
{
	string filename = "Account.txt";
	ofstream file(filename);

	if (!file.is_open()) {
		cout << "Khong the mo file: " << filename << "!";
		return;
	}

	for (int i = 0; i < this->n; i++)
	{
		file << (this->p + i)->getAccountID() << ";";
		file << (this->p + i)->getUsername() << ";";
		file << (this->p + i)->getPassword() << ";";
		file << (this->p + i)->getRole() << ";";
		file << (this->p + i)->getStudentID() << ";";
		file << (this->p + i)->getEmployeeID() << "\n";
	}
	file.close();
}