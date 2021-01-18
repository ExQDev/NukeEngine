#pragma once
#ifndef NUKEE_APPINSTANCE_H
#define NUKEE_APPINSTANCE_H
#include <boost/thread.hpp>
#include <boost/container/list.hpp>
#include <boost/container/map.hpp>
#include <config.h>
#include "../API/Model/Camera.h"
#include "../API/Model/Scene.h"
#include "../input/keyboard.h"
#include "../input/mouse.h"
#include "../render/irender.h"
#include "../render/opengl/nukeogl.h"
#include "./EditorMenu/MenuStrip.h"

namespace bc = boost::container;

class NUKEENGINE_API AppInstance
{
protected:
	AppInstance();
	~AppInstance();
	bool _isEditor = false;
public:
	
	MenuStrip* menuStrip = nullptr;
	GameObject* selectedInHieararchy = nullptr;
	int manipulationMode = 0;
	int manipulationWorld = 0;
	//bc::list<btups::tuple<string, b::function<void()>>> editorWindows;
	bc::map<string, b::function<void()>>* editorWindows = nullptr;

	void PushWindow(const char* key, boost::function<void()> fWindow);

	//void PushWindow(string &key, boost::function<void()> fWindow);
	void PopWindow(string key);



	Scene* currentScene = new Scene();
    KeyBoard* keyboard = nullptr;
    Mouse* mouse = nullptr;
	Config* config = nullptr;
    iRender* render = nullptr;

	bool isEditor();
	void setEditor(bool editor);

	static AppInstance* GetSingleton() 
	{
		static AppInstance instance;
		return &instance;
	}
	
	void UpdateThread();
	void StartUpdateThread();
};

#endif // !NUKEE_APPINSTANCE_H
