#pragma once
#include "NukeEngine.hpp"
#ifndef NUKEE_VECTOR_H
#define NUKEE_VECTOR_H
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>

NUKEENGINE_API class Vector2;
NUKEENGINE_API class Vector3;
NUKEENGINE_API class Vector4;
NUKEENGINE_API class Quaternion;

class Vector2
{
public:
	double x, y;

	Vector2();
	Vector2(double x, double y);

	double abs();
	Vector2 normalize();

	Vector2 operator+(Vector2 other);
	Vector2 operator+=(Vector2 other);
	Vector2 operator-(Vector2 other);
	Vector2 operator-=(Vector2 other);
	Vector2 operator*(Vector2 other);
	Vector2 operator*=(Vector2 other);
	Vector2 operator*(double other);
	Vector2 operator*=(double other);
	Vector2 operator/(Vector2 other);
	Vector2 operator/=(Vector2 other);
	Vector2 operator/(double other);
	Vector2 operator/=(double other);

	std::string toStringA();
	std::wstring toStringW();

    class Vector3 toVector3();
    class Vector4 toVector4();
};

class Vector3 : public Vector2
{
public:
	double z;

	Vector3();
	Vector3(double x, double y, double z);

	static const Vector3 forward; 
	static const Vector3 backward;
	static const Vector3 up;
	static const Vector3 left;
	static const Vector3 right;
	static const Vector3 down;
	static const Vector3 zero;
	static const Vector3 one;

	double abs();
	Vector3 normalize();

	Vector3 operator+(Vector2 other);
	Vector3 operator+(Vector3 other);
	Vector3 operator+=(Vector2 other);
	Vector3 operator+=(Vector3 other);
	Vector3 operator-(Vector2 other);
	Vector3 operator-(Vector3 other);
	Vector3 operator-=(Vector2 other);
	Vector3 operator-=(Vector3 other);
	Vector3 operator*(Vector3 other);
	Vector3 operator*=(Vector3 other);
	Vector3 operator/(Vector3 other);
	Vector3 operator/=(Vector3 other);
	Vector3 operator* (double other) const;
	Vector3 operator*=(double other);
	Vector3 operator/(double other);
	Vector3 operator/=(double other);

	std::string toStringA();
	std::wstring toStringW();

    class Vector4 toVector4();
};


class Vector4 : public Vector3
{
public:
	double w;

	Vector4();
	Vector4(double x, double y, double z, double w);
	
	double abs();
	Vector4 normalize();

	Vector4 operator+(Vector2 other);
	Vector4 operator+(Vector3 other);
	Vector4 operator+(Vector4 other);
	Vector4 operator+=(Vector2 other);
	Vector4 operator+=(Vector3 other);
	Vector4 operator+=(Vector4 other);
	Vector4 operator-(Vector2 other);
	Vector4 operator-(Vector3 other);
	Vector4 operator-(Vector4 other);
	Vector4 operator-=(Vector2 other);
	Vector4 operator-=(Vector3 other);
	Vector4 operator-=(Vector4 other);
	Vector4 operator*(Vector4 other);
	Vector4 operator*=(Vector4 other);
	Vector4 operator/(Vector4 other);
	Vector4 operator/=(Vector4 other);
	Vector4 operator*(double other);
	Vector4 operator*=(double other);
	Vector4 operator/(double other);
	Vector4 operator/=(double other);

	std::string toStringA();
	std::wstring toStringW();

    class Color toColor();
};

class Quaternion : public Vector4
{
public:
	Quaternion();
	Quaternion(double x, double y, double z, double w);

	Quaternion operator = (const Quaternion& q);
	Quaternion operator + (const Quaternion& q);
	Quaternion operator - (const Quaternion& q);
	Quaternion operator * (const Quaternion& q);
	Quaternion operator / (Quaternion& q);
	Quaternion operator += (const Quaternion& q);
	Quaternion operator -= (const Quaternion& q);
	Quaternion operator *= (const Quaternion& q);
	Quaternion operator /= (Quaternion& q);
	bool  operator != (const Quaternion& q);
	bool  operator == (const Quaternion& q);
	Quaternion scale(double  s);
	Quaternion inverse();
	Quaternion conjugate();
	double norm();
	double magnitude();
	Quaternion UnitQuaternion();
};


#endif // !NUKEE_VECTOR_H

