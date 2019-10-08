#include "API/Model/GameObject.h"

GameObject::GameObject(std::string name)
{
	this->name = name;
	this->gameobject = this;
	this->transform = transform;
}

GameObject::~GameObject() {}

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