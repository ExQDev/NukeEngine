#ifndef ASSIMPORTER_H
#define ASSIMPORTER_H
#include <iostream>
#include <assimp/Importer.hpp>
#include <assimp/mesh.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <API/Model/resdb.h>
#include <API/Model/MeshRenderer.h>

using namespace std;

class NUKEENGINE_API AssImporter
{
	AssImporter();
	~AssImporter();

	GameObject* ImportObject(aiNode* node, const aiScene* scene);
	void Import(const char* path);
};
#endif // ASSIMPORTER_H
