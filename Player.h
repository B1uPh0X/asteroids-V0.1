#ifndef ASTEROIDS_GAME_PLAYER_H
#define ASTEROIDS_GAME_PLAYER_H
#include <SFML/Graphics.hpp>

class Player {
public:
    sf::ConvexShape triangle;
    Player();
    void create();
    void controls(char direction);
    void drawPlayer(sf::RenderWindow &window);
    int xmove();
    int ymove();
};

#endif //ASTEROIDS_GAME_PLAYER_H