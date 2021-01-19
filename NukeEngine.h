#ifndef NUKEENGINE_H
#define NUKEENGINE_H
#include <cmath>
#include <algorithm>
#include <iostream>
#include <boost/function.hpp>
#include <boost/container/list.hpp>
#include <string.h>

namespace bst = boost;
namespace bc = bst::container;

#ifdef NUKEENGINE_EXPORTS
#ifdef NUKEENGINE_API
#undef NUKEENGINE_API
#endif
#define NUKEENGINE_API __declspec(dllexport)
#include <boost/config.hpp>
//
//template<typename T> class
//NUKEENGINE_API Func : bst::function<T> {};
//template<typename T> class
//NUKEENGINE_API List : public bc::list<T> {};
//template class bst::function<void(int, int)>;
//template class bst::function<void(int, int, int, int)>;
//template class bst::function<void(int, int, int)>;
//template class bst::function<void(unsigned char, int, int)>;
#else
#define NUKEENGINE_API __declspec(dllimport)
#endif

#ifdef _WINDOWS
#define strdup _strdup
#endif

// This class is exported from the dll
class NUKEENGINE_API CNukeEngine {
public:
	CNukeEngine(void);
	// TODO: add your methods here.
};

extern NUKEENGINE_API int nNukeEngine;

NUKEENGINE_API int fnNukeEngine(void);
#endif