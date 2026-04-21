#pragma once

#include <iostream>

#include "BaseEnemy.h"
#include "task1/exceptions.h"
#include "task1/utils.h"
#include "task2/BaseCharacter.h"
#include "task2/exceptions.h"
#include "task2/MainHero.h"

void task1() {
    try {
        const Password password1("Bobi1");
        std::cout << "Пароль: " << password1 << std::endl;
        password1.validate();
    } catch (const PasswordLengthException &e) {
        std::cout << "Ошибка: " << e.what() << std::endl << std::endl;
    }

    try {
        const Password password2("bobssksss123");
        std::cout << "Пароль: " << password2 << std::endl;
        password2.validate();
    } catch (const PasswordRegisterException &e) {
        std::cout << "Ошибка: " << e.what() << std::endl << std::endl;
    }

    try {
        const Password password3("Bobykssss");
        std::cout << "Пароль: " << password3 << std::endl;
        password3.validate();
    } catch (const PasswordDigitException &e) {
        std::cout << "Ошибка: " << e.what() << std::endl << std::endl;
    }

    try {
        const Password password4("Boblkssss123");
        std::cout << "Пароль: " << password4 << std::endl;
        password4.validate();
    } catch (const PasswordForbiddenLetterException &e) {
        std::cout << "Ошибка: " << e.what() << std::endl << std::endl;
    }

    try {
        const Password password5("oblkssss123");
        std::cout << "Пароль: " << password5 << std::endl;
        password5.validate();
    } catch (const PasswordValidationException &e) {
        std::cout << "Ошибка: " << e.what() << std::endl << std::endl;
    }
}

void task2() {
    Weapon MP4{"MP4", 30, 40};
    Weapon AK47{"AK-47", 20, 60};
    Weapon desert_eagle{"Desert Eagle", 50, 50};

    BaseEnemy enemy{10.5, 15.5, 70, MP4};
    MainHero hero{9.6, 14.9, 80, "Artem"};

    hero.add_weapon(AK47);
    hero.add_weapon(MP4);
    hero.add_weapon(desert_eagle);

    while (true) {
        hero.move(-10 + rand() % 21, -10 + rand() % 21);
        enemy.move(-10 + rand() % 21, -10 + rand() % 21);

        std::cout << "----------\nХодит главный герой\n----------\n\n";
        try {
            hero.hit(enemy);
        } catch (const DeadCharacterException &e) {
            std::cout << "Главный герой выиграл!" << std::endl;
            return;
        }
        hero.next_weapon();
        hero.heal(2);

        if (!enemy.is_alive()) {
            std::cout << "Главный герой выиграл!" << std::endl;
            return;
        }
        std::cout << "----------\nХодит враг\n----------\n\n";

        try {
            enemy.hit(hero);
        } catch (const DeadCharacterException &e) {
            std::cout << "Враг выиграл!" << std::endl;
            return;
        }

        if (!hero.is_alive()) {
            std::cout << "Враг выиграл!" << std::endl;
            return;
        }
    }
}

int main() {
    system("chcp 65001");
    setlocale(LC_ALL, "ru");
    srand(time(0));
    task2();
    return 0;
}
