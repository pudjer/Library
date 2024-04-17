#pragma once
#include <string>

namespace Model {
    struct Client {
        int id;
        std::string passportNumber;
        std::string lastName;
        std::string firstName;
        std::string middleName;
        std::string address;
        std::string dateOfBirth;
    };
}


