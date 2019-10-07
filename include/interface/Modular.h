#pragma once
#ifndef NUKE_MODULAR_H
#define NUKE_MODULAR_H
#include <interface/NUKEEInteface.h>

#include <interface/EditorInstance.h>

#define BOOST_FILESYSTEM_VERSION 3
#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/filesystem.hpp>
namespace bfs = boost::filesystem;

#include <boost/container/vector.hpp>
namespace bc = boost::container;


#include <boost/dll.hpp>
#include <boost/thread.hpp>

#ifdef USE_WINAPI
#include <Windows.h>
#endif // USE_WINAPI

bc::vector<boost::shared_ptr<NUKEModule>> modules;
//NUKEENGINEAPI void InitModules(EditorInstance* instance);
//NUKEENGINEAPI void UnloadModules();

NUKEENGINE_API void InitModules(EditorInstance* instance);
NUKEENGINE_API void UnloadModules();
#endif // !NUKE_MODULAR_H

