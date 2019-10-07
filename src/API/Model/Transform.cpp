#include "API/Model/Transform.h"
#include "API/Model/GameObject.h"
#include "API/Model/Vector.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>

#define _USE_MATH_DEFINES // for C
#include <math.h>

Transform::Transform(GameObject* parent)
{
	Init(parent);
}

void Transform::Init(GameObject* parent)
{
	go = parent;
}

Vector3 Transform::forward()
{
	return direction();
}

Vector3 Transform::right()
{
	return Vector3{ cos(rotation.y - M_PI_2),
				0,
				sin(rotation.y - M_PI_2) } *-1.0;
}

Vector3 Transform::up()
{
	auto r = right(),
		d = direction();
	auto u = glm::cross(glm::vec3{ r.x, r.y, r.z }, { d.x, d.y, d.z });
	return { u.x, u.y, u.z };
}

Vector3 Transform::direction() {
	return Vector3(cos(rotation.y) * cos(rotation.x),
		sin(rotation.x),
		cos(rotation.x) * sin(rotation.y));
}


void Transform::Destroy()
{

}

void Transform::Update()
{

}

void Transform::FixedUpdate()
{

}

void Transform::Pause()
{

}

void Transform::Reset()
{
	position = Vector3::zero;
	rotation = { 0,0,0 };
	scale = Vector3::one;
}



Vector3 Transform::globalPosition() {
	//    cout << "GO: " << this->go << endl;
	//    cout << "GO PARENT: " << this->go->parent << endl;
	//    cout << "GO PARENT POS: " << this->go->parent->transform.position.toStringA() << endl;
	return Vector3((this->go != nullptr && this->go->parent != nullptr)
		? (this->position + this->go->parent->transform.globalPosition())
		: (this->position));
}

Vector3 Transform::globalRotation() {
	return Vector3((this->go->parent) ? (this->rotation + this->go->parent->transform.globalRotation()) : (this->rotation));
}

Vector3 Transform::globalScale() {
	return Vector3((this->go->parent) ? (this->scale * this->go->parent->transform.globalScale()) : (this->scale));
}