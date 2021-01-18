#pragma once
#ifndef NUKEE_SCENE_H
#define NUKEE_SCENE_H
#include "GameObject.h"
#include <memory>

class NUKEENGINE_API Scene
{
protected:
	bc::list<GameObject*> *hierarchy = nullptr;
public:
	std::string name = "Default scene";
    

	Scene();

	GameObject* Get(const char* name);
	bc::list<GameObject*>& GetHierarchy();
	void Add(GameObject* go);

	void Start();

	void Update();
};

#endif // !NUKEE_SCENE_H
