#pragma once
#ifndef NUKEE_MESH_H
#define NUKEE_MESH_H
#include "Transform.h"
#include "Material.h"
#include <assimp/mesh.h>
#include <boost/container/list.hpp>
#include <memory>

namespace bc = boost::container;

class NUKEENGINE_API Mesh
{
public:
    char name[256];
    float *vertexArray;
    float *normalArray;
    float *uvArray;

    int numVerts;
    bc::list<Mesh*> children;


	Mesh();

	void ImportAIMesh(aiMesh* mesh);
};
#endif // !NUKEE_MESH_H
