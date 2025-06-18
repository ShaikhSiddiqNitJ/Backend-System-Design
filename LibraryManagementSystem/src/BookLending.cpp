#include "BookLending.h"
#include <iostream>

void BookLending::lendBook(const string& barcode, const string& memberId) {
    std::cout << "Lending book: " << barcode << " to " << memberId << std::endl;
}

BookLending BookLending::fetchLendingDetails(const string& barcode) {
    return BookLending(); // dummy object
}
