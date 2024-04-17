#pragma once
#pragma once
#include <vector>
#include <iostream>
#include <sqlite3.h>
#include "execSql.h"
using namespace std;


namespace DB {
    class ConnectionError : public exception {
    public:
        ConnectionError(const char* msg);
        ConnectionError();
    };
    sqlite3* getDb();
}