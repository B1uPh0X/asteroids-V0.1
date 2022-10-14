#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Asteroid.h"
#include <cmath>
#include <vector>
#include <iostream>


int main() {

    Player player1;
    Asteroid asteroid;

    sf::RenderWindow window(sf::VideoMode(1024, 768), "AT-Roids");
    sf::Texture t;
    t.loadFromFile("../images/space_background.jpg");
    sf::Sprite s(t);

    std::vector<sf::ConvexShape> asteroids;

    for(int i = 0; i <= 8; i++){
         asteroid.create();
         asteroid.shape.setPosition(rand() % 1024 , rand() % 768);
         asteroids.push_back(asteroid.shape);

    }

    while (window.isOpen()) {
        window.setFramerateLimit(60);
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))

                player1.controls('u', 6.00);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))

                player1.controls('d', 6.00);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))

                player1.triangle.move(cos(player1.triangle.getRotation()*3.14159265/180)*3.f,sin(player1.triangle.getRotation()*3.14159265/180)*-3.f);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))

                player1.triangle.move(cos(player1.triangle.getRotation()*3.14159265/180)*-3.f,sin(player1.triangle.getRotation()*3.14159265/180)*3.f);

            if (player1.triangle.getPosition().x >= window.getSize().x  || player1.triangle.getPosition().y >= window.getSize().y ) {
                player1.triangle.move(-6.f, 0.f);
            }

            window.clear();
            window.draw(s);
            player1.create();
            asteroid.create();
            player1.drawPlayer(window);
            asteroid.draw(window);
            for (unsigned int i = 0; i < asteroids.size(); i++) {
                window.draw(asteroids.at(i));
            }
            window.display();
        }
        printf("Player X Position: %1f \n", player1.triangle.getPosition().x);
        printf("Player Y Position: %1f \n", player1.triangle.getPosition().y);
    }
    return 0;
}