#pragma once
#include "InvoiceService.h"

class InvoiceManageView
{
private:
	InvoiceService* invoiceService;

	string* sidebarInvoiceList;
	int sidebarInvoiceSize;
	int sidebarInvoiceSelected;

public:
	InvoiceManageView(InvoiceService*);
	~InvoiceManageView();
	void show();
	void handleInput(int);


private:
	void draw();
	void drawInvoiceServiceContent(const int&, const int&);
	void drawSidebarInvoice(const int&, const int&);

	string GetLine();
	int GetInt();
};