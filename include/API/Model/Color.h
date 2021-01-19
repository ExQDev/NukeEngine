#pragma once
#ifndef NUKEE_COLOR_H
#define NUKEE_COLOR_H
class Color
{
public:
	double r, g, b, a;

	Color();
	Color(double r, double g, double b, double a);


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
