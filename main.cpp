#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <thread>
#include <string>
#include "interpreter.cpp"

using namespace std;

//temporary function that will be expanded upon later, currently just starts the interperter
void foo(string y){
    interpreter(y);
}

//main function for the program
int main(void)
{   
    //starts thread one
    thread one(foo, "..\\Asteroids\\Bots\\test1.txt");
    //starts thread two
    thread two(foo, "..\\Asteroids\\Bots\\test2.txt");

    //waits for thread one to finish
    one.join();
    //waits for thread two to finish
    two.join();

    //end of main
    return 0;
}