#ifndef ASTEROIDS_GAME_PLAYER_H
#define ASTEROIDS_GAME_PLAYER_H
#include <SFML/Graphics.hpp>

class Player {
public:
    sf::CircleShape triangle;
    Player();
    void create();
    void controls(char direction, float movespeed);
    void drawPlayer(sf::RenderWindow &window);
};

#endif //ASTEROIDS_GAME_PLAYER_H
