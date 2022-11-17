#pragma once
#include <string>

namespace ntshm {

struct vec2 {
	float x;
	float y;
	
	// Constructors
	vec2();
	vec2(float _x, float _y);

	// Operators
	inline vec2 operator+(const vec2& other) { return vec2(x + other.x, y + other.y); }
	vec2& operator+=(const vec2& other) { 
		x += other.x;
		y += other.y;

		return *this;
	}
	inline vec2 operator-(const vec2& other) { return vec2(x - other.x, y - other.y); }
	vec2& operator-=(const vec2& other) { 
		x -= other.x;
		y -= other.y;

		return *this;
	}
	inline bool operator==(const vec2& other) { return ((x == other.x) && (y == other.y)); }
	inline bool operator!=(const vec2& other) { return !(*this == other); }

	// Functions
	float length();
	vec2 normalize();

	std::string to_string();
};

float dot(const vec2& a, const vec2& b);

}