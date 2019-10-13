#pragma once
#ifndef NUKEE_SCENE_H
#define NUKEE_SCENE_H
#include "GameObject.h"

class NUKEENGINE_API Scene
{
public:
	std::string name = "Default scene";
    bc::list<GameObject*> *hierarchy = nullptr;

	Scene();

	GameObject* Get(const char* name);

	void Add(GameObject* go);

	void Start();

	void Update();
};

#endif // !NUKEE_SCENE_H
