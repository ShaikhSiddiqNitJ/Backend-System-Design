#include <string>
#include <vector>

using namespace std;

class Author;          // Assume defined elsewhere
class Date;            // Assume defined
class Rack;            // Forward declared
enum class BookFormat; // Forward declared
enum class BookStatus; // Forward declared

// ---------------- Abstract Class: Book ----------------
class Book {
private:
    string ISBN;
    string title;
    string subject;
    string publisher;
    string language;
    int numberOfPages;
    vector<Author> authors;  // List -> vector
};

// ---------------- Derived Class: BookItem ----------------
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
    bool checkout(string memberId) {
        if (this->getIsReferenceOnly()) {
            ShowError("This book is Reference only and can't be issued");
            return false;
        }
        if (!BookLending::lendBook(this->getBarCode(), memberId)) {
            return false;
        }
        this->updateBookItemStatus(BookStatus::LOANED);
        return true;
    }
};

// ---------------- Class: Rack ----------------
class Rack {
private:
    int number;
    string locationIdentifier;
};
