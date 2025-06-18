// Enums and Constants: Here are the required enums, data types, and constants:


#include <string>

using namespace std;

enum class BookFormat {
    HARDCOVER,
    PAPERBACK,
    AUDIO_BOOK,
    EBOOK,
    NEWSPAPER,
    MAGAZINE,
    JOURNAL
};

enum class BookStatus {
    AVAILABLE,
    RESERVED,
    LOANED,
    LOST
};

enum class ReservationStatus {
    WAITING,
    PENDING,
    CANCELED,
    NONE
};

enum class AccountStatus {
    ACTIVE,
    CLOSED,
    CANCELED,
    BLACKLISTED,
    NONE
};

class Address {
public:
    string streetAddress;
    string city;
    string state;
    string zipCode;
    string country;
};

class Person {
public:
    string name;
    Address address;
    string email;
    string phone;
};

class Constants {
public:
    static const int MAX_BOOKS_ISSUED_TO_A_USER = 5;
    static const int MAX_LENDING_DAYS = 10;
};
