#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include <iostream>
#include <cmath>


int main() {

    Player player1;

    sf::RenderWindow window(sf::VideoMode(1024, 768), "AT-Roids");


    while (window.isOpen()) {

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

            if (player1.triangle.getPosition().x - player1.triangle.getRadius() >= window.getSize().x ||
                player1.triangle.getPosition().y - player1.triangle.getRadius() >= window.getSize().y) {
                player1.triangle.move(-6.f, 0.f);
            }


            std::cout << window.getSize().x << std::endl;
            std::cout << window.getSize().y << std::endl;
            window.clear();
            player1.create();
            player1.drawPlayer(window);
            window.display();
        }
    }
    return 0;
}