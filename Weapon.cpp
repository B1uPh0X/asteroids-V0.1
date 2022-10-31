#include "Weapon.h"

void Weapon::bulletcreate(){
    bullet.setSize(sf::Vector2f(150.f, 1.f));
    bullet.setFillColor(sf::Color::White);
}

void Weapon::bombcreate() {
    bomb.setPointCount(8);
    bomb.setRadius(10);
    bomb.setFillColor(sf::Color::Transparent);
    bomb.setOutlineColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
    bomb.setOutlineThickness(1);
}