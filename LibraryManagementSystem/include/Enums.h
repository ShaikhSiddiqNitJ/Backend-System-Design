#ifndef ENUMS_H
#define ENUMS_H

enum class BookFormat {
    HARDCOVER,
    PAPERBACK,
    AUDIO_BOOK,
    EBOOK,
    NEWSPAPER,
    MAGAZINE,
    JOURNAL
};

enum class BookStatus {
    AVAILABLE,
    RESERVED,
    LOANED,
    LOST
};

enum class ReservationStatus {
    WAITING,
    PENDING,
    CANCELED,
    NONE
};

enum class AccountStatus {
    ACTIVE,
    CLOSED,
    CANCELED,
    BLACKLISTED,
    NONE
};

#endif // ENUMS_H
