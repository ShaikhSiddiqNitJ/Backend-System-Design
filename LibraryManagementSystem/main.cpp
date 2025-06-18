#include <iostream>
#include "Person.h"
#include "Constants.h"
#include "Enums.h"

int main() {
    Address address("123 MG Road", "Bangalore", "Karnataka", "560001", "India");
    Person person("Shaikh Siddiq", address, "shaikh@example.com", "+91-9999999999");

    std::cout << "Name: " << person.getName() << std::endl;
    std::cout << "Email: " << person.getEmail() << std::endl;
    std::cout << "Phone: " << person.getPhone() << std::endl;
    std::cout << "Address: " << person.getAddress() << std::endl;

    std::cout << "Max Books Allowed: " << Constants::MAX_BOOKS_ISSUED_TO_A_USER << std::endl;

    return 0;
}
