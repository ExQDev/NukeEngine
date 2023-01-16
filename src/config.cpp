#include "config.hpp"

#define PREFIX_CONF "[config]\t\t"

struct confColor luaGetColor(lb::LuaRef ref, const char* name) {
	auto col = ref[name];
	struct confColor cc;
	cc.x = ref["r"].cast<float>();
	cc.y = ref["g"].cast<float>();
	cc.z = ref["b"].cast<float>();
	cc.w = ref["a"].cast<float>();
	return cc;
}

struct confUiVec luaGetVector(lb::LuaRef ref, const char* name) {
	auto col = ref[name];
	struct confUiVec cc;
	cc.x = ref["x"].cast<int>();
	cc.y = ref["y"].cast<int>();
	return cc;
}


void loadTheme(struct NukeTheme* t, lb::LuaRef _t) {
	t->WindowPadding = luaGetVector(_t, "WindowPadding");
	t->FramePadding = luaGetVector(_t, "FramePadding");
	t->ItemSpacing = luaGetVector(_t, "ItemSpacing");
	t->ItemInnerSpacing = luaGetVector(_t, "ItemInnerSpacing");

	t->WindowRounding = _t["WindowRounding"].cast<float>();
	t->FrameRounding = _t["FrameRounding"].cast<float>();
	t->IndentSpacing = _t["IndentSpacing"].cast<float>();
	t->ScrollbarSize = _t["ScrollbarSize"].cast<float>();
	t->ScrollbarRounding = _t["ScrollbarRounding"].cast<float>();
	t->GrabMinSize = _t["GrabMinSize"].cast<float>();
	t->GrabRounding = _t["GrabRounding"].cast<float>();

	t->ImGuiCol_Text = luaGetColor(_t, "ImGuiCol_Text");
	t->ImGuiCol_TextDisabled = luaGetColor(_t, "ImGuiCol_TextDisabled");
	t->ImGuiCol_WindowBg = luaGetColor(_t, "ImGuiCol_WindowBg");
    t->ImGuiCol_ChildBg = luaGetColor(_t, "ImGuiCol_ChildBg");
	t->ImGuiCol_PopupBg = luaGetColor(_t, "ImGuiCol_PopupBg");
	t->ImGuiCol_Border = luaGetColor(_t, "ImGuiCol_Border");
	t->ImGuiCol_BorderShadow = luaGetColor(_t, "ImGuiCol_BorderShadow");
	t->ImGuiCol_FrameBg = luaGetColor(_t, "ImGuiCol_FrameBg");
	t->ImGuiCol_FrameBgHovered = luaGetColor(_t, "ImGuiCol_FrameBgHovered");
	t->ImGuiCol_FrameBgActive = luaGetColor(_t, "ImGuiCol_FrameBgActive");
	t->ImGuiCol_TitleBg = luaGetColor(_t, "ImGuiCol_TitleBg");
	t->ImGuiCol_TitleBgCollapsed = luaGetColor(_t, "ImGuiCol_TitleBgCollapsed");
	t->ImGuiCol_TitleBgActive = luaGetColor(_t, "ImGuiCol_TitleBgActive");
	t->ImGuiCol_MenuBarBg = luaGetColor(_t, "ImGuiCol_MenuBarBg");
	t->ImGuiCol_ScrollbarBg = luaGetColor(_t, "ImGuiCol_ScrollbarBg");
	t->ImGuiCol_ScrollbarGrab = luaGetColor(_t, "ImGuiCol_ScrollbarGrab");
	t->ImGuiCol_ScrollbarGrabHovered = luaGetColor(_t, "ImGuiCol_ScrollbarGrabHovered");
	t->ImGuiCol_ScrollbarGrabActive = luaGetColor(_t, "ImGuiCol_ScrollbarGrabActive");
	//t->ImGuiCol_ComboBg = luaGetColor(_t, "ImGuiCol_ComboBg");
	t->ImGuiCol_CheckMark = luaGetColor(_t, "ImGuiCol_CheckMark");
	t->ImGuiCol_SliderGrab = luaGetColor(_t, "ImGuiCol_SliderGrab");
	t->ImGuiCol_SliderGrabActive = luaGetColor(_t, "ImGuiCol_SliderGrabActive");
	t->ImGuiCol_Button = luaGetColor(_t, "ImGuiCol_Button");
	t->ImGuiCol_ButtonHovered = luaGetColor(_t, "ImGuiCol_ButtonHovered");
	t->ImGuiCol_ButtonActive = luaGetColor(_t, "ImGuiCol_ButtonActive");
	t->ImGuiCol_Header = luaGetColor(_t, "ImGuiCol_Header");
	t->ImGuiCol_HeaderHovered = luaGetColor(_t, "ImGuiCol_HeaderHovered");
	t->ImGuiCol_HeaderActive = luaGetColor(_t, "ImGuiCol_HeaderActive");
    t->ImGuiCol_Separator = luaGetColor(_t, "ImGuiCol_Separator");
    t->ImGuiCol_SeparatorHovered = luaGetColor(_t, "ImGuiCol_SeparatorHovered");
    t->ImGuiCol_SeparatorActive = luaGetColor(_t, "ImGuiCol_SeparatorActive");
	t->ImGuiCol_ResizeGrip = luaGetColor(_t, "ImGuiCol_ResizeGrip");
	t->ImGuiCol_ResizeGripHovered = luaGetColor(_t, "ImGuiCol_ResizeGripHovered");
	t->ImGuiCol_ResizeGripActive = luaGetColor(_t, "ImGuiCol_ResizeGripActive");
	//t->ImGuiCol_CloseButton = luaGetColor(_t, "ImGuiCol_CloseButton");
	//t->ImGuiCol_CloseButtonHovered = luaGetColor(_t, "ImGuiCol_CloseButtonHovered");
	//t->ImGuiCol_CloseButtonActive = luaGetColor(_t, "ImGuiCol_CloseButtonActive");
	t->ImGuiCol_PlotLines = luaGetColor(_t, "ImGuiCol_PlotLines");
	t->ImGuiCol_PlotLinesHovered = luaGetColor(_t, "ImGuiCol_PlotLinesHovered");
	t->ImGuiCol_PlotHistogram = luaGetColor(_t, "ImGuiCol_PlotHistogram");
	t->ImGuiCol_PlotHistogramHovered = luaGetColor(_t, "ImGuiCol_PlotHistogramHovered");
	t->ImGuiCol_TextSelectedBg = luaGetColor(_t, "ImGuiCol_TextSelectedBg");
    t->ImGuiCol_ModalWindowDimBg = luaGetColor(_t, "ImGuiCol_ModalWindowDimBg");

	t->isLoaded = true;
}

