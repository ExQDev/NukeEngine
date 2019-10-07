#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <boost/container/list.hpp>
#include <boost/function.hpp>

namespace b = boost;
namespace bc = b::container;

class NUKEENGINE_API KeyBoard
{
    friend class NukeOGL;
    friend class NukeBGFX;

private:
	KeyBoard();
	~KeyBoard();

    bc::list<b::function<void(unsigned char c, int x, int y)>> _onKey;
    bc::list<b::function<void(int key, int x, int y)>> _onSpecialKey;
    bc::list<b::function<void(unsigned char c, int x, int y)>> _onKeyUp;
    bc::list<b::function<void(int key, int x, int y)>> _onSpecialKeyUp;
    bool* keyStates = new bool[256];

	void key(unsigned char c, int x, int y);
	void special(int key, int x, int y);
	void keyup(unsigned char c, int x, int y);
	void specialup(int key, int x, int y);

public:

    static KeyBoard* getSingleton()
    {
        static KeyBoard instance;
        return &instance;
    }

	bool getKeyPressed(unsigned char c);

    // On Key
	KeyBoard* operator+=(b::function<void(unsigned char c, int x, int y)> onKey);
    // On Special Key
	KeyBoard* operator*=(b::function<void(int key, int x, int y)> onSpecialKey);
    // On Key Up
	KeyBoard* operator&=(b::function<void(unsigned char c, int x, int y)> onKeyUp);
    // On Special Key Up
	KeyBoard* operator|=(b::function<void(int key, int x, int y)> onSpecialKeyUp);
};
#endif // KEYBOARD_H
