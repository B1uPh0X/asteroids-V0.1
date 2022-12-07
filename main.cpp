#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <TGUI/TGUI.hpp>
#include "Asteroid.cpp"
#include "PlayerController.cpp"
#include "Asteroid.h"
#include "init.cpp"
#include "Weapon.h"
#include "Weapon.cpp"

using namespace std;


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

	// start button
	tgui::Button::Ptr startButton = tgui::Button::create();
	startButton->setSize(200, 50);                                      // set size
	startButton->setPosition(100, 350);                                 // set position
	startButton->setText("Start");                                 // set text
	startButton->setTextSize(24);                                       // set text size
	startButton->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
	startButton->onPress(&initPlayers);                                   // starts game on press
	gui.add(startButton);                                               // adds the start button

    // // settings button
    // tgui::Button::Ptr settingsButton = tgui::Button::create();
    // settingsButton->setSize(200, 50);                                      // set size
    // settingsButton->setPosition(100, 450);                                 // set position
    // settingsButton->setText("Settings");                                 // set text
    // settingsButton->setTextSize(24);                                       // set text size
    // settingsButton->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
    // //settingsButton->onPress(&initPlayers);                                   // settings menu on press
    // gui.add(settingsButton);                                               // adds the settings button

    // quit button
    tgui::Button::Ptr quitButton = tgui::Button::create();
    quitButton->setSize(200, 50);                                      // set size
    quitButton->setPosition(100, 550);                                 // set position
    quitButton->setText("Quit");                                  // set text
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
        gui.draw();
        window.display();
    }

	// gui.mainLoop();
	
	return 0;
}