#ifndef NUKEBGFX_H
#define NUKEBGFX_H
#include "../irender.h"
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

static void glfw_errorCallback(int error, const char *description)
{
    fprintf(stderr, "GLFW error %d: %s\n", error, description);
}

static void glfw_keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_F1 && action == GLFW_RELEASE)
        s_showStats = !s_showStats;
}

class NukeBGFX : public iRender
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
    NukeBGFX(){
        if(_main)
            _instance = _main;
        else
        {
            _main = this;
            _instance = _main;
        }
    }
    ~NukeBGFX(){}
    b::function<void()> _UIinit;
    b::function<void(unsigned char c, int x, int y)> _UIkeyboard;
    b::function<void(unsigned char c, int x, int y)> _UIkeyaboardUp;
    b::function<void(int key, int x, int y)> _UIspecial;
    b::function<void(int key, int x, int y)> _UIspecialUp;
    b::function<void(int button, int state, int x, int y)> _UImouse;
    b::function<void(int button, int dir, int x, int y)> _UImouseWheel;
    b::function<void(int x, int y)> _UImove;
    b::function<void(int x, int y)> _UIpmove;
    b::function<void(int w, int h)> _UIreshape;

    static NukeBGFX* getSingleton()
    {
        //static NukeBGFX instance;
        if(!_main)
            _main = new NukeBGFX();
        return _main;
    }

    int init(int w, int h){
        glfwSetErrorCallback(glfw_errorCallback);
        if (!glfwInit())
            return 1;
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        window = glfwCreateWindow(1024, 768, "helloworld", nullptr, nullptr);
        if (!window)
            return 1;
        glfwSetKeyCallback(window, glfw_keyCallback);

        // Most graphics APIs must be used on the same thread that created the window.
        bgfx::renderFrame();
        // Initialize bgfx using the native window handle and window resolution.
        bgfx::Init init;
    #if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
        init.platformData.ndt = glfwGetX11Display();
        init.platformData.nwh = (void*)(uintptr_t)glfwGetX11Window(window);
    #elif BX_PLATFORM_OSX
        init.platformData.nwh = glfwGetCocoaWindow(window);
    #elif BX_PLATFORM_WINDOWS
        init.platformData.nwh = glfwGetWin32Window(window);
    #endif
        int width, height;
        glfwGetWindowSize(window, &width, &height);
        init.resolution.width = (uint32_t)width;
        init.resolution.height = (uint32_t)height;
        init.resolution.reset = BGFX_RESET_VSYNC;
        if (!bgfx::init(init))
            return 1;


        bgfx::setViewClear(kClearView, BGFX_CLEAR_COLOR);
        bgfx::setViewRect(kClearView, 0, 0, bgfx::BackbufferRatio::Equal);

        if(_UIinit)
            _UIinit();

//        this->renderThread = new b::thread(b::bind(&NukeBGFX::loop, this));
    }

    int render() {
        glfwPollEvents();
        // Handle window resize.
        int oldWidth = width, oldHeight = height;
        glfwGetWindowSize(window, &width, &height);
        if (width != oldWidth || height != oldHeight) {
            bgfx::reset((uint32_t)width, (uint32_t)height, BGFX_RESET_VSYNC);
            bgfx::setViewRect(kClearView, 0, 0, bgfx::BackbufferRatio::Equal);
        }
        // This dummy draw call is here to make sure that view 0 is cleared if no other draw calls are submitted to view 0.
        bgfx::touch(kClearView);
        // Use debug font to print information about this example.
        bgfx::dbgTextClear();

        if(_onGUI.size() > 0)
            for(auto _rn : _onGUI){
                _rn();
            }

//        bgfx::dbgTextImage(bx::max<uint16_t>(uint16_t(width / 2 / 8), 20) - 20, bx::max<uint16_t>(uint16_t(height / 2 / 16), 6) - 6, 40, 12, s_logo, 160);
        bgfx::dbgTextPrintf(0, 0, 0x0f, "Press F1 to toggle stats.");
        bgfx::dbgTextPrintf(0, 1, 0x0f, "Color can be changed with ANSI \x1b[9;me\x1b[10;ms\x1b[11;mc\x1b[12;ma\x1b[13;mp\x1b[14;me\x1b[0m code too.");
        bgfx::dbgTextPrintf(80, 1, 0x0f, "\x1b[;0m    \x1b[;1m    \x1b[; 2m    \x1b[; 3m    \x1b[; 4m    \x1b[; 5m    \x1b[; 6m    \x1b[; 7m    \x1b[0m");
        bgfx::dbgTextPrintf(80, 2, 0x0f, "\x1b[;8m    \x1b[;9m    \x1b[;10m    \x1b[;11m    \x1b[;12m    \x1b[;13m    \x1b[;14m    \x1b[;15m    \x1b[0m");
        const bgfx::Stats* stats = bgfx::getStats();
        bgfx::dbgTextPrintf(0, 2, 0x0f, "Backbuffer %dW x %dH in pixels, debug text %dW x %dH in characters.", stats->width, stats->height, stats->textWidth, stats->textHeight);
        // Enable stats or debug text.
        bgfx::setDebug(s_showStats ? BGFX_DEBUG_STATS : BGFX_DEBUG_TEXT);
        // Advance to next frame. Process submitted rendering primitives.
        bgfx::frame();
    }

    void renderObject(Mesh* mesh, Material* mat, Transform* transform){

    }

    void loop() {
        while(!glfwWindowShouldClose(this->window)){
            this->render();
        }
    }

    void deinit() {
        bgfx::shutdown();
        glfwTerminate();
    }

    void update() {

    }

    char* getEngine() {
        return  "BGFX - ";
    }

    char* getVersion() {
        return "1.0.0.0";
    }

    void setOnClose(b::function<void()> cb){
        _onClose.push_back(cb);
    }

    void setOnGUI(b::function<void(void)> cb){
        _onGUI.push_back(cb);
//        cout << cb << " -- onGUI[" << this << "]" << endl;
    }

    void setOnRender(b::function<void(void)> cb){
        _onRender.push_back(cb);
//        cout << cb << " -- onRender" << endl;
    }

    void close()
    {
        if(_onClose.size() > 0)
            for(auto cb : _onClose)
                cb();
    }

    void timer(){
        if(_physTrigger)
            _physTrigger();
    }

};

NukeBGFX* NukeBGFX::_main;
#endif // NUKEBGFX_H
