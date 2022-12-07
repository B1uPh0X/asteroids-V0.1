
#include "Entity.h"
#include <math.h>
#include <SFML/Graphics.hpp>

void Entity::move(){
    int x, y;
    double rot, vel = 0.0;

    x = vel * cos(rot);
    y = vel * sin(rot);
}

bool Entity::isalive(){
    bool alive = false;
    return alive;
}

void Entity::spawn(sf::RenderWindow &window){

}

void Entity::kill(){

}