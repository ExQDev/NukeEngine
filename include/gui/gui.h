#ifndef GUI_H
#define GUI_H
#include <imgui-1.89.1/imgui.h>
#include <imgui-1.89.1/imgui_internal.h>
#include <imgui-1.89.1/imconfig.h>
#include "config.hpp"

NUKEENGINE_API class GUI;

class GUI
{
private:
	GUI();
	~GUI();
public:
    static GUI* getSingleton()
    {
        static GUI instance;
        return &instance;
    }

	void load(char* txt_style);
	ImVec4 confColor2ImVec(struct confColor cc);
	void setup(ImGuiContext* context);
	void setupDefault(ImGuiContext* context);
};
#endif // GUI_H
