#ifndef BOOKLENDING_H
#define BOOKLENDING_H

#include <string>
#include "Date.h"

using namespace std;

class BookLending {
private:
    Date creationDate;
    Date dueDate;
    Date returnDate;
    string bookItemBarcode;
    string memberId;

public:
    static void lendBook(const string& barcode, const string& memberId);
    static BookLending fetchLendingDetails(const string& barcode);
    Date getDueDate() const { return dueDate; }
};

#endif
