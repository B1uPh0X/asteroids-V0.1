#ifndef ASTEROID_H
#define ASTEROID_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
//#include <SFML/OpenGL.hpp>
using namespace std;
class Asteroid: public Entity {
public:
    sf::ConvexShape shape;
    void create();
    void draw(sf::RenderWindow &window);
    void setPosition();
private:
};

#endif // ASTEROID_H