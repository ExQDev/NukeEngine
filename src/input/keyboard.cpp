#include "input/keyboard.h"

KeyBoard::KeyBoard() {}
KeyBoard::~KeyBoard() {}

void KeyBoard::key(unsigned char c, int x, int y)
{
	keyStates[c] = true;
	for (auto f : _onKey)
	{
		f(c, x, y);
	}
}

void KeyBoard::special(int key, int x, int y)
{
	for (auto f : _onSpecialKey)
	{
		f(key, x, y);
	}
}

void KeyBoard::keyup(unsigned char c, int x, int y)
{
	keyStates[c] = false;
	for (auto f : _onKeyUp)
	{
		f(c, x, y);
	}
}

void KeyBoard::specialup(int key, int x, int y)
{
	for (auto f : _onSpecialKeyUp)
	{
		f(key, x, y);
	}
}

bool KeyBoard::getKeyPressed(unsigned char c) {
	return keyStates[c];
}

// On Key
KeyBoard* KeyBoard::operator+=(bst::function<void(unsigned char c, int x, int y)> onKey)
{
	_onKey.push_back(onKey);
	return this;
}

// On Special Key
KeyBoard* KeyBoard::operator*=(bst::function<void(int key, int x, int y)> onSpecialKey)
{
	_onSpecialKey.push_back(onSpecialKey);
	return this;
}

// On Key Up
KeyBoard* KeyBoard::operator&=(bst::function<void(unsigned char c, int x, int y)> onKeyUp)
{
	_onKeyUp.push_back(onKeyUp);
	return this;
}

// On Special Key Up
KeyBoard* KeyBoard::operator|=(bst::function<void(int key, int x, int y)> onSpecialKeyUp)
{
	_onSpecialKeyUp.push_back(onSpecialKeyUp);
	return this;
}

