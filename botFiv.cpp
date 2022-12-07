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
const double FIVSX = 812;
const double FIVSY = 234;
double FIVx = FIVSX;
double FIVy = FIVSY;
double FIVrot = 0.0;
double FIVveloc = 0.0;
double FIVdead = 0;
vector<double> FIVdata;

//CEE
int C_FIV_rotate()
{
	return 1;
}
int C_FIV_shoot()
{
	return 1;
}
int C_FIV_velocity()
{
	return 1;
}
int C_FIV_kill()
{
	FIVdead = 1;
	return 1;
}
vector<double> C_FIV_fetch()
{
	FIVdata.clear();
	FIVdata.push_back(FIVx);
	FIVdata.push_back(FIVy);
	FIVdata.push_back(FIVrot);
	FIVdata.push_back(FIVveloc);
	FIVdata.push_back(FIVdead);
	FIVdata.push_back(FIVSX);
	FIVdata.push_back(FIVSY);
	return FIVdata;
}


//LUA
int L_FIV_rotate(lua_State* state)
{
	lua_getglobal(state, "luavar");
	double luavar = lua_tonumber(state, -2);
	FIVrot = luavar;
    cout<<FIVrot<<endl;
	lua_pop(state, 1);
	return 1;
}
int L_FIV_shoot(lua_State* state)
{
	cout<<"BANG5"<<endl;
	return 1;
}
int L_FIV_velocity(lua_State* state)
{
	lua_getglobal(state, "luavar");
	double luavar = lua_tonumber(state, -2);
	FIVrot = luavar;
    cout<<FIVveloc<<endl;
	lua_pop(state, 1);
	return 1;
}
int L_FIV_kill(lua_State* state)
{
	cout<<"5ded"<<endl;
	FIVdead = 1;
	return 1;
}



//init
void fiv_print_error(lua_State* state) {
  const char* message = lua_tostring(state, -1);
  puts(message);
  lua_pop(state, 1);
}
int botFiv(string fn){

	const char* filename = fn.c_str();

	lua_State  *state = luaL_newstate();

	// Make standard libraries available in the Lua object

	luaL_openlibs(state);
	lua_register(state, "rotate", L_FIV_rotate);
	lua_register(state, "throttle", L_FIV_velocity);
	lua_register(state, "shoot", L_FIV_shoot);
	lua_register(state, "kill", L_FIV_kill);

	int result;

	// Load the program; this supports both source code and bytecode files.
	result = luaL_loadfile(state, filename);

	if ( result != LUA_OK ) {
		fiv_print_error(state);
		return 0;
	}

	// Finally, execute the program by calling into it.
	// Change the arguments if you're not running vanilla Lua code.

	result = lua_pcall(state, 0, LUA_MULTRET, 0);

	if ( result != LUA_OK ) {
		fiv_print_error(state);
		return 0;
	}
	return 1;
}