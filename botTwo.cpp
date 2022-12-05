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
double TWOx = 2.2;
double TWOy = 1.1;
double TWOrot = 0.0;
double TWOveloc = 0.0;
double TWOdead = 0;
vector<double> TWOdata;

//CEE
int C_TWO_rotate()
{
	return 1;
}
int C_TWO_shoot()
{
	return 1;
}
int C_TWO_velocity()
{
	return 1;
}
int C_TWO_kill()
{
	TWOdead = 1;
	return 1;
}
vector<double> C_TWO_fetch()
{
	TWOdata.clear();
	TWOdata.push_back(TWOx);
	TWOdata.push_back(TWOy);
	TWOdata.push_back(TWOrot);
	TWOdata.push_back(TWOveloc);
	TWOdata.push_back(TWOdead);
	return TWOdata;
}


//LUA
int L_TWO_rotate(lua_State* state)
{
	lua_getglobal(state, "luavar");
	double luavar = lua_tonumber(state, -2);
	TWOrot = luavar;
    cout<<TWOrot<<endl;
	lua_pop(state, 1);
	return 1;
}
int L_TWO_shoot(lua_State* state)
{
	cout<<"BANG2"<<endl;
	return 1;
}
int L_TWO_velocity(lua_State* state)
{
	lua_getglobal(state, "luavar");
	double luavar = lua_tonumber(state, -2);
	TWOrot = luavar;
    cout<<TWOveloc<<endl;
	lua_pop(state, 1);
	return 1;
}
int L_TWO_kill(lua_State* state)
{
	cout<<"2ded"<<endl;
	TWOdead = 1;
	return 1;
}



//init
void two_print_error(lua_State* state) {
  const char* message = lua_tostring(state, -1);
  puts(message);
  lua_pop(state, 1);
}
int botTwo(string fn){

	const char* filename = fn.c_str();

	lua_State  *state = luaL_newstate();

	// Make standard libraries available in the Lua object

	luaL_openlibs(state);
	lua_register(state, "rotate", L_TWO_rotate);
	lua_register(state, "throttle", L_TWO_velocity);
	lua_register(state, "shoot", L_TWO_shoot);
	lua_register(state, "kill", L_TWO_kill);

	int result;

	// Load the program; this supports both source code and bytecode files.
	result = luaL_loadfile(state, filename);

	if ( result != LUA_OK ) {
		two_print_error(state);
		return 0;
	}

	// Finally, execute the program by calling into it.
	// Change the arguments if you're not running vanilla Lua code.

	result = lua_pcall(state, 0, LUA_MULTRET, 0);

	if ( result != LUA_OK ) {
		two_print_error(state);
		return 0;
	}
	return 1;
}