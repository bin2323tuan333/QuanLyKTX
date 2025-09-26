#include "InvoiceDetailRepository.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

InvoiceDetailRepository::InvoiceDetailRepository()
{
	this->p = nullptr;
	this->n = 0;
}
InvoiceDetailRepository::~InvoiceDetailRepository()
{
	delete[] this->p;
}

// Create
void InvoiceDetailRepository::Add(const InvoiceDetail&)
{

}
void InvoiceDetailRepository::Insert(const InvoiceDetail&, const int&)
{

}

// Read
void InvoiceDetailRepository::Show()
{
	for (int i = 0; i < this->n; i++)
	{
		(this->p + i)->show();
		cout << endl;
	}
}
int InvoiceDetailRepository::IndexOf(const int&)
{

}
InvoiceDetail InvoiceDetailRepository::Search(const int&)
{

}

// Update
void InvoiceDetailRepository::Update(const int&)
{

}

// Delete
void InvoiceDetailRepository::Delete(const int&)
{

}


void InvoiceDetailRepository::LoadDataFromFile()
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

		InvoiceDetail temp;

		getline(ss, token, ';'); temp.setInvoiceDetailID(stoi(token));
		getline(ss, token, ';'); temp.setQuantity(stoi(token));
		getline(ss, token, ';'); temp.setTotalAmount(stoi(token));
		getline(ss, token, ';'); temp.setServiceID(stoi(token));

		this->Add(temp);
	}
	file.close();
}
void InvoiceDetailRepository::SaveDateToFile()
{
	string filename = "Account.txt";
	ofstream file(filename);

	if (!file.is_open()) {
		cout << "Khong the mo file: " << filename << "!";
		return;
	}

	for (int i = 0; i < this->n; i++)
	{
		file << (this->p + i)->getInvoiceDetailID() << ";";
		file << (this->p + i)->getQuantity() << ";";
		file << (this->p + i)->getTotalAmount() << ";";
		file << (this->p + i)->getServiceID() << "\n";
	}
	file.close();
}