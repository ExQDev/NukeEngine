// NukeEngine.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "NukeEngine.h"


// This is an example of an exported variable
NUKEENGINE_API int nNukeEngine=0;

// This is an example of an exported function.
NUKEENGINE_API int fnNukeEngine(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CNukeEngine::CNukeEngine()
{
    return;
}
