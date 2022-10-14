#ifndef ASTEROID_H
#define ASTEROID_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

class Asteroid{
public:
    sf::Texture m_texture;
    sf::VertexArray m_vertices;
    sf::ConvexShape shape;
    void create();
    void draw(sf::RenderWindow &window);
    int xLoc, yLoc, xVel, yVel;
private:
};

#endif // ASTEROID_H
