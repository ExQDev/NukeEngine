#ifndef MOUSE_H
#define MOUSE_H
#include <boost/container/list.hpp>
#include <boost/function.hpp>

namespace bst = boost;
namespace bc = boost::container;

class Mouse
{
    friend class NukeOGL;
    friend class NukeBGFX;

private:
	Mouse();
	~Mouse();

    bc::list<bst::function<void(int button, int state, int mods)>> _onKey;
    bc::list<bst::function<void(int button, int state, int x, int y)>> _onWheel;
    bc::list<bst::function<void(int x, int y)>> _onMove;
    bc::list<bst::function<void(int x, int y)>> _onPMove;

	void key(int button, int state, int mods);
	void wheel(int button, int dir, int x, int y);
	void move(int x, int y);
	void pmove(int x, int y);

public:
    static Mouse *getSingleton()
    {
        static Mouse instance;
        return &instance;
    }

	Mouse* operator+=(bst::function<void(int button, int state, int mods)> onKey);
	Mouse* operator*=(bst::function<void(int button, int dir, int x, int y)> onWheel);
	Mouse* operator&=(bst::function<void(int x, int y)> onMov);
	Mouse* operator|=(bst::function<void(int x, int y)> onPMov);
};
#endif // MOUSE_H
