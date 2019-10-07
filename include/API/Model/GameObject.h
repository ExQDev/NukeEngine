#pragma once
#ifndef NUKEE_GAMEOBJECT_H
#define NUKEE_GAMEOBJECT_H
#include <boost/container/list.hpp>
namespace bc = boost::container;

#include "Transform.h"
#include "Layers.h"
#include "ID.h"

class NUKEENGINE_API GameObject : public NukeComponent
{
public:
	Transform transform = { this };
    GameObject* parent = nullptr;
	ID id;
	std::string name = "GameObject";
	std::string tag = "Untagged";
	int layer = Layer::L_DEFAULT;

    bc::list<NukeComponent*> components;
    bc::list<GameObject*> children;

	GameObject(std::string name);
	~GameObject();


	template<class T>
	T* GetComponent();
	
	
	template<class T>
	bc::list<T*> GetComponents();

	void AddComponent(NukeComponent* cmp);

	void Init(GameObject* parent);
	void FixedUpdate();
	void Update();

	void SetParent(GameObject* newparent);

	void AddChild(GameObject* newChild);

    template <class T>
	void Update();

	void Reset();
	void Pause();
	void Destroy();

private:

};
#endif // !NUKEE_GAMEOBJECT_H
