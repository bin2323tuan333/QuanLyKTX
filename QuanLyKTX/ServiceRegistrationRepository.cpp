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
void ServiceRegistrationRepository::Add(const ServiceRegistration& sr)
{

}
void ServiceRegistrationRepository::Insert(const ServiceRegistration& sr, const int& index)
{

}

// Read
void ServiceRegistrationRepository::Show()
{

}
int ServiceRegistrationRepository::IndexOf(const int& id)
{

}
ServiceRegistration ServiceRegistrationRepository::Search(const int& id)
{

}

// Update
void ServiceRegistrationRepository::Update(const int& id)
{

}

// Delete
void ServiceRegistrationRepository::Delete(const int& id)
{

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