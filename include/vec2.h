#pragma once
#include <string>

namespace ntshm {

struct vec2 {
	float x;
	float y;
	
	// Constructors
	vec2();
	vec2(float _xy);
	vec2(float _x, float _y);

	// Operators
	vec2& operator+=(const vec2& other) { 
		x += other.x;
		y += other.y;

		return *this;
	}
	vec2& operator-=(const vec2& other) { 
		x -= other.x;
		y -= other.y;

		return *this;
	}
	vec2& operator*=(const float other) {
		x *= other;
		y *= other;

		return *this;
	}
	vec2& operator/=(const float other) {
		x /= other;
		y /= other;

		return *this;
	}

	// Functions
	float length();
	vec2 normalize();

	float* data();
	std::string to_string();
};

// Operators
inline vec2 operator+(vec2 lhs, const vec2& rhs) { return vec2(lhs.x + rhs.x, lhs.y + rhs.y); }
inline vec2 operator-(vec2 lhs, const vec2& rhs) { return vec2(lhs.x - rhs.x, lhs.y - rhs.y); }
inline vec2 operator*(vec2 lhs, const float rhs) { return vec2(lhs.x * rhs, lhs.y * rhs); }
inline vec2 operator*(float lhs, const vec2& rhs) { return rhs * lhs; }
inline vec2 operator/(vec2 lhs, const float rhs) { return vec2(lhs.x / rhs, lhs.y / rhs); }
inline vec2 operator/(float lhs, const vec2& rhs) { return rhs / lhs; }
inline bool operator==(const vec2& lhs, const vec2& rhs) { return ((lhs.x == rhs.x) && (lhs.y == rhs.y)); }
inline bool operator!=(const vec2& lhs, const vec2& rhs) { return !(lhs == rhs); }

// Functions
float dot(const vec2& a, const vec2& b);
vec2 reflect(const vec2& i, const vec2& n);
vec2 refract(const vec2& i, const vec2& n, float eta);

}