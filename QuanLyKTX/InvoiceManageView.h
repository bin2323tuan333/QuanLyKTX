#pragma once
#include "ManageViewBase.h"
#include "InvoiceService.h"

class InvoiceManageView : public ManageViewBase
{
private:
	InvoiceService* invoiceService;

	string* sidebarInvoiceList;
	int sidebarInvoiceSize;
	int sidebarInvoiceSelected;

public:
	InvoiceManageView(InvoiceService*);
	~InvoiceManageView();

	void show() override;
	void handleInput(int) override;

private:
	void drawInvoiceServiceContent(const int&, const int&);
	void drawSidebarInvoice(const int&, const int&);

	string GetLine();
	int GetInt();
};