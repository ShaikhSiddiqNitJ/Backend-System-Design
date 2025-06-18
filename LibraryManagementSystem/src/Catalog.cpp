#include "Catalog.h"

vector<Book> Catalog::searchByTitle(string title) {
    return bookTitles[title];
}

vector<Book> Catalog::searchByAuthor(string author) {
    return bookAuthors[author];
}

vector<Book> Catalog::searchBySubject(string subject) {
    return bookSubjects[subject];
}

vector<Book> Catalog::searchByPubDate(Date publishDate) {
    return bookPublicationDates["2025"]; // dummy
}
