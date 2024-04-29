#ifndef ADDRISKVIEW_H
#define ADDRISKVIEW_H

#include "Database.h"
#include <string>

class AddRiskView {
private:
    Database& db;

public:
    AddRiskView(Database& db);
    void submit();
};

#endif // ADDRISKVIEW_H

