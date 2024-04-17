#include "BookRepository.h"
using namespace Model;


BookRepository::BookRepository(sqlite3& dataBase)
{
	db = &dataBase;
};
Book BookRepository::getBook(int id)
{
	return Book();
};
void BookRepository::saveBook(Book& book) {};


