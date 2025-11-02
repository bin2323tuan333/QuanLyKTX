#pragma once
#include "ManageViewBase.h"
#include "ContractService.h"
#include "StudentService.h"
#include "RoomService.h"

class ContractManageView : public ManageViewBase
{
private:
	ContractService* contractService;
	StudentService* studentService;
	RoomService* roomService;

	string* sidebarContractList;
	int sidebarContractSize;
	int sidebarContractSelected;

	int studentIDToSearch;
	int contractIDToSearch;
	int chooseToAdd;
	int contractListIndex;
	int maxPage;

	Student tempStudent;
	int currentIndex;
	int dateIndex;
	bool isDateEdit;
public:
	ContractManageView(ContractService*, StudentService*, RoomService*);
	~ContractManageView();

	void show() override;
	void handleInput(int) override;

private:
	void drawContractServiceContent(const int&, const int&);
	void drawSidebarContract(const int&, const int&);

	string GetLine();
	int GetInt();
};