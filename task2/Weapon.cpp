#include <iostream>
#include "Weapon.h"


Weapon::Weapon(const std::string &name, const double damage, const double range) {
    this->name = name;
    this->damage = damage;
    this->range = range;
}

std::string Weapon::get_name() const {
    return this->name;
}

double Weapon::get_damage() const {
    return this->damage;
}

double Weapon::get_range() const {
    return this->range;
}

std::istream &operator>>(std::istream &is, Weapon &weapon) {
    std::string name;
    double damage, range;

    is >> name >> damage >> range;
    if (is.good()) {
        weapon = Weapon(name, damage, range);
    }

    return is;
}

std::ostream &operator<<(std::ostream &os, const Weapon &weapon) {
    os << weapon.get_name();
    return os;
}
