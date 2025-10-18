#include "InvoiceManageView.h"
#include "ConsolaUI.h"
#include <sstream>

InvoiceManageView::InvoiceManageView(InvoiceService* invoiceService)
	:invoiceService(invoiceService)
{
	this->sidebarInvoiceSelected = 0;
	this->sidebarInvoiceSize = 2;
	this->sidebarInvoiceList = new string[this->sidebarInvoiceSize]
	{
		"Tao Hoa Don",
		"Cap Nhat Trang Thai"
		//Tu Dong Tao Hoa Don
	};

}

InvoiceManageView::~InvoiceManageView()
{
	delete[] this->sidebarInvoiceList;
}

void InvoiceManageView::handleInput(int key)
{
	if (key == 72 || key == 80)
	{
		this->sidebarInvoiceSelected = (this->sidebarInvoiceSelected + (key == 72 ? -1 : 1) + this->sidebarInvoiceSize) % this->sidebarInvoiceSize;
	}
}

void InvoiceManageView::show()
{
	int width = ConsolaUI::getConsoleWidth();
	int height = ConsolaUI::getConsoleHeight();
	drawSidebarInvoice(width, height);
	drawInvoiceServiceContent(width, height);
}

void InvoiceManageView::drawInvoiceServiceContent(const int& width, const int& height)
{
	switch (this->sidebarInvoiceSelected)
	{
	case 0:
		ConsolaUI::text(30, 7, "XEM DANH SACH PHONG:", 14);
		break;
	case 1:
		ConsolaUI::text(30, 7, "LOC THEO TRANG THAI:", 14);
		break;
	}
}
void InvoiceManageView::drawSidebarInvoice(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
	ConsolaUI::text(5, 8, *(this->sidebarInvoiceList), (0 == this->sidebarInvoiceSelected) ? 11 : 8);
	ConsolaUI::text(5, 12, *(this->sidebarInvoiceList + 1), (1 == this->sidebarInvoiceSelected) ? 11 : 8);
}

string InvoiceManageView::GetLine()
{
	string ss;
	ConsolaUI::ShowCursor(true);
	while (true) {
		int key = _getch();
		if (key == '\r' || key == '\n') break;
		if (key == '\b') {
			if (ss.length() > 0) {
				ss.pop_back();
				cout << "\b \b";
			}
		}
		else {
			ss += char(key);
			cout << char(key);
		}
	}
	ConsolaUI::ShowCursor(false);
	return ss;
}

int InvoiceManageView::GetInt() {
	string inputString = GetLine();
	stringstream ss(inputString);
	int result = 0;
	ss >> result;
	return result;
}