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
double ONEx = 2.2;
double ONEy = 1.1;
double ONErot = 0.0;
double ONEveloc = 0.0;
double ONEdead = 0;
vector<double> ONEdata;

//CEE
int C_ONE_rotate()
{
	return 1;
}
int C_ONE_shoot()
{
	return 1;
}
int C_ONE_velocity()
{
	return 1;
}
int C_ONE_kill()
{
	ONEdead = 1;
	return 1;
}
vector<double> C_ONE_fetch()
{
	ONEdata.clear();
	ONEdata.push_back(ONEx);
	ONEdata.push_back(ONEy);
	ONEdata.push_back(ONErot);
	ONEdata.push_back(ONEveloc);
	ONEdata.push_back(ONEdead);
	return ONEdata;
}


//LUA
int L_ONE_rotate(lua_State* state)
{
	lua_getglobal(state, "luavar");
	double luavar = lua_tonumber(state, -2);
	ONErot = luavar;
    cout<<ONErot<<endl;
	lua_pop(state, 1);
	return 1;
}
int L_ONE_shoot(lua_State* state)
{
	cout<<"BANG1"<<endl;
	return 1;
}
int L_ONE_velocity(lua_State* state)
{
	lua_getglobal(state, "luavar");
	double luavar = lua_tonumber(state, -2);
	ONErot = luavar;
    cout<<ONEveloc<<endl;
	lua_pop(state, 1);
	return 1;
}
int L_ONE_kill(lua_State* state)
{
	cout<<"1ded"<<endl;
	ONEdead = 1;
	return 1;
}



//init
void one_print_error(lua_State* state) {
  const char* message = lua_tostring(state, -1);
  puts(message);
  lua_pop(state, 1);
}
int botOne(string fn){

	const char* filename = fn.c_str();

	lua_State  *state = luaL_newstate();

	// Make standard libraries available in the Lua object

	luaL_openlibs(state);
	lua_register(state, "rotate", L_ONE_rotate);
	lua_register(state, "throttle", L_ONE_velocity);
	lua_register(state, "shoot", L_ONE_shoot);
	lua_register(state, "kill", L_ONE_kill);

	int result;

	// Load the program; this supports both source code and bytecode files.
	result = luaL_loadfile(state, filename);

	if ( result != LUA_OK ) {
		one_print_error(state);
		return 0;
	}

	// Finally, execute the program by calling into it.
	// Change the arguments if you're not running vanilla Lua code.

	result = lua_pcall(state, 0, LUA_MULTRET, 0);

	if ( result != LUA_OK ) {
		one_print_error(state);
		return 0;
	}
	return 1;
}