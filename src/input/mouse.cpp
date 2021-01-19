#include "input/mouse.h"

Mouse::Mouse() {}
Mouse::~Mouse() {}

void Mouse::key(int button, int state, int mods)
{
	for (auto f : _onKey)
	{
		f(button, state, mods);
	}
}

void Mouse::wheel(int button, int dir, int x, int y)
{
	for (auto f : _onWheel)
	{
		f(button, dir, x, y);
	}
}

void Mouse::move(int x, int y)
{
	for (auto f : _onMove)
	{
		f(x, y);
	}
}

void Mouse::pmove(int x, int y)
{
	for (auto f : _onPMove)
	{
		f(x, y);
	}
}


Mouse* Mouse::operator+=(bst::function<void(int button, int state, int mods)> onKey)
{
	_onKey.push_back(onKey);
	return this;
}

Mouse* Mouse::operator*=(bst::function<void(int button, int dir, int x, int y)> onWheel)
{
	_onWheel.push_back(onWheel);
	return this;
}

Mouse* Mouse::operator&=(bst::function<void(int x, int y)> onMov)
{
	_onMove.push_back(onMov);
	return this;
}

Mouse* Mouse::operator|=(bst::function<void(int x, int y)> onPMov)
{
	_onPMove.push_back(onPMov);
	return this;
}