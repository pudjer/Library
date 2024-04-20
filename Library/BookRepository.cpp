#include "BookRepository.h"
using namespace Model;

namespace Repositories {
	BookRepository::BookRepository(sqlite3* dataBase)
	{
		db = dataBase;
	};
    Book BookRepository::getBook(int id) {
        string bookQuery = "SELECT id, title, author, year, count FROM books WHERE id = ?;";
        sqlite3_stmt* stmt;

        Book book;
        const char* err;
        int rc = sqlite3_prepare_v2(db, bookQuery.c_str(), -1, &stmt, NULL);
        if (rc != SQLITE_OK) {
            err = sqlite3_errmsg(db);
            cout << err;
            throw runtime_error("Failed to prepare insert statement: " + string(err));
        }

        sqlite3_bind_int(stmt, 1, id);

        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            book.id = sqlite3_column_int(stmt, 0);
            book.title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            book.author = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            book.year = sqlite3_column_int(stmt, 3);
            book.count = sqlite3_column_int(stmt, 4);
        }
        else if (rc != SQLITE_DONE) {
            err = sqlite3_errmsg(db);
            cout << err;
            throw runtime_error("Failed to execute query: " + string(err));
        }

        sqlite3_finalize(stmt);
        return book;
    }
    void BookRepository::saveBook(Book* book) {
        const char* err;
        sqlite3_stmt* stmt;
        // Check if the book already exists in the database by checking its ID
        if (book->id == 0) {
            // If the book ID is 0, it means it's a new book and needs to be inserted
            string insertQuery = "INSERT INTO books (title, author, year, count) VALUES (?, ?, ?, ?);";
            int rc = sqlite3_prepare_v2(db, insertQuery.c_str(), -1, &stmt, NULL);
            if (rc != SQLITE_OK) {
                err = sqlite3_errmsg(db);
                cout << err;
                throw runtime_error("Failed to prepare insert statement: " + string(err));
            }

            sqlite3_bind_text(stmt, 1, book->title.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, book->author.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_int(stmt, 3, book->year);
            sqlite3_bind_int(stmt, 4, book->count);
        }
        else {
            // If the book ID is not 0, it means it's an existing book and needs to be updated
            string updateQuery = "UPDATE book SET title = ?, author = ?, year = ?, count = ? WHERE id = ?;";
            int rc = sqlite3_prepare_v2(db, updateQuery.c_str(), -1, &stmt, NULL);
            if (rc != SQLITE_OK) {
                err = sqlite3_errmsg(db);
                cout << err;
                throw runtime_error("Failed to prepare update statement: " + string(err));
            }

            sqlite3_bind_text(stmt, 1, book->title.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, book->author.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_int(stmt, 3, book->year);
            sqlite3_bind_int(stmt, 4, book->count);
            sqlite3_bind_int(stmt, 5, book->id);
        }

        int result = sqlite3_step(stmt);
        if (result != SQLITE_DONE) {
            err = sqlite3_errmsg(db);
            cout << err;
            throw runtime_error("Failed to execute save query: " + string(err));
        }

        sqlite3_finalize(stmt); // Finalize statement to release resources
        stmt = nullptr; // Reset statement handle
    }
}



