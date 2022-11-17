#include "../include/vec2.h"
#include <cmath>

namespace ntshm {

vec2::vec2(): x(0.0f), y(0.0f) {}
vec2::vec2(float _x, float _y): x(_x), y(_y) {}

float vec2::length() {
	return std::sqrt((x * x) + (y * y));
}

vec2 vec2::normalize() {
	float l = length();

	return vec2(x / l,
		y / l);
}

std::string vec2::to_string() {
	return (std::to_string(x) + ", " + std::to_string(y));
}

float dot(const vec2& a, const vec2& b) {
	return ((a.x * b.x) + (a.y * b.y));
}

}