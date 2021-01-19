#ifndef IRENDER_H
#define IRENDER_H
#include <boost/function.hpp>
#include <API/Model/Transform.h>
#include <API/Model/Mesh.h>

namespace b = boost;

class iRender
{
    friend class NukeOGL;
    friend class NukeBGFX;
private:
    static iRender* _instance;
public:
    static iRender* getSingleton(){
        return _instance;
    }
    Transform* transform = nullptr;
    int width = 0, height = 0;
    bool _crosshair = false;
    float fov = 90, Far = 1000, Near = 0.3f;
	bst::function<void()> _UIinit;
	bst::function<void(unsigned char c, int x, int y)> _UIkeyboard;
	bst::function<void(unsigned char c, int x, int y)> _UIkeyaboardUp;
	bst::function<void(int key, int x, int y)> _UIspecial;
	bst::function<void(int key, int x, int y)> _UIspecialUp;
	bst::function<void(int button, int state, int x, int y)> _UImouse;
	bst::function<void(int button, int dir, int x, int y)> _UImouseWheel;
	bst::function<void(int x, int y)> _UImove;
	bst::function<void(int x, int y)> _UIpmove;
	bst::function<void(int w, int h)> _UIreshape;
    virtual int render() = 0;
    virtual void renderObject(Mesh* mesh, Material* mat, Transform* transform) = 0;
    virtual int init(int w, int h) = 0;
    virtual void loop() = 0;
    virtual void deinit() = 0;
    virtual void update() = 0;
    virtual char* getEngine() = 0;
    virtual char* getVersion() = 0;
    virtual void setOnGUI(bst::function<void(void)> cb) = 0;
    virtual void setOnRender(bst::function<void(void)> cb) = 0;
    virtual void keyboard(int key, int scancode, int action, int mods) = 0;
    virtual void mouseMove(double xpos, double ypos) = 0;
    virtual void mouseClick(int button, int action, int mods) = 0;
    virtual void setCursorMode(int mode) = 0;
    virtual void rawMouse(double xpos, double ypos) = 0;
    virtual void mouseEnterLeave(int entered) = 0;
//    virtual ~iRender(){
//    }
};

#endif // IRENDER_H
