CREATE TABLE IF NOT EXISTS book_loans (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    dateOfIssue VARCHAR(255),
    dateOfReturn VARCHAR(255),
    book_id INTEGER,
    client_id INTEGER,
    canceled INTEGER,
    FOREIGN KEY (book_id) REFERENCES books(id),
    FOREIGN KEY (client_id) REFERENCES clients(id)
);