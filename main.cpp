#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "asteroids.cpp"
#include "soundtest.cpp"

using namespace std;


int main()
{
    // Window
    sf::RenderWindow mainMenuWindow(sf::VideoMode(1024, 768), "Main Menu");

    sf::Event event;

    sf::RectangleShape startRectangle(sf::Vector2f(150.f, 50.f));
    startRectangle.setFillColor(sf::Color::Red);
    startRectangle.setPosition(100.f,200.f);

    sf::RectangleShape soundRectangle(sf::Vector2f(150.f, 50.f));
    soundRectangle.setFillColor(sf::Color::Red);
    soundRectangle.setPosition(100.f,350.f);

    sf::RectangleShape quitRectangle(sf::Vector2f(150.f, 50.f));
    quitRectangle.setFillColor(sf::Color::Red);
    quitRectangle.setPosition(100.f,500.f);

    // gets font from file
    sf::Font font;
    if(!font.loadFromFile("Fonts/Mermaid1001.ttf"))
        throw("COULD NOT LOAD FONT!");

    // makes text
    sf::Text start;
    sf::Text sound;
    sf::Text quit;
    sf::Text name;

    // sets font for text
    start.setFont(font);
    sound.setFont(font);
    quit.setFont(font);
    name.setFont(font);

    // sets string value
    start.setString("Start");
    sound.setString("Sound");
    quit.setString("Quit");
    name.setString("AT-Roids");

    // size of the text
    start.setCharacterSize(32);
    sound.setCharacterSize(32);
    quit.setCharacterSize(32);
    name.setCharacterSize(48);

    // text color
    start.setFillColor(sf::Color::Black);
    sound.setFillColor(sf::Color::Black);
    quit.setFillColor(sf::Color::Black);
    name.setFillColor(sf::Color::Cyan);

    // position of the text
    start.setPosition(startRectangle.getPosition().x + 40,startRectangle.getPosition().y + 2);
    sound.setPosition(soundRectangle.getPosition().x + 40, soundRectangle.getPosition().y + 2);
    quit.setPosition(quitRectangle.getPosition().x + 40, quitRectangle.getPosition().y + 2);
    name.setPosition((mainMenuWindow.getSize().x / 2)-114, 0);

    // Game loop
    while (mainMenuWindow.isOpen())
    {
        // Event polling
        while (mainMenuWindow.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                mainMenuWindow.close();
                break;
 /*           case sf::Event::KeyPressed:
                if (event.key.code = sf::Keyboard::Escape)
                    mainMenuWindow.close();
                break;*/
            case sf::Event::MouseMoved:
                // quitRectangle change color
                if ((event.mouseMove.y >= 500.f) && (event.mouseMove.y <= 550.f) &&
                    (event.mouseMove.x >= 100.f) && (event.mouseMove.x <= 250.f))
/*                if ((event.mouseMove.y >= quitRectangle.getPosition().y) && (event.mouseMove.y <= quitRectangle.getPosition().y + 50) &&
                    (event.mouseMove.x >= quitRectangle.getPosition().x) && (event.mouseMove.x <= quitRectangle.getPosition().x + 150))*/
                {
                    quitRectangle.setFillColor(sf::Color::Blue);
                } else
                    quitRectangle.setFillColor(sf::Color::Red);

                // startRectangle change color
                if ((event.mouseMove.y >= 200.f) && (event.mouseMove.y <= 250.f) &&
                    (event.mouseMove.x >= 100.f) && (event.mouseMove.x <= 250.f))
                {
                    startRectangle.setFillColor(sf::Color::Blue);
                } else
                    startRectangle.setFillColor(sf::Color::Red);

                if ((event.mouseMove.y >= 350.f) && (event.mouseMove.y <= 400.f) &&
                    (event.mouseMove.x >= 100.f) && (event.mouseMove.x <= 250.f))
                {
                    soundRectangle.setFillColor(sf::Color::Blue);
                } else
                    soundRectangle.setFillColor(sf::Color::Red);

                break;
            case sf::Event::MouseButtonPressed:
                // if mouse button was clicked on the quit rect, window closes
                if ((event.mouseButton.y >= 500.f) && (event.mouseButton.y <= 550.f) &&
                    (event.mouseButton.x >= 100.f) && (event.mouseButton.x <= 250.f))
                {
                    cout << "quit button pressed" << endl;
                    mainMenuWindow.close();
                }

                // if mouse button was clicked on start rect, game begins
                if ((event.mouseButton.y >= 200.f) && (event.mouseButton.y <= 250.f) &&
                    (event.mouseButton.x >= 100.f) && (event.mouseButton.x <= 250.f))
                {
                    // add code here to start the game
                    asteroids();
                    cout << "game start" << endl;
                }

                if ((event.mouseButton.y >= 350.f) && (event.mouseButton.y <= 400.f) &&
                    (event.mouseButton.x >=  100.f) && (event.mouseButton.x <= 250.f))
                {
                    soundtest();
                    cout << "sound test started" << endl;
                }


                break;
            }
        }

        // Render
        mainMenuWindow.clear(sf::Color(160,160,160)); // clear old frame

        // draw here
        mainMenuWindow.draw(startRectangle);
        mainMenuWindow.draw(soundRectangle);
        mainMenuWindow.draw(quitRectangle);

        mainMenuWindow.draw(start);
        mainMenuWindow.draw(sound);
        mainMenuWindow.draw(quit);
        mainMenuWindow.draw(name);

        mainMenuWindow.display();   // window is done drawing
    }

    return 0;
}