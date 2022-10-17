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