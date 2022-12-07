#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Player.cpp"
#include "Asteroid.h"
#include "Weapon.h"
#include <cmath>
#include <vector>
#include "init.h"

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

int update(vector<vector<double> > upv){
    /*
    for(int i=0; i<upv.size(); i++){
      
      switch(i){
        case 0:
            player1.setVeloc(upv[0][3]);
            player1.setRotat(upv[0][4]);
            player1.move();
        break;
        case 1:
            player2.setVeloc(upv[0][3]);
            player2.setRotat(upv[0][4]);
            player2.move();
        break;
        case 2:
            player3.setVeloc(upv[0][3]);
            player3.setRotat(upv[0][4]);
            player3.move();
        break;
        case 3:
            player4.setVeloc(upv[0][3]);
            player4.setRotat(upv[0][4]);
            player4.move();
        break;
        case 4:
            player5.setVeloc(upv[0][3]);
            player5.setRotat(upv[0][4]);
            player5.move();
        break;
        case 5:
            player6.setVeloc(upv[0][3]);
            player6.setRotat(upv[0][4]);
            player6.move();
        break;
        default:
            cout<<"e"<<endl;
        break;
      }
    */
    //}

    return 0;
}

//called when all players are dead by playercontroller
int gameover(){
    return 0;
}


int game()
{
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

    // deltattime
    sf::Clock deltaclock;

    while (window.isOpen())
    {
        window.setFramerateLimit(60);
        sf::Time deltattime = deltaclock.restart();
        sf::Event event;
        //while (window.pollEvent(event))
        //{
        
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            // movement for player
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            // {
            //     player1.controls('u');
            // }
            // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            // {
            //     player1.controls('d');
            // }
            // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            // {
            //     player1.triangle.move(player1.xmove(), player1.ymove());
            // }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
            }
            window.clear();
            window.draw(s);

            if(selectedPlayers.size() == 1){
                player1.create();
                player1.color1();
                player1.drawPlayer(window);
                player1.boundaries(window);
                player1.controls();
            }
            if(selectedPlayers.size() == 2){
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
            if(selectedPlayers.size() == 3){
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
            if(selectedPlayers.size() == 4){
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
            if(selectedPlayers.size() == 5){
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
            if(selectedPlayers.size() == 6){
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

            // // player 1 basic functions
            // player1.create();
            // player1.color1();
            // player1.drawPlayer(window);
            // player1.boundaries(window);

            // // player 2 basic functions;
            // player2.create();
            // player2.color2();
            // player2.drawPlayer(window);
            // player2.boundaries(window);

            // // player 3 basic functions
            // player3.create();
            // player3.color3();
            // player3.drawPlayer(window);
            // player3.boundaries(window);

            // // player 4 basic functions
            // player4.create();
            // player4.color4();
            // player4.drawPlayer(window);
            // player4.boundaries(window);

            // // player 5 basic functions
            // player5.create();
            // player5.color5();
            // player5.drawPlayer(window);
            // player5.boundaries(window);

            // // player 6 basic functions
            // player6.create();
            // player6.color6();
            // player6.drawPlayer(window);
            // player6.boundaries(window);
        
            // bullets
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                isfiring = true;
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
        //}
    }
    return 0;
}