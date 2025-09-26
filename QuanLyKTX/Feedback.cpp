#include <iostream>
#include "Feedback.h"

// Constructor
Feedback::Feedback(const int& feedbackID, const string& title, const string& content, const string& status, 
    const Date& processingDate, const int& employeeID, const Date& submissionDate, const int& studentID)
    : feedbackID(feedbackID), title(title), content(content), status(status),processingDate(processingDate), 
    employeeID(employeeID), submissionDate(submissionDate), studentID(studentID) 
{
}
Feedback::Feedback(const Feedback& fb)
    : feedbackID(fb.feedbackID), title(fb.title), content(fb.content),
    status(fb.status), processingDate(fb.processingDate),
    employeeID(fb.employeeID), submissionDate(fb.submissionDate), studentID(fb.studentID) 
{
}
Feedback::~Feedback() 
{
}





// Getter & Setter
int Feedback::getFeedbackID() 
{
    return this->feedbackID;
}
void Feedback::setFeedbackID(const int& feedbackID) 
{
    this->feedbackID = feedbackID;
}
string Feedback::getTitle() 
{
    return this->title;
}
void Feedback::setTitle(const string& title) 
{
    this->title = title;
}
string Feedback::getContent() 
{
    return this->content;
}
void Feedback::setContent(const string& content) 
{
    this->content = content;
}
string Feedback::getStatus() 
{
    return this->status;
}
void Feedback::setStatus(const string& status) 
{
    this->status = status;
}
Date Feedback::getProcessingDate() 
{
    return this->processingDate;
}
void Feedback::setProcessingDate(const Date& processingDate) 
{
    this->processingDate = processingDate;
}
int Feedback::getEmployeeID() 
{
    return this->employeeID;
}
void Feedback::setEmployeeID(const int& employeeID) 
{
    this->employeeID = employeeID;
}
Date Feedback::getSubmissionDate() 
{
    return this->submissionDate;
}
void Feedback::setSubmissionDate(const Date& submissionDate) 
{
    this->submissionDate = submissionDate;
}
int Feedback::getStudentID() 
{
    return this->studentID;
}
void Feedback::setStudentID(const int& studentID) 
{
    this->studentID = studentID;
}






void Feedback::show() {
    cout << this->feedbackID << " "
        << this->title << " "
        << this->content << " "
        << this->status << " "
        << this->processingDate << " "
        << this->employeeID << " "
        << this->submissionDate << " "
        << this->studentID;
}
