#include "API/Model/Scene.h"

GameObject* Scene::Get(std::string name)
{
	for (auto go : hierarchy)
		if (go->name == name)
			return go;
	return nullptr;
}

void Scene::Add(GameObject* go)
{
	hierarchy.push_back(go);
}

void Scene::Start()
{

}

void Scene::Update()
{
	for (GameObject* go : hierarchy)
	{
		go->Update();
	}
}