#ifndef ASTEROIDS_GAME_BOT_H
#define ASTEROIDS_GAME_BOT_H
#include <SFML/Graphics.hpp>

using namespace std;
class Bot {
public:
	sf::ConvexShape triangle;
	static bool alive;
	static const char *file;
	Bot();
	void create(string fn);
	void drawBot(sf::RenderWindow &window);
	static void run();
	static void setVelocity();
	static void setThrottle();
	static void rotate();
	static void shoot();
	static void kill();
	static bool isAlive();
};

#endif //ASTEROIDS_GAME_BOT_H