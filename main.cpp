#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Asteroid.h"
#include "Weapon.h"
#include <cmath>
#include <vector>
#include "ObjectManager.h"


int main() {

    Player player1;
    Asteroid asteroid;
    Weapon bomb;
    Weapon bullet;
    int limit = 0;
    bool isfiring = false;

//window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "AT-Roids");
    sf::Texture t;
    t.loadFromFile("../images/space_background.jpg");
    sf::Sprite s(t);

//vectors for the objects
    std::vector<sf::ConvexShape> asteroids;
    std::vector<Weapon> bullets;

//position at the origin
    sf::Vector2f startPosition(512, 384);

//setting positions for the players
    player1.triangle.setPosition(startPosition.x - 100, startPosition.y - 50 );

//creating asteroids and setting positions for them
    for (int i = 0; i <= 8; ++i) {
        asteroid.create();
        asteroid.shape.setPosition(rand() % 924, rand() % 668);
        asteroids.push_back(asteroid.shape);
    }

    while (window.isOpen()) {
        window.setFramerateLimit(60);
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
//movement for player
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))

                player1.controls('u');

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))

                player1.controls('d');

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                player1.triangle.move(player1.xmove(), player1.ymove());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            }

            window.clear();
            window.draw(s);

//player 1 basic functions
            player1.create();
            player1.color1();
            player1.drawPlayer(window);
            player1.boundaries(window);

// bullets
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                isfiring = true;
            }

            if (isfiring == true) {
                bullet.bulletcreate();
                bullet.bullet.setPosition(player1.triangle.getPosition().x, player1.triangle.getPosition().y);
                bullets.push_back(bullet);
                isfiring = false;
            }

            for (int j = 0; j < bullets.size(); j++) {
                bullets[j].bulletdraw(window);
                bullets[j].bulletfire(3, 0);
            }


//collision with asteroid and player
            for (unsigned int i = 0; i < asteroids.size(); i++) {
                sf::FloatRect asteroidblock = asteroids[i].getGlobalBounds();
                sf::FloatRect playerblock = player1.triangle.getGlobalBounds();
                if (asteroidblock.intersects(playerblock)) {
                    player1.triangle.move(-player1.xmove(), -player1.ymove());
                    player1.triangle.setPosition(rand() % 924, rand() % 668);
                    limit++;
                }
                if (limit == 3) {
                    window.close();
                }
//collision with bullet and asteroid(in progress)

                window.draw(asteroids.at(i));
            }
            window.display();
        }
    }
    return 0;
}