#include "StudentService.h"

StudentService::StudentService(StudentRepository& studentRepo)
	:studentRepo(studentRepo)
{
}

StudentService::~StudentService()
{
}

