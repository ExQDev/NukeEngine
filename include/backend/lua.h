#ifndef LUA_H
#define LUA_H
#ifdef __APPLE__
#include <lua/lua.hpp>
#else
#include <lua.hpp>
#endif
#include <LuaBridge/LuaBridge.h>
#include <boost/filesystem.hpp>
#include <iostream>

namespace bst = boost;
namespace bfs = boost::filesystem;
namespace lb = luabridge;
using namespace std;

class Lua
{
private:
	Lua();
	~Lua();

public:
    lua_State* l;

    static Lua* getSingleton(){
        static Lua instance;
        return &instance;
    }

	lua_State* getState();
	void doFile(const char* path);
	void doStr(const char* str);
	lb::LuaRef getGlobal(const char* var);
};
#endif // LUA_H
