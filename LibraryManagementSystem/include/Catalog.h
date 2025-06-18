#ifndef CATALOG_H
#define CATALOG_H

#include <unordered_map>
#include <vector>
#include <string>
#include "Book.h"
#include "Date.h"
#include "Search.h"

using namespace std;

class Catalog : public Search {
private:
    unordered_map<string, vector<Book>> bookTitles;
    unordered_map<string, vector<Book>> bookAuthors;
    unordered_map<string, vector<Book>> bookSubjects;
    unordered_map<string, vector<Book>> bookPublicationDates;

public:
    vector<Book> searchByTitle(string title) override;
    vector<Book> searchByAuthor(string author) override;
    vector<Book> searchBySubject(string subject) override;
    vector<Book> searchByPubDate(Date publishDate) override;
};

#endif
