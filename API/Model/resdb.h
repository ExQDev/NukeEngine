#ifndef RESDB_H
#define RESDB_H
#include "Mesh.h"
#include "Texture.h"
#include "Material.h"
#include "Shader.h"
#include "GameObject.h"
#include <boost/container/list.hpp>
#include <memory>

namespace bc = boost::container;

class ResDB
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

    std::shared_ptr<uint> loadTexture(const std::string& name)
    {
        Texture* i = nullptr;
        for(auto t : textures){
            if(strcmp(t->path, name.c_str()) == 0)
                i = t;
        }
        if(i == nullptr){
            i = new Texture();
        }



    }
};
#endif // RESDB_H
