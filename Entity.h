

#ifndef ASTEROIDS_GAME_ENTITY_H
#define ASTEROIDS_GAME_ENTITY_H

class Entity {
public:
    void move();
    bool isalive();
    void spawn(sf::RenderWindow &window);
    void kill();
}


#endif //ASTEROIDS_GAME_ENTITY_H
