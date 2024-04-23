#pragma once
#include <sqlite3.h>
#include "BookLoan.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace Model;


namespace Repositories {
	class BookLoanRepository
	{
	private:
		sqlite3* db;
	public:
		BookLoanRepository(sqlite3* dataBase);
		BookLoan getBookLoanById(int id);
		void saveBookLoan(const BookLoan* bookLoan);
		vector<BookLoan> getAllBookLoans(bool openOnly);
		void deleteBookLoan(int id);
		vector<BookLoan> getBookLoansByBook(int bookId, bool openOnly);
		vector<BookLoan> getBookLoansByClient(int clientId, bool openOnly);

	};
	class BookLoanNotFound : exception {
	public:
		BookLoanNotFound();
		BookLoanNotFound(char*);
	};
}

