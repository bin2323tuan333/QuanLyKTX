#pragma once




class InvoiceDetail {
private:
    int invoiceID;
    int quantity;
    int totalAmount;
    int serviceID;

public:
    // Constructor, Copy constructor, Destructor
    InvoiceDetail(const int& = 0, const int& = 0, const int& = 0, const int& = 0);
    InvoiceDetail(const InvoiceDetail&);
    ~InvoiceDetail();

    // Getter & Setter
    int getInvoiceID();
    void setInvoiceID(const int&);

    int getQuantity();
    void setQuantity(const int&);

    int getTotalAmount();
    void setTotalAmount(const int&);

    int getServiceID();
    void setServiceID(const int&);


    void show();
};
