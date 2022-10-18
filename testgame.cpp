#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Asteroid.h"
#include <cmath>
#include <vector>
#include <iostream>

int testgame()
{
  sf::RenderWindow window(sf::VideoMode(1024, 768), "test");
  window.setFramerateLimit(60);

  sf::CircleShape triangle;
  triangle.setPointCount(3);

  sf::Vector2f trianglePosition(500, 360);

  triangle.setPosition(trianglePosition);
  triangle.setRadius(100);

  float xVel = 3;
  float yVel = 3;

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      {
        window.close();
      }
    }

    if (trianglePosition.x < 0 || trianglePosition.x > 1024 - 20) {
      xVel *= -1;
    }
    if (trianglePosition.y < 0 || trianglePosition.y > 768 - 20) {
      yVel *= -1;
    }

    trianglePosition.x += xVel;
    trianglePosition.y += yVel;
    triangle.setPosition(trianglePosition);

    window.clear();
    window.draw(triangle);
    window.display();
  }

  return 0;
}