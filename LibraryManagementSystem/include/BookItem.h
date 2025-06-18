#ifndef BOOKITEM_H
#define BOOKITEM_H

#include <string>
#include "Book.h"
#include "Enums.h"
#include "Date.h"
#include "Rack.h"
#include "BookLending.h"

class BookItem : public Book {
private:
    string barcode;
    bool isReferenceOnly;
    Date borrowed;
    Date dueDate;
    double price;
    BookFormat format;
    BookStatus status;
    Date dateOfPurchase;
    Date publicationDate;
    Rack placedAt;

public:
    bool checkout(const string& memberId);
    string getBarCode() const { return barcode; }
    bool getIsReferenceOnly() const { return isReferenceOnly; }
    void updateBookItemStatus(BookStatus status) { this->status = status; }
};

#endif
