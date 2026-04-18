#include <iostream>
#include "task1/exceptions.h"
#include "task1/utils.h"


void task1() {
    try {
        const Password password1("Bobi1");
        std::cout << "Пароль: " << password1 << std::endl;
        password1.validate();
    } catch (const LengthError &e) {
        std::cout << "Ошибка: " << e.what() << std::endl << std::endl;
    }

    try {
        const Password password2("bobssksss123");
        std::cout << "Пароль: " << password2 << std::endl;
        password2.validate();
    } catch (const RegisterError &e) {
        std::cout << "Ошибка: " << e.what() << std::endl << std::endl;
    }

    try {
        const Password password3("Bobykssss");
        std::cout << "Пароль: " << password3 << std::endl;
        password3.validate();
    } catch (const DigitError &e) {
        std::cout << "Ошибка: " << e.what() << std::endl << std::endl;
    }

    try {
        const Password password4("Boblkssss123");
        std::cout << "Пароль: " << password4 << std::endl;
        password4.validate();
    } catch (const ForbiddenLetterError &e) {
        std::cout << "Ошибка: " << e.what() << std::endl << std::endl;
    }

    try {
        const Password password5("oblkssss123");
        std::cout << "Пароль: " << password5 << std::endl;
        password5.validate();
    } catch (const PasswordError &e) {
        std::cout << "Ошибка: " << e.what() << std::endl << std::endl;
    }
}

int main() {
    system("chcp 65001");
    setlocale(LC_ALL, "ru");
    task1();
    return 0;
}
