#pragma once
#include <string>

namespace ntshm {

struct vec2;
struct vec3;

struct vec4 {
	float x;
	float y;
	float z;
	float w;
	
	// Constructors
	vec4();
	vec4(float _x, float _y, float _z, float _w);
	vec4(float _x, vec3 _yzw);
	vec4(vec3 _xyz, float _w);
	vec4(float _x, float _y, vec2 _zw);
	vec4(float _x, vec2 _yz, float _w);
	vec4(vec2 _xy, float _z, float _w);
	vec4(vec2 _xy, vec2 _zw);

	// Operators
	inline vec4 operator+(const vec4& other) { return vec4(x + other.x, y + other.y, z + other.z, w + other.w); }
	vec4& operator+=(const vec4& other) { 
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;

		return *this;
	}
	inline vec4 operator-(const vec4& other) { return vec4(x - other.x, y - other.y, z - other.z, w - other.w); }
	vec4& operator-=(const vec4& other) { 
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;

		return *this;
	}
	inline bool operator==(const vec4& other) { return ((x == other.x) && (y == other.y) && (z == other.z) && (w == other.w)); }
	inline bool operator!=(const vec4& other) { return !(*this == other); }

	// Functions
	float length();
	vec4 normalize();

	std::string to_string();
};

float dot(const vec4& a, const vec4& b);

}