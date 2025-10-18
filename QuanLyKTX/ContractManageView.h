#pragma once
#include "ContractService.h"

class ContractManageView
{
private:
	ContractService* contractService;

	string* sidebarContractList;
	int sidebarContractSize;
	int sidebarContractSelected;

public:
	ContractManageView(ContractService*);
	~ContractManageView();
	void show();
	void handleInput(int);


private:
	void draw();
	void drawContractServiceContent(const int&, const int&);
	void drawSidebarContract(const int&, const int&);

	string GetLine();
	int GetInt();
};