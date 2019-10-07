#pragma once
#ifndef NUKEE_MATERIAL_H
#define NUKEE_MATERIAL_H
#include <iostream>
#include "Texture.h"
#include "Shader.h"
#include <assimp/material.h>

using namespace std;

class NUKEENGINE_API Material
{
public:
    char* name;
    Texture* diff = nullptr;
    Texture* norm = nullptr;
    Texture* spec = nullptr;

    Shader* shader;
    aiMaterial* aiMat;

	void ImportAiMaterial(aiMaterial* m);
};
#endif // !NUKEE_MATERIAL_H
