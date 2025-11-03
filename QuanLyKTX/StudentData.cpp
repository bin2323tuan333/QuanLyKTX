#include "StudentData.h"
#include <fstream>
#include <sstream>

StudentData::StudentData(const string& fileName)
	:fileName(fileName)
{
	this->loadData();
}
StudentData::~StudentData()
{
	this->saveData();
}
void StudentData::loadData()
{
	ifstream file(this->fileName);
	if (!file.is_open()) 
		return;
	string line;
	while (getline(file, line)) {
		if (line == "") continue;
		stringstream ss(line);
		string token;
		Student* student = new Student();
		getline(ss, token, ';'); student->setStudentID(stoi(token));
		getline(ss, token, ';'); student->setUserId(stoi(token));
		getline(ss, token, ';'); student->setFullName(token);
		getline(ss, token, ';'); student->setGender(token == "1");
		getline(ss, token, ';'); student->setDateOfBirth(Date::stringToDate(token));
		getline(ss, token, ';'); student->setPhoneNumber(token);
		getline(ss, token, ';'); student->setEmail(token);
		getline(ss, token, ';'); student->setClassName(token);
		getline(ss, token, ';'); student->setFaculty(token);
		this->list.add(student);
		this->mapStudentId.insert(student->getStudentID(), student);
	}
	file.close();
}
void StudentData::saveData()
{
	ofstream file(fileName);
	if (!file.is_open())
		return;
	for (ListNode<Student*>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		file << p->value->getStudentID() << ";";
		file << p->value->getUserId() << ";";
		file << p->value->getFullName() << ";";
		file << (p->value->getGender() == true ? "1" : "0") << ";";
		file << p->value->getDateOfBirth() << ";";
		file << p->value->getPhoneNumber() << ";";
		file << p->value->getEmail() << ";";
		file << p->value->getClassName() << ";";
		file << p->value->getFaculty() << endl;
	}
	file.close();
}

LinkedList<Student*>* StudentData::getList()
{
	return &(this->list);
}

void StudentData::Add(const Student& student)
{
	Student* accToAdd = new Student(student);
	this->list.add(accToAdd);
	this->mapStudentId.insert(accToAdd->getStudentID(), accToAdd);
}
void StudentData::Delete(const Student& student)
{
	Student* studentToDelete = GetByStudentId(student.getStudentID());
	if (studentToDelete == nullptr)
		return;
	this->list.remove(studentToDelete);
	this->mapStudentId.remove(studentToDelete->getStudentID());
	delete studentToDelete;
}
void StudentData::Update(const Student& student)
{
	Student* studentToUpdate = GetByStudentId(student.getStudentID());
	if (studentToUpdate == nullptr)
		return;
	*studentToUpdate = student;
}
Student* StudentData::GetByStudentId(const int& studentId)
{
	Student** student = this->mapStudentId.search(studentId);
	if (student == nullptr) 
		return nullptr;
	return *student;
}
int StudentData::GetSize()
{
	return this->list.getSize();
}