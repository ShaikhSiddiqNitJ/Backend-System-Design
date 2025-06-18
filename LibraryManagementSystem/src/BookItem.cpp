#include "BookItem.h"
#include <iostream>

bool BookItem::checkout(const string& memberId) {
    if (this->getIsReferenceOnly()) {
        std::cerr << "This book is reference only and can't be issued.\n";
        return false;
    }
    BookLending::lendBook(this->getBarCode(), memberId);
    this->updateBookItemStatus(BookStatus::LOANED);
    return true;
}
