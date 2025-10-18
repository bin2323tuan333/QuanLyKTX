#include "ContractManageView.h"
#include "ConsolaUI.h"

ContractManageView::ContractManageView(ContractService* contractService)
	:contractService(contractService)
{
	this->sidebarContractSelected = 0;
	this->sidebarContractSize = 2;
	this->sidebarContractList = new string[this->sidebarContractSize]
	{
		"Tao Hop Dong Moi",
		"Ket Thuc Hop Dong"
		//Chuyen Phong
		//Gia Han Hop Dong

	};
}

ContractManageView::~ContractManageView()
{
	delete[] this->sidebarContractList;
}

void ContractManageView::handleInput(int key)
{
	if (key == 72 || key == 80)
	{
		this->sidebarContractSelected = (this->sidebarContractSelected + (key == 72 ? -1 : 1) + this->sidebarContractSize) % this->sidebarContractSize;
	}
}

void ContractManageView::show()
{
	int width = ConsolaUI::getConsoleWidth();
	int height = ConsolaUI::getConsoleHeight();
	drawSidebarContract(width, height);
	drawContractServiceContent(width, height);
}

void ContractManageView::drawContractServiceContent(const int& width, const int& height)
{
	switch (this->sidebarContractSelected)
	{
	case 0:
		ConsolaUI::text(30, 7, "TAO HOP DONG MOI:", 14);
		break;
	case 1:
		ConsolaUI::text(30, 7, "KET THUC HOP DONG:", 14);
		break;
	}
}
void ContractManageView::drawSidebarContract(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
	ConsolaUI::text(5, 8, *(this->sidebarContractList), (0 == this->sidebarContractSelected) ? 11 : 8);
	ConsolaUI::text(5, 12, *(this->sidebarContractList + 1), (1 == this->sidebarContractSelected) ? 11 : 8);
}