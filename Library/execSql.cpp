#include "execSql.h"

namespace DB {

    void execFile(const string& path, sqlite3* db) {
        char* zErrMsg;
        const int bufferSize = 4096;
        char query[bufferSize];

        fromFile(path, query, bufferSize);

        int rc = sqlite3_exec(db, query, 0, 0, &zErrMsg);
        if (rc) {
            cout << zErrMsg << endl;
            sqlite3_free(zErrMsg);
        }
    }

    void execManyFiles(const vector<string>& paths, sqlite3* db) {
        vector<exception> errors;
        for (auto& path : paths) {
            try {
                execFile(path, db);
            } catch (exception err) {
                errors.push_back(err);
            }
        }
        if (errors.size()) {
            for (auto error : errors) {
                cout << "sql file: " << error.what() << endl;
            }
            throw runtime_error("error during exec of sql files");
        }
    }

}


