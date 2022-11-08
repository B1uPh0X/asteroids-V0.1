#ifndef ASTEROIDS_GAME_WEAPON_H
#define ASTEROIDS_GAME_WEAPON_H
#include <SFML/Graphics.hpp>

class Weapon {
public:
    sf::RectangleShape bullet;
    sf::CircleShape bomb;
    void bulletcreate();
    void bulletfire(int x, int y);
    void bulletdraw(sf::RenderWindow &window);
    void bulletposition();
    void bombcreate();
};


#endif //ASTEROIDS_GAME_WEAPON_H