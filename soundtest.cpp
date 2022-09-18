#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

int soundtest()
{

	// Window
	sf::RenderWindow soundWindow(sf::VideoMode(1024, 768), "sound Menu");

	sf::Event event;

	sf::RectangleShape sound1Rectangle(sf::Vector2f(150.f, 50.f));
	sound1Rectangle.setFillColor(sf::Color::Red);
	sound1Rectangle.setPosition(100.f,200.f);

	sf::RectangleShape sound2Rectangle(sf::Vector2f(150.f, 50.f));
	sound2Rectangle.setFillColor(sf::Color::Red);
	sound2Rectangle.setPosition(100.f,350.f);

	sf::RectangleShape sound3Rectangle(sf::Vector2f(150.f, 50.f));
	sound3Rectangle.setFillColor(sf::Color::Red);
	sound3Rectangle.setPosition(100.f,500.f);

	// gets font from file
	sf::Font font;
	if(!font.loadFromFile("Fonts/Mermaid1001.ttf"))
		throw("COULD NOT LOAD FONT!");

	// makes text
	sf::Text one;
	sf::Text two;
	sf::Text three;
	sf::Text name;

	// sets font for text
	one.setFont(font);
	two.setFont(font);
	three.setFont(font);
	name.setFont(font);

	// sets string value
	one.setString("one");
	two.setString("two");
	three.setString("three");
	name.setString("AT-Roids");

	// size of the text
	one.setCharacterSize(32);
	two.setCharacterSize(32);
	three.setCharacterSize(32);
	name.setCharacterSize(48);

	// text color
	one.setFillColor(sf::Color::Black);
	two.setFillColor(sf::Color::Black);
	three.setFillColor(sf::Color::Black);
	name.setFillColor(sf::Color::Cyan);

	// position of the text
	one.setPosition(sound1Rectangle.getPosition().x + 40,sound1Rectangle.getPosition().y + 2);
	two.setPosition(sound2Rectangle.getPosition().x + 40, sound2Rectangle.getPosition().y + 2);
	three.setPosition(sound3Rectangle.getPosition().x + 40, sound3Rectangle.getPosition().y + 2);
	name.setPosition((soundWindow.getSize().x / 2)-114, 0);

	// Game loop
	while (soundWindow.isOpen())
	{

		sf::SoundBuffer buffer1;
		sf::SoundBuffer buffer2;
		sf::SoundBuffer buffer3;



		sf::Sound sound;


		// Event polling
		while (soundWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				soundWindow.close();
				break;
 /*           case sf::Event::KeyPressed:
				if (event.key.code = sf::Keyboard::Escape)
					soundWindow.close();
				break;*/
			case sf::Event::MouseMoved:


				// sound1Rectangle change color
				if ((event.mouseMove.y >= 200.f) && (event.mouseMove.y <= 250.f) &&
					(event.mouseMove.x >= 100.f) && (event.mouseMove.x <= 250.f))
				{
					sound1Rectangle.setFillColor(sf::Color::Blue);
				} else
					sound1Rectangle.setFillColor(sf::Color::Red);

				if ((event.mouseMove.y >= 350.f) && (event.mouseMove.y <= 400.f) &&
					(event.mouseMove.x >= 100.f) && (event.mouseMove.x <= 250.f))
				{
					sound2Rectangle.setFillColor(sf::Color::Blue);
				} else
					sound2Rectangle.setFillColor(sf::Color::Red);

				if ((event.mouseMove.y >= 500.f) && (event.mouseMove.y <= 550.f) &&
					(event.mouseMove.x >= 100.f) && (event.mouseMove.x <= 250.f))
				{
					sound3Rectangle.setFillColor(sf::Color::Blue);
				} else
					sound3Rectangle.setFillColor(sf::Color::Red);


				break;
			case sf::Event::MouseButtonPressed:
				// if mouse button was clicked on the quit rect, window closes

				if (!buffer1.loadFromFile("./sounds/hit-01.wav"))
				   return -1;
				if (!buffer2.loadFromFile("./sounds/shoot-01.wav"))
					return -1;
				if (!buffer3.loadFromFile("./sounds/explosion-01.wav"))
					return -1;


				// if mouse button was clicked on start rect, game begins
				if ((event.mouseButton.y >= 200.f) && (event.mouseButton.y <= 250.f) &&
					(event.mouseButton.x >= 100.f) && (event.mouseButton.x <= 250.f))
				{
					sound.setBuffer(buffer1);
					sound.play();
				}

				if ((event.mouseButton.y >= 350.f) && (event.mouseButton.y <= 400.f) &&
					(event.mouseButton.x >=  100.f) && (event.mouseButton.x <= 250.f))
				{
					sound.setBuffer(buffer2);
					sound.play();
				}

				 if ((event.mouseButton.y >= 500.f) && (event.mouseButton.y <= 550.f) &&
					(event.mouseButton.x >= 100.f) && (event.mouseButton.x <= 250.f))
				{
					sound.setBuffer(buffer3);
					sound.play();
				}

				break;
			}
		}

		// Render
		soundWindow.clear(sf::Color(160,160,160)); // clear old frame

		// draw here
		soundWindow.draw(sound1Rectangle);
		soundWindow.draw(sound2Rectangle);
		soundWindow.draw(sound3Rectangle);

		soundWindow.draw(one);
		soundWindow.draw(two);
		soundWindow.draw(three);
		soundWindow.draw(name);

		soundWindow.display();   // window is done drawing
	}
	return 0;
}