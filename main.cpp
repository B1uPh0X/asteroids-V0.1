#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 500), "Testing");
    sf::CircleShape player1(20, 3);
    player1.setFillColor(sf::Color::Red);
    player1.move(rand() % 800, rand() % 500);
    sf::CircleShape player2(20, 3);
    player2.setFillColor(sf::Color::Blue);
    player2.move(rand() % 800, rand() % 500);
    sf::CircleShape movingasteroid1(20, 8);
    movingasteroid1.setFillColor(sf::Color::White);
    movingasteroid1.move(rand() % 800, rand() % 500);
    sf::CircleShape movingasteroid2(20, 8);
    movingasteroid2.setFillColor(sf::Color::White);
    movingasteroid2.move(rand() % 800, rand() % 500);
    sf::CircleShape movingasteroid3(20, 8);
    movingasteroid3.setFillColor(sf::Color::White);
    movingasteroid3.move(rand() % 800, rand() % 500);
    sf::CircleShape movingasteroid4(20, 8);
    movingasteroid4.setFillColor(sf::Color::White);
    movingasteroid4.move(rand() % 800, rand() % 500);
    std::vector<sf::CircleShape> asteroids;

    for (int i = 0; i <= 14; i++) {
        sf::CircleShape asteroid(20, 8);
        asteroid.setFillColor(sf::Color::White);
        asteroid.move(rand() % 800, rand() % 500);
        asteroids.push_back(asteroid);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (unsigned int i = 0; i < asteroids.size(); i++) {
            window.draw(asteroids.at(i));
            if (player1.getGlobalBounds().intersects(asteroids[i].getGlobalBounds())) {

            }
        }

        window.draw(player1);
        window.draw(player2);
        window.draw(movingasteroid1);
        window.draw(movingasteroid2);
        window.draw(movingasteroid3);
        window.draw(movingasteroid4);
        window.display();


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player1.move(0.f, -1 / 64.f);
            if (player1.getGlobalBounds().intersects(player2.getGlobalBounds())) {
                player1.move(0.f, 1 / 64.f);
            }
            if (player1.getGlobalBounds().intersects(movingasteroid1.getGlobalBounds())) {
                player1.move(0.f, 1 / 64.f);
            }
            if (player1.getGlobalBounds().intersects(movingasteroid2.getGlobalBounds())) {
                player1.move(0.f, 1 / 64.f);
            }
            if (player1.getGlobalBounds().intersects(movingasteroid3.getGlobalBounds())) {
                player1.move(0.f, 1 / 64.f);
            }
            if (player1.getGlobalBounds().intersects(movingasteroid4.getGlobalBounds())) {
                player1.move(0.f, 1 / 64.f);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player1.move(0.f, 1 / 64.f);
            if (player1.getGlobalBounds().intersects(player2.getGlobalBounds())) {
                player1.move(0.f, -1 / 64.f);
            }
            if (player1.getGlobalBounds().intersects(movingasteroid1.getGlobalBounds())) {
                player1.move(0.f, -1 / 64.f);
            }
            if (player1.getGlobalBounds().intersects(movingasteroid2.getGlobalBounds())) {
                player1.move(0.f, -1 / 64.f);
            }
            if (player1.getGlobalBounds().intersects(movingasteroid3.getGlobalBounds())) {
                player1.move(0.f, -1 / 64.f);
            }
            if (player1.getGlobalBounds().intersects(movingasteroid4.getGlobalBounds())) {
                player1.move(0.f, -1 / 64.f);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player1.move(1 / 64.f, 0.f);
            if (player1.getGlobalBounds().intersects(player2.getGlobalBounds())) {
                player1.move(-1 / 64.f, 0.f);
            }
            if (player1.getGlobalBounds().intersects(movingasteroid1.getGlobalBounds())) {
                player1.move(-1 / 64.f, 0.f);
            }
            if (player1.getGlobalBounds().intersects(movingasteroid2.getGlobalBounds())) {
                player1.move(-1 / 64.f, 0.f);
            }
            if (player1.getGlobalBounds().intersects(movingasteroid3.getGlobalBounds())) {
                player1.move(-1 / 64.f, 0.f);
            }
            if (player1.getGlobalBounds().intersects(movingasteroid4.getGlobalBounds())) {
                player1.move(-1 / 64.f, 0.f);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player1.move(-1 / 64.f, 0.f);
            if (player1.getGlobalBounds().intersects(player2.getGlobalBounds())) {
                player1.move(1 / 64.f, 0.f);
            }
            if (player1.getGlobalBounds().intersects(movingasteroid1.getGlobalBounds())) {
                player1.move(1 / 64.f, 0.f);
            }
            if (player1.getGlobalBounds().intersects(movingasteroid2.getGlobalBounds())) {
                player1.move(1 / 64.f, 0.f);
            }
            if (player1.getGlobalBounds().intersects(movingasteroid3.getGlobalBounds())) {
                player1.move(1 / 64.f, 0.f);
            }
            if (player1.getGlobalBounds().intersects(movingasteroid4.getGlobalBounds())) {
                player1.move(1 / 64.f, 0.f);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
            player2.move(0.f, -1 / 64.f);
            if (player2.getGlobalBounds().intersects(player1.getGlobalBounds())) {
                player2.move(0.f, 1 / 64.f);
            }
            if (player2.getGlobalBounds().intersects(movingasteroid1.getGlobalBounds())) {
                player2.move(0.f, 1 / 64);
            }
            if (player2.getGlobalBounds().intersects(movingasteroid2.getGlobalBounds())) {
                player2.move(0.f, 1 / 64);
            }
            if (player2.getGlobalBounds().intersects(movingasteroid3.getGlobalBounds())) {
                player2.move(0.f, 1 / 64);
            }
            if (player2.getGlobalBounds().intersects(movingasteroid4.getGlobalBounds())) {
                player2.move(0.f, 1 / 64);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
            player2.move(0.f, 1 / 64.f);
            if (player2.getGlobalBounds().intersects(player1.getGlobalBounds())) {
                player2.move(0.f, -1 / 64.f);
            }
            if (player2.getGlobalBounds().intersects(movingasteroid1.getGlobalBounds())) {
                player2.move(0.f, -1 / 64);
            }
            if (player2.getGlobalBounds().intersects(movingasteroid2.getGlobalBounds())) {
                player2.move(0.f, -1 / 64);
            }
            if (player2.getGlobalBounds().intersects(movingasteroid3.getGlobalBounds())) {
                player2.move(0.f, -1 / 64);
            }
            if (player2.getGlobalBounds().intersects(movingasteroid4.getGlobalBounds())) {
                player2.move(0.f, -1 / 64);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
            player2.move(1 / 64.f, 0.f);
            if (player2.getGlobalBounds().intersects(player1.getGlobalBounds())) {
                player2.move(-1 / 64.f, 0.f);
            }
            if (player2.getGlobalBounds().intersects(movingasteroid1.getGlobalBounds())) {
                player2.move(-1 / 64.f, 0.f);
            }
            if (player2.getGlobalBounds().intersects(movingasteroid2.getGlobalBounds())) {
                player2.move(-1 / 64.f, 0.f);
            }
            if (player2.getGlobalBounds().intersects(movingasteroid3.getGlobalBounds())) {
                player2.move(-1 / 64.f, 0.f);
            }
            if (player2.getGlobalBounds().intersects(movingasteroid4.getGlobalBounds())) {
                player2.move(-1 / 64.f, 0.f);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
            player2.move(-1 / 64.f, 0.f);
            if (player2.getGlobalBounds().intersects(player1.getGlobalBounds())) {
                player2.move(1 / 64.f, 0.f);
            }
            if (player2.getGlobalBounds().intersects(movingasteroid1.getGlobalBounds())) {
                player2.move(1 / 64.f, 0.f);
            }
            if (player2.getGlobalBounds().intersects(movingasteroid2.getGlobalBounds())) {
                player2.move(1 / 64.f, 0.f);
            }
            if (player2.getGlobalBounds().intersects(movingasteroid3.getGlobalBounds())) {
                player2.move(1 / 64.f, 0.f);
            }
            if (player2.getGlobalBounds().intersects(movingasteroid4.getGlobalBounds())) {
                player2.move(1 / 64.f, 0.f);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }


        movingasteroid1.setRotation(90.f);
        movingasteroid1.setOrigin(-300.f, 50.f);
        movingasteroid1.move(-1 / 128.f, 0.f);

        movingasteroid2.setRotation(90.f);
        movingasteroid2.setOrigin(-300.f, 50.f);
        movingasteroid2.move(-1 / 128.f, 0.f);

        movingasteroid3.setRotation(90.f);
        movingasteroid3.setOrigin(-300.f, 50.f);
        movingasteroid3.move(-1 / 128.f, 0.f);

        movingasteroid4.setRotation(90.f);
        movingasteroid4.setOrigin(-300.f, 50.f);
        movingasteroid4.move(-1 / 128.f, 0.f);

        player1.setRotation(90.f);

        player2.setRotation(90.f);
    }

    return 0;
}
