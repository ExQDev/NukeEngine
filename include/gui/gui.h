#ifndef GUI_H
#define GUI_H
#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/imconfig.h>
#include <imgui/stb_rect_pack.h>
#include "config.h"

class NUKEENGINE_API GUI
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
