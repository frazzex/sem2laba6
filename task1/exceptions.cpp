#include "exceptions.h"

const char *PasswordValidationException::what() const noexcept {
    return "Базовое исключение для ошибок пароля";
}

const char *PasswordLengthException::what() const noexcept {
    return "Длина пароля меньше 9 символов";
}

const char *PasswordRegisterException::what() const noexcept {
    return "Символы пароля не должны быть одного регистра";
}

const char *PasswordDigitException::what() const noexcept {
    return "В пароле нет ни одной цифры";
}

const char *PasswordForbiddenLetterException::what() const noexcept {
    return "В пароле есть символы, которые легко перепутать между собой";
}
