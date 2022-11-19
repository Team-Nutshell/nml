#pragma once
#include <string>
#include <stdexcept>

namespace nml {

struct vec2;

struct vec3 {
	float x;
	float y;
	float z;
	
	// Constructors
	vec3();
	vec3(float _xyz);
	vec3(float _x, float _y, float _z);
	vec3(float _x, vec2 _yz);
	vec3(vec2 _xy, float _z);

	// Operators
	vec3& operator+=(const vec3& other) { 
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}
	vec3& operator-=(const vec3& other) { 
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}
	vec3& operator*=(const float other) {
		x *= other;
		y *= other;
		z *= other;

		return *this;
	}
	vec3& operator/=(const float other) {
		x /= other;
		y /= other;
		z /= other;

		return *this;
	}
	float& operator[](size_t index) {
		if (index == 0) { return x; }
		else if (index == 1) { return y; }
		else if (index == 2) { return z; }
		else { throw std::out_of_range("vec3::operator[]: index is out of range."); }
	}
	float operator[](size_t index) const {
		if (index == 0) { return x; }
		else if (index == 1) { return y; }
		else if (index == 2) { return z; }
		else { throw std::out_of_range("vec3::operator[]: index is out of range."); }
	}

	// Functions
	float length() const;

	float* data();
	std::string to_string() const;
};

// Operators
inline vec3 operator+(vec3 lhs, const vec3& rhs) { return vec3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z); }
inline vec3 operator-(vec3 lhs, const vec3& rhs) { return vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }
inline vec3 operator*(vec3 lhs, const float rhs) { return vec3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs); }
inline vec3 operator*(float lhs, const vec3& rhs) { return rhs * lhs; }
inline vec3 operator/(vec3 lhs, const float rhs) { return vec3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs); }
inline vec3 operator/(float lhs, const vec3& rhs) { return rhs / lhs; }
inline bool operator==(const vec3& lhs, const vec3& rhs) { return ((lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z)); }
inline bool operator!=(const vec3& lhs, const vec3& rhs) { return !(lhs == rhs); }

// Functions
vec3 normalize(const vec3& v);
float dot(const vec3& a, const vec3& b);
vec3 cross(const vec3& a, const vec3& b);
vec3 reflect(const vec3& i, const vec3& n);
vec3 refract(const vec3& i, const vec3& n, float eta);

}