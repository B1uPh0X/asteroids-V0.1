#include <stdio.h>
#include <iostream>
#include <thread>
#include <string>
#include <vector>

#ifdef __cplusplus
# include <lua.hpp>
#else
# include <lua.h>
# include <lualib.h>
# include <lauxlib.h>
#endif

using namespace std;

//VARs
const double FOUSX = 512;
const double FOUSY = 434;
double FOUx = FOUSX;
double FOUy = FOUSY;
double FOUrot = 0.0;
double FOUveloc = 0.0;
double FOUdead = 0;
vector<double> FOUdata;

//CEE
int C_FOU_rotate()
{
	return 1;
}
int C_FOU_shoot()
{
	return 1;
}
int C_FOU_velocity()
{
	return 1;
}
int C_FOU_kill()
{
	FOUdead = 1;
	return 1;
}
vector<double> C_FOU_fetch()
{
	FOUdata.clear();
	FOUdata.push_back(FOUx);
	FOUdata.push_back(FOUy);
	FOUdata.push_back(FOUrot);
	FOUdata.push_back(FOUveloc);
	FOUdata.push_back(FOUdead);
	FOUdata.push_back(FOUSX);
	FOUdata.push_back(FOUSY);
	return FOUdata;
}


//LUA
int L_FOU_rotate(lua_State* state)
{
	lua_getglobal(state, "luavar");
	double luavar = lua_tonumber(state, -2);
	FOUrot = luavar;
    cout<<FOUrot<<endl;
	lua_pop(state, 1);
	return 1;
}
int L_FOU_shoot(lua_State* state)
{
	cout<<"BANG4"<<endl;
	return 1;
}
int L_FOU_velocity(lua_State* state)
{
	lua_getglobal(state, "luavar");
	double luavar = lua_tonumber(state, -2);
	FOUrot = luavar;
    cout<<FOUveloc<<endl;
	lua_pop(state, 1);
	return 1;
}
int L_FOU_kill(lua_State* state)
{
	cout<<"4ded"<<endl;
	FOUdead = 1;
	return 1;
}



//init
void fou_print_error(lua_State* state) {
  const char* message = lua_tostring(state, -1);
  puts(message);
  lua_pop(state, 1);
}
int botFou(string fn){

	const char* filename = fn.c_str();

	lua_State  *state = luaL_newstate();

	// Make standard libraries available in the Lua object

	luaL_openlibs(state);
	lua_register(state, "rotate", L_FOU_rotate);
	lua_register(state, "throttle", L_FOU_velocity);
	lua_register(state, "shoot", L_FOU_shoot);
	lua_register(state, "kill", L_FOU_kill);

	int result;

	// Load the program; this supports both source code and bytecode files.
	result = luaL_loadfile(state, filename);

	if ( result != LUA_OK ) {
		fou_print_error(state);
		return 0;
	}

	// Finally, execute the program by calling into it.
	// Change the arguments if you're not running vanilla Lua code.

	result = lua_pcall(state, 0, LUA_MULTRET, 0);

	if ( result != LUA_OK ) {
		fou_print_error(state);
		return 0;
	}
	return 1;
}