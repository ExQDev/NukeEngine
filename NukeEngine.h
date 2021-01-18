// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the NUKEENGINE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// NUKEENGINE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifndef NUKEENGINE_H
#define NUKEENGINE_H
#include <cmath>
#include <algorithm>
#include <boost/function.hpp>
#include <boost/container/list.hpp>
#include <string.h>

namespace b = boost;
namespace bc = boost::container;

#ifdef NUKEENGINE_EXPORTS
#ifdef NUKEENGINE_API
#undef NUKEENGINE_API
#endif
#define NUKEENGINE_API __declspec(dllexport)
#include <boost/config.hpp>

template<typename T> class
NUKEENGINE_API Func : b::function<T> {};
template<typename T> class
NUKEENGINE_API List : bc::list<T> {};
//template class NUKEENGINE_API b::function<void(int, int)>;
//template class NUKEENGINE_API b::function<void(int, int, int, int)>;
//template class NUKEENGINE_API b::function<void(int, int, int)>;
//template class NUKEENGINE_API b::function<void(unsigned char, int, int)>;
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