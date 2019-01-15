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

class EditorInstance : public AppInstance
{
protected:
    EditorInstance() {
        if(!menuStrip)
            menuStrip = new MenuStrip();
    }
	~EditorInstance() {}

public:
    bool isEditor(){ return true; }
	MenuStrip* menuStrip;
	GameObject* selectedInHieararchy;
    int manipulationMode = 0;
    int manipulationWorld = 0;
    //bc::list<btups::tuple<string, b::function<void()>>> editorWindows;
    bc::map<string, b::function<void()>> editorWindows;

    void PushWindow(string key, boost::function<void()> fWindow){
        for(auto tup: GetSingleton()->editorWindows){
            if(tup.first.compare(key) == 0)
                throw std::runtime_error("Window key must be unique!");
        }
        cout << "Pushing window \"" << key << "\"" << endl;
        editorWindows.insert(make_pair(key, fWindow));
    }

    void PopWindow(string key){
        editorWindows.erase(key);
    }

	static EditorInstance* GetSingleton() 
	{
		static EditorInstance instance;
		return &instance;
	}
};

#endif // !NUKEE_EDITOR_INSTANCE_H
