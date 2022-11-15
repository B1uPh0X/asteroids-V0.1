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

void removePlayer(int &players)
{
  cout << "Removed Player" << endl;
  cout << players << endl;
}

bool in_array(const string &value, const vector<string> &array)
{
  return find(array.begin(), array.end(), value) != array.end();
}

int init()
{
  sf::RenderWindow window(sf::VideoMode(1024, 768), "Initialize Players");
  tgui::GuiSFML gui{window};
  tgui::Theme::setDefault("./themes/Black.txt");

  vector<string> selectedPlayers{};

  // name label
  auto label = tgui::Label::create();
  label->setText("Initialize Players");
  label->getRenderer()->setTextColor(sf::Color::Black);
  label->setTextSize(32);
  label->setPosition("50%", "5%");
  label->setOrigin(0.5f, 0.5f);
  gui.add(label);

  auto chatbox = tgui::ChatBox::create();
  chatbox->setSize(300, 100);
  chatbox->setTextSize(24);
  chatbox->setPosition(100, 100);
  chatbox->setLinesStartFromTop();
  // chatbox->addLine("1", tgui::Color::Black);
  gui.add(chatbox);

  auto chatbox2 = tgui::ChatBox::create();
  chatbox2->setSize(300, 100);
  chatbox2->setTextSize(24);
  chatbox2->setPosition(100, 300);
  chatbox2->setLinesStartFromTop();
  // chatbox2->addLine("2", tgui::Color::Black);
  gui.add(chatbox2);

  auto chatbox3 = tgui::ChatBox::create();
  chatbox3->setSize(300, 100);
  chatbox3->setTextSize(24);
  chatbox3->setPosition(100, 500);
  chatbox3->setLinesStartFromTop();
  // chatbox3->addLine("3", tgui::Color::Black);
  gui.add(chatbox3);

  auto chatbox4 = tgui::ChatBox::create();
  chatbox4->setSize(300, 100);
  chatbox4->setTextSize(24);
  chatbox4->setPosition(550, 100);
  chatbox4->setLinesStartFromTop();
  // chatbox4->addLine("4", tgui::Color::Black);
  gui.add(chatbox4);

  auto chatbox5 = tgui::ChatBox::create();
  chatbox5->setSize(300, 100);
  chatbox5->setTextSize(24);
  chatbox5->setPosition(550, 300);
  chatbox5->setLinesStartFromTop();
  // chatbox5->addLine("5", tgui::Color::Black);
  gui.add(chatbox5);

  auto chatbox6 = tgui::ChatBox::create();
  chatbox6->setSize(300, 100);
  chatbox6->setTextSize(24);
  chatbox6->setPosition(550, 500);
  chatbox6->setLinesStartFromTop();
  // chatbox6->addLine("6", tgui::Color::Black);
  gui.add(chatbox6);

  // delete player 1 button
  auto delPlayerOne = tgui::Button::create();
  delPlayerOne->setSize(50, 50);                                       // set size
  delPlayerOne->setTextSize(24);                                       // set text size
  delPlayerOne->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
  delPlayerOne->setPosition(425, 125);                                 // set position
  delPlayerOne->setText("-");                                          // set text
  delPlayerOne->onPress([&]
                        {
    if (selectedPlayers.size() > 0) {
      selectedPlayers.erase(selectedPlayers.begin());
      chatbox->removeLine(0);
      if (selectedPlayers.size() >= 1) {
        chatbox->addLine(selectedPlayers[0], tgui::Color::White);
        chatbox2->removeLine(0);
        if (selectedPlayers.size() >= 2) {
          chatbox2->addLine(selectedPlayers[1], tgui::Color::White);
          chatbox3->removeLine(0);
          if (selectedPlayers.size() >= 3) {
            chatbox3->addLine(selectedPlayers[2], tgui::Color::White);
            chatbox4->removeLine(0);
            if (selectedPlayers.size() >= 4) {
              chatbox4->addLine(selectedPlayers[3], tgui::Color::White);
              chatbox5->removeLine(0);
              if (selectedPlayers.size() >= 5) {
                chatbox5->addLine(selectedPlayers[4], tgui::Color::White);
                chatbox6->removeLine(0);
                // chatbox6->addLine(selectedPlayers[5], tgui::Color::White);
              }
            }
          }
        }
      }
    } else {
      cout << "Array 1 empty" << endl;
    } });
  gui.add(delPlayerOne); // adds the del player 1 button

  // delete player 2 button
  auto delPlayerTwo = tgui::Button::create();
  delPlayerTwo->setSize(50, 50);                                       // set size
  delPlayerTwo->setTextSize(24);                                       // set text size
  delPlayerTwo->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
  delPlayerTwo->setPosition(425, 325);                                 // set position
  delPlayerTwo->setText("-");                                          // set text
  delPlayerTwo->onPress([&]
                        {
    if (selectedPlayers.size() >= 1) {
      selectedPlayers.erase(selectedPlayers.begin() + 1);
      chatbox2->removeLine(0);
      if (selectedPlayers.size() >= 2) {
        chatbox2->addLine(selectedPlayers[1], tgui::Color::White);
        chatbox3->removeLine(0);
        if (selectedPlayers.size() >= 3) {
          chatbox3->addLine(selectedPlayers[2], tgui::Color::White);
          chatbox4->removeLine(0);
          if (selectedPlayers.size() >= 4) {
            chatbox4->addLine(selectedPlayers[3], tgui::Color::White);
            chatbox5->removeLine(0);
            if (selectedPlayers.size() >= 5) {
              chatbox5->addLine(selectedPlayers[4], tgui::Color::White);
              chatbox6->removeLine(0);
              // chatbox6->addLine(selectedPlayers[5], tgui::Color::White);
            }
          }
        }
      }
    } 
      else {
      cout << "Array2  empty" << endl;
    } });
  gui.add(delPlayerTwo); // adds the del player 2 button

  // delete player 3 button
  auto delPlayerThree = tgui::Button::create();
  delPlayerThree->setSize(50, 50);                                       // set size
  delPlayerThree->setTextSize(24);                                       // set text size
  delPlayerThree->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
  delPlayerThree->setPosition(425, 525);                                 // set position
  delPlayerThree->setText("-");                                          // set text
  delPlayerThree->onPress([&]
                          {
    if (selectedPlayers.size() > 2) {
      selectedPlayers.erase(selectedPlayers.begin() + 2);
      chatbox3->removeLine(0);
      if (selectedPlayers.size() >= 3) {
        chatbox3->addLine(selectedPlayers[2], tgui::Color::White);
        chatbox4->removeLine(0);
        if (selectedPlayers.size() >= 4) {
          chatbox4->addLine(selectedPlayers[3], tgui::Color::White);
          chatbox5->removeLine(0);
          if (selectedPlayers.size() >= 5) {
            chatbox5->addLine(selectedPlayers[4], tgui::Color::White);
            chatbox6->removeLine(0);
            // chatbox6->addLine(selectedPlayers[5], tgui::Color::White);
          }
        }
      }  
    } else {
      cout << "Array 3 empty" << endl;
    } });
  gui.add(delPlayerThree); // adds the del player 3 button

  // delete player 4 button
  auto delPlayerFour = tgui::Button::create();
  delPlayerFour->setSize(50, 50);                                       // set size
  delPlayerFour->setTextSize(24);                                       // set text size
  delPlayerFour->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
  delPlayerFour->setPosition(875, 125);                                 // set position
  delPlayerFour->setText("-");                                          // set text
  delPlayerFour->onPress([&]
                         {
    if (selectedPlayers.size() > 3) {
      selectedPlayers.erase(selectedPlayers.begin() + 3);
      chatbox4->removeLine(0);
      if (selectedPlayers.size() >= 4) {
        chatbox4->addLine(selectedPlayers[3], tgui::Color::White);
        chatbox5->removeLine(0);
        if (selectedPlayers.size() >= 5) {
          chatbox5->addLine(selectedPlayers[4], tgui::Color::White);
          chatbox6->removeLine(0);
          // chatbox6->addLine(selectedPlayers[5], tgui::Color::White);
        }
      }  
    } else {
      cout << "Array 4 empty" << endl;
    } });
  gui.add(delPlayerFour); // adds the del player 4 button

  // delete player 5 button
  auto delPlayerFive = tgui::Button::create();
  delPlayerFive->setSize(50, 50);                                       // set size
  delPlayerFive->setTextSize(24);                                       // set text size
  delPlayerFive->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
  delPlayerFive->setPosition(875, 325);                                 // set position
  delPlayerFive->setText("-");                                          // set text
  delPlayerFive->onPress([&]
                         {
    if (selectedPlayers.size() > 4) {
      selectedPlayers.erase(selectedPlayers.begin() + 4);
      chatbox5->removeLine(0);
      if (selectedPlayers.size() >= 5) {
        chatbox5->addLine(selectedPlayers[4], tgui::Color::White);
        chatbox6->removeLine(0);
        // chatbox6->addLine(selectedPlayers[5], tgui::Color::White);
      }
    } else {
      cout << "Array 5 empty" << endl;
    } });
  gui.add(delPlayerFive); // adds the del player 5 button

  // delete player 6 button
  auto delPlayerSix = tgui::Button::create();
  delPlayerSix->setSize(50, 50);                                       // set size
  delPlayerSix->setTextSize(24);                                       // set text size
  delPlayerSix->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
  delPlayerSix->setPosition(875, 525);                                 // set position
  delPlayerSix->setText("-");                                          // set text
  delPlayerSix->onPress([&]
                        {
    if (selectedPlayers.size() > 5) {
      selectedPlayers.erase(selectedPlayers.begin() + 5);
      chatbox6->removeLine(0);
      // chatbox6->addLine(selectedPlayers[5], tgui::Color::White);
    } else {
      cout << "Array 6 empty" << endl;
    } });
  gui.add(delPlayerSix); // adds the del player 6 button

  // start button
  auto startGameButton = tgui::Button::create();
  startGameButton->setSize(200, 50);                                      // set size
  startGameButton->setPosition(275, 650);                                 // set position
  startGameButton->setText("Start");                                      // set text
  startGameButton->setTextSize(24);                                       // set text size
  startGameButton->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
  startGameButton->onPress(&startGame);                                   // starts game on press
  gui.add(startGameButton);                                               // adds the start button

  // back button
  auto backButton = tgui::Button::create();
  backButton->setSize(200, 50);                                      // set size
  backButton->setPosition(500, 650);                                 // set position
  backButton->setText("Back");                                       // set text
  backButton->setTextSize(24);                                       // set text size
  backButton->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
  backButton->onPress([&]
                      { window.close(); }); // back to main menu on press
  gui.add(backButton);                      // adds the back button

  auto listBox = tgui::ListBox::create();
  listBox->setSize(250, 120);
  listBox->setItemHeight(24);
  listBox->setPosition("50%", "50%");
  listBox->setOrigin(0.5f, 0.5f);
  listBox->addItem("Chris V");
  listBox->addItem("Christopher M");
  listBox->addItem("Ryan S");
  listBox->addItem("Nishan T");
  listBox->addItem("Amos");
  listBox->addItem("Cyan");
  listBox->setVisible(false);
  gui.add(listBox);

  // add player 1 button
  auto playerOne = tgui::Button::create();
  playerOne->setSize(50, 50);                                       // set size
  playerOne->setTextSize(24);                                       // set text size
  playerOne->getRenderer()->setTextColorDownHover(sf::Color::Blue); // sets click down hover text color
  playerOne->setPosition(125, 650);                                 // set position
  playerOne->setText("+");                                          // set text
  playerOne->onPress([&]
                     { listBox->setVisible(true); }); // closes the main menu window on press
  gui.add(playerOne);                                 // adds the player button

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

      case sf::Event::MouseButtonPressed:
        cout << "\n"
             << endl;
        if (listBox->isVisible() == true)
        {
          if (!in_array(listBox->getSelectedItem().toStdString(), selectedPlayers))
          {
            selectedPlayers.push_back(listBox->getSelectedItem().toStdString());
          }

          for (int i = 0; i < selectedPlayers.size(); i++)
          {
            cout << selectedPlayers[i] << endl;
          }

          chatbox->removeLine(0);
          chatbox->addLine(selectedPlayers[0], tgui::Color::White);

          if (selectedPlayers.size() > 1)
          {
            chatbox2->removeLine(0);
            chatbox2->addLine(selectedPlayers[1], tgui::Color::White);
          }

          if (selectedPlayers.size() > 2)
          {
            chatbox3->removeLine(0);
            chatbox3->addLine(selectedPlayers[2], tgui::Color::White);
          }

          if (selectedPlayers.size() > 3)
          {
            chatbox4->removeLine(0);
            chatbox4->addLine(selectedPlayers[3], tgui::Color::White);
          }

          if (selectedPlayers.size() > 4)
          {
            chatbox5->removeLine(0);
            chatbox5->addLine(selectedPlayers[4], tgui::Color::White);
          }

          if (selectedPlayers.size() > 5)
          {
            chatbox6->removeLine(0);
            chatbox6->addLine(selectedPlayers[5], tgui::Color::White);
          }
          listBox->setVisible(false);
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