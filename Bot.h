#ifndef ASTEROIDS_GAME_BOT_H
#define ASTEROIDS_GAME_BOT_H
#include <SFML/Graphics.hpp>

class Bot {
public:
    sf::ConvexShape triangle;
    Bot();
    void create();
    void controls(char direction);
    void drawBot(sf::RenderWindow &window);
    int xmove();
    int ymove();
};

#endif //ASTEROIDS_GAME_BOT_H