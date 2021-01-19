#pragma once
#ifndef NUKEE_TRANSFORM_H
#define NUKEE_TRANSFORM_H

#include "Component.h"
#include "Vector.h"

class Transform : public NukeComponent
{
public:
	Vector3 position;
    Vector3 rotation;
    Vector3 scale = {1,1,1};
    GameObject *go = nullptr;

	Transform(GameObject* parent);
	void Init(GameObject* parent);

	Vector3 forward();
	Vector3 right();
	Vector3 up();
	Vector3 direction();
    Vector3 globalPosition();
	Vector3 globalRotation();
	Vector3 globalScale();

	void Destroy();
	void Update();
	void FixedUpdate();
	void Pause();
	void Reset();
};

#endif // !NUKEE_TRANSFORM_H
