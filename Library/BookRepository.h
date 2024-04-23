#pragma once
#include <sqlite3.h>
#include "Book.h"
#include <iostream>
using namespace std;
using namespace Model;


namespace Repositories {
	class BookRepository
	{
	private:
		void saveGenres(const Book* book);
		sqlite3* db;
	public:
		BookRepository(sqlite3* dataBase);
		Book getBookById(int id);
		void saveBook(Book* book);
		vector<Book> getAllBooks();
		void deleteBook(int id);
	};
	class BookNotFound : exception {
	public:
		BookNotFound();
		BookNotFound(char*);
	};
}


