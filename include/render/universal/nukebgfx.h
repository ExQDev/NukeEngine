#ifndef NUKEBGFX_H
#define NUKEBGFX_H
#include "../irender.h"
#include <GL/glew.h>
#include <input/keyboard.h>
#include <input/mouse.h>
#include <boost/thread.hpp>
#include <iostream>

#include <stdio.h>
#include <bx/bx.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <GLFW/glfw3.h>
#if BX_PLATFORM_LINUX
#define GLFW_EXPOSE_NATIVE_X11
#elif BX_PLATFORM_WINDOWS
#define GLFW_EXPOSE_NATIVE_WIN32
#elif BX_PLATFORM_OSX
#define GLFW_EXPOSE_NATIVE_COCOA
#endif
#include <GLFW/glfw3native.h>

using namespace std;
namespace bc = boost::container;

static bool s_showStats = false;

static void glfw_errorCallback(int error, const char* description);
static void glfw_keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void glfw_mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

NUKEENGINE_API class NukeBGFX;

class NukeBGFX : public iRender
{
private:
    bc::list<b::function<void()>> _onClose;
    bst::function<void()> _physTrigger;
    bc::list<b::function<void(void)>> _onRender;
    bc::list<b::function<void(void)>> _onGUI;

    static NukeBGFX* _main;
    GLFWwindow *window = nullptr;
    const bgfx::ViewId kClearView = 0;
    bst::thread* renderThread = nullptr;
public:
	bool _debug = false;
    bgfx::RendererType::Enum rendererType = bgfx::RendererType::OpenGL;

	NukeBGFX();
	~NukeBGFX();

    static iRender* getSingleton()
    {
        if(!_main)
            _main = new NukeBGFX();
        return _main;
    }

    GLFWwindow* getWindow();
	int init(int w, int h);
	int render();
	void renderObject(Mesh* mesh, Material* mat, Transform* transform);
	void loop();
	void deinit();
	void update();
	char* getEngine();
	char* getVersion();
	void setOnClose(b::function<void()> cb);
	void setOnGUI(b::function<void(void)> cb);
	void setOnRender(b::function<void(void)> cb);
	void close();
	void timer();
	void keyboard(int key, int scancode, int action, int mods);
	void mouseMove(double xpos, double ypos);
	void mouseClick(int button, int action, int mods);
	void setCursorMode(int mode) ;
	void rawMouse(double xpos, double ypos);
	void mouseEnterLeave(int entered);
    void setWindowShouldClose();
};

#endif // NUKEBGFX_H
