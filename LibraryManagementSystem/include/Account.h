#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "Enums.h"
#include "Person.h"

using namespace std;

class Account {
protected:
    string id;
    string password;
    AccountStatus status;
    Person person;

public:
    virtual bool resetPassword() = 0;
};

#endif
