#include "StudentRepository.h"
#include <fstream>
#include <sstream>

StudentRepository::StudentRepository(const string& fileName)
	:fileName(fileName)
{
}
StudentRepository::~StudentRepository()
{
}
void StudentRepository::loadData()
{
	string filename = "Student.txt";
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

		this->list.add(temp);
	}
	file.close();
}
void StudentRepository::saveData()
{
	string filename = "Student.txt";
	ofstream file(filename);

	if (!file.is_open()) {
		cout << "Khong the mo file: " << filename << "!";
		return;
	}
	for (ListNode<Student>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		file << p->value.getStudentID() << ";";
		file << p->value.getFullName() << ";";
		file << p->value.getDateOfBirth() << ";";
		file << p->value.getGender() << ";";
		file << p->value.getClassName() << ";";
		file << p->value.getFaculty() << ";";
		file << p->value.getPhoneNumber() << ";";
		file << p->value.getEmail() << "\n";
	}
	file.close();
}

void StudentRepository::Add(const Student& student)
{
	this->list.add(student);
	this->saveData();
}

void StudentRepository::Delete(const Student& student)
{
	Student* temp = this->GetById(student.getStudentID());
	if (temp == nullptr) return;
	this->list.remove(*temp);
	this->saveData();
}
void StudentRepository::Update(const Student& student)
{
	Student* temp = this->GetById(student.getStudentID());
	*temp = student;
}
LinkedList<Student> StudentRepository::GetAll()
{
	return this->list;
}
Student* StudentRepository::GetById(const int& studentID)
{
	for (ListNode<Student>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		if (p->value.getStudentID() == studentID)
			return &(p->value);
	}
	return nullptr;
}

int StudentRepository::GetSize()
{
	return this->list.getSize();
}