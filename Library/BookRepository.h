#pragma once
#include <sqlite3.h>
#include "Book.h"
#include "fromFile.h"
using namespace Model;

class BookRepository
{
private:
	sqlite3* db;
public:
	BookRepository(sqlite3& dataBase);
	Book getBook(int id);
	void saveBook(Book& book);


};

