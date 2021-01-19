#pragma once
#ifndef NUKEE_GAMEOBJECT_H
#define NUKEE_GAMEOBJECT_H
#include <boost/container/list.hpp>
namespace bc = boost::container;

#include "Transform.h"
#include "Layers.h"
#include "ID.h"
//
//template class bc::list<NukeComponent*>;
//template class bc::list<GameObject*>;

#pragma pack(push, 1)
class GameObject
{
protected:
	

public:
	
	std::string name = "GameObject";
	std::string tag = "Untagged";
	GameObject* parent = nullptr;
	Transform transform = Transform(this);
	
	ID id;
	
	int layer = Layer::L_DEFAULT;

    bc::list<NukeComponent*> components = bc::list<NukeComponent*>();
    bc::list<GameObject*> children = bc::list<GameObject*>();

	GameObject();
	GameObject(const char* name);
	~GameObject();


	std::string GetName();
	std::string GetTag();
	void SetName(const char* name);
	void SetTag(const char* tag);
	Transform& GetTransform();
	
	template<class T>
	T* GetComponent(){
		for (NukeComponent* cmp : this->components)
		{
			std::cout << "[GameObject]\t\t" << cmp << std::endl;
			if (auto res = dynamic_cast<T*>(cmp))
				return res;
		}
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
	GameObject* GetParent();

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
#pragma pack(pop)
#endif // !NUKEE_GAMEOBJECT_H
