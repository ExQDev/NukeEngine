#ifndef RESDB_H
#define RESDB_H
#include "Mesh.h"
#include "Texture.h"
#include "Material.h"
#include "Shader.h"
#include "GameObject.h"
#include <boost/container/list.hpp>
#include <memory>

#ifdef WIN32
#define uint unsigned int
#endif

namespace bc = boost::container;

class NUKEENGINE_API ResDB
{
    ResDB() {}
    ~ResDB() {}
public:
    bc::list<Mesh*> meshes;
    bc::list<Texture*> textures;
    bc::list<Material*> materials;
    bc::list<Shader*> shaders;
    bc::list<GameObject*> prefabs;

    static ResDB* getSingleton(){
        static ResDB instance;
        return &instance;
    }

	std::shared_ptr<uint> loadTexture(const std::string& name);
};
#endif // RESDB_H
