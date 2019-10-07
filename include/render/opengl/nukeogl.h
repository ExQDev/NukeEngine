#ifndef NUKEOGL_H
#define NUKEOGL_H
#include "../irender.h"
#include "input/keyboard.h"
#include "input/mouse.h"
#ifdef __APPLE__
#include <GL/glew.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GL/freeglut.h>
#else
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#endif
#include <boost/thread.hpp>
#include <iostream>

using namespace std;
namespace bc = boost::container;

void oglkeyboard(unsigned char c, int x, int y);
void oglspecialkeyboard(int key, int x, int y);
void oglkeyboardup(unsigned char c, int x, int y);
void oglspecialkeyboardup(int key, int x, int y);
void oglmouse (int button, int state, int x, int y);
void oglmousescroll(int button, int dir, int x, int y);
void oglreshape(int width, int height);
void oglidle(void);
void ogldisplay(void);
void oglclose();
void oglmove(int x, int y);
void oglpmove(int x, int y);
void ogltimer(int t);

class NUKEENGINE_API NukeOGL : public iRender
{
private:
    bc::list<b::function<void()>> _onClose;
    b::function<void()> _physTrigger;
    bc::list<b::function<void(void)>> _onRender;
    bc::list<b::function<void(void)>> _onGUI;

    static NukeOGL* _main;

    GLuint fbo; // The frame buffer object
    GLuint fbo_depth; // The depth buffer for the frame buffer object
    GLuint fbo_texture; // The texture object to write our frame buffer object to

public:
	NukeOGL();
	~NukeOGL();
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

    static NukeOGL* getSingleton()
    {
        if(!_main)
            _main = new NukeOGL();
        return _main;
    }

	unsigned int getRenderTexture();
	void setOnClose(b::function<void()> cb);
	void setOnGUI(b::function<void(void)> cb);
	void setOnRender(b::function<void(void)> cb);
	void close();
	void move(int x, int y);
	void passmove(int x, int y);
	void keyboard(unsigned char c, int x, int y);
	void keyboardUp(unsigned char c, int x, int y);
	void special(int key, int x, int y);
	void specialup(int key, int x, int y);
	void mouse(int button, int state, int x, int y);
	void mousescroll(int button, int dir, int x, int y);
	void timer();
	void reshape(int w, int h);
	void update();
	void initFrameBufferDepthBuffer(void);
	void initFrameBufferTexture(void);
	void initFrameBuffer(void);
	int init(int w, int h);
	void loop();
	void DrawGrid(float HALF_GRID_SIZE);
	void crosshair(void);
	void renderObject(Mesh* mesh, Material* mat, Transform* transform);
	int render();
	void deinit();
	char* getEngine();
	char* getVersion();
};


#endif // NUKEOGL_H
