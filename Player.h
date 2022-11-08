#ifndef ASTEROIDS_GAME_PLAYER_H
#define ASTEROIDS_GAME_PLAYER_H
#include <SFML/Graphics.hpp>

class Player {
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
    void controls(char direction);
    void drawPlayer(sf::RenderWindow &window);
    void boundaries(sf::RenderWindow &window);
    int xmove();
    int ymove();
};

#endif //ASTEROIDS_GAME_PLAYER_H