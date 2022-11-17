#include "../include/vec2.h"
#include <cmath>

namespace nml {

vec2::vec2(): x(0.0f), y(0.0f) {}
vec2::vec2(float _xy): x(_xy), y(_xy) {}
vec2::vec2(float _x, float _y): x(_x), y(_y) {}

float vec2::length() {
	return std::sqrt((x * x) + (y * y));
}

vec2 vec2::normalize() {
	float l = length();

	return vec2(x / l,
		y / l);
}

float* vec2::data() {
	return &x;
}

std::string vec2::to_string() {
	return (std::to_string(x) + ", " + std::to_string(y));
}

float dot(const vec2& a, const vec2& b) {
	return ((a.x * b.x) + (a.y * b.y));
}

vec2 reflect(const vec2& i, const vec2& n) {
	return (i - 2.0f * dot(n, i) * n);
}

vec2 refract(const vec2& i, const vec2& n, float eta) {
	float ndoti = dot(n, i);
	float k = 1.0f - eta * eta * (1.0f - ndoti * ndoti);
	if (k < 0.0f) {
		return vec2(0.0f);
	}
	else {
		return eta * i - (eta * ndoti + std::sqrt(k)) * n;
	}
}

}