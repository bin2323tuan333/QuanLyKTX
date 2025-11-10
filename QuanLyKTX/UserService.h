#pragma once
#include "DB.h"

class UserService
{
private:
    DB* database;

public:
    UserService();
    ~UserService();


    //// ===== STUDENT MANAGEMENT =====
    int createStudent(Student&);
    Student* getStudentById(const int&);
    LinkedList<Student*>* getAllStudents();
    //LinkedList<Student*> getStudentsByFaculty(const string& faculty);
    //LinkedList<Student*> getStudentsByRoom(int roomId);
    //LinkedList<Student*> searchStudents(const string& keyword);
    int updateStudent(int studentId, const Student& updatedStudent);
    bool deleteStudent(int studentId);

    //int getTotalStudents();
    LinkedList<Student*> getStudentsWithoutRoom();

    //// ===== EMPLOYEE MANAGEMENT =====
    //int createEmployee(Employee*);
    //Employee* getEmployeeById(const int&);
    //LinkedList<Employee*>* getAllEmployees();
    //LinkedList<Employee*> getEmployeesByDepartment(const std::string& department);
    //LinkedList<Employee*> searchEmployees(const std::string& keyword);
    //bool updateEmployee(int employeeId, const Employee& updatedEmployee);
    //bool deleteEmployee(int employeeId);
    //int getTotalEmployees();

    //// ===== VALIDATION =====
    //bool checkStudentExists(const std::string& studentCode);
    //bool checkEmployeeExists(const std::string& employeeCode);
    //bool checkEmailExists(const std::string& email);
    //bool checkPhoneExists(const std::string& phone);
};

