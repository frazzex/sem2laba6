#ifndef LABA6_2026_EXCEPTIONS1_H
#define LABA6_2026_EXCEPTIONS1_H
#pragma once
#include <exception>

class PasswordValidationException : public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class PasswordLengthException final : public PasswordValidationException {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class PasswordRegisterException final : public PasswordValidationException {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class PasswordDigitException final : public PasswordValidationException {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class PasswordForbiddenLetterException final : public PasswordValidationException {
public:
    [[nodiscard]] const char *what() const noexcept override;
};


#endif //LABA6_2026_EXCEPTIONS1_H
