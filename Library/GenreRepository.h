#pragma once
#include <sqlite3.h>
#include "Genre.h"
#include <iostream>
using namespace std;
using namespace Model;


namespace Repositories {
	class GenreRepository
	{
	private:
		sqlite3* db;
	public:
		GenreRepository(sqlite3* dataBase);
		Genre getGenre(char* name);
		void saveGenre(Genre* genre);
	};
}

