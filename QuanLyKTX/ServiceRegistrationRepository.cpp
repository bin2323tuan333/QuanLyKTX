#include "ServiceRegistrationRepository.h"
#include <fstream>
#include <sstream>

ServiceRegistrationRepository::ServiceRegistrationRepository()
{
	this->p = nullptr;
	this->n = 0;
}
ServiceRegistrationRepository::~ServiceRegistrationRepository()
{
	delete[] this->p;
}

// Create
void ServiceRegistrationRepository::Add(const ServiceRegistration& serviceRegistration)
{
	ServiceRegistration* temp = new ServiceRegistration[this->n + 1];
	for (int i = 0; i < this->n; i++)
	{
		*(temp + i) = *(this->p + i);
	}
	*(temp + this->n) = serviceRegistration;
	delete[] this->p;
	this->p = temp;
	(this->n)++;
}
void ServiceRegistrationRepository::Insert(const ServiceRegistration& serviceRegistration, const int& index)
{
	ServiceRegistration* temp = new ServiceRegistration[this->n + 1];
	for (int i = 0; i < index; i++)
	{
		*(temp + i) = *(this->p + i);
	}
	*(temp + index) = serviceRegistration;
	for (int i = index; i < this->n; i++)
	{
		*(temp + i + 1) = *(this->p + i);
	}
	delete[] this->p;
	this->p = temp;
	this->n++;
}

// Read
void ServiceRegistrationRepository::Show()
{
	for (int i = 0; i < this->n; i++)
	{
		(this->p + i)->show();
		cout << endl;
	}
}
int ServiceRegistrationRepository::IndexOf(const int& serviceID,const int& studentID)
{
	int index = -1;
	for (int i = 0; i < this->n; i++)
	{
		if ((this->p + i)->getServiceID() == serviceID && (this->p + i)->getStudentID() == studentID)
		{
			index = i;
			break;
		}
	}
	return index;
}
ServiceRegistration ServiceRegistrationRepository::Search(const int& serviceID,const int& studentID)
{
	int index = IndexOf(serviceID, studentID);
	if (index != -1)
	{
		return *(this->p + index);
	}
	else return ServiceRegistration();
}

// Update
void ServiceRegistrationRepository::Update(ServiceRegistration& serviceRegistration)
{
	int index = IndexOf(serviceRegistration.getServiceID(), serviceRegistration.getStudentID());
	if (index == -1)
		return;
	(this->p + index)->setServiceID(serviceRegistration.getServiceID());
	(this->p + index)->setStudentID(serviceRegistration.getStudentID());
	(this->p + index)->setRegistrationDate(serviceRegistration.getRegistrationDate());
}

// Delete
void ServiceRegistrationRepository::Delete(const int& serviceID, const int& studentID)
{
	int index = IndexOf(serviceID, studentID);
	if (index == -1)
		return;
	ServiceRegistration* temp = new ServiceRegistration[this->n - 1];
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



void ServiceRegistrationRepository::LoadDataFromFile()
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

		ServiceRegistration temp;

		getline(ss, token, ';'); temp.setStudentID(stoi(token));
		getline(ss, token, ';'); temp.setServiceID(stoi(token));
		getline(ss, token, ';'); 
		int d, m, y;
		char sep1, sep2;
		stringstream dateStream(token);
		dateStream >> d >> sep1 >> m >> sep2 >> y;
		temp.setRegistrationDate(Date(d, m, y));

		this->Add(temp);
	}
	file.close();
}
void ServiceRegistrationRepository::SaveDateToFile()
{
	string filename = "Account.txt";
	ofstream file(filename);

	if (!file.is_open()) {
		cout << "Khong the mo file: " << filename << "!";
		return;
	}

	for (int i = 0; i < this->n; i++)
	{
		file << (this->p + i)->getStudentID() << ";";
		file << (this->p + i)->getServiceID() << ";";
		file << (this->p + i)->getRegistrationDate() << "\n";
	}
	file.close();
}