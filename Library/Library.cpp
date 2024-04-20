#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>
#include <fstream> 
#include "GetDb.h"
#include "BookRepository.h"
using namespace std;
using namespace Repositories;
int main() {

    sqlite3* db;
    
    db = DB::getDb();
    Repositories::BookRepository bookRepo(db);


    Book book{ "meme", "down", 2022, 3};
    Genre genre{ "porno", "sex" };
    book.genres.push_back(genre);
    bookRepo.saveBook(&book);
    bookRepo.getBook(1);
    cout << book.title << book.author << book.year << book.count;
    for (auto genre : book.genres) {
        cout << "genres: " << endl;
        cout << genre.name;
    }
    return 0;

}
