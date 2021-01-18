#include "import/assimporter.h"

AssImporter::AssImporter() {}
AssImporter::~AssImporter() {}

GameObject* AssImporter::ImportObject(aiNode* node, const aiScene* scene) {
	ResDB* res = ResDB::getSingleton();
	auto go = new GameObject(node->mName.C_Str());
	for (int i = 0; i < node->mNumMeshes; i++) {
		auto cmesh = node->mMeshes[i];
		GameObject* ngo = new GameObject(scene->mMeshes[cmesh]->mName.C_Str());
		Mesh* m = new Mesh();
		m->ImportAIMesh(scene->mMeshes[cmesh]);
		res->meshes.push_back(m);

		Material* mat = new Material();
		mat->ImportAiMaterial(scene->mMaterials[scene->mMeshes[cmesh]->mMaterialIndex]);
		ResDB::getSingleton()->materials.push_back(mat);

		MeshRenderer* mr = new MeshRenderer();
		mr->mesh = m;
		mr->mat = mat;
		ngo->AddComponent(mr);
		go->AddChild(ngo);
	}
	for (int i = 0; i < node->mNumChildren; i++) {
		go->AddChild(ImportObject(node->mChildren[i], scene));
	}
	return go;
}

void AssImporter::Import(const char* path) {

	Assimp::Importer importer;
	ResDB* res = ResDB::getSingleton();
	const aiScene* sc = importer.ReadFile(path, aiProcessPreset_TargetRealtime_MaxQuality);
	if (!sc)
	{
		cout << importer.GetErrorString() << endl;
		return;
	}

	// ================================================================

	std::cout << sc->HasAnimations() << " " << sc->mNumAnimations << std::endl;
	std::cout << sc->HasCameras() << " " << sc->mNumCameras << std::endl;
	std::cout << sc->HasLights() << " " << sc->mNumLights << std::endl;
	std::cout << sc->HasMaterials() << " " << sc->mNumMaterials << std::endl;
	std::cout << sc->HasMeshes() << " " << sc->mNumMeshes << std::endl;
	std::cout << sc->HasTextures() << " " << sc->mNumTextures << std::endl;

	// ================================================================

	if (sc->HasTextures()) {
		cout << "SCENE HAS TExtURES" << endl;
		for (int i = 0; i < sc->mNumTextures; ++i) {
			//cout << "TNAME: " << sc->mTextures[i]->mFilename.C_Str() << endl;
		}
	}
	res->prefabs.push_back(ImportObject(sc->mRootNode, sc));

}