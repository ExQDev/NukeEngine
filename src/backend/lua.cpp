#include "backend/lua.h"

Lua::Lua() {
	l = luaL_newstate();
	bfs::path plugdir("plugins");
	bfs::path plugins("plugins/lua");
	bfs::path main("plugins/lua/main.lua");
	if (!bfs::exists(plugdir))
		bfs::create_directory(plugdir);
	if (!bfs::exists(plugins))
		bfs::create_directory(plugins);
	if (!bfs::exists(main))
	{
		cout << "[lua]\t\t\t" << "Main lua plugin is not detected. Skipping lua initialization." << endl;
	}
	else
	{
		cout << "[lua]\t\t\t" << "Main lua plugin detected. Loading..." << endl;
		doFile(main.string().c_str());
	}
}
Lua::~Lua() {}


lua_State* Lua::getState() {
	return l;
}

void Lua::doFile(const char* path) {
	luaL_dofile(l, path);
}

void Lua::doStr(const char* str) {
	luaL_dostring(l, str);
}

lb::LuaRef Lua::getGlobal(const char* var) {
	return lb::getGlobal(l, var);
}