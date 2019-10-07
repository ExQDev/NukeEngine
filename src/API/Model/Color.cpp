#include "API/Model/Color.h"
#include "API/Model/Vector.h"

float r, g, b, a;

Color::Color() {}
Color::Color(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}


Color Color::operator+(Color other)
{
	Color tmp = Color(other.r + r, other.g + g, other.b + b, other.a + a);
	return tmp;
}

Color Color::operator+=(Color other)
{
	a += other.a; b += other.b; g += other.g; r += other.r;
	return *this;
}

Color Color::operator-(Color other)
{
	Color tmp = Color(r - other.r, g - other.g, b - other.b, a - other.a);
	return tmp;
}

Color Color::operator-=(Color other)
{
	a -= other.a; b -= other.b; g -= other.g; r -= other.r;
	return *this;
}

Color Color::operator*(Color other)
{
	Color tmp = Color(r * other.r, g * other.g, b * other.b, a * other.a);
	return tmp;
}

Color Color::operator*=(Color other)
{
	a *= other.a; b *= other.b; g *= other.g; r *= other.r;
	return *this;
}

Color Color::operator/(Color other)
{
	Color tmp = Color(r / other.r, g / other.g, b / other.b, a / other.a);
	return tmp;
}

Color Color::operator/=(Color other)
{
	a /= other.a; b /= other.b; g /= other.g; r /= other.r;
	return *this;
}

Color Color::operator*(double other)
{
	Color tmp = Color(r - other, g - other, b - other, a - other);
	return tmp;
}

Color Color::operator*=(double other)
{
	a *= other; b *= other; g *= other; r *= other;
	return *this;
}

Color Color::operator/(double other)
{
	Color tmp = Color(r / other, g / other, b / other, a / other);
	return tmp;
}

Color Color::operator/=(double other)
{
	a /= other; b /= other; g /= other; r /= other;
	return *this;
}

Vector4 Color::toVector4()
{
	return Vector4(r, g, b, a);
}