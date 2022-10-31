#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Asteroid.h"
#include "Weapon.h"
#include <cmath>
#include <vector>


int game() {

    Player player1;
    Asteroid asteroid;
    Weapon gun;
    Weapon bomb;
    int limit = 0;
    int shoottimer = 0;

    sf::RenderWindow window(sf::VideoMode(1024, 768), "AT-Roids");
    sf::Texture t;
    t.loadFromFile("./images/space_background.jpg");
    sf::Sprite s(t);

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("./sounds/explosion-04.wav"))
        return -1;

    sf::Sound sound;

    std::vector<sf::ConvexShape> asteroids;

    // bullets
    gun.bulletcreate();
    std::vector<sf::RectangleShape> bullets;
    bullets.push_back(gun.bullet);
    if(shoottimer < 3){
        shoottimer++;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shoottimer >= 3){
       gun.bullet.setPosition(player1.triangle.getPosition().x, player1.triangle.getPosition().y);
       bullets.push_back(gun.bullet);

       shoottimer = 0;
    }
    for(size_t i = 0; i < bullets.size(); i++){
        bullets[i].move(player1.xmove() , player1.ymove());
    }

    sf::Vector2f startPosition(512 - 100, 384 - 50);
    player1.triangle.setPosition(startPosition);

    for (int i = 0; i <= 8; i++) {
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
            if (event.type == sf::Event::LostFocus){
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))

                player1.controls('u');

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))

                player1.controls('d');

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                player1.triangle.move(player1.xmove(), player1.ymove());
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            }
            player1.boundaries(window);
            window.clear();
            window.draw(s);
            player1.create();
            player1.drawPlayer(window);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                bomb.bombcreate();
                bomb.bomb.setPosition(player1.triangle.getPosition());
                window.draw(bomb.bomb);
            }
            for (unsigned int i = 0; i < asteroids.size(); i++) {
                sf::FloatRect asteroidblock = asteroids[i].getGlobalBounds();
                sf::FloatRect playerblock = player1.triangle.getGlobalBounds();
                if (asteroidblock.intersects(playerblock)) {
                    player1.triangle.move(-player1.xmove(), -player1.ymove());
                    sound.setBuffer(buffer);
                    sound.play();
                    player1.triangle.setPosition(rand() % 924, rand() % 668);
                    limit++;
                }
                if (limit == 3) {
                    window.close();
                }
                window.draw(asteroids.at(i));
            }
            window.display();
        }
    }
    exit(0);
}


// #include <SFML/Graphics.hpp>
// #include <SFML/Window.hpp>
// #include <SFML/Audio.hpp>
// #include "Player.h"
// #include "Asteroid.h"
// #include <cmath>
// #include <vector>

// int game()
// {

//     Player player1;
//     Asteroid asteroid;
//     int limit = 0;

//     sf::RenderWindow window(sf::VideoMode(1024, 768), "AT-Roids");
//     sf::Texture t;
//     t.loadFromFile("./images/space_background.jpg");
//     sf::Sprite s(t);

//     sf::SoundBuffer buffer;
//     if (!buffer.loadFromFile("./sounds/explosion-04.wav"))
//         return -1;

//     sf::Sound sound;

//     std::vector<sf::ConvexShape> asteroids;

//     sf::Vector2f startPosition(512 - 100, 384 - 50);
//     player1.triangle.setPosition(startPosition);

//     for (int i = 0; i <= 8; i++)
//     {
//         asteroid.create();
//         // asteroid.shape.setPosition(rand() % 924, rand() % 668);

//         asteroids.push_back(asteroid.shape);
//     }

//     while (window.isOpen())
//     {
//         window.setFramerateLimit(60);
//         sf::Event event;
//         while (window.pollEvent(event))
//         {

//             if (event.type == sf::Event::Closed)
//             {
//                 window.close();
//             }
//             if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))

//                 player1.controls('u');

//             else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))

//                 player1.controls('d');

//             else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//             {
//                 player1.triangle.move(player1.xmove(), player1.ymove());
//             }

//             player1.boundaries(window);
//             window.clear();
//             window.draw(s);
//             player1.create();
//             player1.drawPlayer(window);
//             for (unsigned int i = 0; i < asteroids.size(); i++)
//             {
//                 sf::FloatRect asteroidblock = asteroids[i].getGlobalBounds();
//                 sf::FloatRect playerblock = player1.triangle.getGlobalBounds();
//                 if (asteroidblock.intersects(playerblock))
//                 {
//                     player1.triangle.move(-player1.xmove(), -player1.ymove());
//                     sound.setBuffer(buffer);
//                     sound.play();
//                     player1.triangle.setPosition(rand() % 924, rand() % 668);
//                     limit++;
//                 }
//                 if (limit == 3)
//                 {
//                     window.close();
//                 }
//                 window.draw(asteroids.at(i));
//             }
//             window.display();
//         }
//     }
//     exit(0);
// }