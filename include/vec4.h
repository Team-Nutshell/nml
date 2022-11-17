#pragma once
#include <string>

namespace nml {

struct vec2;
struct vec3;

struct vec4 {
	float x;
	float y;
	float z;
	float w;
	
	// Constructors
	vec4();
	vec4(float _xyzw);
	vec4(float _x, float _y, float _z, float _w);
	vec4(float _x, vec3 _yzw);
	vec4(vec3 _xyz, float _w);
	vec4(float _x, float _y, vec2 _zw);
	vec4(float _x, vec2 _yz, float _w);
	vec4(vec2 _xy, float _z, float _w);
	vec4(vec2 _xy, vec2 _zw);

	// Operators
	vec4& operator+=(const vec4& other) { 
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;

		return *this;
	}
	vec4& operator-=(const vec4& other) { 
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;

		return *this;
	}
	vec4& operator*=(const float other) {
		x *= other;
		y *= other;
		z *= other;
		w *= other;

		return *this;
	}
	vec4& operator/=(const float other) {
		x /= other;
		y /= other;
		z /= other;
		w /= other;

		return *this;
	}

	// Functions
	float length() const;

	float* data();
	std::string to_string() const;
};

// Operators
inline vec4 operator+(vec4 lhs, const vec4& rhs) { return vec4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w); }
inline vec4 operator-(vec4 lhs, const vec4& rhs) { return vec4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w); }
inline vec4 operator*(vec4 lhs, const float rhs) { return vec4(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs); }
inline vec4 operator*(float lhs, const vec4& rhs) { return rhs * lhs; }
inline vec4 operator/(vec4 lhs, const float rhs) { return vec4(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs); }
inline vec4 operator/(float lhs, const vec4& rhs) { return rhs / lhs; }
inline bool operator==(const vec4& lhs, const vec4& rhs) { return ((lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z) && (lhs.w == rhs.w)); }
inline bool operator!=(const vec4& lhs, const vec4& rhs) { return !(lhs == rhs); }

// Functions
vec4 normalize(const vec4& v);
float dot(const vec4& a, const vec4& b);
vec4 reflect(const vec4& i, const vec4& n);
vec4 refract(const vec4& i, const vec4& n, float eta);

}