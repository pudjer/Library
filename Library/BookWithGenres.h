#pragma once
#include "Book.h"
#include <vector>
#include "Genre.h"
namespace Model {

	class BookWithGenres : Book
	{
		std::vector<Genre> genres;
	};
}

