

#ifndef ASTEROIDS_GAME_BULLET_H
#define ASTEROIDS_GAME_BULLET_H
#include <SFML/Graphics.hpp>
#include "Entity.h"


class Bullet: public Entity {
public:
    sf::RectangleShape bullet;
    void bulletcreate();
    void bulletfire(int x, int y, double angle);
    void bulletdraw(sf::RenderWindow &window);
};


#endif //ASTEROIDS_GAME_BULLET_H
