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
		sqlite3* db;
	public:
		BookRepository(sqlite3* dataBase);
		virtual Book getBookById(int id);
		virtual void saveBook(const Book* book);


	};
}


