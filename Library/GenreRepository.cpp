#include "GenreRepository.h"


namespace Repositories {
    GenreRepository::GenreRepository(sqlite3* dataBase)
    {
        db = dataBase;
    }

    Genre GenreRepository::getGenre(const char* name) {
        Genre genre;
        sqlite3_stmt* stmt;
        const char* query = "SELECT name, description FROM genres WHERE name = ?";

        int rc = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            const char* err = sqlite3_errmsg(db);
            throw std::runtime_error("Failed to prepare select statement: " + std::string(err));
        }

        sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);

        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            genre.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            genre.description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        }

        sqlite3_finalize(stmt);

        return genre;
    }

    void GenreRepository::saveGenre(const Genre* genre) {
        sqlite3_stmt* stmt;
        const char* query = "INSERT OR REPLACE INTO genres (name, description) VALUES (?, ?)";

        int rc = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            const char* err = sqlite3_errmsg(db);
            throw std::runtime_error("Failed to prepare insert statement: " + std::string(err));
        }

        sqlite3_bind_text(stmt, 1, genre->name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, genre->description.c_str(), -1, SQLITE_STATIC);

        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            const char* err = sqlite3_errmsg(db);
            throw std::runtime_error("Failed to execute insert statement: " + std::string(err));
        }

        sqlite3_finalize(stmt);
    }
}
