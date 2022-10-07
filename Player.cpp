#include <SFML/Graphics.hpp>
#include "Player.h"


Player::Player() {

}

void Player::create() {
    triangle.setPointCount(3);
    triangle.setRadius(20);
    triangle.setFillColor(sf::Color::Transparent);
    triangle.setOutlineThickness(2);
    triangle.setOutlineColor(sf::Color::Cyan);
}

void Player::controls(char direction, float movespeed) {
    if (direction == 'u') {
        triangle.rotate(-10.f);
    } else if (direction == 'd') {
        triangle.rotate(10.f);
    } else if (direction == 'f') {
        triangle.move(1.f, 0.f);
    }
}

void Player::drawPlayer(sf::RenderWindow &window) {
    window.draw(triangle);
}


