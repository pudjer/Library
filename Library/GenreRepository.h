#pragma once
#include <sqlite3.h>
#include "Genre.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace Model;


namespace Repositories {
	class GenreRepository
	{
	private:
		sqlite3* db;
	public:
		GenreRepository(sqlite3* dataBase);
		Genre getGenre(const char* name);
		void saveGenre(const Genre* genre);
		vector<Genre> getAllGenres();
		void deleteGenre(const char* name);
	};
}

