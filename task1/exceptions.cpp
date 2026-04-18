#include "exceptions.h"

const char *PasswordError::what() const noexcept {
    return "Базовое исключение для ошибок пароля";
}

const char *LengthError::what() const noexcept {
    return "Длина пароля меньше 9 символов";
}

const char *RegisterError::what() const noexcept {
    return "Символы пароля не должны быть одного регистра";
}

const char *DigitError::what() const noexcept {
    return "В пароле нет ни одной цифры";
}

const char *ForbiddenLetterError::what() const noexcept {
    return "В пароле есть символы, которые легко перепутать между собой";
}
