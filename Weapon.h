

#ifndef ASTEROIDS_GAME_WEAPON_H
#define ASTEROIDS_GAME_WEAPON_H
#include <SFML/Graphics.hpp>

class Weapon {
public:
    sf::RectangleShape bullet;
    sf::CircleShape bomb;
    void bulletcreate();
    void bombcreate();
};


#endif //ASTEROIDS_GAME_WEAPON_H
