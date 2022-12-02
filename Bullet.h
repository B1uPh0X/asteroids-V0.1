

#ifndef ASTEROIDS_GAME_BULLET_H
#define ASTEROIDS_GAME_BULLET_H
#include <SFML/Graphics.hpp>


class Bullet {
public:
    sf::RectangleShape bullet;
    void bulletcreate();
    void bulletfire(int x, int y);
    void bulletdraw(sf::RenderWindow &window);
};


#endif //ASTEROIDS_GAME_BULLET_H
