#ifndef ASTEROIDS_GAME_PLAYER_H
#define ASTEROIDS_GAME_PLAYER_H
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player: public Entity {
public:
    sf::ConvexShape triangle;
    Player();
    void create();
    void color1();
    void color2();
    void color3();
    void color4();
    void color5();
    void color6();
    void draw(sf::RenderWindow &window);
    void boundaries(sf::RenderWindow &window);
};

#endif //ASTEROIDS_GAME_PLAYER_H
