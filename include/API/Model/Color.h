#pragma once
#ifndef NUKEE_COLOR_H
#define NUKEE_COLOR_H
class NUKEENGINE_API Color
{
public:
	float r, g, b, a;

	Color();
	Color(float r, float g, float b, float a);


	Color operator+(Color other);

	Color operator+=(Color other);

	Color operator-(Color other);

	Color operator-=(Color other);

	Color operator*(Color other);

	Color operator*=(Color other);

	Color operator/(Color other);

	Color operator/=(Color other);

	Color operator*(double other);

	Color operator*=(double other);

	Color operator/(double other);

	Color operator/=(double other);

    class Vector4 toVector4();
};
#endif // !NUKEE_COLOR_H
