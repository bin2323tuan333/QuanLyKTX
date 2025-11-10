#pragma once
#include "DB.h"

class BillingService
{
private:
    DB* database;

    const int ELECTRIC_PRICE = 3000;
    const int WATER_PRICE = 8000;
    const int ROOM_FEE = 200000;
public:
	BillingService();
	~BillingService();

    //// Invoice CRUD
    int createInvoice(const int& roomId, const int& elec, const int& water, const int& inter);
    Invoice* getInvoiceById(int invoiceId);
    LinkedList<Invoice*> getInvoicesByStudent(int studentId);
    //LinkedList<Invoice*> getInvoicesByContract(int contractId);
    LinkedList<Invoice*>* getAllInvoices();
    //bool updateInvoice(int invoiceId, const Invoice& updatedInvoice);
    //bool deleteInvoice(int invoiceId);

    //// Invoice status
    LinkedList<Invoice*> getUnpaidInvoices();
    LinkedList<Invoice*> getPaidInvoices();
    //LinkedList<Invoice*> getOverdueInvoices();
    //LinkedList<Invoice*> getInvoicesByDateRange(const string& startDate, const string& endDate);
    //LinkedList<Invoice*> getInvoicesByMonth(int month, int year);

    //// Payment operations
    //bool markInvoiceAsPaid(int invoiceId, const string& paymentDate, const string& paymentMethod, double amountPaid);
    //bool recordPartialPayment(int invoiceId, double amount, const string& paymentDate);
    //bool applyDiscount(int invoiceId, double discountAmount, const string& reason);
    //bool applyLateFee(int invoiceId, double feeAmount);

    //// Auto-generation
    //bool generateMonthlyInvoices(int month, int year);
    //bool generateInvoiceForContract(int contractId);
    //bool generateUtilityInvoice(int studentId, double electricityCost,
    //    double waterCost, double internetCost);

    //// Debt management
    //double calculateTotalDebt(int studentId);
    //double calculateOutstandingAmount(int invoiceId);
    ////std::vector<int> getStudentsWithDebt();
    //LinkedList<Invoice*> getDebtByStudent(int studentId);

    //// Reminders & Notifications
    //bool sendPaymentReminder(int invoiceId);
    //bool sendOverdueNotice(int invoiceId);
    //bool sendReceiptEmail(int invoiceId);
    //LinkedList<Invoice*> getInvoicesNeedingReminder();

    //// Refunds
    //bool createRefund(int invoiceId, double amount, const string& reason);
    //LinkedList<Invoice*> getRefundHistory(int studentId);

    //// Statistics & Reports
    //double getTotalRevenue(const string& startDate, const string& endDate);
    //double getTotalRevenueByMonth(int month, int year);
    //double getTotalUnpaidAmount();
    //double getTotalOverdueAmount();
    //int getTotalPaidInvoices();
    //int getTotalUnpaidInvoices();

    //string generateInvoiceReport(int invoiceId);
    //string generateStudentPaymentHistory(int studentId);
    //string generateMonthlyRevenueReport(int month, int year);
    //string generateDebtReport();
};

