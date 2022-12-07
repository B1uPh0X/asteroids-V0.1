#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Asteroid.h"
#include "Weapon.h"
#include <cmath>
#include <vector>
#include "init.h"

int game()
{
    using namespace std;

    Player player1;
    Player player2;
    Player player3;
    Player player4;
    Player player5;
    Player player6;
    Asteroid asteroid;
    Weapon bomb;
    Weapon bullet;
    int limit = 0;
    bool isfiring = false;

    // window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "AT-Asteroids");
    sf::Texture t;
    t.loadFromFile("./images/space_background.jpg");
    sf::Sprite s(t);

    cout << "-------" << endl;
    cout << selectedPlayers.size() << endl;

    // vectors for the objects
    vector<Asteroid> asteroids;
    vector<Weapon> bullets;

    // position at the origin
    sf::Vector2f startPosition(512, 384);

    // setting positions for the players
    player1.triangle.setPosition(startPosition.x - 300, startPosition.y - 150);
    player1.triangle.setRotation(90.f);
    player2.triangle.setPosition(startPosition.x, startPosition.y - 150);
    player2.triangle.setRotation(90.f);
    player3.triangle.setPosition(startPosition.x + 300, startPosition.y - 150);
    player3.triangle.setRotation(90.f);
    player4.triangle.setPosition(startPosition.x - 300, startPosition.y + 150);
    player4.triangle.setRotation(-90.f);
    player5.triangle.setPosition(startPosition.x, startPosition.y + 150);
    player5.triangle.setRotation(-90.f);
    player6.triangle.setPosition(startPosition.x + 300, startPosition.y + 150);
    player6.triangle.setRotation(-90.f);

    // creating asteroids and setting positions for them
    for (int i = 0; i <= 6; ++i)
    {
        asteroid.create();
        asteroid.setPosition();
        asteroids.push_back(asteroid);
    }

    while (window.isOpen())
    {
        window.setFramerateLimit(60);
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {

                    isfiring = true;
                }
            }

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            window.clear();
            window.draw(s);

            if (selectedPlayers.size() == 1)
            {
                player1.create();
                player1.color1();
                player1.drawPlayer(window);
                player1.boundaries(window);
                player1.controls();
            }
            if (selectedPlayers.size() == 2)
            {
                player1.create();
                player1.color1();
                player1.drawPlayer(window);
                player1.boundaries(window);
                player1.controls();

                player2.create();
                player2.color2();
                player2.drawPlayer(window);
                player2.boundaries(window);
            }
            if (selectedPlayers.size() == 3)
            {
                player1.create();
                player1.color1();
                player1.drawPlayer(window);
                player1.boundaries(window);
                player1.controls();

                player2.create();
                player2.color2();
                player2.drawPlayer(window);
                player2.boundaries(window);

                player3.create();
                player3.color3();
                player3.drawPlayer(window);
                player3.boundaries(window);
            }
            if (selectedPlayers.size() == 4)
            {
                player1.create();
                player1.color1();
                player1.drawPlayer(window);
                player1.boundaries(window);
                player1.controls();

                player2.create();
                player2.color2();
                player2.drawPlayer(window);
                player2.boundaries(window);

                player3.create();
                player3.color3();
                player3.drawPlayer(window);
                player3.boundaries(window);

                player4.create();
                player4.color4();
                player4.drawPlayer(window);
                player4.boundaries(window);
            }
            if (selectedPlayers.size() == 5)
            {
                player1.create();
                player1.color1();
                player1.drawPlayer(window);
                player1.boundaries(window);
                player1.controls();

                player2.create();
                player2.color2();
                player2.drawPlayer(window);
                player2.boundaries(window);

                player3.create();
                player3.color3();
                player3.drawPlayer(window);
                player3.boundaries(window);

                player4.create();
                player4.color4();
                player4.drawPlayer(window);
                player4.boundaries(window);

                player5.create();
                player5.color5();
                player5.drawPlayer(window);
                player5.boundaries(window);
            }
            if (selectedPlayers.size() == 6)
            {
                player1.create();
                player1.color1();
                player1.drawPlayer(window);
                player1.boundaries(window);
                player1.controls();

                player2.create();
                player2.color2();
                player2.drawPlayer(window);
                player2.boundaries(window);

                player3.create();
                player3.color3();
                player3.drawPlayer(window);
                player3.boundaries(window);

                player4.create();
                player4.color4();
                player4.drawPlayer(window);
                player4.boundaries(window);

                player5.create();
                player5.color5();
                player5.drawPlayer(window);
                player5.boundaries(window);

                player6.create();
                player6.color6();
                player6.drawPlayer(window);
                player6.boundaries(window);
            }

            if (isfiring)
            {
                bullet.bulletcreate();
                bullet.bullet.setPosition(player1.triangle.getPosition().x, player1.triangle.getPosition().y);
                bullet.bullet.setRotation(player1.triangle.getRotation());
                bullets.push_back(bullet);
                isfiring = false;
            }

            for (auto &shot : bullets)
            {
                shot.bulletdraw(window);
                shot.bulletfire(player1.xmove(), player1.ymove());
            }

            // collision with asteroid and player
            for (unsigned int i = 0; i < asteroids.size(); i++)
            {
                sf::FloatRect asteroidblock = asteroids[i].shape.getGlobalBounds();
                sf::FloatRect playerblock = player1.triangle.getGlobalBounds();
                sf::FloatRect shotbounds = bullet.bullet.getGlobalBounds();
                if (asteroidblock.intersects(playerblock))
                {
                    player1.triangle.move(-player1.xmove(), -player1.ymove());
                    player1.triangle.setPosition(startPosition.x - 300, startPosition.y - 150);
                    player1.triangle.setRotation(90.f);
                    limit++;
                }
                if (limit == 3)
                {
                    window.close();
                }
                // collision with bullet and asteroids(in progress)
                for (auto it = asteroids.begin(); it != asteroids.end(); ++it)
                {
                    if (shotbounds.intersects(asteroidblock))
                    {
                        cout << "bullet hit" << endl;
                        it = asteroids.erase(it);
                    }
                }
                asteroids[i].draw(window);
            }
            window.display();
        }
    }
    return 0;
}