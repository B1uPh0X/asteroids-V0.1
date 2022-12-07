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
    triangle.setScale(0.40f, 0.40f);
    triangle.setFillColor(sf::Color::Transparent);
    triangle.setOutlineThickness(2);
}

void Player::color1(){
    triangle.setFillColor(sf::Color::Transparent);
    triangle.setOutlineColor(sf::Color::Red);
}

void Player::color2(){
    triangle.setFillColor(sf::Color::Transparent);
    triangle.setOutlineColor(sf::Color::Blue);
}

void Player::color3(){
    triangle.setFillColor(sf::Color::Transparent);
    triangle.setOutlineColor(sf::Color::Yellow);
}

void Player::color4(){
    triangle.setFillColor(sf::Color::Transparent);
    triangle.setOutlineColor(sf::Color::Green);
}

void Player::color5(){
    triangle.setFillColor(sf::Color::Transparent);
    triangle.setOutlineColor(sf::Color::Cyan);
}

void Player::color6(){
    triangle.setFillColor(sf::Color::Transparent);
    triangle.setOutlineColor(sf::Color::Magenta);
}


void Player::draw(sf::RenderWindow &window) {
    window.draw(triangle);
}


void Player::boundaries(sf::RenderWindow &window){
    if (triangle.getPosition().x <= 0) {
        triangle.setPosition(0.f, triangle.getPosition().y);
    }
    if (triangle.getPosition().x >= window.getSize().x - triangle.getGlobalBounds().width) {
        triangle.setPosition(window.getSize().x - triangle.getGlobalBounds().width,triangle.getPosition().y);
    }
    if (triangle.getPosition().y <= 0) {
        triangle.setPosition(triangle.getPosition().x, 0.f);
    }
    if (triangle.getPosition().y >= window.getSize().y - triangle.getGlobalBounds().height) {
        triangle.setPosition(triangle.getPosition().x,window.getSize().y - triangle.getGlobalBounds().height);
    }
}