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
double SIXx = 2.2;
double SIXy = 1.1;
double SIXrot = 0.0;
double SIXveloc = 0.0;
double SIXdead = 0;
vector<double> SIXdata;

//CEE
int C_SIX_rotate()
{
	return 1;
}
int C_SIX_shoot()
{
	return 1;
}
int C_SIX_velocity()
{
	return 1;
}
int C_SIX_kill()
{
	SIXdead = 1;
	return 1;
}
vector<double> C_SIX_fetch()
{
	SIXdata.clear();
	SIXdata.push_back(SIXx);//0
	SIXdata.push_back(SIXy);//1
	SIXdata.push_back(SIXrot);//2
	SIXdata.push_back(SIXveloc);//3
	SIXdata.push_back(SIXdead);//4
	return SIXdata;
}


//LUA
int L_SIX_rotate(lua_State* state)
{
	lua_getglobal(state, "luavar");
	double luavar = lua_tonumber(state, -2);
	SIXrot = luavar;
    cout<<SIXrot<<endl;
	lua_pop(state, 1);
	return 1;
}
int L_SIX_shoot(lua_State* state)
{
	cout<<"BANG6"<<endl;
	return 1;
}
int L_SIX_velocity(lua_State* state)
{
	lua_getglobal(state, "luavar");
	double luavar = lua_tonumber(state, -2);
	SIXrot = luavar;
    cout<<SIXveloc<<endl;
	lua_pop(state, 1);
	return 1;
}
int L_SIX_kill(lua_State* state)
{
	cout<<"6ded"<<endl;
	SIXdead = 1;
	return 1;
}



//init
void six_print_error(lua_State* state) {
  const char* message = lua_tostring(state, -1);
  puts(message);
  lua_pop(state, 1);
}
int botSix(string fn){

	const char* filename = fn.c_str();

	lua_State  *state = luaL_newstate();

	// Make standard libraries available in the Lua object

	luaL_openlibs(state);
	lua_register(state, "rotate", L_SIX_rotate);
	lua_register(state, "throttle", L_SIX_velocity);
	lua_register(state, "shoot", L_SIX_shoot);
	lua_register(state, "kill", L_SIX_kill);

	int result;

	// Load the program; this supports both source code and bytecode files.
	result = luaL_loadfile(state, filename);

	if ( result != LUA_OK ) {
		six_print_error(state);
		return 0;
	}

	// Finally, execute the program by calling into it.
	// Change the arguments if you're not running vanilla Lua code.

	result = lua_pcall(state, 0, LUA_MULTRET, 0);

	if ( result != LUA_OK ) {
		six_print_error(state);
		return 0;
	}
	return 1;
}