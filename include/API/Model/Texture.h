#pragma once
#ifndef NUKEE_TEXTURE_H
#define NUKEE_TEXTURE_H

class NUKEENGINE_API Texture
{
public:
    unsigned int id;
    char name[64];
    char path[1024];

	Texture(char* path);

	Texture();
};
#endif // !NUKEE_TEXTURE_H
