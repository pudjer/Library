#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>
#include <fstream> 
#include "GetDb.h"
#include "BookRepository.h"
#include "Genre.h"



using namespace std;
using namespace Repositories;
int main() {

    sqlite3* db;
    
    db = DB::getDb();
    Repositories::BookRepository bookRepo(db);


    Book book{ "meme", "down", 2022, 3};
    Genre genre{ "porno", "sex" };
    bookRepo.saveBook(&book);
    bookRepo.getBookById(1);
    cout << book.title << book.author << book.year << book.count;
    return 0;

}
