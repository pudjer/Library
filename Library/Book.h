#pragma once
#include <string>
#include <vector>
#include "Genre.h"

namespace Model {
    struct Book {
        int id = 0;
        std::string title;
        std::string author;
        int year;
        int count;
        std::vector<Genre> genres;
    };
}


