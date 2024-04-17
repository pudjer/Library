#include <sqlite3.h>
#include <iostream>
#include <string>
#include <vector>
#include "fromFile.h"
#include <fstream>
#pragma once

using namespace std;
namespace DB {

    class QueryError : public exception {
    public:
        QueryError(const char* msg);
        QueryError();
    };


    void execSql(const string& path, sqlite3* db);

    void execManySQL(const vector<string>& paths, sqlite3* db, vector<QueryError>* errors = nullptr);
}