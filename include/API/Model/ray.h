#ifndef RAY_H
#define RAY_H
#include "Vector.h"
#include "Collider.h"

struct Ray
{
    Vector3 start;
    Vector3 direction;
    double length;
    int w, h;

	Ray();
	bool Collide(Collider collider);
};

#endif // RAY_H
