#pragma once
#ifndef NUKEE_EDITOR_INSTANCE_H
#define NUKEE_EDITOR_INSTANCE_H
#include "AppInstance.h"
#include <boost/container/list.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/container/map.hpp>

namespace bc = boost::container;
namespace bst = boost;
namespace btups = boost::tuples;

NUKEENGINE_API class EditorInstance;

class EditorInstance : public AppInstance
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
