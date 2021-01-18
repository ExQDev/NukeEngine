#include "API/Model/GameObject.h"
#include <iostream>

using namespace std;

GameObject::GameObject() : transform(this)
{}

GameObject::GameObject(const char* name) : name(name), transform(this)
{
	cout << "[GameObject]\t\t" << "New GameObject(\"" << name << "\")" << endl;
}

GameObject::~GameObject() {}

std::string GameObject::GetName()
{
	return this->name;
}

std::string GameObject::GetTag()
{
	return this->tag;
}

void GameObject::SetName(const char* name)
{
	this->name = name;
}

void GameObject::SetTag(const char* tag)
{
	this->tag = tag;
}

Transform& GameObject::GetTransform()
{
	return transform;
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
	{
		cout << "[GameObject]\t\t" << "Child update: " << child << ", " << child->name << endl;
		if (child)
			child->Update();
	}
	for (auto cmp : components)
	{
		cout << "[GameObject]\t\t" << "Component update: " << cmp << endl;
		if(cmp)
			cmp->Update();
	}
}

void GameObject::SetParent(GameObject* newparent) {
	newparent->children.push_back(this);
	parent = newparent;
}

GameObject* GameObject::GetParent()
{
	return this->parent;
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
	parent->children.remove(this);
	free(this);
}