#ifndef LABA6_2026_EXCEPTIONS_H
#define LABA6_2026_EXCEPTIONS_H
#include <exception>

class PasswordError : public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class LengthError : public PasswordError {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class RegisterError : public PasswordError {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class DigitError : public PasswordError {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class ForbiddenLetterError : public PasswordError {
public:
    [[nodiscard]] const char *what() const noexcept override;
};


#endif //LABA6_2026_EXCEPTIONS_H
