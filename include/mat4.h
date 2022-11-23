#pragma once
#include "vec4.h"
#include <string>
#include <iostream>

namespace nml {

//  xx | yx | zx | wx
// ----|----|----|----
//  xy | yy | zy | wy
// ----|----|----|----
//  xz | yz | zz | wz
// ----|----|----|----
//  xw | yw | zw | ww
struct mat4 {
	vec4 x;
	vec4 y;
	vec4 z;
	vec4 w;
	
	// Constructors
	mat4();
	mat4(float _xxxyxzxwyxyyyzywzxzyzzzwwxwywzww);
	mat4(float _xx, float _xy, float _xz, float _xw, float _yx, float _yy, float _yz, float _yw, float _zx, float _zy, float _zz, float _zw, float _wx, float _wy, float _wz, float _ww);
	mat4(float _xx, float _xy, float _xz, float _xw, float _yx, float _yy, float _yz, float _yw, float _zx, float _zy, float _zz, float _zw, vec4 _wxwywzww);
	mat4(float _xx, float _xy, float _xz, float _xw, float _yx, float _yy, float _yz, float _yw, vec4 _zxzyzzzw, float _wx, float _wy, float _wz, float _ww);
	mat4(float _xx, float _xy, float _xz, float _xw, vec4 _yxyyyzyw, float _zx, float _zy, float _zz, float _zw, float _wx, float _wy, float _wz, float _ww);
	mat4(vec4 _xxxyxzxw, float _yx, float _yy, float _yz, float _yw, float _zx, float _zy, float _zz, float _zw, float _wx, float _wy, float _wz, float _ww);
	mat4(float _xx, float _xy, float _xz, float _xw, float _yx, float _yy, float _yz, float _yw, vec4 _zxzyzzzw, vec4 _wxwywzww);
	mat4(float _xx, float _xy, float _xz, float _xw, vec4 _yxyyyzyw, float _zx, float _zy, float _zz, float _zw, vec4 _wxwywzww);
	mat4(vec4 _xxxyxzxw, float _yx, float _yy, float _yz, float _yw, float _zx, float _zy, float _zz, float _zw, vec4 _wxwywzww);
	mat4(float _xx, float _xy, float _xz, float _xw, vec4 _yxyyyzyw, vec4 _zxzyzzzw, float _wx, float _wy, float _wz, float _ww);
	mat4(vec4 _xxxyxzxw, float _yx, float _yy, float _yz, float _yw, vec4 _zxzyzzzw, float _wx, float _wy, float _wz, float _ww);
	mat4(vec4 _xxxyxzxw, vec4 _yxyyyzyw, float _zx, float _zy, float _zz, float _zw, float _wx, float _wy, float _wz, float _ww);
	mat4(float _xx, float _xy, float _xz, float _xw, vec4 _yxyyyzyw, vec4 _zxzyzzzw, vec4 _wxwywzww);
	mat4(vec4 _xxxyxzxw, float _yx, float _yy, float _yz, float _yw, vec4 _zxzyzzzw, vec4 _wxwywzww);
	mat4(vec4 _xxxyxzxw, vec4 _yxyyyzyw, float _zx, float _zy, float _zz, float _zw, vec4 _wxwywzww);
	mat4(vec4 _xxxyxzxw, vec4 _yxyyyzyw, vec4 _zxzyzzzw, float _wx, float _wy, float _wz, float _ww);
	mat4(vec4 _xxxyxzxw, vec4 _yxyyyzyw, vec4 _zxzyzzzw, vec4 _wxwywzww);

	// Operators
	mat4& operator+=(const mat4& other);
	mat4& operator-=(const mat4& other);
	mat4& operator*=(const float other);
	mat4& operator*=(const mat4& other);
	mat4& operator/=(const float other);
	vec4& operator[](size_t index);
	const vec4& operator[](size_t index) const;

	// Functions
	float det() const;

	float* data();
	std::string to_string() const;
};

// Operators
mat4 operator+(mat4 lhs, const mat4& rhs);
mat4 operator-(mat4 lhs, const mat4& rhs);
mat4 operator*(mat4 lhs, const float rhs);
mat4 operator*(float lhs, const mat4& rhs);
mat4 operator*(mat4 lhs, const mat4& rhs);
mat4 operator/(mat4 lhs, const float rhs);
bool operator==(const mat4& lhs, const mat4& rhs);
bool operator!=(const mat4& lhs, const mat4& rhs);

// Functions
mat4 transpose(const mat4& mat);
mat4 inverse(const mat4& mat);

}