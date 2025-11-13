#include "AuthService.h"
#include "Account.h"
#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include <string>

AuthService::AuthService()
{
	this->database = DB::Instance();
}
AuthService::~AuthService()
{
}

IAccount* AuthService::login(const string& username, const string& password)
{
	IAccount* temp = DB::Instance()->getAccountByUsername(username);
	if (temp == nullptr) return 0;
	if (temp->getPassword() == password)
	{
		return temp;
	}
	return nullptr;
}
int AuthService::changePassword(IAccount* user, const string& oldPass, const string& newPass, const string& reNewPass)
{
	if (oldPass != user->getPassword()) return 2;						// Mat Khau Cu Khong Dung
	if (oldPass == "" || newPass == "" || reNewPass == "") return 3;	// De trong mat khau
	if (newPass != reNewPass) return 4;									// mat khau moi nhap lai khong khop
	if (newPass == oldPass) return 5;									// Mat khau cu giong mau khau moi
	user->setPassword(newPass);
	return 1;
}
bool AuthService::genAccount(IPerson* person)
{
	if (person->getAccount() != nullptr) return false;

	IAccount* newAccount = new Account();
	newAccount->setUserId(this->getIdAuto());
	IStudent* student = dynamic_cast<IStudent*>(person);
	IEmployee* employee = dynamic_cast<IEmployee*>(person);
	if (student != nullptr)
	{
		newAccount->setUsername(to_string(student->getStudentId()));
	}
	else if (employee != nullptr)
	{
		newAccount->setUsername(to_string(employee->getEmployeeId()));
	}
	else return false;
	string pass = "";
	if (person->getDateOfBirth().getDay() < 10)
	{
		pass += "0";
		pass += to_string(person->getDateOfBirth().getDay());
	}
	else pass += to_string(person->getDateOfBirth().getDay());
	if (person->getDateOfBirth().getDay() < 10)
	{
		pass += "0";
		pass += to_string(person->getDateOfBirth().getMonth());
	}
	else pass += to_string(person->getDateOfBirth().getMonth());
	pass += to_string(person->getDateOfBirth().getYear());
	newAccount->setPassword(pass);
	this->database->addAccount(newAccount);
	person->AddAccount(newAccount);
	person->setUserId(newAccount->getUserId());
	return true;
}
int AuthService::getIdAuto()
{
	int maxId = 0;
	for (ListNode<IAccount*>* p = database->getAllAccounts()->getHead(); p != nullptr; p = p->next)
	{
		if (p->value->getUserId() > maxId) maxId = p->value->getUserId();
	}
	return ++maxId;
}