#include <cmath>
#include <iostream>
#include "BaseCharacter.h"

#include "exceptions.h"

BaseCharacter::BaseCharacter(const double pos_x, const double pos_y, const double hp) {
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->hp = hp;
}

double BaseCharacter::get_x() const {
    return this->pos_x;
}

double BaseCharacter::get_y() const {
    return this->pos_y;
}

bool BaseCharacter::is_alive() const {
    if (this->hp <= 0) return false;
    return true;
}

void BaseCharacter::take_damage(const double amount) {
    this->set_hp(std::max(this->get_hp() - amount, 0.0));
}

void BaseCharacter::move(const double delta_x, const double delta_y) {
    this->pos_x += delta_x;
    this->pos_y += delta_y;
}

double BaseCharacter::get_distance_to_another(const BaseCharacter &other_actor) const {
    double distance = std::sqrt(

        pow(other_actor.get_x() - this->get_x(), 2)
        + pow(other_actor.get_y() - this->get_y(), 2)

    );

    return distance;
}


void BaseCharacter::hit(BaseCharacter &target) {
    if (!target.is_alive()) {
        throw DeadCharacterException();
    }

    const Weapon selected_weapon = this->get_selected_weapon();
    if (selected_weapon.get_damage() == -1) {
        throw EmptyInventoryException();
    }
    double distance = this->get_distance_to_another(target);

    if (selected_weapon.get_range() < distance) {
        std::cout << "Персонаж слишком далеко для оружия " << selected_weapon.get_name() << std::endl;
        return;
    }

    target.take_damage(selected_weapon.get_damage());

    std::cout << "Персонажу " << " нанесен урон оружием "
            << selected_weapon.get_name()
            << " в размере "
            << selected_weapon.get_damage() << ". Осталось HP: " << target.get_hp() << std::endl;
}

double BaseCharacter::get_hp() const {
    return this->hp;
}

void BaseCharacter::set_hp(const double amount) {
    this->hp = amount;
}