void Config::reload(Config* instance) {
	
	Lua* lua = Lua::getSingleton();
	bfs::path configDir("config");
	bfs::path config("./config/main.lua");
	if (!bfs::exists(configDir))
		bfs::create_directory(configDir);
	if (!bfs::exists(config))
	{
		cout << PREFIX_CONF << "Main config not found, create it please!" << endl;
	}
	boost::filesystem::recursive_directory_iterator iter(configDir), eod;
	for (auto& p : iter)
	{
		cout << PREFIX_CONF << p.path().string().c_str() << endl;
		lua->doFile(p.path().string().c_str());
	}
	/*lua_dump(lua->l, lua)*/
	auto w = lb::getGlobal(lua->l, "window");
	//cout << PREFIX_CONF << "Window ref: " << w.tostring() << endl;
	if (!w.isNil()) {
		instance->window = NukeWindow();
		instance->window.h = w["height"].cast<int>();
		instance->window.w = w["width"].cast<int>();
		std::string fontName = w["mainFont"].cast<std::string>();
		//strcpy(instance->window.mainFont, fontName.c_str());
		instance->window.mainFont = (char*)fontName.c_str();
		cout << PREFIX_CONF << "Window size = [" << instance->window.w << "x" << instance->window.h << "]" << endl;
		cout << PREFIX_CONF << "FONT IS " << instance->window.mainFont << endl;
	}

	auto t = lb::getGlobal(lua->l, "theme");
	if (!t.isNil()) {
		loadTheme(&instance->theme, t);
	}
}

Config::Config() {
	cout << PREFIX_CONF << "CWD: " << bfs::current_path() << endl;

	//reload(this);
}
Config::~Config() {}

NukeWindow* Config::getWindow() {
    return &this->window;
}

NukeTheme* Config::getTheme() {
    return &this->theme;
}

std::string Config::getMainFont(){
    return std::string(window.mainFont);
}
