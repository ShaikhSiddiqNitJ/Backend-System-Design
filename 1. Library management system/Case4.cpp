// Search interface and Catalog: The Catalog class will implement the Search interface to facilitate searching of books.

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Book;  // Forward declaration
class Date;  // Forward declaration

// ---------------- Interface Equivalent in C++ ----------------
class Search {
public:
    virtual vector<Book> searchByTitle(string title) = 0;
    virtual vector<Book> searchByAuthor(string author) = 0;
    virtual vector<Book> searchBySubject(string subject) = 0;
    virtual vector<Book> searchByPubDate(Date publishDate) = 0;

    virtual ~Search() = default; // Virtual destructor for interface
};

// ---------------- Catalog Class Implementing Search ----------------
class Catalog : public Search {
private:
    unordered_map<string, vector<Book>> bookTitles;
    unordered_map<string, vector<Book>> bookAuthors;
    unordered_map<string, vector<Book>> bookSubjects;
    unordered_map<string, vector<Book>> bookPublicationDates;

public:
    vector<Book> searchByTitle(string query) override {
        return bookTitles[query];
    }

    vector<Book> searchByAuthor(string query) override {
        return bookAuthors[query];
    }

    // You haven’t provided subject/pubDate functions' bodies in Java,
    // so those are omitted here too, as per your instruction.
};
