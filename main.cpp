#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <thread>
#include <string>
#include "interpreter.cpp"

using namespace std;

void foo(string y){
    interpreter(y);
}


int main(void)
{   
    thread one(foo, "..\\Bots\\test1.txt");
    thread two(foo, "..\\Bots\\test2.txt");

    one.join();
    two.join();

    return 0;
}