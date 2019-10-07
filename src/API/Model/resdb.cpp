#include "API/Model/resdb.h"

std::shared_ptr<uint> ResDB::loadTexture(const std::string& name)
{
	Texture* i = nullptr;
	for (auto t : textures) {
		if (strcmp(t->path, name.c_str()) == 0)
			i = t;
	}
	if (i == nullptr) {
		i = new Texture();
	}

	// TODO: return not empty
	return std::shared_ptr<uint>();
}