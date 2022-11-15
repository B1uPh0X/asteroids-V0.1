#include "Asteroid.h"
#include <vector>
#include <SFML/Graphics.hpp>


void Asteroid::create() {
    shape.setPointCount(11);
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineThickness(1.f);
    shape.setOutlineColor(sf::Color::White);

    shape.setPoint(0, sf::Vector2f(40, 70));
    shape.setPoint(1, sf::Vector2f(70, 60));
    shape.setPoint(2, sf::Vector2f(65, 80));
    shape.setPoint(3, sf::Vector2f(80, 62));
    shape.setPoint(4, sf::Vector2f(99, 71));
    shape.setPoint(5, sf::Vector2f(110, 88));
    shape.setPoint(6, sf::Vector2f(94, 100));
    shape.setPoint(7, sf::Vector2f(97, 115));
    shape.setPoint(8, sf::Vector2f(88, 126));
    shape.setPoint(9, sf::Vector2f(50, 120));
    shape.setPoint(10, sf::Vector2f(35, 90));
    shape.setOrigin(77, 93);
}

void Asteroid::draw(sf::RenderWindow &window) {
    window.draw(shape);
}

void Asteroid::setPosition(){
    int num = rand() % 4;
    if (num == 0) {
       shape.setPosition(rand() % 150, rand() % 150);
    }
    if (num == 1) {
        shape.setPosition(1024 - rand() % 150, 0 + rand() % 150);
    }
    if (num == 2) {
        shape.setPosition(0 + rand() % 150, 768 - rand() % 150);
    }
    if (num == 3) {
        shape.setPosition(1024 - rand() % 150, 768 - rand() % 150);
    }
}
