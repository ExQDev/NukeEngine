#include "API/Model/Vector.h"
#include "API/Model/Color.h"
#include <sstream>


Vector2::Vector2() {}
Vector2::Vector2(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Vector2::abs()
{
	return sqrt(x * x + y * y);
}
Vector2 Vector2::normalize()
{
	return *this / this->abs();
}

Vector2 Vector2::operator+(Vector2 other)
{
	auto _x = x + other.x;
	auto _y = y + other.y;
	return Vector2(_x, _y);
}

Vector2 Vector2::operator+=(Vector2 other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector2 Vector2::operator-(Vector2 other)
{
	auto _x = x - other.x;
	auto _y = y - other.y;
	return Vector2(_x, _y);
}

Vector2 Vector2::operator-=(Vector2 other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2 Vector2::operator*(Vector2 other)
{
	auto _x = x * other.x;
	auto _y = y * other.y;
	return Vector2(_x, _y);
}

Vector2 Vector2::operator*=(Vector2 other)
{
	x *= other.x;
	y *= other.y;
	return *this;
}

Vector2 Vector2::operator*(double other)
{
	auto _x = x * other;
	auto _y = y * other;
	return Vector2(_x, _y);
}

Vector2 Vector2::operator*=(double other)
{
	x *= other;
	y *= other;
	return *this;
}

Vector2 Vector2::operator/(Vector2 other)
{
	auto _x = x / other.x;
	auto _y = y / other.y;
	return Vector2(_x, _y);
}

Vector2 Vector2::operator/=(Vector2 other)
{
	x /= other.x;
	y /= other.y;
	return *this;
}

Vector2 Vector2::operator/(double other)
{
	auto _x = x / other;
	auto _y = y / other;
	return Vector2(_x, _y);
}

Vector2 Vector2::operator/=(double other)
{
	x /= other;
	y /= other;
	return *this;
}

std::string Vector2::toStringA()
{
	std::stringstream ss;
	ss << "(" << x << ", " << y << ")";
	return ss.str();
}

std::wstring Vector2::toStringW()
{
	std::wstringstream ss;
	ss << "(" << x << ", " << y << ")";
	return ss.str();
}




Vector3::Vector3() {}
Vector3::Vector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double Vector3::abs()
{
	return sqrt(x * x + y * y + z * z);
}
Vector3 Vector3::normalize()
{
	return *this / this->abs();
}

Vector3 Vector3::operator+(Vector2 other)
{
	//        Vector3 tmp = *static_cast<Vector3*>((Vector2(this->x, this->y) + other));
	return Vector3(this->x + other.x, this->y + other.y, this->z);
}
Vector3 Vector3::operator+(Vector3 other)
{
	//		Vector3 tmp = *static_cast<Vector3*>(&(*static_cast<Vector2*>(this) + (Vector2)other));
	//		tmp.z = z + other.z;
	return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector3 Vector3::operator+=(Vector2 other)
{
	(*static_cast<Vector2*>(this) += other);
	return *this;
}

Vector3 Vector3::operator+=(Vector3 other)
{
	(*static_cast<Vector2*>(this) += (Vector2)other);
	z += other.z;
	return *this;
}

Vector3 Vector3::operator-(Vector2 other)
{
	//        Vector3 tmp = *static_cast<Vector3*>(&(*static_cast<Vector2*>(this) - other));
	//		tmp.z = z;
	return Vector3(this->x - other.x, this->y - other.y, this->z);
}

Vector3 Vector3::operator-(Vector3 other)
{
	//		Vector3 tmp = *static_cast<Vector3*>(&(*static_cast<Vector2*>(this) - (Vector2)other));
	//		tmp.z = z - other.z;
	return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector3 Vector3::operator-=(Vector2 other)
{
	(*static_cast<Vector2*>(this) -= other);
	return *this;
}

Vector3 Vector3::operator-=(Vector3 other)
{
	(*static_cast<Vector2*>(this) -= (Vector2)other);
	z -= other.z;
	return *this;
}

Vector3 Vector3::operator*(Vector3 other)
{
	//		Vector3 tmp = *static_cast<Vector3*>(&(*static_cast<Vector2*>(this) * (Vector2)other));
	//		tmp.z = z * other.z;
	return Vector3(this->x * other.x, this->y * other.y, this->z * other.z);
}

Vector3 Vector3::operator*=(Vector3 other)
{
	(*static_cast<Vector2*>(this) *= (Vector2)other);
	z *= other.z;
	return *this;
}

Vector3 Vector3::operator/(Vector3 other)
{
	//		Vector3 tmp = *static_cast<Vector3*>(&(*static_cast<Vector2*>(this) / (Vector2)other));
	//		tmp.z = z / other.z;
	return Vector3(this->x / other.x, this->y / other.y, this->z / other.z);
}

Vector3 Vector3::operator/=(Vector3 other)
{
	(*static_cast<Vector2*>(this) /= (Vector2)other);
	z /= other.z;
	return *this;
}

Vector3 Vector3::operator* (double other) const
{
	//		Vector3 tmp = *(Vector3*)&((*(Vector2*)this) * other);
	//		tmp.z = z * other;
	return Vector3(this->x * other, this->y * other, this->z * other);
}

Vector3 Vector3::operator*=(double other)
{
	(*(Vector2*)this) *= other;
	z *= other;
	return *this;
}

Vector3 Vector3::operator/(double other)
{
	//		Vector3 tmp = *(Vector3*)&((*(Vector2*)this) / other);
	//		tmp.z = z / other;
	return Vector3(this->x / other, this->y / other, this->z / other);
}

Vector3 Vector3::operator/=(double other)
{
	(*(Vector2*)this) /= other;
	z /= other;
	return *this;
}

std::string Vector3::toStringA()
{
	std::stringstream ss;
	ss << "(" << x << ", " << y << ", " << z << ")";
	return ss.str();
}

std::wstring Vector3::toStringW()
{
	std::wstringstream ss;
	ss << "(" << x << ", " << y << ", " << z << ")";
	return ss.str();
}

const Vector3 Vector3::forward = Vector3(0, 0, 1);
const Vector3 Vector3::backward = Vector3(0, 0, -1);
const Vector3 Vector3::up = Vector3(0, 1, 0);
const Vector3 Vector3::down = Vector3(0, -1, 0);
const Vector3 Vector3::left = Vector3(-1, 0, 0);
const Vector3 Vector3::right = Vector3(1, 0, 0);
const Vector3 Vector3::zero = Vector3(0, 0, 0);
const Vector3 Vector3::one = Vector3(1, 1, 1);


Vector4::Vector4() {}
Vector4::Vector4(double x, double y, double z, double w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

double Vector4::abs()
{
	return sqrt(x * x + y * y + z * z + w * w);
}
Vector4 Vector4::normalize()
{
	return *this / this->abs();
}

Vector4 Vector4::operator+(Vector2 other)
{
	//		Vector4 tmp = *static_cast<Vector4*>(&(*static_cast<Vector2*>(this) + other));
	//		tmp.z = z;
	//		tmp.w = w;
	return Vector4(this->x + other.x, this->y + other.y, this->z, this->w);
}

Vector4 Vector4::operator+(Vector3 other)
{
	//		Vector4 tmp = *static_cast<Vector4*>(&(*static_cast<Vector3*>(this) + other));
	//		tmp.w = w;
	return Vector4(this->x + other.x, this->y + other.y, this->z + other.z, this->w);
}

Vector4 Vector4::operator+(Vector4 other)
{
	//		Vector4 tmp = *static_cast<Vector4*>(&(*static_cast<Vector3*>(this) + (Vector3)other));
	//		tmp.w = w + other.w;
	return Vector4(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
}

Vector4 Vector4::operator+=(Vector2 other)
{
	(*static_cast<Vector2*>(this) += other);
	return *this;
}

Vector4 Vector4::operator+=(Vector3 other)
{
	(*static_cast<Vector3*>(this) += (Vector3)other);
	return *this;
}

Vector4 Vector4::operator+=(Vector4 other)
{
	(*static_cast<Vector3*>(this) += (Vector3)other);
	w += other.w;
	return *this;
}

Vector4 Vector4::operator-(Vector2 other)
{
	//		Vector4 tmp = *static_cast<Vector4*>(&(*static_cast<Vector3*>(this) - other));
	//		tmp.w = w;
	return Vector4(this->x - other.x, this->y - other.y, this->z, this->w);
}

Vector4 Vector4::operator-(Vector3 other)
{
	//		Vector4 tmp = *static_cast<Vector4*>(&(*static_cast<Vector3*>(this) - other));
	//		tmp.w = w;
	return Vector4(this->x - other.x, this->y - other.y, this->z - other.z, this->w);
}

Vector4 Vector4::operator-(Vector4 other)
{
	//		Vector4 tmp = *static_cast<Vector4*>(&(*static_cast<Vector3*>(this) - (Vector3)other));
	//		tmp.w = w - other.w;
	return Vector4(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
}

Vector4 Vector4::operator-=(Vector2 other)
{
	(*static_cast<Vector2*>(this) -= other);
	return *this;
}

Vector4 Vector4::operator-=(Vector3 other)
{
	(*static_cast<Vector3*>(this) -= other);
	return *this;
}

Vector4 Vector4::operator-=(Vector4 other)
{
	(*static_cast<Vector3*>(this) -= (Vector3)other);
	w -= other.w;
	return *this;
}

Vector4 Vector4::operator*(Vector4 other)
{
	//		Vector4 tmp = *static_cast<Vector4*>(&(*static_cast<Vector3*>(this) * (Vector3)other));
	//		tmp.w = w * other.w;
	return Vector4(this->x * other.x, this->y * other.y, this->z * other.z, this->w * other.w);
}

Vector4 Vector4::operator*=(Vector4 other)
{
	(*static_cast<Vector3*>(this) *= (Vector3)other);
	w *= other.w;
	return *this;
}

Vector4 Vector4::operator/(Vector4 other)
{
	//		Vector4 tmp = *static_cast<Vector4*>(&(*static_cast<Vector3*>(this) / (Vector3)other));
	//		tmp.w = w / other.w;
	return Vector4(this->x / other.x, this->y / other.y, this->z / other.z, this->w / other.w);
}

Vector4 Vector4::operator/=(Vector4 other)
{
	(*static_cast<Vector3*>(this) /= (Vector3)other);
	w /= other.w;
	return *this;
}

Vector4 Vector4::operator*(double other)
{
	//		Vector4 tmp = *(Vector4*)&((*(Vector3*)this) * other);
	//		tmp.w = w * other;
	return Vector4(this->x * other, this->y * other, this->z * other, this->w * other);
}

Vector4 Vector4::operator*=(double other)
{
	(*(Vector3*)this) *= other;
	w *= other;
	return *this;
}

Vector4 Vector4::operator/(double other)
{
	//		Vector4 tmp = *(Vector4*)&((*(Vector3*)this) / other);
	//		tmp.w = w / other;
	return Vector4(this->x / other, this->y / other, this->z / other, this->w / other);
}

Vector4 Vector4::operator/=(double other)
{
	(*(Vector3*)this) /= other;
	w /= other;
	return *this;
}

std::string Vector4::toStringA()
{
	std::stringstream ss;
	ss << "(" << x << ", " << y << ", " << z << ", " << w << ")";
	return ss.str();
}

std::wstring Vector4::toStringW()
{
	std::wstringstream ss;
	ss << "(" << x << ", " << y << ", " << z << ", " << w << ")";
	return ss.str();
}





Quaternion::Quaternion() {}
Quaternion::Quaternion(double x, double y, double z, double w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Quaternion Quaternion::operator = (const Quaternion& q)
{
	w = q.w;
	x = q.x;
	y = q.y;
	z = q.z;

	return (*this);
}

Quaternion Quaternion::operator + (const Quaternion& q)
{
	return Quaternion(w + q.w, x + q.x, y + q.y, z + q.z);
}

Quaternion Quaternion::operator - (const Quaternion& q)
{
	return Quaternion(w - q.w, x - q.x, y - q.y, z - q.z);
}


Quaternion Quaternion::operator * (const Quaternion& q)
{
	return Quaternion(
		w * q.w - x * q.x - y * q.y - z * q.z,
		w * q.x + x * q.w + y * q.z - z * q.y,
		w * q.y + y * q.w + z * q.x - x * q.z,
		w * q.z + z * q.w + x * q.y - y * q.x);
}

Quaternion Quaternion::operator / (Quaternion& q)
{
	return ((*this) * (q.inverse()));
}

Quaternion Quaternion::operator += (const Quaternion& q)
{
	w += q.w;
	x += q.x;
	y += q.y;
	z += q.z;

	return (*this);
}

Quaternion Quaternion::operator -= (const Quaternion& q)
{
	w -= q.w;
	x -= q.x;
	y -= q.y;
	z -= q.z;

	return (*this);
}

Quaternion Quaternion::operator *= (const Quaternion& q)
{
	double w_val = w * q.w - x * q.x - y * q.y - z * q.z;
	double x_val = w * q.x + x * q.w + y * q.z - z * q.y;
	double y_val = w * q.y + y * q.w + z * q.x - x * q.z;
	double z_val = w * q.z + z * q.w + x * q.y - y * q.x;

	w = w_val;
	x = x_val;
	y = y_val;
	z = z_val;

	return (*this);
}

Quaternion Quaternion::operator /= (Quaternion& q)
{
	(*this) = (*this) * q.inverse();
	return (*this);
}

bool  Quaternion::operator != (const Quaternion& q)
{
	return (w != q.w || x != q.x || y != q.y || z != q.z) ? true : false;
}

bool  Quaternion::operator == (const Quaternion& q)
{
	return (w == q.w && x == q.x && y == q.y && z == q.z) ? true : false;
}

Quaternion Quaternion::scale(double  s)
{
	return Quaternion(w * s, x * s, y * s, z * s);
}

Quaternion Quaternion::inverse()
{
	return conjugate().scale(1 / norm());
}

Quaternion Quaternion::conjugate()
{
	return Quaternion(w, -x, -y, -z);
}

double Quaternion::norm()
{
	return (w * w + x * x + y * y + z * z);
}

double Quaternion::magnitude()
{
	return sqrt(norm());
}

Quaternion Quaternion::UnitQuaternion()
{
	return (*this).scale(1 / (*this).magnitude());
}

/*Quaternion operator+(Quaternion other)
{
	Quaternion tmp = *static_cast<Quaternion*>(&(*static_cast<Vector4*>(this) + (Vector4)other));
	return tmp;
}

Quaternion operator+=(Quaternion other)
{
	*((Vector4*)this) += other;
	return *this;
}

Quaternion operator-(Quaternion other)
{
	Quaternion tmp = *static_cast<Quaternion*>(&(*static_cast<Vector4*>(this) - (Vector4)other));
	return tmp;
}


Quaternion operator-=(Quaternion other)
{
	*((Vector4*)this) -= (Vector4)other;
	return *this;
}

Quaternion operator*(Quaternion other)
{
	Quaternion tmp = *static_cast<Quaternion*>(&(*static_cast<Vector4*>(this) * (Vector4)other));
	return tmp;
}

Quaternion operator*=(Quaternion other)
{
	*((Vector4*)this) *= (Vector4)other;
	return *this;
}

Quaternion operator/(Quaternion other)
{
	Quaternion tmp = *static_cast<Quaternion*>(&(*static_cast<Vector4*>(this) / (Vector4)other));
	return tmp;
}

Quaternion operator/=(Quaternion other)
{
	*((Vector4*)this) /= (Vector4)other;
	return *this;
}

Quaternion operator*(double other)
{
	Quaternion tmp = *(Quaternion*)&((*(Vector4*)this) * other);
	return tmp;
}

Quaternion operator*=(double other)
{
	(*(Vector4*)this) *= other;
	return *this;
}

Quaternion operator/(double other)
{
	Quaternion tmp = *(Quaternion*)&((*(Vector4*)this) / other);
	return tmp;
}

Quaternion operator/=(double other)
{
	(*(Vector4*)this) /= other;
	return *this;
}*/


Vector3 Vector2::toVector3()
{
	return Vector3(x, y, 0);
}

Vector4 Vector2::toVector4()
{
	return Vector4(x, y, 0, 0);
}

Vector4 Vector3::toVector4()
{
	return Vector4(x, y, z, 0);
}

Color Vector4::toColor()
{
	return Color(x, y, z, w);
}
