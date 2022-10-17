#include <SFML/Graphics.hpp>
#include "Player.h"


Player::Player() {

}

void Player::create() {
    triangle.setPointCount(3);

    triangle.setPoint(0, sf::Vector2f(0,0));
    triangle.setPoint(1, sf::Vector2f(100, 40));
    triangle.setPoint(2, sf::Vector2f(0, 80));
    triangle.setOrigin(50, 40);
    triangle.setScale(0.5f, 0.5f);
    triangle.setFillColor(sf::Color::Transparent);
    triangle.setOutlineThickness(2);
    triangle.setOutlineColor(sf::Color::Cyan);
}

void Player::controls(char direction) {
    if (direction == 'u') {
        triangle.rotate(-6.f);
    } else if (direction == 'd') {
        triangle.rotate(6.f);
    } else if (direction == 'f') {
        triangle.move(1.f, 0.f);
    }
}

void Player::drawPlayer(sf::RenderWindow &window) {
    window.draw(triangle);
}

int Player::xmove(){
    sf::Vector2f head = triangle.getTransform().transformPoint(triangle.getPoint(1));
    sf::Vector2f origin = triangle.getTransform().transformPoint(triangle.getOrigin());
    return (head.x - origin.x) / 8;
}
int Player::ymove(){
    sf::Vector2f head = triangle.getTransform().transformPoint(triangle.getPoint(1));
    sf::Vector2f origin = triangle.getTransform().transformPoint(triangle.getOrigin());
    return (head.y - origin.y) / 8;
}



