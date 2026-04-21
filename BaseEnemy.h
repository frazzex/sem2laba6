#ifndef LABA6_2026_BASEENEMY_H
#define LABA6_2026_BASEENEMY_H

#pragma once
#include "task2/BaseCharacter.h"


class BaseEnemy final : public BaseCharacter {
    Weapon weapon;

public:
    BaseEnemy(double pos_x, double pos_y, double hp, Weapon weapon);

    friend std::ostream &operator<<(std::ostream &os, const BaseEnemy &enemy);

    Weapon get_selected_weapon() override;
};


#endif //LABA6_2026_BASEENEMY_H
