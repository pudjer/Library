#pragma once
#include <string>
#include "Book.h"
#include "Client.h"

namespace Model {
    struct BookLoan {
        int id;
        std::string dateOfIssue;
        std::string dateOfReturn;
        Book book;
        Client client;
        bool canceled;
    };
}

