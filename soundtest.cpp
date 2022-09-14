#include <SFML/Audio.hpp>
#include <ctime>
#include <iostream>

void pause(int dur);

int soundtest()
{
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sounds\\270306__littlerobotsoundfactory__explosion-02.wav"))
        return -1;

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    
    pause(5);

    return 0;
}

void pause(int dur){
    int temp = time(NULL) + dur;
    while (temp > time(NULL));    
}