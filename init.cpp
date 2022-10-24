#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <thread>
#include <string>
#include <TGUI/TGUI.hpp>
#include "game.cpp"
// #include "Asteroid.cpp"
// #include "interpreter.cpp"
// #include "Asteroid.h"
// #include "Player.cpp"
// #include "Player.h"

using namespace std;

void startGame()
{
  cout << "Start Game pressed" << endl;
  game();
}

int init()
{
  sf::RenderWindow window(sf::VideoMode(1024, 768), "Initialize Players");
  tgui::GuiSFML gui{window};
  tgui::Theme::setDefault("./themes/Black.txt");

  auto chatbox = tgui::ChatBox::create();
  chatbox->setSize(300, 100);
  chatbox->setTextSize(24);
  chatbox->setPosition(100, 100);
  chatbox->setLinesStartFromTop();
  chatbox->addLine("Player 1", tgui::Color::Black);
  gui.add(chatbox);

  auto chatbox2 = tgui::ChatBox::create();
  chatbox2->setSize(300, 100);
  chatbox2->setTextSize(24);
  chatbox2->setPosition(100, 300);
  chatbox2->setLinesStartFromTop();
  chatbox2->addLine("Player 1", tgui::Color::Black);
  gui.add(chatbox2);

  auto chatbox3 = tgui::ChatBox::create();
  chatbox3->setSize(300, 100);
  chatbox3->setTextSize(24);
  chatbox3->setPosition(100, 500);
  chatbox3->setLinesStartFromTop();
  chatbox3->addLine("Player 1", tgui::Color::Black);
  gui.add(chatbox3);

  auto chatbox4 = tgui::ChatBox::create();
  chatbox4->setSize(300, 100);
  chatbox4->setTextSize(24);
  chatbox4->setPosition(550, 100);
  chatbox4->setLinesStartFromTop();
  chatbox4->addLine("Player 1", tgui::Color::Black);
  gui.add(chatbox4);

  auto chatbox5 = tgui::ChatBox::create();
  chatbox5->setSize(300, 100);
  chatbox5->setTextSize(24);
  chatbox5->setPosition(550, 300);
  chatbox5->setLinesStartFromTop();
  chatbox5->addLine("Player 1", tgui::Color::Black);
  gui.add(chatbox5);

  auto chatbox6 = tgui::ChatBox::create();
  chatbox6->setSize(300, 100);
  chatbox6->setTextSize(24);
  chatbox6->setPosition(550, 500);
  chatbox6->setLinesStartFromTop();
  chatbox6->addLine("Player 1", tgui::Color::Black);
  gui.add(chatbox6);

  // name label
  auto label = tgui::Label::create();
  label->setText("Initialize Players");
  label->getRenderer()->setTextColor(sf::Color::Black);
  label->setTextSize(32);
  label->setPosition("50%", "5%");
  label->setOrigin(0.5f, 0.5f);
  gui.add(label);

  // add player 1 button
  auto playerOne = tgui::Button::create();
  playerOne->setSize(50, 50);                                       // set size
  playerOne->setTextSize(24);                                       // set text size
  playerOne->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
  playerOne->setPosition(425, 125);                                 // set position
  playerOne->setText("+");                                          // set text
  playerOne->onPress([&]
                     { window.close(); }); // closes the main menu window on press
  gui.add(playerOne);                      // adds the player button

  // add player 2 button
  auto playerTwo = tgui::Button::create();
  playerTwo->setSize(50, 50);                                       // set size
  playerTwo->setTextSize(24);                                       // set text size
  playerTwo->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
  playerTwo->setPosition(425, 325);                                 // set position
  playerTwo->setText("+");                                          // set text
  gui.add(playerTwo);                                               // adds the player button

  // add player 3 button
  auto playerThree = tgui::Button::create();
  playerThree->setSize(50, 50);                                       // set size
  playerThree->setTextSize(24);                                       // set text size
  playerThree->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
  playerThree->setPosition(425, 525);                                 // set position
  playerThree->setText("+");                                          // set text
  gui.add(playerThree);                                               // adds the player button

  // add player 4 button
  auto playerFour = tgui::Button::create();
  playerFour->setSize(50, 50);                                       // set size
  playerFour->setTextSize(24);                                       // set text size
  playerFour->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
  playerFour->setPosition(875, 125);                                 // set position
  playerFour->setText("+");                                          // set text
  gui.add(playerFour);                                               // adds the player button

  // add player 5 button
  auto playerFive = tgui::Button::create();
  playerFive->setSize(50, 50);                                       // set size
  playerFive->setTextSize(24);                                       // set text size
  playerFive->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
  playerFive->setPosition(875, 325);                                 // set position
  playerFive->setText("+");                                          // set text
  gui.add(playerFive);                                               // adds the player button

  // add player 6 button
  auto playerSix = tgui::Button::create();
  playerSix->setSize(50, 50);                                       // set size
  playerSix->setTextSize(24);                                       // set text size
  playerSix->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
  playerSix->setPosition(875, 525);                                 // set position
  playerSix->setText("+");                                          // set text
  gui.add(playerSix);                                               // adds the player button

  // start button
  auto startGameButton = tgui::Button::create();
  startGameButton->setSize(200, 50);                                      // set size
  startGameButton->setPosition(300, 650);                                 // set position
  startGameButton->setText("Start");                                      // set text
  startGameButton->setTextSize(24);                                       // set text size
  startGameButton->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
  startGameButton->onPress(&startGame); // starts game on press
  gui.add(startGameButton);                      // adds the start button

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      gui.handleEvent(event);

      // check the type of the event...
      switch (event.type)
      {
      // window closed
      case sf::Event::Closed:
        window.close();
        break;

      // key pressed
      case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::Escape)
        {
          window.close();
        }
        break;
      }
    }

    window.clear(sf::Color(160, 160, 160));
    gui.draw();
    window.display();
  }

  return 0;
}