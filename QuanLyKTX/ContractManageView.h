#pragma once
#include "ManageViewBase.h"
#include "ContractService.h"

class ContractManageView : public ManageViewBase
{
private:
	ContractService* contractService;

	string* sidebarContractList;
	int sidebarContractSize;
	int sidebarContractSelected;

public:
	ContractManageView(ContractService*);
	~ContractManageView();

	void show() override;
	void handleInput(int) override;

private:
	void drawContractServiceContent(const int&, const int&);
	void drawSidebarContract(const int&, const int&);

	string GetLine();
	int GetInt();
};