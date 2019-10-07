#include "API/Model/ID.h"

ID::ID()
{
	generate();
}

ID::ID(long id)
{
	this->id = id;
}

void ID::generate()
{
	id = reinterpret_cast<long>(this);
}