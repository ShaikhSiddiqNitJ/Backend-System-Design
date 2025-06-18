#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Address.h"

class Person {
private:
    std::string name;
    Address address;
    std::string email;
    std::string phone;

public:
    Person(const std::string& name, const Address& address,
           const std::string& email, const std::string& phone)
        : name(name), address(address), email(email), phone(phone) {}

    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    std::string getPhone() const { return phone; }
    std::string getAddress() const { return address.getFullAddress(); } // needs Address fix
};

#endif // PERSON_H
