#include "Weapon.h"
#include "Player.h"

void Weapon::bulletcreate()
{
    bullet.setSize(sf::Vector2f(50.f, 1.f));
    bullet.setFillColor(sf::Color::White);
}

void Weapon::bulletfire(int x, int y)
{
    bullet.move(x, y);
}

void Weapon::bulletdraw(sf::RenderWindow &window)
{
    window.draw(bullet);
}

void Weapon::bulletposition()
{
    bullet.getGlobalBounds();
}

void Weapon::bombcreate()
{
    bomb.setPointCount(8);
    bomb.setRadius(10);
    bomb.setFillColor(sf::Color::Transparent);
    bomb.setOutlineColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
    bomb.setOutlineThickness(1);
}