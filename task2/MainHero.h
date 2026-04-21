#ifndef LABA6_2026_MAINHERO_H
#define LABA6_2026_MAINHERO_H
#pragma once
#include <vector>
#include "BaseCharacter.h"

class MainHero final : public BaseCharacter {
    std::vector<Weapon> inventory{};
    int selected_weapon_idx = -1;
    std::string name;
    double max_hp = 200;

public:
    MainHero(double pos_x, double pos_y, double hp, std::string name);

    Weapon get_selected_weapon() override;

    void add_weapon(const Weapon &weapon);

    void next_weapon();

    void heal(double amount);
};


#endif //LABA6_2026_MAINHERO_H
