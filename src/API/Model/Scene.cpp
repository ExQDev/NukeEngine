#include "API/Model/Scene.h"
#include <iostream>

Scene::Scene() : name("Default scene"), hierarchy(new bc::list<GameObject*>()) {
	std::cout << "[Scene]\t\t\t" << "This:" << this << ", Hierarchy is " << hierarchy << ", Hierarchy size: " << hierarchy->size() << std::endl;
}

GameObject* Scene::Get(const char* name)
{
	for (auto go : GetHierarchy())
		if (go->GetName() == name)
			return go;
	return nullptr;
}

bc::list<GameObject*>& Scene::GetHierarchy()
{
	return *hierarchy;
}

void Scene::Add(GameObject* go)
{
	hierarchy->push_back(go);
}

void Scene::Start()
{

}

void Scene::Update()
{
	for (GameObject* go : *hierarchy)
	{
		go->Update();
	}
}