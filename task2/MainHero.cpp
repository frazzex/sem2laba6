#include <iostream>
#include <utility>
#include "MainHero.h"

#include "exceptions.h"

MainHero::MainHero(const double pos_x, const double pos_y, const double hp, std::string name) : BaseCharacter(
    pos_x, pos_y, hp) {
    this->name = std::move(name);
}

Weapon MainHero::get_selected_weapon() {
    if (this->inventory.empty()) return {"Ничего", -1, -1};

    try {
        Weapon selected_weapon = this->inventory.at(selected_weapon_idx);
        return selected_weapon;
    } catch (const std::out_of_range &e) {
        return {"Ничего", -1, -1};
    }
}

void MainHero::add_weapon(const Weapon &weapon) {
    this->inventory.emplace_back(weapon);
    if (this->inventory.size() == 1) {
        this->selected_weapon_idx = 0;
    }
    std::cout << "Подобрал " << weapon.get_name() << std::endl;
}

void MainHero::next_weapon() {
    if (this->inventory.empty()) {
        throw EmptyInventoryException();
    }

    if (this->inventory.size() == 1) {
        std::cout << "У меня только одно оружие" << std::endl;
        return;
    }

    this->selected_weapon_idx++;
    if (this->selected_weapon_idx >= this->inventory.size()) this->selected_weapon_idx = 0;
    std::cout << "Сменил оружие на " << this->get_selected_weapon() << std::endl;
}

void MainHero::heal(const double amount) {
    const double temp_hp = this->get_hp() + amount;
    this->set_hp(std::min(temp_hp, this->max_hp));
}
