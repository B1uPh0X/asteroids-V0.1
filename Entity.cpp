
#include "Entity.h"
#include <math.h>
#include <SFML/Graphics.hpp>

using namespace std;

int x, y;
double rot, vel = 0.0;
bool alive = false;

void Entity::move(){
    x = vel * cos((float)rot);
    y = vel * sin((float)rot);
}

bool Entity::isalive(){
    return alive;
}

void Entity::spawn(){
    alive = true;
}

void Entity::kill(){
    alive = false;
}

void Entity::draw(){
    
}
