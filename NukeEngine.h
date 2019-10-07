// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the NUKEENGINE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// NUKEENGINE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifndef NUKEENGINE_H
#define NUKEENGINE_H
#ifdef NUKEENGINE_EXPORTS
#define NUKEENGINE_API __declspec(dllexport)
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