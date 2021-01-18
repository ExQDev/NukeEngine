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

class NUKEENGINE_API NukeBGFX : public iRender
{
private:
    bc::list<b::function<void()>> _onClose;
    b::function<void()> _physTrigger;
    bc::list<b::function<void(void)>> _onRender;
    bc::list<b::function<void(void)>> _onGUI;

    static NukeBGFX* _main;
    GLFWwindow *window = nullptr;
    const bgfx::ViewId kClearView = 0;
    b::thread* renderThread = nullptr;
public:
	NukeBGFX();
	~NukeBGFX();

    static iRender* getSingleton()
    {
        if(!_main)
            _main = new NukeBGFX();
        return _main;
    }

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
};

#endif // NUKEBGFX_H
