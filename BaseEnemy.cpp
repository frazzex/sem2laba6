#include <iostream>
#include <utility>

#include "BaseEnemy.h"


BaseEnemy::BaseEnemy(const double pos_x, const double pos_y, const double hp, Weapon weapon) : BaseCharacter(
        pos_x, pos_y, hp), weapon(std::move(weapon)) {
}

std::ostream &operator<<(std::ostream &os, const BaseEnemy &enemy) {
    os << "Враг на позиции (" << enemy.get_x() << ", " << enemy.get_y() << ")" << std::endl;
    return os;
}

Weapon BaseEnemy::get_selected_weapon() {
    return this->weapon;
}
