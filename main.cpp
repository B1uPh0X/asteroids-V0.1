#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <TGUI/TGUI.hpp>
#include "Asteroid.cpp"
#include "interpreter.cpp"
#include "Asteroid.h"
#include "Player.cpp"
#include "Player.h"
#include "init.cpp"
#include "Weapon.h"
#include "Weapon.cpp"

using namespace std;

void execute(string y)
{
    interpreter(y.c_str());
}

void initPlayers()
{
    cout << "init pressed" << endl;
    init();
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Main Menu");
    tgui::GuiSFML gui{window};
    tgui::Theme::setDefault("./themes/Black.txt");

    Player p;

    // position at the origin
    sf::Vector2f startPosition(512, 384);

    p.triangle.setPosition(startPosition.x + 200, startPosition.y - 50);
    p.triangle.setRotation(90.f);

    // start button
    tgui::Button::Ptr startButton = tgui::Button::create();
    startButton->setSize(200, 50);                                      // set size
    startButton->setPosition(100, 350);                                 // set position
    startButton->setText("Start");                                      // set text
    startButton->setTextSize(24);                                       // set text size
    startButton->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
    startButton->onPress(&initPlayers);                                 // starts game on press
    gui.add(startButton);                                               // adds the start button

    // quit button
    tgui::Button::Ptr quitButton = tgui::Button::create();
    quitButton->setSize(200, 50);                                      // set size
    quitButton->setPosition(100, 550);                                 // set position
    quitButton->setText("Quit");                                       // set text
    quitButton->setTextSize(24);                                       // set text size
    quitButton->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
    quitButton->onPress([&]
                        { window.close(); }); // closes the main menu window on press
    gui.add(quitButton);                      // adds the quit button

    // name label
    auto label = tgui::Label::create();
    label->setText("AT-Asteroids");
    label->getRenderer()->setTextColor(sf::Color::Black);
    label->setTextSize(32);
    label->setPosition("50%", "5%");
    label->setOrigin(0.5f, 0.5f);
    gui.add(label);

    // Adds text box
    auto editBox = tgui::EditBox::create();
    gui.add(editBox, "WidgetName");
    editBox->setVisible(false);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            gui.handleEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(160, 160, 160));
        p.create();
        p.color1();
        p.drawPlayer(window);
        gui.draw();
        window.display();
    }

    // gui.mainLoop();
    return 0;
}