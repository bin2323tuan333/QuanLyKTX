#include "ContractManageView.h"
#include "ConsolaUI.h"
#include <sstream>

ContractManageView::ContractManageView(ContractService* contractService)
	:contractService(contractService)
{
	this->sidebarContractSelected = 0;
	this->sidebarContractSize = 3;
	this->sidebarContractList = new string[this->sidebarContractSize]
	{
		"Tim Kiem Hop Dong",
		"Tao Hop Dong Moi",
		"Gia Han Hop Dong"
	};

	this->studentIDToSearch = 0;
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


	if (this->sidebarContractSelected == 0)
	{
		if (key == 'F' || key == 'f')
		{
			ConsolaUI::gotoXY(66, 9);
			this->studentIDToSearch = GetInt();
		}
	}
	else if (this->sidebarContractSelected == 1)
	{

	}
	else if (this->sidebarContractSelected == 2)
	{

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
		ConsolaUI::text(30, 7, "TIM KIEM HOP DONG:", 14);
		ConsolaUI::text(35, 9, "[F] Nhap Ma So Sinh Vien: ", 15);
		ConsolaUI::drawBox(65, 8, 25, 2, 15);

		if (this->studentIDToSearch != 0)
		{
			/*Contract* contractToShow = this->contractService->ge(this->studentIDToSearch);*/
		}
		break;
	case 1:
		ConsolaUI::text(30, 7, "TAO HOP DONG MOI:", 14);
		break;
	case 2:
		ConsolaUI::text(30, 7, "GIA HAN HOP DONG:", 14);
		break;
	}
}
void ContractManageView::drawSidebarContract(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
	ConsolaUI::text(5, 8, *(this->sidebarContractList), (0 == this->sidebarContractSelected) ? 11 : 8);
	ConsolaUI::text(5, 10, *(this->sidebarContractList + 1), (1 == this->sidebarContractSelected) ? 11 : 8);
	ConsolaUI::text(5, 12, *(this->sidebarContractList + 2), (2 == this->sidebarContractSelected) ? 11 : 8);
}

string ContractManageView::GetLine()
{
	string ss;
	ConsolaUI::ShowCursor(true);
	while (true)
	{
		int key = _getch();
		if (key == '\r' || key == '\n') break;
		if (key == '\b')
		{
			if (ss.length() > 0)
			{
				ss.pop_back();
				cout << "\b \b";
			}
		}
		else
		{
			ss += char(key);
			cout << char(key);
		}
	}
	ConsolaUI::ShowCursor(false);
	return ss;
}

int ContractManageView::GetInt()
{
	string inputString = GetLine();
	stringstream ss(inputString);
	int result = 0;
	ss >> result;
	return result;
}