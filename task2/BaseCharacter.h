#ifndef LABA6_2026_BASECHARACTER_H
#define LABA6_2026_BASECHARACTER_H

#pragma once
#include "Weapon.h"

class Weapon;

class BaseCharacter {
    double pos_x;
    double pos_y;
    double hp;

    void take_damage(double amount);

    [[nodiscard]] double get_distance_to_another(const BaseCharacter &other_actor) const;

public:
    virtual ~BaseCharacter() = default;

    BaseCharacter(double pos_x, double pos_y, double hp);

    void move(double delta_x, double delta_y);

    [[nodiscard]] bool is_alive() const;

    [[nodiscard]] double get_x() const;

    [[nodiscard]] double get_y() const;

    virtual Weapon get_selected_weapon() = 0;

    virtual void hit(BaseCharacter &target);

    void set_hp(double amount);

    [[nodiscard]] double get_hp() const;
};


#endif //LABA6_2026_BASECHARACTER_H
