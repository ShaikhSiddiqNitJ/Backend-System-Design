#ifndef FINE_H
#define FINE_H

#include <string>
#include "Date.h"

using namespace std;

class Fine {
private:
    Date creationDate;
    double bookItemBarcode;
    string memberId;

public:
    static void collectFine(const string& memberId, long days);
};

#endif
