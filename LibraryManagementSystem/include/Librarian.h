#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "Account.h"
#include "Member.h"
#include "BookItem.h"

class Librarian : public Account {
public:
    bool addBookItem(BookItem bookItem);
    bool blockMember(Member member);
    bool unBlockMember(Member member);
};

#endif
