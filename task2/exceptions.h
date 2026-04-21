#ifndef LABA6_2026_EXCEPTIONS2_H
#define LABA6_2026_EXCEPTIONS2_H

#pragma once
#include <exception>


class GameException : public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class DeadCharacterException final : public GameException {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class EmptyInventoryException final : public GameException {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class OutOfBoundsException final : public GameException {
public:
    [[nodiscard]] const char *what() const noexcept override;
};


#endif //LABA6_2026_EXCEPTIONS2_H
