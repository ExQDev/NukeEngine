#include "API/Model/Material.h"

void Material::ImportAiMaterial(aiMaterial* m) {
	aiString diffName;
	m->GetTexture(aiTextureType::aiTextureType_DIFFUSE, 0, &diffName);
	cout << "DIFF_NAME: " << diffName.C_Str() << endl;
	if (diffName.length > 0)
	{
		diff = new Texture(diffName.data);
	}

	aiString normName;
	m->GetTexture(aiTextureType::aiTextureType_NORMALS, 0, &normName);
	cout << "NORM_NAME: " << normName.C_Str() << endl;
	if (normName.length > 0)
	{
		norm = new Texture(normName.data);
	}

	aiString specName;
	m->GetTexture(aiTextureType::aiTextureType_SPECULAR, 0, &specName);
	cout << "SPEC_NAME: " << specName.C_Str() << endl;
	if (specName.length > 0)
	{
		spec = new Texture(specName.data);
	}

	aiMat = m;
}