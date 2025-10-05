#include "PaymentService.h"

PaymentService::PaymentService(InvoiceRepository& invRepo)
	:invoiceRepo(invRepo)
{
}

PaymentService::~PaymentService()
{
}
