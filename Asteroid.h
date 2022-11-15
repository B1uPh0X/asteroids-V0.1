#ifndef ASTEROID_H
#define ASTEROID_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

class Asteroid{
public:
    sf::ConvexShape shape;
    void create();
    void draw(sf::RenderWindow &window);
    void setPosition();
private:
};

#endif // ASTEROID_H