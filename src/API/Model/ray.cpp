#include "API/Model/ray.h"
#include <glm/glm.hpp>

Ray::Ray() {}
bool Ray::Collide(Collider collider) {
	glm::vec4 viewport = glm::vec4(0, 0, w, h);
	glm::vec3 wincoord = glm::vec3(start.x, start.y, start.z);
	//        glm::vec3 objcoord = glm::unProject(wincoord, view, projection, viewport);
	return false;
}