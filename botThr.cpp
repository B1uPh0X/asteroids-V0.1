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
double THRx = 2.2;
double THRy = 1.1;
double THRrot = 0.0;
double THRveloc = 0.0;
double THRdead = 0;
vector<double> THRdata;

//CEE
int C_THR_rotate()
{
	return 1;
}
int C_THR_shoot()
{
	return 1;
}
int C_THR_velocity()
{
	return 1;
}
int C_THR_kill()
{
	THRdead = 1;
	return 1;
}
vector<double> C_THR_fetch()
{
	THRdata.clear();
	THRdata.push_back(THRx);
	THRdata.push_back(THRy);
	THRdata.push_back(THRrot);
	THRdata.push_back(THRveloc);
	THRdata.push_back(THRdead);
	return THRdata;
}


//LUA
int L_THR_rotate(lua_State* state)
{
	lua_getglobal(state, "luavar");
	double luavar = lua_tonumber(state, -2);
	THRrot = luavar;
    cout<<THRrot<<endl;
	lua_pop(state, 1);
	return 1;
}
int L_THR_shoot(lua_State* state)
{
	cout<<"BANG3"<<endl;
	return 1;
}
int L_THR_velocity(lua_State* state)
{
	lua_getglobal(state, "luavar");
	double luavar = lua_tonumber(state, -2);
	THRrot = luavar;
    cout<<THRveloc<<endl;
	lua_pop(state, 1);
	return 1;
}
int L_THR_kill(lua_State* state)
{
	cout<<"3ded"<<endl;
	THRdead = 1;
	return 1;
}



//init
void thr_print_error(lua_State* state) {
  const char* message = lua_tostring(state, -1);
  puts(message);
  lua_pop(state, 1);
}
int botThr(string fn){

	const char* filename = fn.c_str();

	lua_State  *state = luaL_newstate();

	// Make standard libraries available in the Lua object

	luaL_openlibs(state);
	lua_register(state, "rotate", L_THR_rotate);
	lua_register(state, "throttle", L_THR_velocity);
	lua_register(state, "shoot", L_THR_shoot);
	lua_register(state, "kill", L_THR_kill);

	int result;

	// Load the program; this supports both source code and bytecode files.
	result = luaL_loadfile(state, filename);

	if ( result != LUA_OK ) {
		thr_print_error(state);
		return 0;
	}

	// Finally, execute the program by calling into it.
	// Change the arguments if you're not running vanilla Lua code.

	result = lua_pcall(state, 0, LUA_MULTRET, 0);

	if ( result != LUA_OK ) {
		thr_print_error(state);
		return 0;
	}
	return 1;
}