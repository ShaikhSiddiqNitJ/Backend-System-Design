#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address {
private:
    std::string streetAddress;
    std::string city;
    std::string state;
    std::string zipCode;
    std::string country;

public:
    // ✅ Constructor defined (fixes error 2)
    Address(const std::string& street, const std::string& city,
            const std::string& state, const std::string& zipCode,
            const std::string& country)
        : streetAddress(street), city(city), state(state), zipCode(zipCode), country(country) {}

    // ✅ This method was missing (fixes error 1)
    std::string getFullAddress() const {
        return streetAddress + ", " + city + ", " + state + ", " + zipCode + ", " + country;
    }
};

#endif // ADDRESS_H
