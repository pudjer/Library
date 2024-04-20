#pragma once
#include "Book.h"
#include <string>
#include <vector>

using namespace std;
using namespace Model;

class BookService
{
	Book getBookById(int id);
	vector<Book> getBookByName(string name);


};

