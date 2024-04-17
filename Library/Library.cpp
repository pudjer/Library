#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>
#include <fstream> 
#include "GetDb.h"
using namespace std;
int main() {

    sqlite3* db;
    
    db = DB::getDb();
    

    return 0;

}
