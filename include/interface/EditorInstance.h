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

class NUKEENGINE_API EditorInstance : public AppInstance
{
protected:
	EditorInstance();
	~EditorInstance();

public:
	bool isEditor();
	MenuStrip* menuStrip;
	GameObject* selectedInHieararchy;
    int manipulationMode = 0;
    int manipulationWorld = 0;
    //bc::list<btups::tuple<string, b::function<void()>>> editorWindows;
    bc::map<string, b::function<void()>> *editorWindows;

	void PushWindow(string key, boost::function<void()> fWindow);
	void PopWindow(string key);

	static EditorInstance* GetSingleton() 
	{
		static EditorInstance instance;
		return &instance;
	}
};

#endif // !NUKEE_EDITOR_INSTANCE_H
