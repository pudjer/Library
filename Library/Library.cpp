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


    Book book{ "meme", "down", 2022, 3, 1};
    Genre genre{ "porno", "sex" };
    book.genres.push_back(genre);
    bookRepo.saveBook(&book);
    book = bookRepo.getBookById(3);
    cout << book.title << endl;
    cout << book.author << endl;
    cout << book.year << endl;
    cout << book.count << endl;
    for (auto genrea : book.genres) {
        cout << genrea.name << endl;
    }
    return 0;

}
