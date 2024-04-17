#include "execSql.h"

using namespace std;
namespace DB {
    QueryError::QueryError(const char* msg) : std::exception(msg) {}
    QueryError::QueryError() : std::exception() {}

    void execSql(const string& path, sqlite3* db) {
        char* zErrMsg = 0;
        char query[4096];
        try {
            fromFile(path, query);
        }
        catch (exception e) {
            throw QueryError(e.what());
        }
        int rc = sqlite3_exec(db, query, 0, 0, &zErrMsg);
        if (rc) {
            cout << zErrMsg << endl;
            throw QueryError(zErrMsg);
            sqlite3_free(zErrMsg);
        }
    }

    void execManySQL(const vector<string>& paths, sqlite3* db, vector<QueryError>* errors) {
        for (auto& path : paths) {
            try {
                execSql(path, db);
            } catch (QueryError& err) {
                if (errors) errors->push_back(err);
            }
        }
    }
}


