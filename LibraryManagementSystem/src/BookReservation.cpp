#include "BookReservation.h"
#include <iostream>

BookReservation BookReservation::fetchReservationDetails(const string& barcode) {
    return BookReservation(); // dummy object
}

void BookReservation::updateStatus(ReservationStatus newStatus) {
    status = newStatus;
}

void BookReservation::sendBookAvailableNotification() {
    std::cout << "Notification sent to member: " << memberId << std::endl;
}
