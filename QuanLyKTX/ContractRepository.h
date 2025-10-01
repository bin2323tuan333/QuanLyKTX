#pragma once
#include "Contract.h"




class ContractRepository
{
private:
    Contract* p;
    int n;

public:
    ContractRepository();
    ~ContractRepository();

    // Create
    void Add(const Contract&);
    void Insert(const Contract&, const int&);

    // Read
    void Show();
    int IndexOf(const int&);
    Contract Search(const int&);

    // Update
    void Update(Contract&);

    // Delete
    void Delete(const int&);

    void LoadDataFromFile();
    void SaveDateToFile();
};
