#pragma once
#include "NukeEngine.hpp"
#ifndef NUKEE_TEXTURE_H
#define NUKEE_TEXTURE_H

NUKEENGINE_API class Texture;

class Texture
{
public:
    unsigned int id;
    char name[64];
    char path[1024];

	Texture(char* path);

	Texture();
};
#endif // !NUKEE_TEXTURE_H
