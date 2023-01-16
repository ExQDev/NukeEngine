#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Material.h"
#include "Mesh.h"
#ifndef NUKEE_MESHRENDERER_H
#define NUKEE_MESHRENDERER_H

NUKEENGINE_API class MeshRenderer;

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
