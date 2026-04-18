#ifndef LABA6_2026_UTILS_H
#define LABA6_2026_UTILS_H
#pragma once
#include <string>


class PasswordValidator {
public:
    static bool length_validator(const std::string &password);

    static bool register_validator(const std::string &password);

    static bool presence_digit_validator(const std::string &password);

    static bool presence_confusing_symbols_validator(const std::string &password);
};

class Password {
    std::string password;

public:
    explicit Password(const std::string &password);

    bool validate() const;

    friend std::ostream &operator<<(std::ostream &os, const Password &password);
};


#endif //LABA6_2026_UTILS_H
