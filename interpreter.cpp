
#include <stdio.h>
#include <iostream>

#ifdef __cplusplus
# include <lua.hpp>
#else
# include <lua.h>
# include <lualib.h>
# include <lauxlib.h>
#endif


using namespace std;

int foo(lua_State* state)
{
    cout<<"foo has been called "<<lua_gettop(state)<<endl;
    return 1;
}

int bar(lua_State* state)
{
    cout<<"BAR\n"<<lua_gettop(state)<<endl;
    return 1;
}

void print_err(lua_State* state)
{
    const char* message = lua_tostring(state, -1);
    puts(message);
    lua_pop(state, 1);
}


//main interperter function, reads file, stores contents of file in a 2d vector, runs specified commands
void interpreter(const char* filename)
{
    cout<<filename<<endl;

    lua_State *state = luaL_newstate();

    luaL_openlibs(state);
    lua_register(state, "foo", foo);
    lua_register(state, "bar", bar);
    
    int result;
    result = luaL_loadfile(state, filename);

    if ( result != LUA_OK ) { 
        cerr<<state<<endl;
        cout<<"1"<<endl;
        print_err(state);
        return;
    }

    result = lua_pcall(state, 0, LUA_MULTRET, 0);

    if ( result != LUA_OK ){
        cerr<<state<<endl;
        cout<<"2"<<endl;
        print_err(state);
        return;
    }
}