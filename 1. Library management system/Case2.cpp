#include <string>

using namespace std;

class Date; // Assume Date is defined elsewhere
enum class ReservationStatus; // Assume ReservationStatus is defined

class BookReservation {
private:
    Date creationDate;
    ReservationStatus status;
    string bookItemBarcode;
    string memberId;

public:
    static BookReservation fetchReservationDetails(string barcode);
};

class BookLending {
private:
    Date creationDate;
    Date dueDate;
    Date returnDate;
    string bookItemBarcode;
    string memberId;

public:
    static void lendBook(string barcode, string memberId);
    static BookLending fetchLendingDetails(string barcode);
};

class Fine {
private:
    Date creationDate;
    double bookItemBarcode;
    string memberId;

public:
    static void collectFine(string memberId, long days);
};
