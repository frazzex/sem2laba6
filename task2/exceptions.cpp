//
// Created by ARTEM on 21.04.2026.
//

#include "exceptions.h"

const char *GameException::what() const noexcept {
    return "Базовое игровое исключение";
}

const char *DeadCharacterException::what() const noexcept {
    return "Персонаж уже умер!";
}

const char *EmptyInventoryException::what() const noexcept {
    return "Инвентарь пустой!";
}

const char *OutOfBoundsException::what() const noexcept {
    return "Выход за пределы допустимого игрового мира!";
}
