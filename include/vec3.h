#pragma once
#include <string>

namespace ntshm {

struct vec2;

struct vec3 {
	float x;
	float y;
	float z;
	
	// Constructors
	vec3();
	vec3(float _x, float _y, float _z);
	vec3(float _x, vec2 _yz);
	vec3(vec2 _xy, float _z);

	// Operators
	inline vec3 operator+(const vec3& other) { return vec3(x + other.x, y + other.y, z + other.z); }
	vec3& operator+=(const vec3& other) { 
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}
	inline vec3 operator-(const vec3& other) { return vec3(x - other.x, y - other.y, z - other.z); }
	vec3& operator-=(const vec3& other) { 
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}
	inline bool operator==(const vec3& other) { return ((x == other.x) && (y == other.y) && (z == other.z)); }
	inline bool operator!=(const vec3& other) { return !(*this == other); }

	// Functions
	float length();
	vec3 normalize();

	std::string to_string();
};

float dot(const vec3& a, const vec3& b);
vec3 cross(const vec3& a, const vec3& b);

}