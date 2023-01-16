#include "API/Model/Texture.h"
#include <cstring>
#include <memory>

Texture::Texture(char* path) {
    strcpy(this->path, path);

}

Texture::Texture() {}
