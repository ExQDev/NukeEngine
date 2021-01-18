#include "API/Model/MeshRenderer.h"
#include <render/irender.h>

MeshRenderer::MeshRenderer() : NukeComponent("MeshRenderer") {}

void MeshRenderer::Init(GameObject* parent) {
	transform = &parent->GetTransform();
	parent->components.push_back(this);
}

void MeshRenderer::Destroy() {

}

void MeshRenderer::Update() {
	if (enabled)
		iRender::getSingleton()->renderObject(mesh, mat, transform);
}

void MeshRenderer::FixedUpdate() {}

void MeshRenderer::Pause() {}

void MeshRenderer::Reset() {
	mesh = nullptr;
}