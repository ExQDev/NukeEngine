#pragma once
#ifndef NUKEE_APPINSTANCE_H
#define NUKEE_APPINSTANCE_H
#include <boost/thread.hpp>
#include <config.h>
#include "../API/Model/Camera.h"
#include "../API/Model/Scene.h"
#include "../input/keyboard.h"
#include "../input/mouse.h"
#include "../render/irender.h"
#include "../render/opengl/nukeogl.h"

class NUKEENGINE_API AppInstance
{
protected:
	AppInstance();
	~AppInstance();
public:
	
	Scene* currentScene = nullptr;
    KeyBoard* keyboard = nullptr;
    Mouse* mouse = nullptr;
	Config* config = nullptr;
    iRender* render = nullptr;

	virtual bool isEditor();
	static AppInstance* GetSingleton() 
	{
		static AppInstance instance;
		return &instance;
	}
	
	void UpdateThread();
	void StartUpdateThread();
};

#endif // !NUKEE_APPINSTANCE_H
