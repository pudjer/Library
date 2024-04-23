#pragma once
#include <string>

namespace Model {
    struct Client {
        std::string passportNumber;
        std::string lastName;
        std::string firstName;
        std::string middleName;
        std::string address;
        std::string dateOfBirth;
        int id = 0;
    };
}


