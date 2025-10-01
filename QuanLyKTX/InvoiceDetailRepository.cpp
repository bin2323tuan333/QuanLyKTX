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
void InvoiceDetailRepository::Add(const InvoiceDetail& invoiceDetail)
{
	InvoiceDetail* temp = new InvoiceDetail[this->n + 1];
	for (int i = 0; i < this->n; i++)
	{
		*(temp + i) = *(this->p + i);
	}
	*(temp + this->n) = invoiceDetail;
	delete[] this->p;
	this->p = temp;
	(this->n)++;
}
void InvoiceDetailRepository::Insert(const InvoiceDetail& invoiceDetail, const int& index)
{
	if (index < 0 || index > this->n)
		return;

	InvoiceDetail* temp = new InvoiceDetail[this->n + 1];
	for (int i = 0; i < index; i++)
	{
		*(temp + i) = *(this->p + i);
	}
	*(temp + index) = invoiceDetail;
	for (int i = index; i < this->n; i++)
	{
		*(temp + i + 1) = *(this->p + i);
	}
	delete[] this->p;
	this->p = temp;
	(this->n)++;
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
int InvoiceDetailRepository::IndexOf(const int& invoiceID, const int& serviceID)
{
	int index = -1;
	for (int i = 0; i < this->n; i++)
	{
		if ((this->p + i)->getInvoiceID() == invoiceID && (this->p + i)->getServiceID() == serviceID)
		{
			index = i;
			break;
		}
	}
	return index;
}
InvoiceDetail InvoiceDetailRepository::Search(const int& invoiceID, const int& serviceID)
{
	int index = IndexOf(invoiceID, serviceID);
	if (index != -1)
		return *(this->p + index);
	else
		return InvoiceDetail();
}

// Update
void InvoiceDetailRepository::Update(InvoiceDetail& invoiceDetail)
{
	int index = IndexOf(invoiceDetail.getInvoiceID(), invoiceDetail.getServiceID());
	if (index == -1)
		return;

	(this->p + index)->setInvoiceID(invoiceDetail.getInvoiceID());
	(this->p + index)->setServiceID(invoiceDetail.getServiceID());
	(this->p + index)->setQuantity(invoiceDetail.getQuantity());
	(this->p + index)->setTotalAmount(invoiceDetail.getTotalAmount());
}

// Delete
void InvoiceDetailRepository::Delete(const int& invoiceID, const int& serviceID)
{
	int index = IndexOf(invoiceID, serviceID);
	if (index == -1) return;

	InvoiceDetail* temp = new InvoiceDetail[this->n - 1];
	for (int i = 0; i < index; i++)
	{
		*(temp + i) = *(this->p + i);
	}
	for (int i = index; i < this->n - 1; i++)
	{
		*(temp + i) = *(this->p + i + 1);
	}
	delete[] this->p;
	this->p = temp;
	(this->n)--;
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