#pragma once
#include "Date.h"
#include <string>
using namespace std;




class Feedback {
private:
    int feedbackID;
    string title;
    string content;
    string status;
    Date processingDate;
    int employeeID;
    Date submissionDate;
    int studentID;

public:
    // Constructor, Copy constructor, Destructor
    Feedback(const int& = 0, const string & = "", const string & = "", const string & = "",
        const Date & = Date(), const int& = 0, const Date & = Date(), const int& = 0);
    Feedback(const Feedback&);
    ~Feedback();

    // Getter & Setter
    int getFeedbackID();
    void setFeedbackID(const int&);

    string getTitle();
    void setTitle(const string&);

    string getContent();
    void setContent(const string&);

    string getStatus();
    void setStatus(const string&);

    Date getProcessingDate();
    void setProcessingDate(const Date&);

    int getEmployeeID();
    void setEmployeeID(const int&);

    Date getSubmissionDate();
    void setSubmissionDate(const Date&);

    int getStudentID();
    void setStudentID(const int&);


    void show();
};
