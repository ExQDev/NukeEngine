#pragma once
#ifndef NUKEE_LIGHT_H
#define NUKEE_LIGHT_H
#include "Component.h"
#include "Color.h"

NUKEENGINE_API class Light;

class Light : public NukeComponent
{
	enum LightType 
	{
		directional,
		point,
		area,
		spot
	};
public:
	float intensity, brightness;
	Color color;
	LightType lightType = LightType::directional;
};
#endif // !NUKEE_LIGHT_H
