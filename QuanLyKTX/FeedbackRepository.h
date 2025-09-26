#pragma once
#include "Feedback.h"




class FeedbackRepository
{
private:
    Feedback* p;
    int n;

public:
    FeedbackRepository();
    ~FeedbackRepository();

    // Create
    void Add(const Feedback&);
    void Insert(const Feedback&, const int&);

    // Read
    void Show();
    int IndexOf(const int&);
    Feedback Search(const int&);


    // Update
    void Update(const int&);

    // Delete
    void Delete(const int&);

    void LoadDataFromFile();
    void SaveDateToFile();
};
