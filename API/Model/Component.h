#pragma once
#ifndef NUKEE_COMPONENT_H
#define NUKEE_COMPONENT_H
class GameObject;
class Transform;
class Script;
class Camera;
class Light;


class NukeComponent
{
public:
    bool enabled = true;
	Transform* transform;
	GameObject* gameobject;
    char* name;
    NukeComponent(char* _name = "NukeComponent") : name(_name){}
	virtual void Init(GameObject* parent) = 0;
	virtual void Destroy() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Pause() = 0;
	virtual void Reset() = 0;

};
#endif
