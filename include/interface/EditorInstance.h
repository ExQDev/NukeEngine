#pragma once
#ifndef NUKEE_EDITOR_INSTANCE_H
#define NUKEE_EDITOR_INSTANCE_H
#include "AppInstance.h"
#include "EditorMenu/MenuStrip.h"
#include <boost/container/list.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/container/map.hpp>

namespace bc = boost::container;
namespace b = boost;
namespace btups = boost::tuples;

class NUKEENGINE_API EditorInstance
{
protected:
	EditorInstance();
	~EditorInstance();

public:
	bool isEditor();
	

	static EditorInstance* GetSingleton() 
	{
		static EditorInstance instance;
		/*if (!instance.currentScene)
			instance.currentScene = new Scene();
		if (!instance.currentScene->hierarchy)
			instance.currentScene->hierarchy = new bc::list<GameObject*>();*/
		return &instance;
	}
};

#endif // !NUKEE_EDITOR_INSTANCE_H
