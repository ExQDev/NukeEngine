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
	T* GetComponent(){
		std::cout << "This gameobject: " << this << "; components: " << &components << std::endl;
		for (auto cmp : components)
			if (auto res = dynamic_cast<T*>(cmp))
				return res;
		return nullptr;
	}
	
	
	template<class T>
	bc::list<T*> GetComponents() {
		bc::list<T*> lst;
		for (auto cmp : components)
			if (auto res = dynamic_cast<T*>(cmp))
				lst.push_back(res);
		return lst;
	}

	void AddComponent(NukeComponent* cmp);

	void Init(GameObject* parent);
	void FixedUpdate();
	void Update();

	void SetParent(GameObject* newparent);

	void AddChild(GameObject* newChild);

    template <class T>
	void Update() {
		for (auto c : children) {
			if (auto mr = c->GetComponent<T>())
				mr->Update();
		}
	}

	void Reset();
	void Pause();
	void Destroy();

private:

};
#endif // !NUKEE_GAMEOBJECT_H
