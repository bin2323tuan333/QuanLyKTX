#include "FeedbackRepository.h"
#include <fstream>
#include <sstream>
using namespace std;

FeedbackRepository::FeedbackRepository()
{
    this->p = nullptr;
    this->n = 0;
}
FeedbackRepository::~FeedbackRepository()
{
    delete[] this->p;
}

// Create
void FeedbackRepository::Add(const Feedback& feedback)
{
    Feedback* temp = new Feedback[this->n + 1];
    for (int i = 0; i < this->n; i++)
    {
        *(temp + i) = *(this->p + i);
    }
    *(temp + this->n) = feedback;
    delete[] this->p;
    this->p = temp;
    (this->n)++;
}
void FeedbackRepository::Insert(const Feedback& feedback, const int& index)
{
    if (index < 0 || index > this->n)
        return;

    Feedback* temp = new Feedback[this->n + 1];
    for (int i = 0; i < index; i++)
    {
        *(temp + i) = *(this->p + i);
    }
    *(temp + index) = feedback;
    for (int i = index; i < this->n; i++)
    {
        *(temp + i + 1) = *(this->p + i);
    }
    delete[] this->p;
    this->p = temp;
    (this->n)++;
}

// Read
void FeedbackRepository::Show()
{
    for (int i = 0; i < this->n; i++)
    {
        (this->p + i)->show();
        cout << endl;
    }
}
int FeedbackRepository::IndexOf(const int& feedbackID)
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if (feedbackID == (this->p + i)->getFeedbackID())
        {
            index = i;
            break;
        }
    }
    return index;
}
Feedback FeedbackRepository::Search(const int& feedbackID)
{
    int index = IndexOf(feedbackID);
    if (index != -1)
    {
        return *(this->p + index);
    }
    return Feedback();
}

// Update
void FeedbackRepository::Update(const int& feedbackID)
{

}

// Delete
void FeedbackRepository::Delete(const int& feedbackID)
{
    int index = IndexOf(feedbackID);
    if (index == -1) return;

    Feedback* temp = new Feedback[this->n - 1];
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


void FeedbackRepository::LoadDataFromFile()
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

        Feedback temp;

        getline(ss, token, ';'); temp.setFeedbackID(stoi(token));
        getline(ss, token, ';'); temp.setTitle(token);
        getline(ss, token, ';'); temp.setContent(token);
        getline(ss, token, ';'); temp.setStatus(token);
        getline(ss, token, ';'); 
        int d, m, y;
        char sep1, sep2;
        stringstream dateStream(token);
        dateStream >> d >> sep1 >> m >> sep2 >> y;
        temp.setProcessingDate(Date(d, m, y));
        getline(ss, token, ';'); temp.setEmployeeID(stoi(token));
        getline(ss, token, ';');
        stringstream dateS(token);
        dateS >> d >> sep1 >> m >> sep2 >> y;
        temp.setSubmissionDate(Date(d, m, y));
        getline(ss, token, ';'); temp.setStudentID(stoi(token));

        this->Add(temp);
    }
    file.close();
}
void FeedbackRepository::SaveDateToFile()
{
    string filename = "Account.txt";
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Khong the mo file: " << filename << "!";
        return;
    }

    for (int i = 0; i < this->n; i++)
    {
        file << (this->p + i)->getFeedbackID() << ";";
        file << (this->p + i)->getTitle() << ";";
        file << (this->p + i)->getContent() << ";";
        file << (this->p + i)->getStatus() << ";";
        file << (this->p + i)->getProcessingDate() << ";";
        file << (this->p + i)->getEmployeeID() << ";";
        file << (this->p + i)->getSubmissionDate() << ";";
        file << (this->p + i)->getStudentID() << "\n";
    }
    file.close();
}