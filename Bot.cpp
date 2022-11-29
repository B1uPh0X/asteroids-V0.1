#include <stdio.h>
#include <string>
//#include "Bot.h"

#ifdef __cplusplus
# include <lua.hpp>
#else
# include <lua.h>
# include <lualib.h>
# include <lauxlib.h>
#endif

using namespace std;



/*
void Bot(string x){
alive = false;
}

static void setVelocity(){
	cout<<"setVelocity"<<endl;
}

static void setThrottle(){
	cout<<"setThrottle"<<endl;
}

static void rotate(){
	cout<<"rotate"<<endl;
}


static void shoot(){
	cout<<"shoot"<<endl;
}

static void kill(){
	alive = false;
}

static bool isAlive(){
	return alive;
}

void Bot::create(string fn){
	file = fn.c_str();
	/*triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(0,0));
	triangle.setPoint(1, sf::Vector2f(100, 40));
	triangle.setPoint(2, sf::Vector2f(0, 80));
	triangle.setOrigin(50, 40);
	triangle.setScale(0.5f, 0.5f);
	triangle.setFillColor(sf::Color::Transparent);
	triangle.setOutlineThickness(2);
	triangle.setOutlineColor(sf::Color::Cyan);*//*
}

void Bot::drawBot(sf::RenderWindow &window){
	window.draw(triangle);
}

void Bot::run(){
	alive = true;

	lua_State *state = luaL_newstate();

	//Make standard libraries available in the Lua object
	luaL_openlibs(state);
	lua_register(state, "setVeloc", setVelocity);
	lua_register(state, "setThrot", setThrottle);
	lua_register(state, "rot", rotate);
	lua_register(state, "shoot", shoot);

	lua_re

	int result;

	//Load the program; this supports both source code and bytecode files.
	result = luaL_loadfile(state, file);


	if ( result != LUA_OK ) {
    	//print_error(state);
    	return;
	}

	result = lua_pcall(state, 0, LUA_MULTRET, 0);

	
	if ( result != LUA_OK ) {
    	//print_error(state);
   		return;
  	}

}
*/