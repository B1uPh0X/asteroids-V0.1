<<<<<<< HEAD
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <thread>
#include <string>
#include "interpreter.cpp"

using namespace std;

//temporary function that will be expanded upon later, currently just starts the interperter
void execute(string y){
    interpreter(y.c_str());
}

//main function for the program
int main(void)

{   
    //starts thread one
    thread one(execute, "..\\Asteroids\\Bots\\test1.lua");
    //starts thread two
    thread two(execute, "..\\Asteroids\\Bots\\test2.lua");

    //waits for thread one to finish
    one.join();
    //waits for thread two to finish
    two.join();

    //end of main
    return 0;
}
=======
#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.cpp"
#include "Asteroid.cpp"
#include "Asteroid.h"
#include "Player.cpp"
#include "Player.h"
// #include <nana/gui.hpp>
// #include <nana/gui/widgets/label.hpp>
// #include <nana/gui/widgets/button.hpp>

#include <TGUI/TGUI.hpp>

void startGame()
{
    std::cout << "Start Game pressed" << std::endl;
    game();
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Main Menu");
    tgui::GuiSFML gui{window};
    tgui::Theme::setDefault("./themes/Black.txt");

    // Adds button
    tgui::Button::Ptr quitButton = tgui::Button::create();
    gui.add(quitButton);
    tgui::Button::Ptr startButton = tgui::Button::create();
    gui.add(startButton);

    // Sets size
    quitButton->setSize(200, 50);
    sf::Vector2f size = quitButton->getSize();
    startButton->setSize(200, 50);
    // sf::Vector2f size = startButton->getSize();

    // Sets position
    quitButton->setPosition(100, 550);
    sf::Vector2f position = quitButton->getPosition();
    startButton->setPosition(100, 350);
    // sf::Vector2f position = startButton->getPosition();

    // Sets text inside button
    quitButton->setText("Quit Game");
    quitButton->setTextSize(24);
    startButton->setText("Start Game");
    startButton->setTextSize(24);

    // Sets text color to blue whenever you click the button
    startButton->getRenderer()->setTextColorDownHover(sf::Color::Blue);
    quitButton->getRenderer()->setTextColorDownHover(sf::Color::Blue);

    // Start Button starts the game
    startButton->onPress(&startGame);

    // Quit Button closes Window
    quitButton->onPress([&]
                        { window.close(); });

    auto label = tgui::Label::create();
    label->setText("AT-Asteroids");
    label->getRenderer()->setTextColor(sf::Color::Black);
    label->setTextSize(32);
    label->setPosition("50%", "5%");
    label->setOrigin(0.5f, 0.5f);

    gui.add(label);

    std::cout << gui.getView().getSize().x << std::endl;
    std::cout << label->getAutoSize() << std::endl;

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
}

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(1024, 768), "Asteroidssssss");
//     sf::Texture t;
//     t.loadFromFile("images/space_background.jpg");
//     sf::Sprite s(t);
//     while (window.isOpen())
//     {
//         sf::Event windowEvent;
//         while (window.pollEvent(windowEvent))
//         {
//             if (windowEvent.type == sf::Event::Closed)
//                 window.close();
//         }
//         window.clear();
//         window.draw(s);
//         window.display();

//     }

// using namespace nana;

// //Define a form.
// form fm;

// //Define a label and display a text.
// label lab{fm, "Hello, <bold blue size=16>Nana C++ Library</>"};
// lab.format(true);

// //Define a button and answer the click event.
// button btn{fm, "Quit"};
// btn.events().click([&fm]{
//     fm.close();
// });

// //Layout management
// fm.div("vert <><<><weight=80% text><>><><weight=24<><button><>><>");
// fm["text"]<<lab;
// fm["button"] << btn;
// fm.collocate();

// //Show the form
// fm.show();

// //Start to event loop process, it blocks until the form is closed.
// exec();

//     return 0;
// }
>>>>>>> CV
