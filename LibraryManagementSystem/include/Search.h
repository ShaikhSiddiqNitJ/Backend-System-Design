#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <string>
#include "Book.h"
#include "Date.h"

class Search {
public:
    virtual std::vector<Book> searchByTitle(std::string title) = 0;
    virtual std::vector<Book> searchByAuthor(std::string author) = 0;
    virtual std::vector<Book> searchBySubject(std::string subject) = 0;
    virtual std::vector<Book> searchByPubDate(Date publishDate) = 0;

    virtual ~Search() = default;
};

#endif
