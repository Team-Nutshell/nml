#pragma once
#include "vec3.h"
#include <array>
#include <utility>
#include <string>
#include <iostream>

namespace nml {

struct mat4;

//  xx | yx | zx
// ----|----|----
//  xy | yy | zy
// ----|----|----
//  xz | yz | zz
struct mat3 {
	vec3 x;
	vec3 y;
	vec3 z;
	
	// Constructors
	mat3();
	mat3(float _value);
	mat3(float _xx, float _xy, float _xz, float _yx, float _yy, float _yz, float _zx, float _zy, float _zz);
	mat3(float _xx, float _xy, float _xz, float _yx, float _yy, float _yz, const vec3& _z);
	mat3(float _xx, float _xy, float _xz, const vec3& _y, float _zx, float _zy, float _zz);
	mat3(const vec3& _x, float _yx, float _yy, float _yz, float _zx, float _zy, float _zz);
	mat3(float _xx, float _xy, float _xz, const vec3& _y, const vec3& _z);
	mat3(const vec3& _x, const vec3& _y, float _zx, float _zy, float _zz);
	mat3(const vec3& _x, float _yx, float _yy, float _yz, const vec3& _z);
	mat3(const vec3& _x, const vec3& _y, const vec3& _z);
	mat3(const float* _ptr);
	mat3(const mat4& _mat);

	// Operators
	mat3& operator+=(const mat3& other);
	mat3& operator-=(const mat3& other);
	mat3& operator*=(const mat3& other);
	mat3& operator*=(const float other);
	mat3& operator/=(const float other);
	vec3& operator[](size_t index);
	const vec3& operator[](size_t index) const;

	// Functions
	float det() const;
	std::array<std::pair<float, vec3>, 3> eigen() const;

	float* data();

	// Static Functions
	static mat3 identity();
};

// Operators
mat3 operator+(mat3 lhs, const mat3& rhs);
mat3 operator-(mat3 lhs, const mat3& rhs);
mat3 operator*(mat3 lhs, const mat3& rhs);
vec3 operator*(mat3 lhs, const vec3& rhs);
mat3 operator*(mat3 lhs, const float rhs);
mat3 operator*(float lhs, const mat3& rhs);
mat3 operator/(mat3 lhs, const float rhs);
bool operator==(const mat3& lhs, const mat3& rhs);
bool operator!=(const mat3& lhs, const mat3& rhs);

// Functions
mat3 transpose(const mat3& mat);
mat3 inverse(const mat3& mat);
mat3 translate(const vec2& translation);
mat3 rotate(const float angle);
mat3 scale(const vec2& scaling);

std::string to_string(const mat3& mat);

}