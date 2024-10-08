#pragma once
#include <string>

namespace nml {

struct vec2;
struct vec4;
struct mat4;
struct quat;

// x | y | z
struct vec3 {
	float x;
	float y;
	float z;
	
	// Constructors
	vec3();
	vec3(float _value);
	vec3(float _x, float _y, float _z);
	vec3(float _x, const vec2& _yz);
	vec3(const vec2& _xy, float _z);
	vec3(const float* _ptr);
	vec3(const vec4& _xyzw);

	// Operators
	vec3& operator+=(const vec3& other);
	vec3& operator-=(const vec3& other);
	vec3& operator*=(const float other);
	vec3& operator/=(const float other);
	vec3 operator-() const;
	float& operator[](size_t index);
	const float operator[](size_t index) const;

	// Functions
	float length() const;

	float* data();
};

// Operators
vec3 operator+(vec3 lhs, const vec3& rhs);
vec3 operator-(vec3 lhs, const vec3& rhs);
vec3 operator*(vec3 lhs, const float rhs);
vec3 operator*(float lhs, const vec3& rhs);
vec3 operator/(vec3 lhs, const float rhs);
bool operator==(const vec3& lhs, const vec3& rhs);
bool operator!=(const vec3& lhs, const vec3& rhs);

// Functions
vec3 normalize(const vec3& vec);
float dot(const vec3& a, const vec3& b);
vec3 cross(const vec3& a, const vec3& b);
vec3 reflect(const vec3& i, const vec3& n);
vec3 refract(const vec3& i, const vec3& n, float ior);
vec3 quatToEulerAngles(const quat& qua);
vec3 rotationMatrixToEulerAngles(const mat4& mat);

std::string to_string(const vec3& vec);

}