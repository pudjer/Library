#include <sqlite3.h>
#include <iostream>
#include <string>
#include <vector>
#include "fromFile.h"
#include <fstream>
#pragma once

using namespace std;
namespace DB {


    void execFile(const string& path, sqlite3* db);

    void execManyFiles(const vector<string>& paths, sqlite3* db);
}