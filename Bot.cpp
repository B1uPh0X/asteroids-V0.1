#include <stdio.h>
#include "Bot.h"

#ifdef __cplusplus
# include <lua.hpp>
#else
# include <lua.h>
# include <lualib.h>
# include <lauxlib.h>
#endif

Bot::Bot(){

}

void Bot::create(string fn){
	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(0,0));
	triangle.setPoint(1, sf::Vector2f(100, 40));
	triangle.setPoint(2, sf::Vector2f(0, 80));
	triangle.setOrigin(50, 40);
	triangle.setScale(0.5f, 0.5f);
	triangle.setFillColor(sf::Color::Transparent);
	triangle.setOutlineThickness(2);
	triangle.setOutlineColor(sf::Color::Cyan);
}

void Bot::drawBot(sf::RenderWindow &window){
	window.draw(triangle);
}

void Bot::run(){
	lua_State *state = luaL_newstate();

	//Make standard libraries available in the Lua object
	luaL_openlibs(state);
	lua_register(state, "setVelocity", setVelocity);
	lua_register(state, "setThrottle", setThrottle);
	lua_register(state, "rotate", rotate);
	lua_register(state, "shoot", shoot);

	int result;

	//Load the program; this supports both source code and bytecode files.
	result = luaL_loadfile(state, filename);


	if ( result != LUA_OK ) {
    	print_error(state);
    	return;
	}

	result = lua_pcall(state, 0, LUA_MULTRET, 0);

	
	if ( result != LUA_OK ) {
    	print_error(state);
   		return;
  	}

}

void Bot::setVelocity(){
	cout<<"setVelocity"<<endl;
}

void Bot::setThrottle(){
	cout<<"setThrottle"<<endl;
}

void Bot::rotate(){
	cout<<"rotate"<<endl;
}

void Bot::shoot(){
	cout<<"shoot"<<endl;
}