#include "StudentRepository.h"
#include <fstream>
#include <sstream>

StudentRepository::StudentRepository()
{
	this->p = nullptr;
	this->n = 0;
}
StudentRepository::~StudentRepository()
{
	delete[] this->p;
}

// Create
void StudentRepository::Add(const Student& student)
{
	Student* temp = new Student[this->n + 1];
	for (int i = 0; i < this->n; i++)
	{
		*(temp + i) = *(this->p + i);
	}
	*(temp + this->n) = student;
	delete[] this->p;
	this->p = temp;
	(this->n)++;
}
void StudentRepository::Insert(const Student& student, const int& index)
{
	if (index<0 || index > this->n)
		return;

	Student* temp = new Student[this->n + 1];
	for (int i = 0; i < index; i++)
	{
		*(temp + i) = *(this->p + i);
	}
	*(temp + index) = student;
	for (int i = index; i < this->n; i++)
	{
		*(temp + i + 1) = *(this->p + i);
	}
	delete[] this->p;
	this->p = temp;
	(this->n)++;
}

// Read
int StudentRepository::IndexOf(const int& studentID)
{
	int index = -1;
	for (int i = 0; i < this->n; i++)
	{
		if (studentID == (this->p + i)->getStudentID())
		{
			index = i;
			break;
		}
	}
	return index;
}
Student StudentRepository::Search(const int& studentID)
{
	int index = IndexOf(studentID);
	if (index != -1)
	{
		return *(this->p + index);
	}
	return Student();
}

// Update
void StudentRepository::Update(Student& student)
{
	int index = IndexOf(student.getStudentID());
	if (index == -1)
		return;

	(this->p + index)->setStudentID(student.getStudentID());
	(this->p + index)->setFullName(student.getFullName());
	(this->p + index)->setDateOfBirth(student.getDateOfBirth());
	(this->p + index)->setGender(student.getGender());
	(this->p + index)->setClassName(student.getClassName());
	(this->p + index)->setFaculty(student.getFaculty());
	(this->p + index)->setPhoneNumber(student.getPhoneNumber());
	(this->p + index)->setEmail(student.getEmail());
}

// Delete
void StudentRepository::Delete(const int& studentID)
{
	int index = IndexOf(studentID);
	Student* temp = new Student[this->n - 1];
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


void StudentRepository::LoadDataFromFile()
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

		Student temp;

		getline(ss, token, ';'); temp.setStudentID(stoi(token));
		getline(ss, token, ';'); temp.setFullName(token);
		getline(ss, token, ';');
		int d, m, y;
		char sep1, sep2;
		stringstream dateStream(token);
		dateStream >> d >> sep1 >> m >> sep2 >> y;
		temp.setDateOfBirth(Date(d, m, y));
		getline(ss, token, ';'); temp.setGender(token);
		getline(ss, token, ';'); temp.setClassName(token);
		getline(ss, token, ';'); temp.setFaculty(token);
		getline(ss, token, ';'); temp.setPhoneNumber(token);
		getline(ss, token, ';'); temp.setEmail(token);

		this->Add(temp);
	}
	file.close();
}
void StudentRepository::SaveDateToFile()
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
		file << (this->p + i)->getFullName() << ";";
		file << (this->p + i)->getDateOfBirth() << ";";
		file << (this->p + i)->getGender() << ";";
		file << (this->p + i)->getClassName() << ";";
		file << (this->p + i)->getFaculty() << ";";
		file << (this->p + i)->getPhoneNumber() << ";";
		file << (this->p + i)->getEmail() << "\n";
	}
	file.close();
}