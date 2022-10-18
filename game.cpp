#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Asteroid.h"
#include <cmath>
#include <vector>
#include <iostream>

int game()
{
    Player player1;
    Asteroid asteroid;

    sf::RenderWindow window(sf::VideoMode(1024, 768), "AT-Roids");
    sf::Texture t;
    t.loadFromFile("./images/space_background.jpg");
    sf::Sprite s(t);

    std::vector<sf::ConvexShape> asteroids;

    sf::Vector2f startPosition(512, 384);
    player1.triangle.setPosition(startPosition);

    for (int i = 0; i <= 8; i++)
    {
        asteroid.create();
        asteroid.shape.setPosition(rand() % 924, rand() % 668);
        asteroids.push_back(asteroid.shape);
    }

    while (window.isOpen())
    {
        window.setFramerateLimit(120);
        sf::Event event;

        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))

                player1.controls('u');

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))

                player1.controls('d');

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                player1.triangle.move(player1.xmove(), player1.ymove());
            }

            if (player1.triangle.getPosition().x <= 0)
            {
                player1.triangle.setPosition(0.f, player1.triangle.getPosition().y);
            }
            if (player1.triangle.getPosition().x >= window.getSize().x - player1.triangle.getGlobalBounds().width)
            {
                player1.triangle.setPosition(window.getSize().x - player1.triangle.getGlobalBounds().width, player1.triangle.getPosition().y);
            }
            if (player1.triangle.getPosition().y <= 0)
            {
                player1.triangle.setPosition(player1.triangle.getPosition().x, 0.f);
            }
            if (player1.triangle.getPosition().y >= window.getSize().y - player1.triangle.getGlobalBounds().height)
            {
                player1.triangle.setPosition(player1.triangle.getPosition().x, window.getSize().y - player1.triangle.getGlobalBounds().height);
            }
            window.clear();
            window.draw(s);
            player1.create();
            player1.drawPlayer(window);
            for (unsigned int i = 0; i < asteroids.size(); i++)
            {
                if (asteroids[i].getGlobalBounds().intersects(player1.triangle.getGlobalBounds()))
                {
                    player1.triangle.setOutlineColor(sf::Color::Magenta);
                }
                window.draw(asteroids.at(i));
            }
            window.display();
        }
    }
    return 0;
}