#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>
#include "Author.h" // placeholder
using namespace std;

class Book {
protected:
    string ISBN;
    string title;
    string subject;
    string publisher;
    string language;
    int numberOfPages;
    vector<Author> authors;

public:
    string getISBN() const { return ISBN; }
    string getTitle() const { return title; }
    // add setters/getters if needed
};

#endif
