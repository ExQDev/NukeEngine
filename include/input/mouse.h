#ifndef MOUSE_H
#define MOUSE_H
#include <boost/container/list.hpp>
#include <boost/function.hpp>

namespace b = boost;
namespace bc = b::container;

class NUKEENGINE_API Mouse
{
    friend class NukeOGL;
    friend class NukeBGFX;

private:
	Mouse();
	~Mouse();

    bc::list<b::function<void(int button, int state, int x, int y)>> _onKey;
    bc::list<b::function<void(int button, int state, int x, int y)>> _onWheel;
    bc::list<b::function<void(int x, int y)>> _onMove;
    bc::list<b::function<void(int x, int y)>> _onPMove;

	void key(int button, int state, int x, int y);
	void wheel(int button, int dir, int x, int y);
	void move(int x, int y);
	void pmove(int x, int y);

public:
    static Mouse *getSingleton()
    {
        static Mouse instance;
        return &instance;
    }

	Mouse* operator+=(b::function<void(int button, int state, int x, int y)> onKey);
	Mouse* operator*=(b::function<void(int button, int dir, int x, int y)> onWheel);
	Mouse* operator&=(b::function<void(int x, int y)> onMov);
	Mouse* operator|=(b::function<void(int x, int y)> onPMov);
};
#endif // MOUSE_H
