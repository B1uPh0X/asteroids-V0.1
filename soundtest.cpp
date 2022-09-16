#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>

void pause(int dur);

int main()
{

    sf::Window window(sf::VideoMode(800,600), "My window");

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sounds\\explosion-02.wav"))
        return -1;

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                    window.close();
            }
        }
    }
    return 0;
}

void pause(int dur){
    int temp = time(NULL) + dur;
    while (temp > time(NULL));    
}