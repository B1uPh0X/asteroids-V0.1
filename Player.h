#ifndef ASTEROIDS_GAME_PLAYER_H
#define ASTEROIDS_GAME_PLAYER_H
#include <SFML/Graphics.hpp>

class Player {
public:
    sf::ConvexShape triangle;
    double veloc, rotat =0.0;
    int x, y = 0;
    bool alive = false;
    Player();
    void create();
    void color1();
    void color2();
    void color3();
    void color4();
    void color5();
    void color6();
    void controls();
    void drawPlayer(sf::RenderWindow &window);
    void boundaries(sf::RenderWindow &window);
    int xmove();
    int ymove();
    int setVeloc(double x);
    int setRotat(double x);
    int move();
};

#endif //ASTEROIDS_GAME_PLAYER_H