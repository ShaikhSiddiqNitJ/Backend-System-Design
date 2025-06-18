#ifndef MEMBER_H
#define MEMBER_H

#include "Account.h"
#include "BookItem.h"
#include "Constants.h"
#include "BookReservation.h"
#include "BookLending.h"
#include "Fine.h"
#include "Date.h"

class Member : public Account {
private:
    Date dateOfMembership;
    int totalBooksCheckedout;

    void incrementTotalBooksCheckedout();
    void checkForFine(const string& bookItemBarcode);

public:
    int getTotalBooksCheckedout() const;
    bool reserveBookItem(BookItem bookItem);
    bool checkoutBookItem(BookItem bookItem);
    void returnBookItem(BookItem bookItem);
    bool renewBookItem(BookItem bookItem);
    string getMemberId() const { return this->id; }

    // ✅ Implementing the pure virtual method
    bool resetPassword() override {
        // Example dummy logic
        password = "new_password"; // This could be input or randomly generated
        return true;
    }
};

#endif
