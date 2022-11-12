#ifndef ASTEROIDS_GAME_BOT_H
#define ASTEROIDS_GAME_BOT_H
#include <SFML/Graphics.hpp>

class Bot {
public:
	sf::ConvexShape triangle;
	Bot();
	void create(string fn);
	void drawBot(sf::RenderWindow &window);
	void run();
	int setVelocity();
	int setThrottle();
	int rotate();
	int shoot();
};

#endif //ASTEROIDS_GAME_BOT_H