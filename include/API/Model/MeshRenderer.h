#pragma once
#ifndef NUKEE_MESHRENDERER_H
#define NUKEE_MESHRENDERER_H
#include "API/Model/Include.h"

class MeshRenderer : public NukeComponent
{

public:
    Mesh        *mesh;
    Material    *mat;

	MeshRenderer();

	void Init(GameObject* parent);

	void Destroy();

	void Update();

	void FixedUpdate();

	void Pause();

	void Reset();

};
#endif // !NUKEE_MESHRENDERER_h
