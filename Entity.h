

#ifndef ASTEROIDS_GAME_ENTITY_H
#define ASTEROIDS_GAME_ENTITY_H
#include <SFML/Graphics.hpp>

class Entity {
public:
    int x, y;
    double rot, vel = 0.0;
    bool alive = false;
    void move();
    bool isalive();
    void spawn();
    void kill();
    void draw();
};


#endif //ASTEROIDS_GAME_ENTITY_H
