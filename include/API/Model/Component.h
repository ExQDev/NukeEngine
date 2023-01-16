#pragma once
#ifndef NUKEE_COMPONENT_H
#define NUKEE_COMPONENT_H
#include "NukeEngine.hpp"

class GameObject;
class Transform;
class Script;
class Camera;
class Light;

NUKEENGINE_API class NukeComponent;

class NukeComponent
{
public:
    bool enabled = true;
	Transform* transform = nullptr;
	GameObject* gameobject = nullptr;
    char* name;
    NukeComponent(const char* _name = "NukeComponent") : name((char*)_name){}
	virtual void Init(GameObject* parent) = 0;
	virtual void Destroy() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Pause() = 0;
	virtual void Reset() = 0;

};
#endif
