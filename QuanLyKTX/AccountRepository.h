#pragma once
#include "Account.h"




class AccountRepository
{
private:
	Account* p;
	int n;

public:
	AccountRepository();
	~AccountRepository();

	// Create
	void Add(const Account&);
	void Insert(const Account&, const int&);

	// Read
	int IndexOf(const int&);
	Account SearchByID(const int&);
	Account SearchByUsername(const string&);

	// Update
	void Update(Account&);

	// Delete
	void Delete(const int&); 


	void LoadDataFromFile();
	void SaveDateToFile();

};