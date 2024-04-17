CREATE TABLE IF NOT EXISTS clients (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    passportNumber VARCHAR(255),
    lastName VARCHAR(255),
    firstName VARCHAR(255),
    middleName VARCHAR(255),
    address VARCHAR(255),
    dateOfBirth VARCHAR(255)
);
