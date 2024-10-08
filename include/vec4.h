#pragma once
#include <string>

namespace nml {

struct vec2;
struct vec3;

// x | y | z | w
struct vec4 {
	float x;
	float y;
	float z;
	float w;
	
	// Constructors
	vec4();
	vec4(float _value);
	vec4(float _x, float _y, float _z, float _w);
	vec4(float _x, const vec3& _yzw);
	vec4(const vec3& _xyz, float _w);
	vec4(float _x, float _y, const vec2& _zw);
	vec4(float _x, const vec2& _yz, float _w);
	vec4(const vec2& _xy, float _z, float _w);
	vec4(const vec2& _xy, const vec2& _zw);
	vec4(const float* _ptr);

	// Operators
	vec4& operator+=(const vec4& other);
	vec4& operator-=(const vec4& other);
	vec4& operator*=(const float other);
	vec4& operator/=(const float other);
	vec4 operator-() const;
	float& operator[](size_t index);
	const float operator[](size_t index) const;

	// Functions
	float length() const;

	float* data();
};

// Operators
vec4 operator+(vec4 lhs, const vec4& rhs);
vec4 operator-(vec4 lhs, const vec4& rhs);
vec4 operator*(vec4 lhs, const float rhs);
vec4 operator*(float lhs, const vec4& rhs);
vec4 operator/(vec4 lhs, const float rhs);
bool operator==(const vec4& lhs, const vec4& rhs);
bool operator!=(const vec4& lhs, const vec4& rhs);

// Functions
vec4 normalize(const vec4& vec);
float dot(const vec4& a, const vec4& b);
vec4 reflect(const vec4& i, const vec4& n);
vec4 refract(const vec4& i, const vec4& n, float ior);

std::string to_string(const vec4& vec);

}