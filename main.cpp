#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

int main() {

    sf::RenderWindow window(sf::VideoMode(1024, 768), "Asteroids");

    sf::CircleShape player1(20, 3);
    sf::Vector2f velocity(0, 0);
    float acceleration = 1.f;


    player1.setFillColor(sf::Color::Red);
    player1.setRotation(90.f);
    player1.move(40, 384);

    std::vector<sf::CircleShape> asteroids;

    for (int i = 0; i <= 30; i++) {
        sf::CircleShape asteroid(20, 8);
        asteroid.setFillColor(sf::Color::White);
        asteroid.move(rand() % 1024, rand() % 768);
        asteroids.push_back(asteroid);
    }


    sf::Clock deltaclock;
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        sf::Time deltatime = deltaclock.restart();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (player1.getFillColor() == sf::Color::Transparent) {
                window.close();
            }
        }


        window.draw(player1);
        window.display();
        window.clear();
        for (unsigned int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i].getGlobalBounds().intersects(player1.getGlobalBounds())) {
                player1.setFillColor(sf::Color::Transparent);
            }
            for (int j = 0; j <= 14; j++) {
                asteroids[j].move(-1 / 32.f, 0.f);
            }
            window.draw(asteroids.at(i));
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            if (velocity.x < 10) velocity.x += acceleration * deltatime.asSeconds();
            if (velocity.y < 10) velocity.y += acceleration * deltatime.asSeconds();
            player1.move(1.f, 0.f);

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            if (velocity.x > 0) velocity.x += acceleration * deltatime.asSeconds();
            if (velocity.y > 0) velocity.y += acceleration * deltatime.asSeconds();
            player1.move(-1.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player1.move(0.f, -1.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player1.move(0.f, 1.f);
        }

        player1.setRotation(90.f);

    }
    return 0;
}

