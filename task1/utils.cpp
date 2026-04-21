#include "utils.h"

#include "exceptions.h"

bool PasswordValidator::length_validator(const std::string &password) {
    return password.size() >= 9;
}

bool PasswordValidator::register_validator(const std::string &password) {
    if (password.empty()) return false;

    bool has_upper = false, has_lower = false;

    for (const auto el: password) {
        if (isupper(el)) has_upper = true;
        if (islower(el)) has_lower = true;
        if (has_upper && has_lower) return true;
    }

    return has_upper && has_lower;
}

bool PasswordValidator::presence_digit_validator(const std::string &password) {
    if (password.empty()) return false;

    for (const auto el: password) {
        if (isdigit(el)) return true;
    }
    return false;
}

bool PasswordValidator::presence_confusing_symbols_validator(const std::string &password) {
    if (password.empty()) return true;

    std::string confusing_symbols = "lI1Oo0";

    for (const auto el: password) {
        if (confusing_symbols.find(el)) return false;
    }

    return true;
}

Password::Password(const std::string &password) {
    this->password = password;
}

bool Password::validate() const {
    if (!PasswordValidator::length_validator(this->password)) throw PasswordLengthException();
    if (!PasswordValidator::register_validator(this->password)) throw PasswordRegisterException();
    if (!PasswordValidator::presence_digit_validator(this->password)) throw PasswordDigitException();
    if (!PasswordValidator::presence_confusing_symbols_validator(this->password)) throw
            PasswordForbiddenLetterException();

    return true;
}

std::ostream &operator<<(std::ostream &os, const Password &password) {
    os << password.password;
    return os;
}
