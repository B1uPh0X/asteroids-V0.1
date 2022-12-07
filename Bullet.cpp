//
// Created by shuck on 11/28/2022.
//

#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include "Player.h"

void Bullet::bulletcreate(){
bullet.setSize(sf::Vector2f(50.f, 1.f));
bullet.setFillColor(sf::Color::White);
bullet.setOrigin(25.f, 0.5f);
}

void Bullet::bulletfire(int x, int y, double angle){
    bullet.move(x ,y);
    bullet.setRotation(angle);
}

void Bullet::draw(sf::RenderWindow &window){
    window.draw(bullet);
}