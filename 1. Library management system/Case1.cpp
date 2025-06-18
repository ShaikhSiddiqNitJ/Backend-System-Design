#include <string>

using namespace std;

// Assume enums like AccountStatus etc. already defined elsewhere

class Person;  // Forward declaration if needed

// ---------------- Abstract Base Class ----------------
class Account {
private:
    string id;
    string password;
    AccountStatus status;
    Person person;

public:
    virtual bool resetPassword() = 0; // pure virtual for abstract class
};

// ---------------- Librarian ----------------
class BookItem;  // Forward declaration
class Member;    // Forward declaration

class Librarian : public Account {
public:
    bool addBookItem(BookItem bookItem);
    bool blockMember(Member member);
    bool unBlockMember(Member member);
};

// ---------------- Member ----------------
class Date; // Assume it's defined or typedef'd

class Member : public Account {
private:
    Date dateOfMembership;
    int totalBooksCheckedout;

    void incrementTotalBooksCheckedout();

public:
    int getTotalBooksCheckedout();
    bool reserveBookItem(BookItem bookItem);

    bool checkoutBookItem(BookItem bookItem) {
        if (this->getTotalBooksCheckedout() >= Constants::MAX_BOOKS_ISSUED_TO_A_USER) {
            ShowError("The user has already checked-out maximum number of books");
            return false;
        }

        BookReservation bookReservation = BookReservation::fetchReservationDetails(bookItem.getBarcode());

        if (bookReservation != nullptr && bookReservation.getMemberId() != this->getId()) {
            ShowError("This book is reserved by another member");
            return false;
        } else if (bookReservation != nullptr) {
            bookReservation.updateStatus(ReservationStatus::COMPLETED);
        }

        if (!bookItem.checkout(this->getId())) {
            return false;
        }

        this->incrementTotalBooksCheckedout();
        return true;
    }

private:
    void checkForFine(string bookItemBarcode) {
        BookLending bookLending = BookLending::fetchLendingDetails(bookItemBarcode);
        Date dueDate = bookLending.getDueDate();
        Date today = Date(); // Assuming default constructor gives today

        if (today.compareTo(dueDate) > 0) {
            long diff = today.getTime() - dueDate.getTime();
            long diffDays = diff / (24 * 60 * 60 * 1000);
            Fine::collectFine(memberId, diffDays);
        }
    }

public:
    void returnBookItem(BookItem bookItem) {
        this->checkForFine(bookItem.getBarcode());
        BookReservation bookReservation = BookReservation::fetchReservationDetails(bookItem.getBarcode());

        if (bookReservation != nullptr) {
            bookItem.updateBookItemStatus(BookStatus::RESERVED);
            bookReservation.sendBookAvailableNotification();
        }

        bookItem.updateBookItemStatus(BookStatus::AVAILABLE);
    }

    bool renewBookItem(BookItem bookItem) {
        this->checkForFine(bookItem.getBarcode());
        BookReservation bookReservation = BookReservation::fetchReservationDetails(bookItem.getBarcode());

        if (bookReservation != nullptr && bookReservation.getMemberId() != this->getMemberId()) {
            ShowError("This book is reserved by another member");
            member.decrementTotalBooksCheckedout();
            bookItem.updateBookItemState(BookStatus::RESERVED);
            bookReservation.sendBookAvailableNotification();
            return false;
        } else if (bookReservation != nullptr) {
            bookReservation.updateStatus(ReservationStatus::COMPLETED);
        }

        BookLending::lendBook(bookItem.getBarCode(), this->getMemberId());
        bookItem.updateDueDate(LocalDate::now().plusDays(Constants::MAX_LENDING_DAYS));
        return true;
    }
};
