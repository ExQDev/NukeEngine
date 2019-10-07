#include "API/Model/GameObject.h"

GameObject::GameObject(std::string name)
{
	this->name = name;
	this->gameobject = this;
	this->transform = transform;
}
GameObject::~GameObject() {}


template<class T>
T* GameObject::GetComponent()
{
	for (auto cmp : components)
		if (auto res = dynamic_cast<T*>(cmp))
			return res;
	return nullptr;
}


template<class T>
bc::list<T*> GameObject::GetComponents()
{
	bc::list<T*> lst;
	for (auto cmp : components)
		if (auto res = dynamic_cast<T*>(cmp))
			lst.push_back(res);
	return lst;
}

void GameObject::AddComponent(NukeComponent* cmp) {
	cmp->Init(this);
}

void GameObject::Init(GameObject* parent)
{
	this->parent = parent;
}
void GameObject::FixedUpdate() {}
void GameObject::Update()
{
	for (auto child : children)
		child->Update();
	for (auto cmp : components)
		cmp->Update();
}

void GameObject::SetParent(GameObject* newparent) {
	newparent->children.push_back(this);
	parent = newparent;
}

void GameObject::AddChild(GameObject* newChild) {
	children.push_back(newChild);
	newChild->parent = this;
}

template <class T>
void GameObject::Update() {
	for (auto c : children) {
		if (auto mr = c->GetComponent<T>())
			mr->Update();
	}
}

void GameObject::Reset() {}
void GameObject::Pause() {}
void GameObject::Destroy()
{
	for (auto x : children)
	{
		x->Destroy();
	}
	parent->gameobject->children.remove(this);
	delete this;
}