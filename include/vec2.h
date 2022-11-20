#pragma once
#include <string>
#include <stdexcept>

namespace nml {

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
	float& operator[](size_t index) {
		if (index == 0) { return x; }
		else if (index == 1) { return y; }
		else { throw std::out_of_range("vec2::operator[]: index is out of range."); }
	}
	float operator[](size_t index) const {
		if (index == 0) { return x; }
		else if (index == 1) { return y; }
		else { throw std::out_of_range("vec2::operator[]: index is out of range."); }
	}

	// Functions
	float length() const;

	float* data();
	std::string to_string() const;
};

// Operators
inline vec2 operator+(vec2 lhs, const vec2& rhs) { 
	lhs += rhs;

	return lhs;
}
inline vec2 operator-(vec2 lhs, const vec2& rhs) {
	lhs -= rhs;

	return lhs;
}
inline vec2 operator*(vec2 lhs, const float rhs) {
	lhs *= rhs;

	return lhs;
}
inline vec2 operator*(float lhs, const vec2& rhs) { return rhs * lhs; }
inline vec2 operator/(vec2 lhs, const float rhs) { 
	lhs /= rhs;

	return lhs;
}
inline bool operator==(const vec2& lhs, const vec2& rhs) { return ((lhs.x == rhs.x) && (lhs.y == rhs.y)); }
inline bool operator!=(const vec2& lhs, const vec2& rhs) { return !(lhs == rhs); }

// Functions
vec2 normalize(const vec2& v);
float dot(const vec2& a, const vec2& b);
vec2 reflect(const vec2& i, const vec2& n);
vec2 refract(const vec2& i, const vec2& n, float eta);

}