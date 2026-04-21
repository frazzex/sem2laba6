#ifndef LABA6_2026_WEAPON_H
#define LABA6_2026_WEAPON_H

#pragma once
#include <string>


class Weapon {
    std::string name;
    double damage;
    double range;

public:
    Weapon(const std::string &name, double damage, double range);

    friend std::ostream &operator<<(std::ostream &os, const Weapon &weapon);

    friend std::istream &operator>>(std::istream &is, const Weapon &weapon);

    [[nodiscard]] std::string get_name() const;

    [[nodiscard]] double get_damage() const;

    [[nodiscard]] double get_range() const;
};


#endif //LABA6_2026_WEAPON_H
