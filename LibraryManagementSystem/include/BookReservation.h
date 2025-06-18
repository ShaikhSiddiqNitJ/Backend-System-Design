#ifndef BOOKRESERVATION_H
#define BOOKRESERVATION_H

#include <string>
#include "Date.h"
#include "Enums.h"

using namespace std;

class BookReservation {
private:
    Date creationDate;
    ReservationStatus status;
    string bookItemBarcode;
    string memberId;

public:
    static BookReservation fetchReservationDetails(const string& barcode);
    string getMemberId() const { return memberId; }
    void updateStatus(ReservationStatus newStatus);
    void sendBookAvailableNotification();
};

#endif
